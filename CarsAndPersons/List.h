template <class T>
class List
{
private:
    static const int DefaultListLength = 4;

private:
    T const **  m_elements;
    int m_length;
    int m_count;

public:
    List();
    List(int length);
    ~List();

    bool Add(T const* elem);
    bool Remove(T const* elem);
    bool Contains(T const* elem);
    bool IsEmpty() const;
    int Count() const;

    friend ostream& operator<< <>(ostream&, const List&);
};

template <class T>
List<T>::List()
{
    m_elements = new Person*[DefaultListLength];
    m_length = DefaultListLength;
    m_count = 0;
}

template <class T>
List<T>::List(int length)
{
    m_elements = new const Person*[length];
    m_length = length;
    m_count = 0;
}


template <class T>
List<T>::~List()
{
    delete[] m_elements;
};

template <class T>
bool List<T>::Add(T const* elem)
{
    if (m_count == m_length)
        return false;

    m_elements[m_count] = elem;
    m_count++;
    return true;
}

template <class T>
bool List<T>::Remove(T const* elem)
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

template <class T>
bool List<T>::Contains(T const* elem)
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

template <class T>
bool List<T>::IsEmpty() const
{
    return (m_count == 0);
}

template <class T>
int List<T>::Count() const
{
    return m_count;
}

template <class T>
ostream& operator<< (ostream& os, const List<T>&  list)
{
    for (int i = 0; i < list.m_count; i++)
    {
        os << *list.m_elements[i] << endl;
    }

    return os;
}