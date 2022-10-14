#include "Bin.h"

int main()
{
	Bin *b1 = new Bin(7);
	std::cout << "Insert 1, Estado: " << b1->insert(4) << std::endl;
	b1->print();
	std::cout << std::endl;
	std::cout << "Insert 2, Estado: " << b1->insert(3) << std::endl;
	b1->print();
	std::cout << std::endl;
	std::cout << "Insert 3, Estado: " << b1->insert(6) << std::endl;
	b1->print();
	std::cout << std::endl;

	Bin *b2 = new Bin(7);

	b2->insert(3);
	b2->insert(4);
	b2->print();
	std::cout << std::endl;

	Bin *b3 = new Bin(7);

	b3->insert(5);
	// b3->insert(2);
	b3->print();
	std::cout << std::endl;

	std::cout << "Equals 1: " << b2->equals(b1) << std::endl;
	std::cout << "Equals 2: " << b3->equals(b1) << std::endl;

	std::cout << "Value b1: " << b1->getValue() << std::endl;
	std::cout << "Value b2: " << b2->getValue() << std::endl;
	std::cout << "Value b3: " << b3->getValue() << std::endl;

	Bin *b5 = b3->copy();
	b5->print();
	std::cout << std::endl;
	b5->insert(2);
	b5->print();
	std::cout << std::endl;
	b3->print();
	std::cout << std::endl;

	delete b1;
	delete b2;
	delete b3;
	delete b5;
	// Bin *b4 = new Bin(200);
	// b4->insert(15);
	// b4->insert(25);
	// b4->insert(3);
	// b4->insert(15);
	// b4->insert(1);
	// b4->insert(60);
	// b4->insert(7);
	// b4->print();
	// std::cout << "Value b4: " << b4->getValue() << std::endl;
}
