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
	this->numValue = 0;
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
		items.push_back(item);
		if (item == 1 || weight == 0)
		{
			numValue += item;
		}
		else
		{
			numValue *= item;
		}

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
int Bin::getValue()
{
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
	return bin->getValue() == this->getValue();
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
	std::vector<int>::iterator itr;
	std::cout << "{";
	if (items.size() != 0)
	{
		for (itr = items.begin(); itr + 1 != items.end(); itr++)
		{
			std::cout << *itr << ", ";
		}
		std::cout << *itr;
	}
	std::cout << "}";
}
