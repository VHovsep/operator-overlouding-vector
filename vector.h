#ifndef vector_h_
#define vector_h_
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstddef>
#include <stdexcept>
#include <cstring>
#include "iterator.h"

template<class T>
class myvector
{
  public:
    typedef myiterator<T> iterator;
    typedef const myiterator<T> const_iterator;
    typedef size_t size_type;
    typedef T* pointer;
    typedef const T* const_pointer;
    typedef T& reference;
    typedef const T& const_reference;
    typedef T value_type;

    myvector();
    myvector(const myvector& other);
    ~myvector();

    void resize(const int &newsize);
    void reserve(int newcapasity);
    void push_back(const T &val);
    void pop_back();
    
    myiterator<T> begin();
    myiterator<T> end();
    T& operator[](size_t);
    const T& operator[](size_t)const;

    size_t size() const;
    size_t capasity() const;
    bool empty() const;

  private:
    T* vector_pointer;
    size_t vector_size;
    size_t vector_capasity;
};

template<class T>
myvector<T>::myvector()
         :vector_pointer(NULL)
         ,vector_size(0)
         ,vector_capasity(0)
{

}

template<class T>
myvector<T>::myvector(const myvector& other)
         :vector_pointer(NULL)
         ,vector_size(0)
         ,vector_capasity(0)
{
  vector_pointer = new T[other.capasity()];
  memcpy(vector_pointer,&other[0],sizeof(T)*size());
  vector_size = other.vector_size;
  vector_capasity = other.vector_capasity;
}

template<class T>
void myvector<T>::resize(const int &newsize)
{
  if(newsize < vector_size)
  {
    T* temp = new T[newsize];
    memcpy(temp,vector_pointer,sizeof(T)*newsize);
    delete []vector_pointer;
    vector_pointer = temp;
  }
  else if(newsize > vector_capasity)
  {
    reserve(newsize);
  }
  vector_size = newsize;
}

template<class T>
void myvector<T>::reserve(const int newcapasity)
{
  if(newcapasity > vector_capasity);
  {  
    T* temp = new T[newcapasity];
    memcpy(temp,vector_pointer,sizeof(T)*vector_capasity);
    delete []vector_pointer;
    vector_pointer = temp;
    vector_capasity = newcapasity;
  }
}

template<class T>
void myvector<T>::push_back(const T &val)
{
  if(vector_capasity <= vector_size)
    reserve(vector_capasity);
  vector_pointer[vector_size++] = val;
}

template<class T>
void myvector<T>::pop_back()
{
  if(vector_size)
    --vector_size;
}

template<class T>
myiterator<T> myvector<T>::begin()
{
  return myiterator<T>(vector_pointer);
}

template<class T>
myiterator<T> myvector<T>::end()
{
  return myiterator<T>(vector_pointer + vector_size);
}

template<class T>
T& myvector<T>::operator[](size_t index)
{
  if(index >= vector_size)
    throw std::out_of_range("vector subscript out of range");
  return vector_pointer[index];
}

template<class T>
const T& myvector<T>::operator[](size_t index)const
{
  if(index >= vector_size)
    throw std::out_of_range("vector subscript out of range");
  return vector_pointer[index];
}

template<class T>
size_t myvector<T>::size()const
{
  return vector_size;
}

template<class T>
size_t myvector<T>::capasity()const
{
  return vector_capasity;
}

template<class T>
bool myvector<T>::empty()const
{
  return vector_size == 0;
}  

template<class T>
myvector<T>::~myvector()
{
  delete []vector_pointer;
}

#endif
