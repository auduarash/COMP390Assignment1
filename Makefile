default: main

main: antialiasing.o house.o
	g++ antialiasing.o house.o -o main -framework OpenGL -framework GLUT

antialiasing.o: antialiasing.cpp house.hpp
	g++ -c antialiasing.cpp 

house.o: house.cpp house.hpp
	g++ -c house.cpp

clean:
	rm -rf *.o main