FLAGS = -c -std=c++20

main: main.o Player.o PlayerController.o
	g++ main.o Player.o PlayerController.o -o main

main.o: main.cpp Player.hh PlayerController.hh
	g++ $(FLAGS) main.cpp

Player.o: Player.cpp Player.hh
	g++ $(FLAGS) Player.cpp

PlayerController.o: PlayerController.cpp PlayerController.hh Player.hh
	g++ $(FLAGS) PlayerController.cpp

clean:
	rm *.o
