#ifndef PATIENT_H
#define PATIENT_H

#include <bits/stdc++.h>
#include "Person.h"
using namespace std;
class Doctor;
class Patient : public Person
{
private:
    int roomNumber;
    static int uniquePatientId;
    Doctor *currentDoc;

public:
    Patient(string name, string address, string gender, long int phoneNumber, int age, int roomNumber) : Person(name, address, gender, phoneNumber, age, uniquePatientId)
    {
        this->roomNumber = roomNumber;
        uniquePatientId++;
    }

    void setCurrentDoctor(Doctor *doc)
    {
        this->currentDoc = doc;
    }

    Doctor *currentDoctor()
    {
        return currentDoc;
    }

    int getRoomNumber()
    {
        return roomNumber;
    }

    void setRoomNumber(int roomNumber)
    {
        this->roomNumber = roomNumber;
    }
    void display()
    {
        cout << "********************************************************************************"
             << "\n";
        cout << "\t \t \t  Details Of The Patient: \n";
        cout << "********************************************************************************"
             << "\n \n";

        cout << "ID"
             << "\t \t"
             << "Name"
             << "\t \t"
             << "Address"
             << "\t \t"
             << "Gender"
             << "\t \t"
             << "Age"
             << "\t \t"
             << "Phone number"
             << "\t \t"
             << "Room Number"
             << endl;

        cout << this->getId() << "\t \t" << this->getName() << "\t \t" << this->getAddress() << "\t \t" << this->getGender() << "\t \t" << this->getAge() << "\t \t" << this->getPhoneNumber() << "\t \t " << this->getRoomNumber() << endl;
    }
};

int Patient::uniquePatientId = 100;

#endif