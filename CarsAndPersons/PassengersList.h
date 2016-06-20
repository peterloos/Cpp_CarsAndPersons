class PassengersList
{
private:
    static const int DefaultListLength = 4;

private:
    Person const ** m_elements;
    int m_length;
    int m_count;

public:
    // c'tor/d'tor
    PassengersList();
    PassengersList(int length);
    ~PassengersList();

    // public interface
    bool Add(Person const* elem);
    bool Remove(Person const* elem);
    bool Contains(const Person* elem);
	bool IsEmpty() const;
	int Count() const;

    // output operator
    friend ostream& operator<< (ostream&, const PassengersList&);
};

