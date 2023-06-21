main: build/main.o build/indice.o build/normalizador.o 
	c++ -I include -std=c++17 build/main.o build/indice.o build/normalizador.o -o main

build/main.o: src/main.cpp
	c++ -I include -std=c++17 -c src/main.cpp -o build/main.o

build/indice.o: include/indice.h src/indice.cpp
	c++ -I include -std=c++17 -c src/indice.cpp -o build/indice.o

build/normalizador.o: include/normalizador.h src/normalizador.cpp
	c++ -I include -std=c++17 -c src/normalizador.cpp -o build/normalizador.o

run: main
	./main