
//
// Created by Ahmad Idris on 5/24/22.
//
#include <iostream>
#include <cassert>
#ifndef EX3_QUEUE_H
#define EX3_QUEUE_H
//#define EXPAND_RATE 2
//#define INITIAL_SIZE 10
template<class Q>


class Queue{
public:

    explicit Queue(int size);
    Queue(const Queue& a);
    ~Queue();
    Queue();
    Queue& operator=(const Queue& a);
    int size() const;
    Q& front();
    Q& front()const;
    void popFront();
    void pushBack(const Q& add);
    int getMaxSize() const;
    class EmptyQueue{};

    class Iterator;
    class ConstIterator;

    Iterator begin();
    Iterator end();

    ConstIterator begin() const;
    ConstIterator end() const;
    static const int EXPAND_RATE=2;
    static const int INITIAL_SIZE=10;



private:
    Q* m_arr;
    int m_size;
    int m_max_size;
    void expand();
};


template<class Q>
int Queue<Q>::size() const
{
    if (m_size<0)
    {////////////////////////////////////////////////////////////////////////////////////
        throw EmptyQueue();
    }
    return m_size;
}

template<class Q>
int Queue<Q>::getMaxSize() const
{
    return m_max_size;
}

template<class Q>
Queue<Q>& Queue<Q>::operator=(const Queue<Q> &a){
    if (this== &a)
    {
        return *this;
    }
    delete[] m_arr;
    m_arr=new Q[a.m_size];
    m_size  =a.m_size;
    try {
        for(int i=0; i < m_size;++i)
        {
            m_arr[i]=a.m_arr[i];
        }

    }
    catch (...)
    {
        delete[] m_arr;
        throw;
    }

    return *this;
}

template<class Q>
Queue<Q>::Queue() : m_arr(new Q[INITIAL_SIZE]),m_size(0)
{

}
template<class Q>
Queue<Q>::Queue(int size) : m_arr(new Q[INITIAL_SIZE]),m_size(size)
{

}

template<class Q>
Queue<Q>::~Queue()
{
    delete[] m_arr;
}

template<class Q>
Queue<Q>::Queue(const Queue<Q>& copy):m_arr(new Q[copy.m_max_size]),m_size(copy.m_size),m_max_size(copy.m_max_size)
{
    for(int i=0;i<m_size;++i)
    {
        m_arr[i]=copy.m_arr[i];//////////////////////////////
    }
}

template<class Q>
void Queue<Q>::expand()
{

    int newSize = m_max_size * EXPAND_RATE;
    Q *newArr = new Q[newSize];
    try {

        for (int i = 0; i < size(); ++i)
        {
            newArr[i] = m_arr[i];
        }
    }
    catch(...)
    {
        delete[] newArr;
        throw ;

    }
    delete[] m_arr;

    m_arr = newArr;
    m_max_size = newSize;


}

template<class Q>
void Queue<Q>::pushBack(const Q& add)
{
    if(size()>=getMaxSize())
    {
        expand();
    }
    m_arr[m_size]=add;
    m_size++;
}

template <class Q>
Q& Queue<Q>::front()
{
    if (m_size <= 0)
    {
        throw EmptyQueue();
    }

    return m_arr[0];
}

template <class Q>
Q& Queue<Q>::front() const
{
    if (m_size < 0)
    {
        throw EmptyQueue();
    }
    return m_arr[0];
}

