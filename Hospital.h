#ifndef HOSPITAL_H
#define HOSPITAL_H
#include <bits/stdc++.h>
#include "Department.h"
#include "Receptionist.h"

class Hospital
{
    static Hospital *instance;

public:
    static Hospital *getInstance()
    {
        if (!instance)
        {
            instance = new Hospital();
        }
        return instance;
    }
    void mainMenu()
    {
        int opt;

        while (true)
        {
            // system("CLS");

            cout << endl;
            cout << "            *** Welcome to the Hospital Management System ***    "
                 << "\n\n\n";
            cout << "                   1. Menu :   "
                 << "\n\n";
            ;
            cout << "                   2. Exit :   "
                 << "\n\n\n";
            cout << "Enter Your Choice  :";
            cin >> opt;
            cout << "\n\n";
            switch (opt)
            {
            case 1:
                Receptionist::getInstance()->menu();
                break;

            case 2:
                exit(0);
                break;

            default:
                cout << "Enter valid choice" << endl;
                break;
            }
        }
    }
};

Hospital *Hospital::instance = nullptr;
#endif