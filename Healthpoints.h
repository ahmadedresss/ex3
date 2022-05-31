//
// Created by Ahmad Idris on 5/22/22.
//

#ifndef EX3_HEALTHPOINTS_H
#define EX3_HEALTHPOINTS_H
#define DE_HP 100
#include <iostream>
class HealthPoints{
private:

    int m_max_HP;
    int m_HP;
    friend std::ostream& operator<<(std::ostream& os,const HealthPoints& r);
    friend bool operator==(const HealthPoints& r,const HealthPoints& it);
    friend bool operator<(const HealthPoints& r,const HealthPoints& it);



public:
    class InvalidArgument {};
    HealthPoints(const HealthPoints& healthPoints)=default;
    ~HealthPoints()=default;

    HealthPoints(int maxHP=DE_HP);
    HealthPoints& operator+=(const int add);
    HealthPoints& operator-=(const int minus);
    HealthPoints& operator= (const HealthPoints& other)= default;
    HealthPoints& operator= (int num);

};
HealthPoints operator+(const int add,const HealthPoints& it);
HealthPoints operator+(const HealthPoints& it,const int add);
HealthPoints operator-(const int minus ,const HealthPoints& it);
HealthPoints operator-(const HealthPoints& it,const int minus);




bool operator>=(const HealthPoints& r,const HealthPoints& it);

bool operator>(const HealthPoints& r,const HealthPoints& it);

bool operator<=(const HealthPoints& r,const HealthPoints& it);

bool operator!=(const HealthPoints& r,const HealthPoints& it);




#endif //EX3_HEALTHPOINTS_H
