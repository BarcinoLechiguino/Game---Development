# Mutual Cooperation
Mutual Cooperation is a 2D Platformer developed by Gerard Romeu and Ángel González, two 2nd year students of the Bachelor Degree in Video Game Design and Development at UPC CITM/TTC, Barcelona .  It has been made from scratch in C++ with Visual Studio and Brofiler has been used as profiling tool.



# Versions

- **v0.1**: 

  - Collider Module Implementation

  - Player 1 and Player 2 Module Implementation

  - Camera Module Implementation

  - Two levels can be played through.

  - Maps can be transitioned from one to another.

  - Cooperative gameplay: 2 Players can play at the same time. 

  - Players can move, jump, perform dual moves together and can teleport to each other. 

  - Implemented 7 different debug keys:

    - F1: Loads the first map.
    - F2: Loads the second map.
    - F3: Resets the players' position to the map's starting point.
    - F5: Load Game.
    - F6: Save Game.
    - F9: Collider Debug (Makes all colliders visible).
    - F10: God Mode.

    

- **v0.5**: 

  - Discarded both maps from v0.1 and designed 2 new ones.

  - Animation pushbacks are now loaded from a tmx file.

  - There is now a death animation for both players.

  - The collider rebound bug from v0.1 has been fixed.

  - Both Parallax and Camera Culling have been implemented.

  - Framerate control has been implemented (Avg FPS, measurement of frames in ms...).

  - Frames are now capped at 30 without Vsync. To uncap them press F11.

  - All in-game movement has been normalized using dt.

  - Implemented skill cooldowns ( the teleport skill has a cooldown of 1 second).

  - Now the teleport skill cannot be used when a player is facing a wall up close.

  - Both skill cooldowns and not being able to teleport have their own sfx.

  - An autosave function triggered by reaching a checkpoint has been implemented.

  - Implemented three new debug keys:

    - F7: Frees the camera and can be moved around with the arrow keys.
    - F8: Pathfinding Debug Mode. 
    - F11: Uncaps the framerate.

  - An entity system has been implemented.

  - Both a flying and a land enemy have been implemented.

  - Players now have an attack action, so enemies can be defeated.

  - Pathfinding has been implemented:

    - Now both flying and land enemies have a detection range.
    - Once a player has been detected and if there is a viable path, the enemy entity will path around any obstacles to reach the player. 

  - Brofiler has been implemented as profiling tool. Graphics, pathfinding and other logic code have been visually differentiated.

    

# Instructions:
Download the game file in which you will find the executable. 



# Controls
## Player 1
- **Basic Movement Keys:** 

  - A Key: Move to the left.
  - S Key: Crouch.
  - D Key: Move to the right.
  - Space Bar: Jump.

- **Special Actions:**

  - E Key: Teleport Player 2 to Player 1.

  - W Key: Attack.

    

## Player 2
- **Basic Movement Keys:** 

  - 4 Key (Keypad): Move to the left.
  - 5 Key (Keypad): Crouch.
  - 6 Key (Keypad): Move to the right.
  - 0 Key (Keypad): Jump.

- **Special Actions:**

  - 7 Key (Keypad): Teleport Player 1 to Player 2.
  - 8 Key (Keypad): Attack.

  

# Innovative features
* **Cooperative Gameplay:**

  * The game can be played by **two players** (P1 has a red cape and P2 has a blue one).

  * The players have **combined movements**:

    * **Boost Jump**: When a player is in crouch position and the other runs towards them, the running player will be boosted upwards to reach higher or further platforms. 
    * **Teleport**: A player can teleport the other player to their actual position.

    

* **Skill Cooldown:**

  * The teleport skill now has a 1 second cooldown.
  * When the teleport skill comes out of cooldown, a sfx will be reproduced.

  

* **Checkpoint Autosave:**

  * The game will be automatically saved for the player who reaches the checkpoint.
  * The respawn point of the player who reaches the checkpoint will be set to the checkpoint's position.



# Debug Keys
- **F1**: Loads the first level. 

- **F2**: Loads the second level. 

- **F3**: Resets the players' position to the map's starting point. 

- **F5**: Load the saved game. 

- **F6**: Save the current game. 

- **F7**: Camera Debug Mode (Camera can be moved around with the arrow keys).

- **F8**: Pathfinding Debug Mode (Paths are visible and can be created with 2 right clicks).

- **F9**: Collider Debug Mode (Makes all colliders visible). 

- **F10**: God Mode (Players are invincible, can go through walls and have free movement). 

- **F11**: Enable/Disable frame cap.

  

# Team Members
- **Gerard Romeu:** https://github.com/Gromeu2000

- **Ángel González:** https://github.com/BarcinoLechiguino

  

# Work distribution
- **Ángel González:** 

  - Collider Module implementation (Colliders loaded from each of the maps' xml file).

  - Camera Module implementation (Camera takes the mid position between both players)

  - Both Player 1 and Player 2 module and gameplay logic (inputs, skills...) implementation.

  - Animations implementation (Animation pushbacks loaded from an xml file).

  - Parallax and Camera Culling implementation

  - Frame Cap, Movement normalization with dt and Framerate Control implementation.

  - Entity System implementation.

  - Enemy Entities implementation.

  - Player Attack and Enemy Destruction implementation. 

  - Pathfinding module and entity behavior implementation.

  - F7, F8, F9, F10 and F11 debug keys implementation.

  - ReadMe.

    

- **Gerard Romeu:** 

  - Audio & FX 

  - Level design.

  - Map Transtion implementation.

  - Player Animations & enemy sprites and fx implementation.

  - j1Entity and j1EntityManager implementation. 

  - UML of the Entity System.

  - Checkpoint Autosave implementation.

  - Load & Save Implementation

  - F1, F2, F3, F5 and F6 debug keys implementation.

  - ReadMe.

  

# Credits
- https://rvros.itch.io/animated-pixel-hero

- https://edermunizz.itch.io/free-pixel-art-forest

- https://0x72.itch.io/16x16-industrial-tileset

- https://0x72.itch.io/16x16-robot-tileset

- https://szadiart.itch.io/pixel-dark-forest

- https://anokolisa.itch.io/forest-game-assets-20

- https://northgames.itch.io/dirtbrick

  

# Link to Repository
https://github.com/BarcinoLechiguino/Development---Game



# License
MIT License

Copyright (c) [2019] [Gerard Romeu, Ángel González]

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.