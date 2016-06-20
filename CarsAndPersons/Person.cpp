#include <string.h>
#include <iostream>
using namespace std;

#include "Person.h"

Person::Person()
{
    m_name = (char*) 0;
}

Person::Person(char* name)
{
    int len = strlen(name);
    m_name = new char[len + 1];
    strcpy_s(m_name, len + 1, name);
}

Person::Person(const Person& person)
{
    int len = strlen(person.m_name);
    m_name = new char[len + 1];
    strcpy_s(m_name, len + 1, person.m_name);
}


Person::~Person()
{
    delete[] m_name;
}

bool operator== (const Person& p1, const Person& p2)
{
    return (strcmp(p1.m_name, p2.m_name) == 0);
}

bool operator!= (const Person& p1, const Person& p2)
{
    return !(p1 == p2);
}

ostream& operator<< (ostream& os, const Person& person)
{
    os << person.m_name;
    return os;
}

// assignment operator
Person& Person::operator= (const Person& person)
{
    if (this != &person)
    {
        delete[] m_name;

        int len = strlen(person.m_name);
        m_name = new char[len + 1];
        strcpy_s(m_name, len + 1, person.m_name);
    }

    return *this;
}
