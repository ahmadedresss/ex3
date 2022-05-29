//
// Created by Ahmad Idris on 5/24/22.
//

#ifndef EX3_QUEUE_H
#define EX3_QUEUE_H
#define EXPAND_RATE 2
template<class Q>

class Array{
public:

    explicit Array(int size);
    Array(const Array& a);
    ~Array();
    Array();
    Array&operator=(const Array& a);
    int size() const;
    int front();
    int front()const;
    void popFront();
    void pushBack(const Q& add);
    int getMaxSize() const;
    int empty();
    void popFront();
    class Iterator;
    class ConstIterator;
    Iterator begin() const;
    Iterator end() const;



private:
    Q* m_arr;
    int m_size;
    int m_max_size;
    void expand();
};

template<class Q>
int Array<Q>::size() const
{
    return m_size;
}
template<class Q>
int Array<Q>::getMaxSize() const
{
    return m_max_size;
}

template<class Q>
Array<Q>& Array<Q>::operator=(const Array<Q> &a){
    if (this== &a)
    {
        return *this;
    }
    delete[] m_arr;
    m_arr=new Q[a.size];
    m_size  =a.size;

    for(int i=0; i < m_size;++i)
    {
        m_arr[i]=a.arr[i];
    }
    return *this;
}

template<class Q>
Array<Q>::Array() : m_arr(new Q[m_size]),m_size(0)
{}

template<class Q>
Array<Q>::~Array()
{
    delete[] m_arr;
}

template<class Q>
Array<Q>::Array(const Array<Q>& copy):m_arr(new Q[copy.m_max_size]),m_size(copy.m_size),m_max_size(copy.m_max_size)
{
    for(int i=0;i<m_size;++i)
    {
        m_arr[i]=copy.arr[i];
    }
}

template<class Q>
void Array<Q>::expand(){
    int newSize = m_size*EXPAND_RATE ;
    Q* newArr= new Q[newSize];
    for (int i=0; i< m_size; ++i)
    {
        newArr[i]=m_arr[i];
    }

    delete[] m_arr;
    m_arr=newArr;
    m_max_size=m_max_size*EXPAND_RATE;
}

template<class Q>
void Array<Q>::pushBack(const Q& add)
{
    if(size()>=getMaxSize())
    {
        expand();
    }
    m_arr[m_size]=add;
}


template <class Q>
int Array<Q>::front()
{
    if (size() == 0)
    {
        throw empty();
    }
    return m_arr[this->getFront()];
}
template <class Q>
int Array<Q>::front()const
{
    if (size() == 0)
    {
        throw empty();
    }
    return m_arr[this->getFront()];
}

template<class Q>
void Queue<Q>::popFront() {
    if(m_size == 0)
        throw empty();
    --m_size;
    for (int i = 0; i < m_size; ++i) {
        m_arr[i] = m_arr[i+1];
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////// popFront
/////////----------ITERATOR---------//////////
template <class Q>
class Array<Q>::Iterator
{
    Array<Q> * array;
    int index;
    Iterator(const Array<Q>* queue, int index);
    friend class Array;

public:
    Q& operator*()const;
    Iterator& operator++();
    Iterator operator++(int);
    bool operator==(const Iterator& it);
    bool operator!=(const Iterator& it);
    Iterator(const Iterator&) = default;
    Iterator& operator=(const Iterator&) = default;

};

template<class Q>
typename Array<Q>::Iterator Array<Q>::Iterator::operator++(int)
{
    Iterator result=*this;
    ++*this;
    return result;
}

template <class Q>
typename Array<Q>::Iterator& Array<Q>::Iterator::operator++()
{
    ++index;
    return *this;
}

template <class Q>
bool Array<Q>::Iterator::operator==(const Iterator& i)
{
    //assert(i== this);
    return index==i.index;
}

template <class Q>
bool Array<Q>::Iterator::operator!=(const Iterator& i) {
    return !(*this == i);
}

template <class Q>
typename Array<Q>::Iterator Array<Q>::begin()
{
    return Iterator(this,0);
}

template <class Q>
typename Array<Q>::Iterator Array<Q>::end()
{
    return Iterator(this,0);
}










template <class Q>
class ConstIterator{
    const Array<Q>* array;
    int index;
    ConstIterator(const Array<Q>*queue, int index);
    friend class Array;

    public:
    cconst Q& operator*()const;
    Iterator& operator++();
    Iterator operator++(int);
    bool operator==(const Iterator& it)const;
    bool operator!=(const Iterator& it)const;
    Iterator(const Iterator&) = default;
    Iterator& operator=(const Iterator&) = default;




    };

template<class Q>
typename Array<Q>::Iterator Array<Q>::Iterator::operator++(int)
{
    Iterator result=*this;
    ++*this;
    return result;
}


template <class Q>
typename Array<Q>::Iterator& Array<Q>::Iterator::operator++()
{
    ++index;
    return *this;
}

template <class Q>
bool Array<Q>::Iterator::operator==(const Iterator& i)const
{
    //assert(i== this);
    return index==i.index;
}

template <class Q>
bool Array<Q>::Iterator::operator!=(const Iterator& i) const{
    return !(*this == i);
}

template <class Q>
typename Array<Q>::Iterator Array<Q>::begin() const
{
    return Iterator(this,0);
}

template <class Q>
typename Array<Q>::Iterator Array<Q>::end() const
{
    return Iterator(this,0);
}


#endif //EX3_QUEUE_H
