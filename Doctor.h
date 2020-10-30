#ifndef DOCTOR_H
#define DOCTOR_H

#include <bits/stdc++.h>
#include "Person.h"
#include "Patient.h"
using namespace std;

class Doctor : public Person
{
private:
    string department;
    string specialization;
    static int uniqueDocId;
    unordered_map<int, Patient *> patientList;

public:
    Doctor() : Person() {}
    Doctor(string name, string address, string gender, long int phoneNumber, int age, string department, string specialization) : Person(name, address, gender, phoneNumber, age, uniqueDocId)
    {
        this->department = department;
        this->specialization = specialization;
        uniqueDocId++;
    }

    Patient *findPatient(int patientId)
    {
        if (patientList.find(patientId) != patientList.end())
        {
            return patientList[patientId];
        }
        return nullptr;
    }

    void setPatientCurrDocNull()
    {
        for (auto itr : patientList)
        {
            itr.second->setCurrentDoctor(nullptr);
        }
        this->patientList.clear();
    }

    void removePatient(int patientId)
    {
        Patient *patient = findPatient(patientId);
        if (patient != nullptr)
        {
            patient->setCurrentDoctor(nullptr);
            patientList.erase(patientId);
        }
        else
        {
            cout << "  \t       Invalid patientId" << endl;
            return;
        }
        cout << "  \t       Patient Successfully removed" << endl;
    }

    void addPatient(Patient *patient)
    {
        patientList.insert(make_pair(patient->getId(), patient));
    }

    string getDepartment()
    {
        return this->department;
    }

    void setDepartment(string department)
    {
        this->department = department;
    }

    string getSpecialization()
    {
        return this->specialization;
    }

    void setSpecialization(string specialization)
    {
        this->specialization = specialization;
    }
    void display()
    {
        cout << "********************************************************************************"
             << "\n";
        cout << "\t \t \t  Details Of The Doctors: \n";
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
             << "Specialization"
             << "\t \t"
             << " Department"
             << endl;

        cout << this->getId() << "\t \t" << this->getName() << "\t \t" << this->getAddress() << "\t \t" << this->getGender() << "\t \t" << this->getAge() << "\t \t" << this->getPhoneNumber() << "\t \t " << this->getSpecialization() << "\t \t" << this->getDepartment() << endl;
    }
};

int Doctor::uniqueDocId = 700;

#endif