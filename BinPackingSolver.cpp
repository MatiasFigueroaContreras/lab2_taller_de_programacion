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

/*
    Metodo:
    Descripcion: este metodo permite resolver un problema
        de Bin Packing, buscando el numero optimo de Bins
        a generar con los elementos y la capacidad entregados.
    Parametros:
        -elements: elementos que se repartiran en los Bins.
        -capacity: maxima capacidad que tendran los Bins.
    Retorno: Numero optimo de Bins dado las entradas.
*/
int BinPackingSolver::solve(std::vector<int> elements, int capacity)
{
    int mid;
    std::sort(elements.begin(), elements.end(), std::greater<int>());
    std::cout << elements[0];
    for (int i = 1; i < (int) elements.size(); i++)
    {
        std::cout << ", " << elements[i];
    }
    std::cout << std::endl;
    int upper = upperBound(elements, capacity);
    int lower = lowerBound(elements, capacity);

    std::cout << "Cota superior: " << upper << ", Cota Inferior: " << lower << std::endl;

    while (upper > lower)
    {
        mid = (upper + lower) / 2;
        if (hasSolution(elements, capacity, mid))
        {
            upper = mid;
        }
        else
        {
            if (lower == mid)
            {
                return lower + 1;
            }

            lower = mid;
        }
    }

    return lower;
}

/*
    Metodo:
    Descripcion: este metodo permite saber si dado los elementos,
        la capacidad y el numero de bins establecidos, es posible
        generar un Bin Packing, es decir que se utilizen todos
        los elementos.
    Parametros:
        -elements: elementos que se repartiran en los Bins (Ordenados en solve).
        -capacity: maxima capacidad que tendran los Bins.
        -numBIns: numero de bins establecidos que tendra el BinPacking.
    Retorno:
        -true: si es posible generar un Bin Package utilizando todos
            los elementos.
        -false: si NO es posible generar un Bin Package utilizando todos
            los elementos.
*/
bool BinPackingSolver::hasSolution(std::vector<int> elements, int capacity, int numBins)
{
    std::vector<std::unordered_set<std::string>> visitedCombinations;
    std::multimap<int, BinPackage *, std::greater<int>> binPackagesToVisit;
    std::multimap<int, BinPackage *, std::greater<int>>::iterator currentMapItr;
    int currentPos;
    BinPackage *currentBP, *copyBP, *initialBP = new BinPackage(numBins, capacity);

    for(int i = 0; i < (int) elements.size(); i++)
    {
        std::unordered_set<std::string> us;
        us.reserve(10000);
        visitedCombinations.push_back(us);
    }

    binPackagesToVisit.emplace(0, initialBP);
    visitedCombinations[0].insert(initialBP->getValue());
    std::cout << "========================================" << std::endl;
    while (!binPackagesToVisit.empty())
    {
        currentMapItr = binPackagesToVisit.begin();
        currentBP = currentMapItr->second;
        currentPos = currentMapItr->first;
        std::cout << "------------------------" << std::endl;
        std::cout << "Valor a ingresar:  " << elements[currentPos] << ", Bin Package a combinar:" << std::endl;
        currentBP->print();
        binPackagesToVisit.erase(currentMapItr);
        for (int i = 0; i < currentBP->length; i++)
        {
            copyBP = currentBP->copy();
            if (copyBP->insert(elements[currentPos], i) && visitedCombinations[currentPos].insert(copyBP->getValue()).second)
            {
                std::cout << "Combinacion Nueva nPos°" << i + 1 << ": " << std::endl;
                copyBP->print();
                if (currentPos + 1 == (int)elements.size())
                {
                    std::cout << "Si es posible con: " << numBins << " numero de bins" << std::endl;
                    copyBP->print();
                    std::cout << "========================================" << std::endl;
                    deleteRemainingBinPackages(binPackagesToVisit);
                    return true;
                }

                binPackagesToVisit.emplace(currentPos + 1, copyBP);
            }
            else
            {
                delete copyBP;
            }
        }
        delete currentBP;
        std::cout << "------------------------" << std::endl;
    }
    std::cout << "No es posible con: " << numBins << " numero de bins" << std::endl;
    std::cout << "========================================" << std::endl;

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
    for (int i = 0; i < numElements; i++)
    {
        element = 1 + std::rand() % capacity;
        elements.push_back(element);
    }

    return elements;
}

/*
    Metodo:
    Descripcion: este metodo permite obtener el numero de
        Bins maximo que se pueden tener en base a los elementos
        y la capacidad maxima de los bins.
    Parametros:
        -elements: elementos que se repartiran en los Bins (Ordenados en solve).
        -capacity: maxima capacidad que tendran los Bins.
    Retorno:
        numero de bins maximo.
*/
int BinPackingSolver::upperBound(std::vector<int> elements, int capacity)
{
    int j;
    std::vector<int>::iterator itr;
    BinPackage *binPackage = new BinPackage(1, capacity);

    for (itr = elements.begin(); itr != elements.end(); itr++)
    {
        for (j = 0; j < binPackage->length && !binPackage->insert(*itr, j); j++);

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

/*
    Metodo:
    Descripcion: este metodo permite obtener el numero de
        Bins minimo que se pueden tener en base a los elementos
        y la capacidad maxima de los bins.
    Parametros:
        -elements: elementos que se repartiran en los Bins (Ordenados en solve).
        -capacity: maxima capacidad que tendran los Bins.
    Retorno:
        numero de bins minimo.
*/
int BinPackingSolver::lowerBound(std::vector<int> elements, int capacity)
{
    int lb;
    std::vector<int>::iterator itr;
    int alpha = elements.back();
    if (alpha <= capacity / 2)
    {
        int num_j1 = 0;
        int num_j2 = 0;
        int sum_j2 = 0;
        int sum_j3 = 0;
        for (itr = elements.begin(); itr != elements.end() && *itr > capacity - alpha; itr++)
        {
            num_j1++;
        }
        for (; itr != elements.end() && *itr > capacity / 2; itr++)
        {
            sum_j2 += *itr;
            num_j2++;
        }
        for (; itr != elements.end() && *itr >= alpha; itr++)
        {
            sum_j3 += *itr;
        }
        float fop = (float)(sum_j3 - (num_j2 * capacity - sum_j2)) / capacity;
        int op = fop;
        if (op < fop)
        {
            op++;
        }

        if (op < 0)
        {
            op = 0;
        }

        lb = num_j1 + num_j2 + op;
    }
    else
    {
        int sum = 0;
        for (itr = elements.begin(); itr != elements.end(); itr++)
        {
            sum += *itr;
        }

        float flb = (float)sum / capacity;
        lb = flb;
        if (lb < flb)
        {
            lb++;
        }
    }

    return lb;
}

/*
    Metodo:
    Descripcion: este metodo permite eliminar los BinPackage
        que contiene la estructura de entrada, liberando asi
        la memoria.
    Parametros:
        -binPackages: estructura que contiene los BinPackage
            a eliminar.
    Retorno: Vacio.
*/
void BinPackingSolver::deleteRemainingBinPackages(std::multimap<int, BinPackage *, std::greater<int>> binPackages)
{
    std::multimap<int, BinPackage *, std::greater<int>>::iterator itr;
    for (itr = binPackages.begin(); itr != binPackages.end(); itr++)
    {
        delete itr->second;
    }
}