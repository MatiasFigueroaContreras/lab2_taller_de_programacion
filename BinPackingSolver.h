#include "BinPackage.h"
#include <unordered_set>
#include <algorithm>
#include <map>

/*
	Descripcion de la clase BinPackingSolver:
	Esta clase buscara resolver un problema de Bin Packing
	teniendo metodos referentes a la solucion del problema,
	y ademas la generacion de elementos de prueba para
	probar el solucionador.
*/
class BinPackingSolver
{
private:
	int upperBound(std::vector<int> elements, int capacity);
	int lowerBound(std::vector<int> elements, int capacity);
	void deleteRemainingBinPackages(std::multimap<int, BinPackage *, std::greater<int>> binPackages);

public:
	BinPackingSolver();
	~BinPackingSolver();
	int solve(std::vector<int>, int capacity);
	bool hasSolution(std::vector<int>, int capacity, int numBins);
	std::vector<int> generateElements(int numElements, int capacity);
};
