#include <string.h>
#include <iostream>
using namespace std;

#include "Person.h"
#include "PassengersList.h"

PassengersList::PassengersList()
{
    m_elements = new const Person*[DefaultListLength];
    m_length = DefaultListLength;
	m_count = 0;
}

PassengersList::PassengersList(int length)
{
    m_elements = new const Person*[length];
    m_length = length;
    m_count = 0;
}

PassengersList::~PassengersList()
{
	delete[] m_elements;
};

bool PassengersList::Add(Person const* elem)
{
    if (m_count == m_length)
        return false;

    m_elements[m_count] = elem;
    m_count++;
    return true;
}

bool PassengersList::Remove(Person const* elem)
{
    // search slot
    for (int i = 0; i < m_count; i++)
    {
        // compare objects, not pointer
        if (*m_elements[i] == *elem)
        {
            // found slot - copy last element into this slot
            m_elements[i] = m_elements[m_count - 1];
            m_count--;
            return true;
        }
    }

    // element not found
    return false;
}

bool PassengersList::Contains(const Person* elem)
{
    // search slot
    for (int i = 0; i < m_count; i++)
    {
        // compare objects, not pointers
        if (*m_elements[i] == *elem)
        {
            return true;
        }
    }

    // element not found
    return false;
}

bool PassengersList::IsEmpty() const
{
	return (m_count == 0);
}

int PassengersList::Count() const
{
	return m_count;
}

ostream& operator<< (ostream& os, const PassengersList& list)
{
    for (int i = 0; i < list.m_count; i++)
    {
        os << *list.m_elements[i] << endl;
    }

    return os;
}
