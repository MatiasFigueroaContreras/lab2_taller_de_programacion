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
    int mid;
    std::sort(elements.begin(), elements.end(), std::greater<int>());
    int upper = upperBound(elements, capacity);
    int lower = lowerBound(elements, capacity);

    std::cout << "Cota superior: " << upper << ", Cota Inferior: " << lower << std::endl;

    while (upper > lower)
    {
        mid = (upper + lower) / 2;
        if(hasSolution(elements, capacity, mid))
        {
            upper = mid;
        }
        else
        {
            if(lower == mid)
            {
                return lower + 1;
            }

            lower = mid;
        }
    }
    
    return lower;
}

bool BinPackingSolver::hasSolution(std::vector<int> elements, int capacity, int numBins)
{
    std::unordered_map<std::string, BinPackage*> visitedCombinations;
    std::multimap<int, BinPackage*, std::greater<int>> binPackagesToVisit;
    std::multimap<int, BinPackage*, std::greater<int>>::iterator currentMapItr;
    int currentPos;
    BinPackage *currentBP, *copyBP, *initialBP = new BinPackage(numBins, capacity);

    visitedCombinations.reserve(10000); // cambiar por cantidad maxima de combinaciones

    binPackagesToVisit.emplace(0, initialBP);
    visitedCombinations.emplace(initialBP->toString(), initialBP);
    std::cout << "========================================" << std::endl;
    while (!binPackagesToVisit.empty())
    {
        currentMapItr = binPackagesToVisit.begin();
        currentBP = currentMapItr->second;
        currentPos = currentMapItr->first;
        std::cout << "------------------------" << std::endl;
        std::cout << "Valor a ingresar:  " <<  elements[currentPos] << ", Bin Package a combinar:" << std::endl;
        currentBP->print();
        binPackagesToVisit.erase(currentMapItr);
        for (int i = 0; i < currentBP->length; i++)
        {
            copyBP = currentBP->copy();
            if (copyBP->insert(elements[currentPos], i) && visitedCombinations.emplace(copyBP->toString(), copyBP).second)
            {
                std::cout << "Combinacion Nueva nPos°" << i + 1 << ": " << std::endl;
                copyBP->print();
                if (currentPos + 1 == (int) elements.size())
                {
                    std::cout << "Si es posible con: " << numBins << " numero de bins" << std::endl;
                    copyBP->print();
                    std::cout << "========================================" << std::endl;
                    deleteBinPackagesGenerated(visitedCombinations);
                    delete copyBP;
                    return true;
                }

                binPackagesToVisit.emplace(currentPos + 1, copyBP);
            }
            else
            {
                delete copyBP;
            }
        }
        std::cout << "------------------------" << std::endl;
    }
    std::cout << "No es posible con: " << numBins << " numero de bins" << std::endl;
    std::cout << "========================================" << std::endl;
    deleteBinPackagesGenerated(visitedCombinations);

    return false;
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
    elements.reserve(numElements);
    std::srand(time(NULL));
    for (int i = 0; i < numElements; i++)
    {
        element = 1 + std::rand() % capacity;
        elements.push_back(element);
    }

    return elements;
}

int BinPackingSolver::upperBound(std::vector<int> elements, int capacity)
{
    int j;
    std::vector<int>::iterator itr;
    BinPackage *binPackage = new BinPackage(1, capacity);

    for (itr = elements.begin(); itr != elements.end(); itr++)
    {
        for (j = 0; j < binPackage->length && !binPackage->insert(*itr, j); j++)
        {
        }

        if (j == binPackage->length)
        {
            binPackage->insertBin();
            binPackage->insert(*itr, j);
        }
    }

    int length = binPackage->length;
    delete binPackage;

    return length;
}

int BinPackingSolver::lowerBound(std::vector<int> elements, int capacity)
{
    int sum = 0;
    std::vector<int>::iterator itr;
    for (itr = elements.begin(); itr != elements.end(); itr++)
    {
        sum += *itr;
    }

    return (sum / capacity);
}

void BinPackingSolver::deleteBinPackagesGenerated(std::unordered_map<std::string, BinPackage *> binPackages)
{
    std::unordered_map<std::string, BinPackage *>::iterator itr;
    for(itr = binPackages.begin(); itr != binPackages.end(); itr++)
    {
        delete itr->second;
    }
}