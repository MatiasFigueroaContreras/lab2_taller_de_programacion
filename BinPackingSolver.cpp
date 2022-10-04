#include "BinPackingSolver.h"
/*
    Descripcion de la clase BinPackingSolver:
    Esta clase buscara resolver un problema de Bin Packing
    teniendo metodos referentes a la solucion del problema,
    y ademas la generacion de elementos de prueba para 
    probar el solucionador.
*/

BinPackingSolver::BinPackingSolver()
{
}

BinPackingSolver::~BinPackingSolver()
{
}

int BinPackingSolver::solve(std::vector<int> elements, int capacity)
{
    return 0;
}

/*
    Metodo: 
    Descripcion: este metodo permite generar una lista
        de elementos aleatorios dado una capacidad,
        y la cantidad de elementos que va a tener la lista.
    Parametros:
        -numElements: cantidad de elementos que tendra la lista.
        -capacity: valor maximo que tendran los elementos aleatorios
    Retorno: 
        la lista de enteros generada.
*/
std::vector<int> BinPackingSolver::generateElements(int numElements, int capacity)
{
    int element;
    std::vector<int> elements;
    std::srand(time(NULL));
    for (int i = 0; i < numElements; i++)
    {
        element = 1 + std::rand() % capacity;
        elements.push_back(element);
    }

    return elements;
}

int BinPackingSolver::upperLimit(std::vector<int> elements, int capacity)
{
    return 0;
}

int BinPackingSolver::lowerLimit(std::vector<int> elements, int capacity)
{
    return 0;
}
