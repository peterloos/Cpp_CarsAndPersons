#include <iostream>
using namespace std;

#include "Person.h"
#include "PassengersList.h"
// #include "List.h"
#include "Car.h"

void test00();
void test01();
void test02();
void test03();
void test04();

void test01()
{
    Person anton("Anton");
    Person franz("Franz");
    Person gustl("Gustl");
    Car benz;
    benz.GetIn(anton);
    benz.GetIn(gustl);
    benz.GetIn(franz);

    cout << benz << endl;
    cout << benz.NumOfPassengers() << " passengers are in the car." << endl;
}

void test02()
{
    Car vw;
    Person anton("Anton");
    Person franz("Franz");
    Person gustl("Gustl");

    vw.GetIn(anton);
    vw.GetIn(franz);
    cout << vw.NumOfPassengers() << " passengers are in the car." << endl;

    bool result = vw.GetOff(gustl);
    cout << gustl <<  " could leave the car: " << result << endl;

    vw.GetIn(gustl);
    cout << vw.NumOfPassengers() << " passengers are in the car." << endl;

    result = vw.GetIn(gustl);
    cout << gustl << " entered the car a second time: " << result << endl;
    cout << vw.NumOfPassengers() << " passengers are in the car." << endl;
}

void test03()
{
    Car vw;
    Person franz("Franz");

    cout << "Is Franz in the car: " << vw.IsCarried(franz) << endl;
    vw.GetIn(franz);
    cout << "Is Franz in the car: " << vw.IsCarried(franz) << endl;
    cout << "There is(are) " << vw.NumOfPassengers()
        << " passenger(s) in the car." << endl;
    cout << endl << vw << endl;
}

void test04()
{
    Car  cinquecento(2);
    Person franz("Franz");
    Person susan("Susan");
    Person werner("Werner");

    cinquecento.GetIn(franz);
    cout << "Number of passenger(s): "
        << cinquecento.NumOfPassengers() << '.' << endl;

    cinquecento.GetIn(susan);
    cout << "Number of passenger(s): " 
        << cinquecento.NumOfPassengers() << '.' << endl;

    cinquecento.GetIn(werner);
    cout << "Number of passenger(s): "
        << cinquecento.NumOfPassengers() << '.' << endl;

    cout << "Is Susan in the car: "
        << cinquecento.IsCarried(susan) << endl;
    cout << "Is Werner in the car: "
        << cinquecento.IsCarried(werner) << endl;
}

void main()
{
    test01();
    test02();
    test03();
    test04();
    getchar();
}