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
	this->capacity = capacity;
	for (int i = 0; i < length; i++)
	{
		bins.push_back(new Bin(capacity));
		binsOrdered.insert("{}");
	}
}

BinPackage::~BinPackage()
{
	std::vector<Bin *>::iterator itr;
	for(itr = bins.begin(); itr != bins.end(); itr++)
	{
		delete *itr;
	}
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

	std::string key = bins[index]->toString();
	if (!bins[index]->insert(element))
	{
		return false;
	}

	auto node = binsOrdered.extract(key);
	node.value() = bins[index]->toString();
	binsOrdered.insert(std::move(node));

	return true;
}

void BinPackage::insertBin()
{
	bins.push_back(new Bin(capacity));
	binsOrdered.insert("{}");
	length++;
}

/*
	Metodo:
	Descripcion: este metodo permite obtener un valor
		entero que representa al Bin Package.
	Retorno: entero que representa al Bin Package.
*/
long int BinPackage::getBinsValue()
{
	std::vector<Bin *>::iterator itr;
	long int value = 0;
	for (itr = bins.begin(); itr != bins.end(); itr++)
	{
		value += (*itr)->getValue();
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
	return binPackage->binsOrdered == this->binsOrdered;
}

BinPackage *BinPackage::copy()
{
	BinPackage *binPackageCopy = new BinPackage(0, this->capacity);
	std::vector<Bin *>::iterator itr;
	Bin *binCopy;
	for (itr = bins.begin(); itr != bins.end(); itr++)
	{
		binCopy = (*itr)->copy();
		binPackageCopy->bins.push_back(binCopy);
		binPackageCopy->binsOrdered.insert(binCopy->toString()); //Mejorable
	}
	
	binPackageCopy->length = this->length;

	return binPackageCopy;
}

/*
	Metodo:
	Descripcion: este metodo permite representar el
		Bin en un string, incluyendo el contenido de este.
	Retorno:
		string, que representa el bin.
*/
std::string BinPackage::toString()
{
	std::multiset<std::string>::iterator itr;
	std::string str = "{";
	if (length != 0)
	{
		itr = binsOrdered.begin();
		str.append(*itr);
		for (itr++; itr != binsOrdered.end(); itr++)
		{
			str.append(", ");
			str.append(*itr);
		}
	}
	str.append("}");

	return str;
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
	std::cout << this->toString() << std::endl;
}