#include <iostream>
using namespace std;

#include "Person.h"
#include "PassengersList.h"
// #include "List.h"
#include "Car.h"

Car::Car() : m_Passengers(DefaultNumPassengers)
{
    m_MaxNumPassengers = DefaultNumPassengers;
}

Car::Car(int maxNumPassengers) : m_Passengers (maxNumPassengers)
{
    m_MaxNumPassengers = maxNumPassengers;
}

bool Car::GetIn(const Person& person)
{
    if (m_Passengers.Count() == m_MaxNumPassengers)
        return false;

    if (m_Passengers.Contains(&person))
        return false;

    m_Passengers.Add(&person);
    return true;
}

bool Car::GetOff(const Person& person)
{
    if (! m_Passengers.Contains(&person))
        return false;

    m_Passengers.Remove(&person);
    return true;
}

int Car::NumOfPassengers() const
{
    return m_Passengers.Count();
}

bool Car::IsCarried(const Person& person)
{
    return m_Passengers.Contains(&person) ? true : false;
}

ostream& operator<< (ostream& os, const Car& car)
{
    os << "List of passengers:" << endl;
    os << "-------------------" << endl;
    os << car.m_Passengers;
    os << "===================" << endl;

    return os;
}
