CC=g++
LDLIBS=-lsfml-graphics -lsfml-window -lsfml-system

all: build/bin

build/bin: main.o entity.o animation.o
	$(CC) $^ $(LDLIBS) -o $@

main.o: src/main.cpp 
	$(CC) -c $^ -o $@

entity.o: src/entity.cpp include/entity.h
	$(CC) -c src/entity.cpp -o $@

animation.o: src/animation.cpp include/animation.h
	$(CC) -c src/animation.cpp -o $@

c:
	rm *.o build/bin

r: build/bin
	$^

rc: build/bin
	$^ && make c
