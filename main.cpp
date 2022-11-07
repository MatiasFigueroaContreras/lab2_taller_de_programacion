#include <ctime>
#include "BinPackingSolver.h"

int main()
{
    clock_t ti, tf;
    double dt = 0, tavg = 0;
    int N = 0;
    int num_elements, capacity, sol;

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
        sol = solver->solve(elements, capacity);
        std::cout << "Resultado: " << sol << std::endl;
        tf = clock();
        dt = (tf - ti) / (double)CLOCKS_PER_SEC;
        tavg += dt;
        std::cout << "Tiempo de ejecucion: " << dt << " segundos" << std::endl;
    }

    std::cout << "Tiempo promedio: " << tavg / N << " segundos" << std::endl;

    // Ejemplos que se demoran mas
    // 6 seg aprox
    // elements = {94, 92, 88, 88, 87, 86, 83, 83, 83, 79, 77, 77, 76, 70, 69, 65, 65, 64, 56, 54, 52, 52, 46, 45, 45, 43, 43, 41, 41, 40, 40, 36, 35, 33, 33, 30, 29, 28, 26, 25, 25, 23, 18, 18, 17, 17, 15, 11, 5, 1};
    // 25 seg aprox
    // elements = {91, 90, 86, 81, 79, 74, 71, 69, 68, 66, 66, 62, 62, 58, 57, 56, 54, 54, 48, 48, 47, 46, 45, 44, 42, 36, 36, 35, 35, 35, 34, 33, 31, 31, 30, 29, 29, 26, 19, 19, 18, 17, 12, 10, 5, 4, 4, 2, 1, 1};
    // 50 seg aprox
    // elements = {99, 99, 92, 91, 91, 85, 84, 83, 82, 78, 74, 70, 67, 62, 60, 59, 57, 55, 54, 52, 50, 49, 47, 47, 47, 46, 42, 42, 41, 41, 39, 38, 37, 35, 34, 34, 31, 28, 26, 23, 21, 13, 12, 11, 8, 8, 8, 5, 3, 3};

    /*
    ti = clock();
    sol = solver->solve(elements, capacity);
    tf = clock();
    std::cout << "Sol 1: " << sol << std::endl;
    dt = (tf - ti) / (double)CLOCKS_PER_SEC;
    std::cout << "Tiempo ejemplo extra: " << dt << " segundos" << std::endl;
    */

    delete solver;

    return 0;
}