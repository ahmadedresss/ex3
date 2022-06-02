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


public:
    class InvalidArgument {};
    /**
     * this is the default copy constructor .
     * @param healthPoints
     */
    HealthPoints(const HealthPoints& healthPoints)=default;
    /**
     * default destructor.
     */
    ~HealthPoints()=default;

    /**
     * printing function .
     * @param os
     * @param r
     * @return
     */
    friend std::ostream& operator<<(std::ostream& os,const HealthPoints& r);
    /**
     * in this operator we check if health points of (r) equals health points of (it)
     * this operator is friend witch means it can access to the Health points private part
     * @param r
     * @param it
     * @return
     */
    friend bool operator==(const HealthPoints& r,const HealthPoints& it);
    /**
     * in this operator we check if health points of (r) smaller than health points of (it)
     * this operator is friend witch means it can access to the Health points private part
     * @param r
     * @param it
     * @return
     */
    friend bool operator<(const HealthPoints& r,const HealthPoints& it);

    /**
     * constructor that give an initial value to m_HP and m_maxHP
     * @param maxHP
     */
    HealthPoints(int maxHP=DE_HP);
    /**
     * this operator adds the value of the the parm (add) to m_hp
     * @param add
     * @return
     */
    HealthPoints& operator+=(const int add);
    /**
     * this operator decrease the value of the the parm (minus) from m_hp
     * @param minus
     * @return
     */
    HealthPoints& operator-=(const int minus);


    /**
     * this operator receives other HealthPoints parm and gives it HP,maxHP values to the current m_HP,m_maxHP
     * its defined as default
     * @param other
     * @return
     */
    HealthPoints& operator= (const HealthPoints& other)= default;
    /**
     * this operator receives int parm and equals HP,maxHP values to num
     * @param num
     * @return
     */
    HealthPoints& operator= (int num);

};


/**
 * this operator adds the value of the the parm (add) to m_hp
 * @param add
 * @param it
 * @return
 */

HealthPoints operator+(const int add,const HealthPoints& it);
/**
 * this operator adds the value of the the parm (add) to m_hp
 * @param it
 * @param add
 * @return
 */
HealthPoints operator+(const HealthPoints& it,const int add);
/**
 * this operator decrease the value of the the parm (minus) from m_hp
 * @param minus
 * @param it
 * @return
 */
HealthPoints operator-(const int minus ,const HealthPoints& it);
/**
 * this operator decrease the value of the the parm (minus) from m_hp
 * @param it
 * @param minus
 * @return
 */
HealthPoints operator-(const HealthPoints& it,const int minus);



/**
 * bool operator returns true if r.m_HP bigger or equals than it.m_HP else returns false
 * @param r
 * @param it
 * @return
 */
bool operator>=(const HealthPoints& r,const HealthPoints& it);
/**
 * bool operator returns true if r.m_HP bigger that it.m_HP else returns false
 * @param r
 * @param it
 * @return
 */
bool operator>(const HealthPoints& r,const HealthPoints& it);
/**
 * bool operator returns false if r.m_HP bigger than it.m_HP else returns true
 * @param r
 * @param it
 * @return
 */
bool operator<=(const HealthPoints& r,const HealthPoints& it);
/**
 * bool operator returns true if r.m_HP not equals it.m_HP else returns false
 * @param r
 * @param it
 * @return
 */
bool operator!=(const HealthPoints& r,const HealthPoints& it);




#endif //EX3_HEALTHPOINTS_H
