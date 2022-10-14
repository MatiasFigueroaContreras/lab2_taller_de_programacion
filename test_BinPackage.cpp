#include "BinPackage.h"

int main()
{
    BinPackage *binP1 = new BinPackage(2, 5);
    std::cout << "Insert 2, index 0, Estado: " << binP1->insert(2, 0) << std::endl;
    binP1->print();
    std::cout << "Insert 3, index 0, Estado:" << binP1->insert(3, 0) << std::endl;
    binP1->print();
    std::cout << "Insert 5, index 0, Estado: " << binP1->insert(5, 0) << std::endl;
    binP1->print();
    std::cout << "Insert 5, index 1, Estado: " << binP1->insert(5, 1) << std::endl;
    binP1->print();
    std::cout << "Insert 3, index 2, Estado: " << binP1->insert(3, 2) << std::endl;
    std::cout << "binP1:" << std::endl;
    binP1->print();

    BinPackage *binP2 = new BinPackage(2, 5);
    binP2->insert(3, 1);
    binP2->insert(2, 1);
    binP2->insert(5, 0);
    std::cout << "binP2:" << std::endl;
    binP2->print();

    BinPackage *binP3 = new BinPackage(2, 7);
    binP3->insert(1, 0);
    binP3->insert(4, 0);
    binP3->insert(5, 1);
    std::cout << "binP3:" << std::endl;
    binP3->print();

    std::cout << "Equals 1: " << binP1->equals(binP2) << std::endl;
    std::cout << "Equals 2: " << binP1->equals(binP3) << std::endl;

    std::cout << "Value binP1: " << binP1->getBinsValue() << std::endl;
    std::cout << "Value binP2: " << binP2->getBinsValue() << std::endl;
    std::cout << "Value binP3: " << binP3->getBinsValue() << std::endl;

    BinPackage *binP4 = binP3->copy();

    binP4->print();
    binP4->insert(2, 1);
    binP4->print();
    binP3->print();
    BinPackage *binP4temp = binP4;
    binP4 = binP2->copy();
    binP4->print();

    delete binP1;
    delete binP2;
    delete binP3;
    delete binP4;
    delete binP4temp;
}
