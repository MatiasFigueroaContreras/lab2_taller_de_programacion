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
        bins.push_back(0);
        binsOrdered.insert(0);
    }
}

/*
    Metodo: Destructor
    Descripcion: este metodo permite eliminar el BinPackage,
        liberando la memoria de los Bin que esta posee.
    Retorno: vacio.
*/
BinPackage::~BinPackage()
{
    // std::vector<int>::iterator itr;
    // for (itr = bins.begin(); itr != bins.end(); itr++)
    // {
    //     delete *itr;
    // }
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

    int key = bins[index];
    if (key + element > capacity)
    {
        return false;
    }
    bins[index] += element; 

    auto node = binsOrdered.extract(key);
    node.value() = bins[index];
    binsOrdered.insert(std::move(node));

    return true;
}

/*
    Metodo:
    Descripcion: este metodo permite insertar un nuevo
        Bin vacio.
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
        Bin en un string, incluyendo el contenido de este.
    Retorno:
        string, que representa el bin.
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