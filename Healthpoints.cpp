//
// Created by Ahmad Idris on 5/22/22.

#include "HealthPoints.h"
#include <iostream>
#include <ostream>

HealthPoints::HealthPoints(int maxHP):m_max_HP(maxHP),m_HP(maxHP)
{
    if(maxHP<=0)
    {
        throw InvalidArgument();
    }
}

HealthPoints& HealthPoints::operator+=(const int add)
{
    if(add<0)
    {
        throw HealthPoints::InvalidArgument();
    }
    if(m_HP+add>m_max_HP)
    {
        m_HP=m_max_HP;
        return *this;
    }
        m_HP+=add;
    return *this;
}

HealthPoints& HealthPoints::operator-=(const int minus)
{
    if(minus<0)
    {
        throw HealthPoints::InvalidArgument();
    }

    if(m_HP-minus<0)
    {
        m_HP = 0;
        return *this;
    }
    else
    {
        m_HP -= minus;
        return *this;

    }

}

HealthPoints operator-(const int minus,const HealthPoints& it)
{
    HealthPoints result=it;
    result-=minus;
    return result;
}

HealthPoints operator-(const HealthPoints& it,const int minus)
{
    HealthPoints result=it;
    result-=minus;
    return result;
}

HealthPoints operator+(const int add,const HealthPoints& it)
{
    HealthPoints result=it;
    result+=add;
    return result;
}

HealthPoints operator+(const HealthPoints& it,const int add)
{
    HealthPoints result=it;
    result+=add;
    return result;
}

bool operator==(const HealthPoints& r,const HealthPoints& it)
{
    if(r.m_HP==it.m_HP )
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool operator>=(const HealthPoints& r,const HealthPoints& it)
{
    return !(r<it);

}

bool operator>(const HealthPoints& r,const HealthPoints& it)
{

    return it<r;
}

bool operator<=(const HealthPoints& r, const HealthPoints& it)
{
    return !(r>it);
}

bool operator<(const HealthPoints& r,const HealthPoints& it)
{
    if(r.m_HP<it.m_HP )
    {
        return true;
    }
    else
    {
        return false;
    }
}

std::ostream& operator<<(std::ostream& os,const HealthPoints& r)
{
    return os << r.m_HP << "(" << r.m_max_HP << ")";
}
