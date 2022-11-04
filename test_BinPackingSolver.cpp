#include "BinPackingSolver.h"

int main()
{
    int sol;
    BinPackingSolver *bps = new BinPackingSolver();
    std::vector<int> elements = bps->generateElements(10, 4);
    std::vector<int>::iterator itr;
    for (itr = elements.begin(); itr != elements.end(); itr++)
    {
        std::cout << *itr << " ";
    }
    std::cout << std::endl;
    sol = bps->solve(elements, 7);
    std::cout << "Resultado elements 1: " << sol << std::endl;

    std::vector<int> elements2 {50, 3, 48, 53, 53, 4, 3, 41, 23, 20, 52, 49};
    sol = bps->solve(elements2, 100);
    std::cout << "Resultado elements 2: " << sol << std::endl;

    std::vector<int> elements3 {49, 41, 34, 33, 29, 26, 26, 22, 20, 19};
    sol = bps->solve(elements3, 100);
    std::cout << "Resultado elements 3: " << sol << std::endl;

    delete bps;
}
