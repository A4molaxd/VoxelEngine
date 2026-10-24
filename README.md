# Voxel Engine

I started from [this](https://www.youtube.com/watch?v=45MIykWJ-C4) tutorial series in Youtube from Victor Gordan.

Objectives (from more to less probable):
  - Different types of blocks to interact with.
  - Create a chunk-based system to render procedurally generated terrain.
  - Break and place blocks.
  - Optimize it.
  - Save and load worlds.
  - Water.
  - Player.

Resources used to look up information:
  - https://0fps.net/2012/06/30/meshing-in-a-minecraft-game/
  - https://0fps.net/2012/01/14/an-analysis-of-minecraft-like-engines/ 
  - https://www.youtube.com/@wsalevan (Very interesting and informative videos on his Minecraft clone)

Interesting issues so far:
 - As it turns out, when you do `for (Chunk chunk : loadedChunks) {...}` it takes approximately 4 ms to calculate the next item each time the code inside is executed (I think this is because I modify the element once inside), this lead to a giant leap from 20 to more than 1000 FPS when I discovered the problem.
