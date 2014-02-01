#ifndef FARRAYLIST_H
#define FARRAYLIST_H
#include "tdalist.h"
#include "object.h"

class FArrayList : public TDAList
{
public:
FArrayList(int);
virtual ~FArrayList();
virtual bool insert(Object*, unsigned int);
virtual Object* remove(unsigned int);
virtual Object* first() const;
virtual Object* last() const;
virtual int getCapacity() const;
virtual bool isFull() const;
virtual void clear();
virtual int indexOf(Object*) const;
virtual Object* get(unsigned int) const;
virtual void print()const;
virtual bool insert(Object *e, int p);//////////////////
virtual int indexOf(const Object* E) const ;/////////////
virtual int prev(int) const;
virtual int next(int) const;

private:
unsigned int capacity;
Object** data;
};

#endif