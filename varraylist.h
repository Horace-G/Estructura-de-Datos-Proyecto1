#include "object.h"
#include "tdalist.h"

class VArrayList : public TDAList
{
public:
VArrayList(int,int);
virtual ~VArrayList();
virtual bool insert(Object*, unsigned int);/////////
virtual bool remove(unsigned int);/////////
virtual Object* first() const;/////////
virtual Object* last() const;/////////
virtual int getCapacity() const;
virtual bool isFull() const;/////////
virtual void clear();/////////
virtual int indexOf(Object*) const;/////////
virtual Object* get(unsigned int) const;/////////
virtual int prev(int) const;
virtual int next(int) const;

//prev
//next

private:
unsigned int capacity;
double increment;
Object** data;
bool makebigger();
};