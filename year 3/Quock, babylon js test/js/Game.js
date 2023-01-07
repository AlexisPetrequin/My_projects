document.addEventListener("DOMContentLoaded", function () {
    new Game('renderCanvas');
}, false);

Game = function (canvasId) {
    // Canvas et engine défini ici
    var canvas = document.getElementById(canvasId);
    var engine = new BABYLON.Engine(canvas, true);
    this.engine = engine
    var _this = this;
    this.scene = this._initScene(engine);
    this._rockets = [];
    this._lasers = [];
    this._explosionRadius = [];
    this.allSpawnPoints = [
        new BABYLON.Vector3(-20, 300, 0),
        new BABYLON.Vector3(0, 300, 0),
        new BABYLON.Vector3(20, 300, 0),
        new BABYLON.Vector3(-40, 300, 0)
    ];
    var armory = new Armory(this);
    _this.armory = armory;
    var _player = new Player(_this, canvas);
    var _arena = new Arena(_this);
    this._PlayerData = _player;
    this._deltaFireRate = this.armory.weapons[this._PlayerData.camera.weapons.inventory[this._PlayerData.camera.weapons.actualWeapon].typeWeapon].setup.cadency;

    engine.runRenderLoop(function () {
        // Récuperet le ratio par les fps
        _this.fps = Math.round(1000 / engine.getDeltaTime());
        _player._checkMove((_this.fps) / 60);
        // _this.fireRate(engine);
        _this.renderRockets();
        _this.renderExplosionRadius();
        _this.renderLaser();
        _this.renderWeapons();
        _this.scene.render();
        if (_player.camera.weapons.launchBullets === true && _this.fireRate(engine)) {
                _player.camera.weapons.launchFire();
        }
    });
    window.addEventListener("resize", function () {
        if (engine) {
            engine.resize();
        }
    }, false);

};

Game.prototype = {
    _initScene: function (engine) {
        var scene = new BABYLON.Scene(engine);
        scene.clearColor = new BABYLON.Color3(0, 0, 0);
        scene.gravity = new BABYLON.Vector3(0, -9.81, 0);
        scene.collisionsEnabled = true;
        return scene;
    },
    fireRate: function (engine) {
        // if (!this._PlayerData.camera.weapons.canFire) {
        //     this._deltaFireRate -= engine.getDeltaTime();
        //     console.log("time left = ", this._deltaFireRate -= engine.getDeltaTime())
        //     if (this._deltaFireRate <= 0 && this._PlayerData.isAlive) {
        //         console.log("boom")
        //         this._PlayerData.camera.weapons.canFire = true;
        //         this._deltaFireRate = this.armory.weapons[this._PlayerData.camera.weapons.inventory[this._PlayerData.camera.weapons.actualWeapon].typeWeapon].setup.cadency;
        //     }
        // }
        return (this._PlayerData.camera.weapons.canFire);
    },
    renderWeapons: function () {
        if (this._PlayerData && this._PlayerData.camera.weapons.inventory) {
            // On regarde toutes les armes dans inventory
            var inventoryWeapons = this._PlayerData.camera.weapons.inventory;

            for (var i = 0; i < inventoryWeapons.length; i++) {
                // Si l'arme est active et n'est pas à la position haute (topPositionY)
                if (inventoryWeapons[i].isActive && inventoryWeapons[i].position.y < this._PlayerData.camera.weapons.topPositionY) {
                    inventoryWeapons[i].position.y += 0.1;
                } else if (!inventoryWeapons[i].isActive && inventoryWeapons[i].position.y != this._PlayerData.camera.weapons.bottomPosition.y) {
                    // Sinon, si l'arme est inactive et pas encore à la position basse
                    inventoryWeapons[i].position.y -= 0.1;
                }
            }
        }
    },
    renderLaser: function () {
        if (this._lasers.length > 0) {
            for (var i = 0; i < this._lasers.length; i++) {
                this._lasers[i].edgesWidth -= 0.5;
                if (this._lasers[i].edgesWidth <= 0) {
                    this._lasers[i].dispose();
                    this._lasers.splice(i, 1);
                }
            }
        }
    },
    renderRockets: function () {
        for (var i = 0; i < this._rockets.length; i++) {
            var rayRocket = new BABYLON.Ray(this._rockets[i].position, this._rockets[i].direction);

            // On regarde quel est le premier objet qu'on touche
            var meshFound = this._rockets[i].getScene().pickWithRay(rayRocket);
            // Si la distance au premier objet touché est inférieure à 10, on détruit la roquette
            if (!meshFound || meshFound.distance < 10) {
                // On vérifie qu'on a bien touché quelque chose
                if (meshFound.pickedMesh && !meshFound.pickedMesh.isMain) {
                    var explosionRadius = BABYLON.Mesh.CreateSphere("sphere", 5.0, 20, this.scene);
                    explosionRadius.position = meshFound.pickedPoint;
                    explosionRadius.isPickable = false;
                    explosionRadius.material = new BABYLON.StandardMaterial("textureExplosion", this.scene);
                    explosionRadius.material.diffuseColor = new BABYLON.Color3(1, 0.6, 0);
                    explosionRadius.material.specularColor = new BABYLON.Color3(0, 0, 0);
                    explosionRadius.material.alpha = 0.8
                    explosionRadius.computeWorldMatrix(true);
                    console.log("explosion");
                    if (this._PlayerData.isAlive && this._PlayerData.camera.playerBox && explosionRadius.intersectsMesh(this._PlayerData.camera.playerBox)) {
                        console.log('hit')
                        this._PlayerData.getDamage(30)
                    }
                    this._explosionRadius.push(explosionRadius);
                }
                this._rockets[i].dispose();
                this._rockets.splice(i, 1);
            } else {
                let relativeSpeed = 1 / ((this.fps) / 60);
                this._rockets[i].position.addInPlace(this._rockets[i].direction.scale(relativeSpeed))
            }
        };
    },
    renderExplosionRadius: function () {
        if (this._explosionRadius.length > 0) {
            for (var i = 0; i < this._explosionRadius.length; i++) {
                this._explosionRadius[i].material.alpha -= 0.02;
                if (this._explosionRadius[i].material.alpha <= 0) {
                    this._explosionRadius[i].dispose();
                    this._explosionRadius.splice(i, 1);
                }
            }
        }
    }
};

function degToRad(deg) {
    return (Math.PI * deg) / 180
}
function radToDeg(rad) {
    // return (Math.PI*deg)/180
    return (rad * 180) / Math.PI
}