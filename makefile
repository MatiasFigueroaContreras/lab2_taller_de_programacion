FLAGS = -O2 -g -Wall

all: clean test_BinPackage test_BinPackingSolver run

main: main.cpp BinPackingSolver.o BinPackage.o
	g++ $(FLAGS) -o main BinPackingSolver.o BinPackage.o main.cpp

test_BinPackingSolver: BinPackage.o BinPackingSolver.o test_BinPackingSolver.cpp
	g++ $(FLAGS) -o test_BinPackingSolver BinPackage.o BinPackingSolver.o test_BinPackingSolver.cpp

test_BinPackage: BinPackage.o test_BinPackage.cpp
	g++ $(FLAGS) -o test_BinPackage BinPackage.o test_BinPackage.cpp

BinPackage.o: BinPackage.cpp BinPackage.h
	g++ $(FLAGS) -c BinPackage.cpp

BinPackingSolver.o: BinPackingSolver.cpp BinPackingSolver.h
	g++ $(FLAGS) -c BinPackingSolver.cpp

clean:
	rm -f test_BinPackage test_BinPackingSolver main *.o

run:
	./test_BinPackage
	./test_BinPackingSolver
