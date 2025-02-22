# OOP-based 2d game
***The game is a maze with events on the cells. 
The goal is to reach the exit cell***

# Build part
After clone repository use the following commands:
```
mkdir Build
cd Build
cmake ..
cmake --build .
```
Then you can see executable file "main" in Build directory

# Examples
![image](https://github.com/yaQvadrat/OOP/assets/91385956/2716858f-3918-43d1-9211-669a6564cb64)
![image](https://github.com/yaQvadrat/OOP/assets/91385956/59c40c8b-5914-4912-850c-f94658a4a5b8)
![image](https://github.com/yaQvadrat/OOP/assets/91385956/8f23ad52-d436-4152-9b89-898961368bdb)

In these screenshots, you can see what the console view of the game looks like

File logs that are can be saved in the file "/Logger/LOGS" or also release on the console during the game (SELECT REQUIRED MODE).


***Game Elements***

- [@] = PLAYER

- [ ] = DEFAULT CELL

- [#] = WALL

- [P] = POINTS

- [T] = TRAP

- [>], [<], [v], [^] = THROW ASIDE EVENT


***Default config:***

- W=MVUP

- S=MVDOWN

- A=MVLEFT

- D=MVRIGHT

- Q=EXIT

R=RESTART

The config can be changed in the file "/Input/CONFIG"
