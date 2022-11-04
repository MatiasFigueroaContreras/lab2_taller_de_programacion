#include "BinPackage.h"

/*
    Metodo: Constructor
    Descripcion: este metodo permite inicializar un conjunto de pesos en 0,
        con un largo maximo, y una capacidad establecida para los bins.
    Parametros:
        -length: largo maximo del conjunto de pesos.
        -capacity: capacidad maxima de los pesos pertenecientes al conjunto.
    Retorno: La direccion del objeto creado.
*/
BinPackage::BinPackage(int length, int capacity)
{
    this->length = length;
    this->capacity = capacity;
    for (int i = 0; i < length; i++)
    {
        bins.push_back(0);
        binsOrdered.insert(0);
    }
}

/*
    Metodo: Destructor
    Descripcion: este metodo permite eliminar el BinPackage,
        liberando la memoria de las estructuras usadas.
    Retorno: vacio.
*/
BinPackage::~BinPackage()
{
}

/*
    Metodo:
    Descripcion: este metodo permite insertar un elemento,
        dado un indice, sumando el peso si es que no supera la
        capacidad.
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

    int key = bins[index];
    if (key + element > capacity)
    {
        return false;
    }

    binsOrdered.erase(binsOrdered.find(key));
    bins[index] += element;
    binsOrdered.insert(bins[index]);

    return true;
}

/*
    Metodo:
    Descripcion: este metodo permite insertar/inicializar
        un nuevo peso en 0.
    Parametros: No tiene.
    Retorno: No posee.
*/
void BinPackage::insertBin()
{
    bins.push_back(0);
    binsOrdered.insert(0);
    length++;
}

/*
    Metodo:
    Descripcion: este metodo permite obtener el valor de tipo
        string que representa al BinPackage.
    Parametros: No tiene.
    Retorno: string que representa al BinPackage.
*/
std::string BinPackage::getValue()
{
    std::multiset<int>::iterator itr;
    std::string value;
    for (itr = binsOrdered.begin(); itr != binsOrdered.end(); itr++)
    {
        value += std::to_string(*itr);
    }

    return value;
}

/*
    Metodo:
    Descripcion: este metodo permite copiar el objeto con sus
        respectivos valores.
    Parametros: No tiene.
    Retorno: La direccion del objeto creado con los valores
        del objeto copiado.
*/
BinPackage *BinPackage::copy()
{
    BinPackage *binPackageCopy = new BinPackage(0, this->capacity);
    binPackageCopy->bins = this->bins;
    binPackageCopy->binsOrdered = this->binsOrdered;

    binPackageCopy->length = this->length;

    return binPackageCopy;
}

/*
    Metodo:
    Descripcion: este metodo permite representar el
        BinPackage en un string, incluyendo el contenido de este.
    Retorno:
        string, que representa el binPackage.
*/
std::string BinPackage::toString()
{
    std::multiset<int>::iterator itr;
    std::string str = "{";
    if (length != 0)
    {
        itr = binsOrdered.begin();
        str.append(std::to_string(*itr));
        for (itr++; itr != binsOrdered.end(); itr++)
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
        el Bin Package.
    Retorno:
        Vacio.
*/
void BinPackage::print()
{
    std::cout << this->toString() << std::endl;
}
