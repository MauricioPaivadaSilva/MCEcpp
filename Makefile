

all: saida
	g++ -c main.cpp

saida: main.o
	g++ main.o -o graph-app -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm -rf *.o
	rm -rf graph-app
