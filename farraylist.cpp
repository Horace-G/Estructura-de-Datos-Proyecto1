#include "farraylist.h"
#include "object.h"
#include <sstream>

FArrayList::FArrayList(int c) : TDAList() {
capacity = c;
data = new Object*[capacity];
}

FArrayList::~FArrayList() {
delete[] data;
}

bool FArrayList::insert(Object* E, unsigned int p) {
/* Precondiciones */
if (isFull())
return false;
if (!(p >= 0 && p <= size()))
return false;

/* Si la lista está vacía o se está insertando
al final de la lista puede asignarse sin
ningún inconveniente a la lista.
*/
if (isEmpty() || p == size())
data[p] = E;
else {
/* Si se inserta en medio de la lista se
necesita mover los elementos contiguos
para dejar libre la casilla del elemento
en el arreglo.
*/
for (int i = size(); i > p; i--)
data[i] = data[i - 1];

data[p] = E;
}

ssize++;
return true;
}

Object* FArrayList::remove(unsigned int p) {
if (isEmpty())
return NULL;
if (!(p >= 0 && p < size()))
return NULL;

Object* retval = data[p];

if (p == size() - 1)
data[p] = NULL;
else {
for (int i = p; i < size() - 1; i++)
data[i] = data[i + 1];

data[size() - 1] = NULL;
}

ssize--;
return retval;
}

Object* FArrayList::first() const {
if (isEmpty())
return NULL;

return data[0];
}

Object* FArrayList::last() const {
if (isEmpty())
return NULL;

return data[size() - 1];
}

int FArrayList::getCapacity() const {
return capacity;
}

bool FArrayList::isFull() const {
return ssize == capacity;
}

void FArrayList::clear() {
delete[] data;

data = new Object*[capacity];
ssize = 0;
}

int FArrayList::indexOf(Object* E) const {
for (int i = 0; i < size(); i++) {
if(data[i]->equals(E))
return i;
}

return -1;
}

Object* FArrayList::get(unsigned int p) const {
if(isEmpty())
return NULL;
if(!(p >= 0 && p < size()))
return NULL;

return data[p];
}

bool FArrayList::insert(Object *e, int p) { // inserta un objeto en la posición p del arreglo
      if ( isFull() ) 
        return false;
      if ( !((p >= 0) && (p <= size())) )
        return false;
      if ( isEmpty() )
        data[p] = e;
      else {
        if ( p == size() )
          data[p] = e;
        else {
          for (int i = size() - 1; i >= p; i--)
            data[i + 1] = data[i];
          data[p]=e;
        } 
      }
      ssize++;
      return true;
    } // fin del Insert

    int FArrayList::indexOf(const Object* E) const{
      if( isEmpty() ) // Si el arreglo está vacío, retorna -1
        return -1;
      int posicion = -1;
      for(int i = 0; i < size() ; i++){ // Recorre el arreglo y si encuentra el objeto e en el arreglo
        if(data[i] == E){ // asigna el índice a la posicion
          posicion = i;
          break;
        } //Fin del if
      } //Fin del for
      return posicion; // retorna el valor de posición
    } //fin del indexOf

    int FArrayList::prev(int p) const{
    	return (p-1);
    }

    int FArrayList::next(int p) const{
    	return p+1;
    }

    void FArrayList::print()const{
	for(int i=0;i<size();i++)
		data[i]->print();
}