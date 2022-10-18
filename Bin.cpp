#include "Bin.h"
/*
	Descripcion de la clase Bin:
	Esta clase representa un contenedor con una capacidad, 
	este almacena numeros enteros los cuales seran sumados
	al peso del contenedor.
*/

/*
	Metodo: Constructor
	Descripcion: este metodo permite crear un conjunto de elementos
		Bin, con el maximo peso dado.
	Parametros:
		-capacity: capacidad maxima del bin.
	Retorno: La direccion del objeto creado.
*/
Bin::Bin(int capacity)
{
	this->capacity = capacity;
	this->weight = 0;
}

Bin::~Bin()
{
}

/*
	Metodo: 
	Descripcion: este metodo permite insertar un elemento
		al bin, verificando que no se sobre pase la capacidad
		de este.
	Parametros:
		-item: elemento a agregar al bin.
	Retorno:
		-true: si se pudo ingresar el item.
		-false: si no fue posible ingresar el item.
*/
bool Bin::insert(int item)
{
	if (capacity >= weight + item)
	{
		items.insert(item);
		weight += item;
		return true;
	}

	return false;
}

/*
	Metodo:
	Descripcion: este metodo permite obtener un valor
		entero que representa al bin.
	Retorno: entero que representa al bin.
*/
long int Bin::getValue()
{
	std::multiset<int>::iterator itr;
	long int mult = 1;
	long int numValue = 0;
	for (itr = items.begin(); itr != items.end(); itr++)
	{
		numValue += *itr * mult;
		mult *= 100;
	}

	return numValue;
}

/*
	Metodo:
	Descripcion: este metodo permite saber si dos bins
		son iguales o no.
	Parametros:
		-bin: Objeto a comparar.
	Retorno:
		-true: si son iguales.
		-false: si no son iguales.
*/
bool Bin::equals(Bin *bin)
{
	return bin->items == this->items;
}

/*
	Metodo:
	Descripcion: este metodo permite copiar el objeto con sus
		respectivos valores.
	Parametros: No tiene.
	Retorno: La direccion del objeto creado con los valores
		del objeto copiado.
*/
Bin *Bin::copy()
{
	Bin *binCopy = new Bin(this->capacity);
	std::multiset<int>::iterator itr;

	binCopy->items = this->items;
	binCopy->weight = this->weight;
	
	return binCopy;
}

/*
	Metodo:
	Descripcion: este metodo permite representar el
		Bin en un string, incluyendo el contenido de este.
	Retorno:
		string, que representa el bin.
*/
std::string Bin::toString()
{
	std::multiset<int>::iterator itr;
	std::string str = "{";
	if (items.size() != 0)
	{
		itr = items.begin();
		str.append(std::to_string(*itr));
		for (itr++; itr != items.end(); itr++)
		{
			str.append(", ");
			str.append(std::to_string(*itr));
		}
	}
	str.append("}");

	return str;
}

/*
	Metodo:
	Descripcion: este metodo permite imprimir por consola
		el bin.
	Retorno:
		Vacio.
*/
void Bin::print()
{
	std::cout << this->toString();
}