template<class Q>
void Queue<Q>::popFront() {
    if(m_size < 0)
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
class Queue<Q>::Iterator
{
    Queue<Q> * array;
    int index;
    Iterator(Queue<Q>* queue, int index);
    friend class Queue;
public:
    Q& operator*() const;
    Iterator& operator++();
    Iterator operator++(int);
    bool operator==(const Iterator& it);
    bool operator!=(const Iterator& it);
    Iterator(const Iterator&) = default;
    Iterator& operator=(const Iterator&) = default;

    class InvalidOperation
    {
    public:
        InvalidOperation() = default;
    };
};

template<class Q>
Queue<Q>::Iterator::Iterator(Queue<Q>* queue, int index) :
        array(queue), index(index){}

template<class Q>
Q& Queue<Q>::Iterator::operator*() const
{
    if (index >= array->size())
    {
        throw InvalidOperation();
    }
    return array->m_arr[index];
}

template<class Q>
typename Queue<Q>::Iterator Queue<Q>::Iterator::operator++(int)
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
typename Queue<Q>::Iterator& Queue<Q>::Iterator::operator++()
{
    if (index >= array->size())
    {
        throw InvalidOperation();
    }
    ++index;
    return *this;
}

template <class Q>
bool Queue<Q>::Iterator::operator==(const Iterator& i)
{
    assert(array== i.array);/////////////////////////////////////////////////////////
    return index==i.index;
}

template <class Q>
bool Queue<Q>::Iterator::operator!=(const Iterator& i) {
    return !(*this == i);
}

template <class Q>
typename Queue<Q>::Iterator Queue<Q>::begin()
{
    return Iterator(this,0);
}

template <class Q>
typename Queue<Q>::Iterator Queue<Q>::end()
{
    return Iterator(this,m_size);
}





/////////-----CONSTITERATOR-------////////////




template <class Q>
class Queue<Q>::ConstIterator{
        const Queue<Q>* array;
    int index;
    ConstIterator(const Queue<Q>* queue, int index);
    friend class Queue<Q>;

public:
    const Q& operator*() const;
    ConstIterator& operator++();
    ConstIterator operator++(int);
    bool operator==(const ConstIterator& it)const;
    bool operator!=(const ConstIterator& it)const;
    ConstIterator(const ConstIterator&) = default;
    ConstIterator& operator=(const ConstIterator&) = default;

    class InvalidOperation
    {
    public:
        InvalidOperation() = default;
    };
};


template<class Q>
Queue<Q>::ConstIterator::ConstIterator(const Queue<Q>* queue, int index) :
        array(queue), index(index)
{}

template<class Q>
const Q& Queue<Q>::ConstIterator::operator*() const
{
    if (index >= array->m_size)
    {
        throw InvalidOperation();
    }
    return array->m_arr[index];
}

template<class Q>
typename Queue<Q>::ConstIterator Queue<Q>::ConstIterator::operator++(int)
{
    if (index >= array->size())
    {
        throw Queue<Q>::ConstIterator::InvalidOperation();
    }
    ConstIterator result=*this;
    ++ *this;
    return result;
}


template <class Q>
typename Queue<Q>::ConstIterator& Queue<Q>::ConstIterator::operator++()
{
    if (index >= array->size())
    {
        throw Queue<Q>::ConstIterator::InvalidOperation();
    }
    ++index;
    return *this;
}

template <class Q>

bool Queue<Q>::ConstIterator::operator==(const ConstIterator& it) const
{
    assert(array==it.array);
    return index==it.index;
}

template <class Q>
bool Queue<Q>::ConstIterator::operator!=(const ConstIterator& it) const{
    return (!(*this == it));
}

template <class Q>
typename Queue<Q>::ConstIterator Queue<Q>::begin() const
{
    return ConstIterator(this,0);
}

template <class Q>
typename Queue<Q>::ConstIterator Queue<Q>::end() const {
    return ConstIterator(this, m_size);
}




template<class Q, class Function>
void transform(Queue<Q>& queue, Function c)
{

    for (auto iterator = queue.begin(); iterator != queue.end(); ++iterator)
    {
        c(*iterator);
    }

}
template<class Q, class Function>
Queue<Q> filter (Queue<Q> arr,Function c)
{
    Queue<Q> temp;
    for (auto iterator = arr.begin(); iterator != arr.end(); ++iterator) {
        if(c(*iterator))
        {
            try {
                temp.pushBack(*iterator);
                }
            catch (...)
            {
                throw;
            }
        }
    }
    return temp;
}


#endif //EX3_QUEUE_H
