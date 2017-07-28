default: first second

first: antialiasing.o house.o
	g++ antialiasing.o house.o -o first -framework OpenGL -framework GLUT

second: transformation.o house.o
	g++ transformation.o house.o -o second -framework OpenGL -framework GLUT

third: colouring.o 
	g++ colouring.o -o third -framework OpenGL -framework GLUT

antialiasing.o: antialiasing.cpp house.hpp
	g++ -c antialiasing.cpp 

transformation.o: transformation.cpp house.hpp
	g++ -c transformation.cpp 

house.o: house.cpp house.hpp
	g++ -c house.cpp

colouring.o: colouring.cpp
	g++ -c colouring.cpp

clean:
	rm -rf *.o first second third