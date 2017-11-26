#ifndef _iterator_h_
#define _iterator_h_
#include <iterator>

template<class T>
class myiterator
{
  public:
    typedef T value_type;
    typedef T* pointer;
    typedef T& reference;
    typedef std::random_access_iterator_tag iterator_category;

    myiterator();
    myiterator(T *);
    myiterator(const myiterator &);
    myiterator& operator=(const myiterator &);

    myiterator& operator++();
    myiterator& operator--();
    myiterator operator++(int);
    myiterator operator--(int);
    myiterator operator+(const int &);
    myiterator operator-(const int &);

    T& operator *();
    T* operator ->();

    bool operator ==(const myiterator &);
    bool operator !=(const myiterator &);

  private:
    T* ptr;
};

template<class T>
myiterator<T>::myiterator()
           :ptr(0)
{

}

template<class T>
myiterator<T>::myiterator(T* _ptr)
           :ptr(_ptr)
{

}

template<class T>
myiterator<T>::myiterator(const myiterator& other)
           :ptr(other.ptr)
{

}

template<class T>
myiterator<T>& myiterator<T>::operator =(const myiterator& other)
{
  if(this != &other)
  ptr = other.ptr;

  return *this;
}

template<class T>
myiterator<T>& myiterator<T>::operator++()
{
  ++ptr;
  return *this;
}

template<class T>
myiterator<T>& myiterator<T>::operator--()
{
  --ptr;
  return *this;
}

template<class T>
myiterator<T> myiterator<T>::operator++(int)
{
  myiterator tmp(*this);
  operator++();
  return tmp;
}

template<class T>
myiterator<T> myiterator<T>::operator--(int)
{
  myiterator tmp(*this);
  operator--();
  return tmp;
}

template<class T>
myiterator<T> myiterator<T>::operator+(const int &other)
{
  return myiterator(ptr + other);
}

template<class T>
myiterator<T> myiterator<T>::operator-(const int &other)
{
  return myiterator(ptr - other);
}

template<class T>
T& myiterator<T>::operator *()
{
  return *ptr;
}

template<class T>
T* myiterator<T>::operator ->()
{
  return ptr;
}

template<class T>
bool myiterator<T>::operator==(const myiterator &other)
{
  return ptr == other.ptr;
}

template<class T>
bool myiterator<T>::operator!=(const myiterator &other)
{
  return !(*this == other);
}

#endif
