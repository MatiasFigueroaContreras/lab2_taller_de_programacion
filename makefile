FLAGS = -O2 -g -Wall

all: clean test_Bin test_BinPackage test_BinPackingSolver run

main: main.cpp BinPackingSolver.o BinPackage.o Bin.o
	g++ $(FLAGS) -o main BinPackingSolver.o BinPackage.o Bin.o main.cpp

test_Bin: Bin.o test_Bin.cpp
	g++ $(FLAGS) -o test_Bin Bin.o test_Bin.cpp

test_BinPackage: Bin.o BinPackage.o test_BinPackage.cpp
	g++ $(FLAGS) -o test_BinPackage Bin.o BinPackage.o test_BinPackage.cpp

test_BinPackingSolver: Bin.o BinPackage.o BinPackingSolver.o test_BinPackingSolver.cpp
	g++ $(FLAGS) -o test_BinPackingSolver Bin.o BinPackage.o BinPackingSolver.o test_BinPackingSolver.cpp

Bin.o: Bin.cpp Bin.h
	g++ $(FLAGS) -c Bin.cpp

BinPackage.o: BinPackage.cpp BinPackage.h
	g++ $(FLAGS) -c BinPackage.cpp

BinPackingSolver.o: BinPackingSolver.cpp BinPackingSolver.h
	g++ $(FLAGS) -c BinPackingSolver.cpp

clean:
	rm -f test_Bin test_BinPackage test_BinPackingSolver main *.o

run:
	./test_Bin
	./test_BinPackage
	./test_BinPackingSolver