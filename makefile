all: main.o 
	g++ main.o chess.o ejemplo.c -lglut -lGL -lGLU -w -o ejemplo
main.o: main.c
	g++ -c main.c
