FLAGS = -g 

all: clean test_Bin run

test_Bin: Bin.o test_Bin.cpp
	g++ $(FLAGS) -o test_Bin Bin.o test_Bin.cpp

Bin.o: Bin.cpp Bin.h
	g++ $(FLAGS) -c Bin.cpp

clean:
	rm -f test_Bin *.o

run:
	./test_Bin