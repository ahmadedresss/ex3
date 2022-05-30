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
    int EmptyQueue();

    class Iterator;
    class ConstIterator;
    Iterator begin();
    Iterator end();
    ConstIterator begin() const;
    ConstIterator end() const;

private:
    Q* m_arr;
    int m_size;
    int m_max_size;
    void expand();
};

template<class Q>
int Array<Q>::size() const
{
    if (m_size==0)
    {
        throw EmptyQueue();
    }
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
{

}

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
void Array<Q>::expand()
{
    try {
        int newSize = m_size * EXPAND_RATE;
        Q *newArr = new Q[newSize];

    }
    catch(...)
    {
        delete[] m_arr;
        throw std::bad_alloc;
    }
        for (int i = 0; i < m_size; ++i)
        {
            newArr[i] = m_arr[i];
        }

        m_arr = newArr;
        m_max_size = m_max_size * EXPAND_RATE;
}

template<class Q>
void Array<Q>::pushBack(const Q& add)
{
    if(size()>=getMaxSize())
    {
        expand();
    }
    m_arr[m_size]=add;
    m_size++;
}

template <class Q>
int Array<Q>::front()
{
    if (size() == 0)
    {
        throw EmptyQueue();
    }

    return m_arr[this->getFront()];
}

template <class Q>
int Array<Q>::front()const
{
    if (size() == 0)
    {
        throw EmptyQueue();
    }
    return m_arr[this->getFront()];
}

template<class Q>
void Array<Q>::popFront() {
    if(m_size == 0)
    {
        throw EmptyQueue();
    }
    --m_size;
    for (int i = 0; i < m_size; ++i) {
        m_arr[i] = m_arr[i+1];
    }
}


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

    class InvalidOperation
    {
        InvalidOperation() = default;
    };
};

template<class Q>
Q& Array<Q>::Iterator::operator*() const
{
    if (index >= array->size())
    {
        throw InvalidOperation();
    }
    return array->m_arr[index];
}

template<class Q>
typename Array<Q>::Iterator Array<Q>::Iterator::operator++(int)
{
    if (index >= array->size())
    {
        throw InvalidOperation();
    }
    Iterator result=*this;
    ++*this;
    return result;
}

template <class Q>
typename Array<Q>::Iterator& Array<Q>::Iterator::operator++()
{
    if (index >= array->size())
    {
        throw InvalidOperation();
    }
    ++index;
    return *this;
}

template <class Q>
bool Array<Q>::Iterator::operator==(const Iterator& i)
{
    assert(array== i.array);/////////////////////////////////////////////////////////
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
    return Iterator(this,this->size());
}





/////////-----CONSTITERATOR-------////////////




template <class Q>
class Array<Q>::ConstIterator{
    const Array<Q>* array;
    int index;
    ConstIterator(const Array<Q>*queue, int index);
    friend class Array<Q>;

public:
    const Q& operator*()const;
    ConstIterator& operator++();
    ConstIterator operator++(int);
    bool operator==(const ConstIterator& it)const;
    bool operator!=(const ConstIterator& it)const;
    ConstIterator(const ConstIterator&) = default;
    ConstIterator& operator=(const ConstIterator&) = default;

    class InvalidOperation
    {
        InvalidOperation() = default;
    };
};

template<class Q>
const Q& Array<Q>::Iterator::operator*() const
{
    if (index >= array->size())
    {
        throw InvalidOperation();
    }
    return array->m_arr[index];
}

template<class Q>
typename Array<Q>::ConstIterator Array<Q>::ConstIterator::operator++(int)
{
    if (index >= array->size())
    {
        throw InvalidOperation();
    }
    ConstIterator result=*this;
    ++ *this;
    return result;
}


template <class Q>
typename Array<Q>::ConstIterator& Array<Q>::ConstIterator::operator++()
{
    if (index >= array->size())
    {
        throw InvalidOperation();
    }
    ++index;
    return *this;
}

template <class Q>

bool Array<Q>::ConstIterator::operator==(const ConstIterator& it) const
{
    assert(array==it.array);/////////////////////////////////////////////////////////////////////////
    return index==it.index;
}

template <class Q>
bool Array<Q>::ConstIterator::operator!=(const ConstIterator& it) const{
    return (!(*this == it));
}

template <class Q>
typename Array<Q>::ConstIterator Array<Q>::begin() const
{
    return Iterator(this,0);
}

template <class Q>
typename Array<Q>::ConstIterator Array<Q>::end() const
{
    return Iterator(this,this->size());
}


#endif //EX3_QUEUE_H
