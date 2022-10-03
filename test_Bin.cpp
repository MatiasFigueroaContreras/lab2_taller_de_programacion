#include "SetW.h"

int main()
{
	SetW *s = new SetW(7);
	std::cout << "Insert 1: " << s->insert(3) << std::endl;
	s->print();
	std::cout << "Insert 2: " << s->insert(4) << std::endl;
	s->print();
	std::cout << "Insert 3: " << s->insert(6) << std::endl;
	s->print();

	std::vector<SetW> v;
	SetW *c;
	for(int i = 0; i < 3; i++)
	{
		c = new SetW(7);
		v.push_back(*c);
	}

	std::vector<SetW>::iterator itr;

	v[0].insert(3);
	v[0].insert(4);

	v[1].insert(7);

	v[2].insert(5);
	v[2].insert(2);

	std::cout << "Equals 1: " << v[0].equals(&v[1]) << std::endl;
	std::cout << "Equals 2: " << v[0].equals(s) << std::endl;

	for(itr = v.begin(); itr != v.end(); itr++)
	{
		itr->print();
	}
}