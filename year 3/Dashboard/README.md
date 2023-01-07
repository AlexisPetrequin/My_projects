# **Dashboard Epitech**

## **Authors**

- valentin.elter@epitech.eu
- alexis.petrequin@epitech.eu

## **Architecture**

Our project is divided into 2 parts, the front and the back.

This architecture allows us to work both on the same project without risking merge errors.

### **The services**

- Weather API, giving the weather in a given city
- Youtube API, giving informations about a given channel
- Conversion API, giving the value of money given converted to another currency
- Steam API, giving 3 functionalities : 
    - finding a game and it's statistics
    - finding a given player and it's most recently played games as well as how much time they played them
    - finding a given player's friend list

## **Production deployement**

Our project uses `Gradle`.

### **Gradle**

Gradle is used for **local environment**.

To build the project: `$> gradle build`

To run the project: `$> gradle bootrun`

## **Frontend**

The frontend (main application) is available at `http://localhost:8080` on local env.

A `about.json` file is available at `http://localhost:8080/about.json`.
