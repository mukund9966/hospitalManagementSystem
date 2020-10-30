#ifndef DEPARTMENT_H
#define DEPARTMENT_H
#include <bits/stdc++.h>
#include "Doctor.h"
using namespace std;

class Department
{
private:
    static int departmentId;
    int Id;
    string name;
    unordered_map<int, Doctor *> registeredDoctors;

public:
    Department(string name)
    {
        this->name = name;
        this->Id = departmentId;
        departmentId++;
    }
    unordered_map<int, Doctor *> getRegisteredDoctor()
    {
        return this->registeredDoctors;
    }
    int getId()
    {
        return this->Id;
    }

    string getName()
    {
        return this->name;
    }

    void setName(string name)
    {
        this->name = name;
    }

    void addDoctor(Doctor *doctor)
    {
        registeredDoctors.insert(make_pair(doctor->getId(), doctor));
        cout << "doctor succesfully added in department" << endl;
    }

    void removeAllDocterFromDepartment()
    {
        for (auto field : registeredDoctors)
        {
            field.second = nullptr;
        }
        this->registeredDoctors.clear();
    }

    Doctor *findDoctor(int docId)
    {
        if (registeredDoctors.find(docId) != registeredDoctors.end())
        {
            return registeredDoctors[docId];
        }
        return nullptr;
    }

    void removeDoctor(int docId)
    {
        if (findDoctor(docId) != nullptr)
        {
            registeredDoctors.erase(docId);
        }
        else
        {
            cout << "  \t       Invalid docId" << endl;
            return;
        }
        cout << "  \t       Doctor Successfully removed" << endl;
    }

    void displayDetailAllDoctor()
    {
        cout << "********************************************************************************"
             << "\n";
        cout << "\t \t \t  Details Of All The Doctors In The Department \n";
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
             << "specialization"
             << endl;

        for (auto field : registeredDoctors)
        {
            cout << field.first << "\t \t" << field.second->getName() << "\t \t" << field.second->getAddress() << "\t \t" << field.second->getGender() << "\t \t" << field.second->getAge() << "\t \t" << field.second->getPhoneNumber() << "\t \t " << field.second->getSpecialization() << endl;
        }
    }
};

int Department::departmentId = 500;

#endif