Player = function (game, canvas) {
    var _this = this;
    this.game = game;
    this.axisMovement = [false, false, false, false];

    //SENSI SOURIS
    this.angularSensibility = 200;
    //MOVE SPEED PERSO
    this.speed = 1;
    // TIR DU PLAYER
    this.weaponShoot = false;

    this.previousWheeling = 0;

    window.addEventListener("mousewheel", function (evt) {
        console.log("wherll")
        // Si la différence entre les deux tours de souris sont minimes
        if (Math.round(evt.timeStamp - _this.previousWheeling) > 10) {
            if (evt.deltaY < 0) {
                _this.camera.weapons.nextWeapon(1);
            } else {
                _this.camera.weapons.nextWeapon(-1);
            }
            _this.previousWheeling = evt.timeStamp;
        }

    }, false);
    window.addEventListener("keyup", function (evt) {
        switch (evt.key) {
            case "z":
                _this.camera.axisMovement[0] = false;
                break;
            case "s":
                _this.camera.axisMovement[1] = false;
                break;
            case "q":
                _this.camera.axisMovement[2] = false;
                break;
            case "d":
                _this.camera.axisMovement[3] = false;
                break;
        }
    }, false);
    window.addEventListener("keydown", function (evt) {
        switch (evt.key) {
            case "z":
                _this.camera.axisMovement[0] = true;
                break;
            case "s":
                _this.camera.axisMovement[1] = true;
                break;
            case "q":
                _this.camera.axisMovement[2] = true;
                break;
            case "d":
                _this.camera.axisMovement[3] = true;
                break;
        }
    }, false);
    // On récupère le canvas de la scène
    var canvas = this.game.scene.getEngine().getRenderingCanvas();

    // On affecte le clic et on vérifie qu'il est bien utilisé dans la scène (_this.controlEnabled)
    canvas.addEventListener("mousedown", function (evt) {
        if (_this.controlEnabled && !_this.weaponShoot) {
            _this.weaponShoot = true;
            _this.handleUserMouseDown();
        }
    }, false);

    // On fait pareil quand l'utilisateur relache le clic de la souris
    canvas.addEventListener("mouseup", function (evt) {
        if (_this.controlEnabled && _this.weaponShoot) {
            _this.weaponShoot = false;
            _this.handleUserMouseUp();
        }
    }, false);
    window.addEventListener("mousemove", function (evt) {
        if (_this.rotEngaged === true) {
            _this.camera.playerBox.rotation.y += evt.movementX * 0.001 * (_this.angularSensibility / 250);
            var nextRotationX = _this.camera.playerBox.rotation.x + (evt.movementY * 0.001 * (_this.angularSensibility / 250));
            if (nextRotationX < degToRad(90) && nextRotationX > degToRad(-90)) {
                _this.camera.playerBox.rotation.x += evt.movementY * 0.001 * (_this.angularSensibility / 250);
            }
        }
    }, false);

    this.controlEnabled = false;
    this._initPointerLock();

    this._initCamera(this.game.scene, canvas);
};

