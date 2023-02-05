# BasicSFMLGame

A Basic C++ Game made using SFML. The main goal of this project is expand my knowledge of C++ so I can develop my own game.

*Can't really call this a game since there are no mechanics other than movement atm but idc 😊* (It has animations at least now 😂)

# Demo
---

![image](https://user-images.githubusercontent.com/44748508/216804012-3ec5ab8d-a703-43e8-838f-aed08c830950.png)
*Will update to video later on*

## TODO List: (There is alot so its just the priority ones)
 - Fix Animation bug (When a player walks, multiple animation request are sent & Animations are too easiy overwritten)
 - Solve the "Render Layering" problem. (Can be demonstrated by moving in front of the cat)
 - Tiles & Blocks
 
## Design Choices:
 - Thinking about having an internal "tick" system, (Used by game servers, my experience being Minecraft), and relying on that for Tile & Entity updates. (Movement will be calculated in Component#render instead.)
 - Optimizations, currently I have no experience with C++ but I'm learning, so I'll be refactoring my code alot for optimizations and small changes. (Decoupling, Globally cached animations, etc.)

# Resources
---

- Textures / Sprites: 
  - https://game-endeavor.itch.io/ (Character Sprite)
  - https://elthen.itch.io/2d-pixel-art-cat-sprites (Cat Sprite)
