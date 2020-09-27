#include<iostream>

template<class T>
class List
{
    T* elements;
    int maxSize;
    static const int increment=10;
    int size;
    void incSize();
public:
    class EMPTY{};
    class INVALID_INDEX{};

    List(int n=10)
    {
        maxSize=n;
        elements = new T[maxSize];
        size = 0;
    }
    ~List()
    {
        delete elements;
    }

    void insert(T _item);
    void insert(int index, T _item);
    T remove();
    T remove(int index);
    int getsize();
    void display();
};
template<class T>
int List<T>::getsize()
{
    return size;
}
template<class T>
void List<T>::incSize()
    {
        maxSize+=increment;
        T* temp = new T[maxSize];
        for(int i=0;i<size;i++)
            temp[i] = elements[i];
        delete elements;
        elements = temp;
    }
template<class T>
void List<T>::insert(int index ,T _item)
    {
        if(index > size || index < 0)
            throw INVALID_INDEX();
        if(size == maxSize)
            incSize();
        for(int i=size;i>index;i--)
            elements[i] = elements[i-1];
        size++;
        elements[index] = _item;
    }
template<class T>
void List<T>::insert(T _item)
    {
        if(size == maxSize)
            incSize();
        elements[size] = _item;
        size++;
    }
template<class T>
T List<T>::remove(int index)
    {
        if(size == 0)
            throw EMPTY();
        if(index > size-1 || index < 0)
            throw INVALID_INDEX();
        T temp = elements[index];
        for(int i=index;i<size-1;i++)
            elements[i] = elements[i+1];
        size--;
        return temp;
    }
template<class T>
T List<T>::remove()
    {
        if(size == 0)
            throw EMPTY();
        size--;
        return elements[size+1];
    }
template<class T>
void List<T>::display()
    {
        if(size == 0)
            throw EMPTY();
            //return;
        for(int i=0;i<size;i++)
            std::cout<<" "<<elements[i];
    }