Player.prototype = {
    playerDead: function (i) {
        this.deadCamera = new BABYLON.ArcRotateCamera("ArcRotateCamera",
            1, 0.8, 10,
            new BABYLON.Vector3(this.camera.playerBox.position.x, this.camera.playerBox.position.y, this.camera.playerBox.position.z),
            this.game.scene);
        this.camera.playerBox.dispose();
        this.camera.dispose();
        this.camera.weapons.inventory[this.camera.weapons.actualWeapon].dispose();
        this.isAlive = false;
        this.game.scene.activeCamera = this.deadCamera;
        this.deadCamera.attachControl(this.game.scene.getEngine().getRenderingCanvas());
        var newPlayer = this;
        var canvas = this.game.scene.getEngine().getRenderingCanvas();
        setTimeout(() => {
            this.camera.setTarget(BABYLON.Vector3.Zero());
            newPlayer._initCamera(newPlayer.game.scene, canvas);
            this.game.scene.activeCamera = newPlayer.camera;
        }, 4000);
    },
    getDamage: function (damage) {
        var damageTaken = damage;
        if (this.camera.armor > Math.round(damageTaken / 2)) {
            this.camera.armor -= Math.round(damageTaken / 2);
            damageTaken = Math.round(damageTaken / 2);
        } else {
            damageTaken = damageTaken - this.camera.armor;
            this.camera.armor = 0;
        }
        if (this.camera.health > damageTaken) {
            this.camera.health -= damageTaken;
        } else {
            this.playerDead()
        }
    },

    handleUserMouseDown: function () {
        if (this.isAlive === true) {
            this.camera.weapons.fire();
        }
    },
    handleUserMouseUp: function () {
        if (this.isAlive === true) {
            this.camera.weapons.stopFire();
        }
    },
    _checkMove: function (ratioFps) {
        let relativeSpeed = this.speed / ratioFps;
        if (this.camera.axisMovement[0]) {
            forward = new BABYLON.Vector3(
                parseFloat(Math.sin(parseFloat(this.camera.playerBox.rotation.y))) * relativeSpeed,
                0,
                parseFloat(Math.cos(parseFloat(this.camera.playerBox.rotation.y))) * relativeSpeed
            );
            this.camera.playerBox.moveWithCollisions(forward);
        }
        if (this.camera.axisMovement[1]) {
            backward = new BABYLON.Vector3(
                parseFloat(-Math.sin(parseFloat(this.camera.playerBox.rotation.y))) * relativeSpeed,
                0,
                parseFloat(-Math.cos(parseFloat(this.camera.playerBox.rotation.y))) * relativeSpeed
            );
            this.camera.playerBox.moveWithCollisions(backward);
        }
        if (this.camera.axisMovement[2]) {
            left = new BABYLON.Vector3(
                parseFloat(Math.sin(parseFloat(this.camera.playerBox.rotation.y) + degToRad(-90))) * relativeSpeed,
                0,
                parseFloat(Math.cos(parseFloat(this.camera.playerBox.rotation.y) + degToRad(-90))) * relativeSpeed
            );
            this.camera.playerBox.moveWithCollisions(left);
        }
        if (this.camera.axisMovement[3]) {
            right = new BABYLON.Vector3(
                parseFloat(-Math.sin(parseFloat(this.camera.playerBox.rotation.y) + degToRad(-90))) * relativeSpeed,
                0,
                parseFloat(-Math.cos(parseFloat(this.camera.playerBox.rotation.y) + degToRad(-90))) * relativeSpeed
            );
            this.camera.playerBox.moveWithCollisions(right);
        }
        // GRAVITE
        this.camera.playerBox.moveWithCollisions(new BABYLON.Vector3(0, (-1.5) * relativeSpeed, 0));
    },

    _initPointerLock: function () {
        // controle souris
        var _this = this;

        var canvas = this.game.scene.getEngine().getRenderingCanvas();
        canvas.addEventListener("click", function (evt) {
            canvas.requestPointerLock = canvas.requestPointerLock || canvas.msRequestPointerLock || canvas.mozRequestPointerLock || canvas.webkitRequestPointerLock;
            if (canvas.requestPointerLock) {
                canvas.requestPointerLock();
            }
        }, false);

        var pointerlockchange = function (event) {
            _this.controlEnabled = (document.mozPointerLockElement === canvas || document.webkitPointerLockElement === canvas || document.msPointerLockElement === canvas || document.pointerLockElement === canvas);
            if (!_this.controlEnabled) {
                _this.rotEngaged = false;
            } else {
                _this.rotEngaged = true;
            }
        };
        document.addEventListener("pointerlockchange", pointerlockchange, false);
        document.addEventListener("mspointerlockchange", pointerlockchange, false);
        document.addEventListener("mozpointerlockchange", pointerlockchange, false);
        document.addEventListener("webkitpointerlockchange", pointerlockchange, false);
    },

    _initCamera: function (scene, canvas) {
        let randomPoint = Math.random();

        // randomPoint fait un arrondi de ce chiffre et du nombre de spawnPoints
        randomPoint = Math.round(randomPoint * (this.game.allSpawnPoints.length - 1));

        // On dit que le spawnPoint est celui choisi selon le random plus haut
        this.spawnPoint = this.game.allSpawnPoints[randomPoint];

        var playerBox = BABYLON.Mesh.CreateBox("headMainPlayer", 3, scene);
        // On donne le spawnPoint avec clone() pour que celui-ci ne soit pas affecté par le déplacement du joueur
        playerBox.position = this.spawnPoint.clone();
        playerBox.ellipsoid = new BABYLON.Vector3(2, 4, 2);
        this.camera = new BABYLON.FreeCamera("camera", new BABYLON.Vector3(0, 0, 0), scene);
        this.camera.playerBox = playerBox
        this.camera.parent = this.camera.playerBox;
        this.camera.health = 100;
        this.camera.armor = 0;
        this.camera.playerBox.checkCollisions = true;
        this.camera.playerBox.applyGravity = true;
        this.isAlive = true;
        this.camera.isMain = true;
        this.camera.weapons = new Weapons(this);
        this.camera.axisMovement = [false, false, false, false];


        var hitBoxPlayer = BABYLON.Mesh.CreateBox("hitBoxPlayer", 3, scene);
        hitBoxPlayer.parent = this.camera.playerBox;
        hitBoxPlayer.scaling.y = 2;
        hitBoxPlayer.isPickable = true;
        hitBoxPlayer.isMain = true;

    }
};