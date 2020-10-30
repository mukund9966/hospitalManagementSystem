#ifndef PERSON_H
#define PERSON_H

#include <bits/stdc++.h>
using namespace std;

class Person
{
private:
    string name;
    string address;
    string gender;
    long int phoneNumber;
    int age;
    int id;

public:
    Person() {}
    Person(string name, string address, string gender, long int phoneNumber, int age, int id)
    {
        this->name = name;
        this->address = address;
        this->gender = gender;
        this->phoneNumber = phoneNumber;
        this->age = age;
        this->id = id;
    }
    string getName()
    {
        return this->name;
    }

    void setName(string name)
    {
        this->name = name;
    }

    string getAddress()
    {
        return this->address;
    }

    void setAddress(string address)
    {
        this->address = address;
    }

    string getGender()
    {
        return this->gender;
    }

    void setGender(string gender)
    {
        this->gender = gender;
    }

    long int getPhoneNumber()
    {
        return this->phoneNumber;
    }

    void setPhoneNumber(long int phoneNumber)
    {
        this->phoneNumber = phoneNumber;
    }

    int getAge()
    {
        return this->age;
    }

    void setAge(int age)
    {
        this->age = age;
    }

    int getId()
    {
        return this->id;
    }

    void setId(int id)
    {
        this->id = id;
    }
};

#endif