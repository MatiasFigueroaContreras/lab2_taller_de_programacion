#include "BinPackage.h"
/*
	Descripcion de la clase BinPackage:
	Esta clase representa un conjunto de contenedores ("Bins"),
	considerando la misma capacidad para un numero establecido
	de contenedores.
*/

/*
	Metodo: Constructor
	Descripcion: este metodo permite crear un conjunto de bins,
		con un largo maximo, y una capacidad establecida para los bins.
	Parametros:
		-length: largo maximo del conjunto de bins.
		-capacity: capacidad maxima de los bins pertenecientes al conjunto.
	Retorno: La direccion del objeto creado.
*/
BinPackage::BinPackage(int length, int capacity)
{
	this->length = length;
	for (int i = 0; i < length; i++)
	{
		bins.push_back(Bin(capacity));
	}
}

BinPackage::~BinPackage()
{
}

/*
	Metodo:
	Descripcion: este metodo permite insertar un elemento
		a un bin dado el indice de este.
	Parametros:
		-element: elemento a agregar a un bin.
		-index: indice del bin al cual se agregara el elemento.
	Retorno:
		-true: si se pudo ingresar el elemento.
		-false: si no fue posible ingresar el elemento.
*/
bool BinPackage::insert(int element, int index)
{
	if (length <= index)
	{
		return false;
	}

	return bins[index].insert(element);
}

/*
	Metodo:
	Descripcion: este metodo permite obtener un valor
		entero que representa al Bin Package.
	Retorno: entero que representa al Bin Package.
*/
int BinPackage::getBinsValue()
{
	int value = 0;
	for (int i = 0; i < length; i++)
	{
		value += bins[i].getValue();
	}

	return value;
}

/*
	Metodo:
	Descripcion: este metodo permite saber si dos Bin Packages
		son iguales o no.
	Parametros:
		-binPackage: Objeto a comparar.
	Retorno:
		-true: si son iguales.
		-false: si no son iguales.
*/
bool BinPackage::equals(BinPackage *binPackage)
{
	return binPackage->getBinsValue() == this->getBinsValue();
}

/*
	Metodo:
	Descripcion: este metodo permite imprimir por consola
		el Bin Package.
	Retorno:
		Vacio.
*/
void BinPackage::print()
{
	std::vector<Bin>::iterator itr;
	std::cout << "{";
	for (itr = bins.begin(); itr + 1 != bins.end(); itr++)
	{
		itr->print();
		std::cout << ", ";
	}
	itr->print();
	std::cout << "}" << std::endl;
}