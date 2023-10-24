bin/main: obj/main.o obj/indice.o obj/normalizador.o 
	c++ -I include -std=c++17 obj/main.o obj/indice.o obj/normalizador.o -g -o main

obj/main.o: src/main.cpp
	c++ -I include -std=c++17 -c src/main.cpp -o obj/main.o

obj/indice.o: include/indice.h src/indice.cpp
	c++ -I include -std=c++17 -c src/indice.cpp -o obj/indice.o

obj/normalizador.o: include/normalizador.h src/normalizador.cpp
	c++ -I include -std=c++17 -c src/normalizador.cpp -o obj/normalizador.o

all: bin/main

run: bin/main
	./main