class Person
{
private:
    char* m_name;

public:
    // c'tor / d'tor
    Person();
    Person(char* name);
    Person(const Person& person);
    ~Person();

    // comparison operators
    friend bool operator== (const Person&, const Person&);
    friend bool operator!= (const Person&, const Person&);

    // output operator
    friend ostream& operator<< (ostream&, const Person&);

    // assignment operator
    Person& operator = (const Person&);
};