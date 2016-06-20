class Car
{
private:
    static const int DefaultNumPassengers = 5;

    PassengersList m_Passengers;
    // List<Person> m_Passengers;

    int m_MaxNumPassengers;

public:
    Car();
    Car(int maxNumPassengers);

    bool GetIn(const Person& person);
    bool GetOff(const Person& person);
    int NumOfPassengers() const;
    bool IsCarried(const Person& person);

    friend ostream& operator<< (ostream&, const Car&);
};