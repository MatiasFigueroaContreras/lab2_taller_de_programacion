#include <ctime>
#include "BinPackingSolver.h"

int main()
{
    clock_t ti, tf;
    double dt = 0, tavg = 0;
    int N = 0;
    int num_elements, capacity;

    BinPackingSolver *solver = new BinPackingSolver();
    std::vector<int> elements;

    std::cout << "Ingrese el numero de elementos con el que se trabajara: ";
    std::cin >> num_elements;
    std::cout << "Ingrese la capacidad con la que se trabajara: ";
    std::cin >> capacity;
    std::cout << "Ingrese cantidad de ciclos: ";
    std::cin >> N;
    std::cout << "Se ejecutaran " << N << " ciclos" << std::endl;
    std::srand(time(NULL));
    for (int i = 0; i < N; i++)
    {
        elements = solver->generateElements(num_elements, capacity);
        ti = clock();
        solver->solve(elements, capacity);
        tf = clock();
        dt = (tf - ti) / (double)CLOCKS_PER_SEC;
        tavg += dt;
        std::cout << "Tiempo de ejecucion: " << dt << " segundos" << std::endl;
    }
    std::cout << "Tiempo promedio: " << tavg / N << " segundos" << std::endl;

    delete solver;

    return 0;
}