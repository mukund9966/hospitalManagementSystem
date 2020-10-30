#ifndef RECEPTIONIST_H
#define RECEPTIONIST_H

#include <bits/stdc++.h>
#include "Doctor.h"
#include "Patient.h"
#include "Department.h"
using namespace std;

class Receptionist
{
private:
    int Id;
    string name;
    static Receptionist *instance;
    static int uniqueRoomId;
    unordered_map<int, Doctor *> doctorList;
    unordered_map<int, Patient *> patientList;
    vector<Department *> departmentList;

public:
    static Receptionist *getInstance()
    {
        if (!instance)
        {
            instance = new Receptionist("Alexa", 1001);
        }
        return instance;
    }
    Receptionist(string name, int Id)
    {
        this->name = name;
        this->Id = Id;
    }
    void printInstructionsForPatient()
    {
        cout << "\n\n";
        cout << "       *** Welcome To Patient's DataBase ***    "
             << "\n \n \n\n";

        cout << "  \t       1. Add New Patient's Information              " << endl;
        cout << "  \t       2. Display Patient's Information              " << endl;
        cout << "  \t       3. Detail Of All The Patient In The Hospital " << endl;
        cout << "  \t       4. Remove Patient from the Hospital     " << endl;
        cout << "  \t       5. EXIT                                      "
             << "\n\n\n";
    }
    void printInstructionsForDoctor()
    {
        cout << "\n\n";
        cout << "             *** Welcome To Doctor's DataBase ***    "
             << "\n \n \n\n";

        cout << "  \t       1. Add New Doctor's Information              " << endl;
        cout << "  \t       2. Display Doctor's Information              " << endl;
        cout << "  \t       3. Detail OF All The Doctors In The Hospital " << endl;
        cout << "  \t       4. Remove Doctor From Hospital               " << endl;
        cout << "  \t       5. EXIT                                      "
             << "\n\n\n";
    }
    void printInstructionsForDepartment()
    {
        cout << "\n\n";
        cout << "       *** Welcome To Department's DataBase ***    "
             << "\n \n \n\n";

        cout << "  \t       1. Add New Department                         " << endl;
        cout << "  \t       2. Display All Department's Information              " << endl;
        cout << "  \t       3. Remove Department from the Hospital     " << endl;
        cout << "  \t       4. EXIT                                      "
             << "\n\n\n";
    }

    void displayDetailAllDoctorInHospital()
    {
        cout << "********************************************************************************"
             << "\n";
        cout << "\t \t \t  Details Of All The Doctors In The Hospital \n";
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
             << "\t \t"
             << "Department"
             << endl;

        for (auto field : doctorList)
        {
            cout << field.first << "\t \t" << field.second->getName() << "\t \t" << field.second->getAddress() << "\t \t" << field.second->getGender() << "\t \t" << field.second->getAge() << "\t \t" << field.second->getPhoneNumber() << "\t \t" << field.second->getSpecialization() << "\t \t" << field.second->getDepartment() << endl;
        }
    }

    void displayDetailAllPatientInHospital()
    {
        cout << "********************************************************************************"
             << "\n";
        cout << "\t \t \t  Details Of All The Patients In The Hospital \n";
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

        for (auto field : patientList)
        {
            cout << field.first << "\t \t" << field.second->getName() << "\t \t" << field.second->getAddress() << "\t \t" << field.second->getGender() << "\t \t" << field.second->getAge() << "\t \t" << field.second->getPhoneNumber() << "\t \t " << field.second->getRoomNumber() << endl;
        }
    }

    void displayDetailAllDepartmentInHospital()
    {
        cout << "********************************************************************************"
             << "\n";
        cout << "\t \t \t  Details Of All The Department's In The Hospital \n";
        cout << "********************************************************************************"
             << "\n \n";

        cout << "ID"
             << "\t \t"
             << "Name"
             << endl;

        for (auto field : departmentList)
        {
            cout << field->getId() << "\t \t" << field->getName() << endl;
        }
    }

    Doctor *findDoctorInHospital(int docId)
    {
        if (doctorList.find(docId) != doctorList.end())
        {
            return doctorList[docId];
        }
        return nullptr;
    }
    Patient *findPatientInHospital(int PatientId)
    {
        if (patientList.find(PatientId) != patientList.end())
        {
            return patientList[PatientId];
        }
        return nullptr;
    }

    void removeDoctorFromHospital(int docID)
    {
        if (findDoctorInHospital(docID) != nullptr)
        {

            for (auto field : departmentList)
            {
                if (field->findDoctor(docID) != nullptr)
                {
                    field->removeDoctor(docID);
                    break;
                }
            }
            doctorList[docID]->setPatientCurrDocNull();
            doctorList.erase(docID);
        }
        else
        {
            return;
        }
    }

    void removePatientFromHospital(int patientId)
    {
        if (findPatientInHospital(patientId) != nullptr)
        {
            for (auto field : doctorList)
            {
                if (field.second->findPatient(patientId) != nullptr)
                {
                    field.second->removePatient(patientId);
                    break;
                }
            }
            patientList[patientId]->setCurrentDoctor(nullptr);
            patientList.erase(patientId);
        }
        else
        {
            cout << "  \t       Invalid patientId" << endl;
            return;
        }
    }

    void addDepartment()
    {
        string name;
        cout << "  \t       Enter Department's Name                :";
        cin >> name;
        Department *department = new Department(name);
        departmentList.push_back(department);
    }

    Department *findDepartmentinHospital(int deptId)
    {
        for (auto itr : departmentList)
        {
            if (itr->getId() == deptId)
            {
                return itr;
            }
        }
        return nullptr;
    }

    int getDepartmentPos(int deptId)
    {
        int counter = 0;
        int indx = -1;
        for (auto itr : departmentList)
        {
            if (itr->getId() == deptId)
            {
                indx = counter;
                break;
            }
            counter++;
        }
        return indx;
    }

    void removeDepartmentFromHospital(int deptId)
    {
        Department *department = findDepartmentinHospital(deptId);
        if (department != nullptr)
        {

            for (auto itr : doctorList)
            {
                if (itr.second->getDepartment() == department->getName())
                {
                    removeDoctorFromHospital(itr.second->getId());
                }
            }
            departmentList.erase(departmentList.begin() + getDepartmentPos(deptId));
        }
        else
        {
            cout << "   \t   invalid department Id" << endl;
        }
    }

    void
    inputDocInfo()
    {

        string name, address, specialization, gender, department;
        int age;
        long int phoneNumber;
        cout << "\n\n";
        cout << "  \t       Enter Doctor's Name                :";
        cin >> name;
        cout << "  \t       Enter Doctor's Address             :";
        cin >> address;
        cout << "  \t       Enter Doctor's Gender              :";
        cin >> gender;
        cout << "  \t       Enter Doctor's Age                 :";
        cin >> age;
        cout << "  \t       Enter Doctor's Phone Number        :";
        cin >> phoneNumber;
        cout << "  \t       Enter Doctor's Specialization      :";
        cin >> specialization;
        cout << "  \t       Choose Doctor's Department         :";
        cout << endl;
        int counter = 0;
        int dept;
        if (departmentList.size() == 0)
        {
            cout << "\n  \t       No departments Exist" << endl;
            return;
        }
        for (auto field : departmentList)
        {
            cout << "  \t       " << counter << ".     " << field->getId() << "    " << field->getName() << endl;
            counter++;
        }
        cout << "\n  \t       Enter your choice                :  ";
        cin >> dept;
        if (dept >= counter)
        {
            cout << "invalid choice" << endl;
            return;
        }
        Doctor *doctor = new Doctor(name, address, gender, phoneNumber, age, departmentList[dept]->getName(), specialization);
        doctorList.insert(make_pair(doctor->getId(), doctor));
        departmentList[dept]->addDoctor(doctor);
        return;
    }

    void inputPatientInfo()
    {

        string name, address, gender;
        int docId;
        int age, roomNumber;
        long int phoneNumber;
        cout << "\n\n";
        cout << "  \t       Enter Patient's Name                :";
        cin >> name;
        cout << "  \t       Enter Patient's Address             :";
        cin >> address;
        cout << "  \t       Enter Patient's Gender              :";
        cin >> gender;
        cout << "  \t       Enter Patient's Age                 :";
        cin >> age;
        cout << "  \t       Enter Patient's Phone Number        :";
        cin >> phoneNumber;
        cout << "\n";

        cout << "  \t       List of All Doctor                  :";
        cout << endl;
        displayDetailAllDoctorInHospital();
        cout << "\n\n";
        cout << "  \t       Enter Patient's Doctor Id           :";
        cin >> docId;
        Doctor *doc = findDoctorInHospital(docId);
        if (doc != nullptr)
        {
            cout << "  \t       you have an appointment with " << doc->getName() << endl;
            roomNumber = uniqueRoomId;
            Patient *patient = new Patient(name, address, gender, phoneNumber, age, roomNumber);
            uniqueRoomId++;
            patientList.insert(make_pair(patient->getId(), patient));
            patient->setCurrentDoctor(doc);
            doc->addPatient(patient);
        }
        else
        {
            cout << "  \t       Invalid Doctor Id" << endl;
            cout << "\n";
        }

        return;
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
                menu();
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

    void menu()
    {

        int opt1, opt2, opt3, opt4;

        // system("cls");  \t
        while (true)
        {

            cout << "\n\n";
            cout << "  \t       1.   Enter  into Doctor's    DataBase   " << endl;
            cout << "  \t       2.   Enter  into Patient's   DataBase   " << endl;
            cout << "  \t       3.   Enter  into Department's Database  " << endl;
            cout << "  \t       4.   Generate    Patient's   Bill       " << endl;
            cout << "  \t       5.   EXIT                               "
                 << "\n\n\n";
            cout << "Please  Enter Your choice  :"
                 << " ";
            cin >> opt1;

            switch (opt1)
            {
            case 1:
            {
                printInstructionsForDoctor();

                cout << "Please Enter your choice :"
                     << " ";
                cin >> opt2;
                switch (opt2)
                {
                case 1:
                {
                    inputDocInfo();
                    break;
                }
                case 2:
                {

                    int docId;
                    cout << "  \t       Enter the doctor's ID you want to see.              " << endl;
                    cin >> docId;
                    Doctor *doc = findDoctorInHospital(docId);
                    if (doc == nullptr)
                    {
                        cout << "No Doctor found" << endl;
                        break;
                    }
                    doc->display();
                    cout << "\n";
                    break;
                }

                case 3:
                {
                    displayDetailAllDoctorInHospital();
                    break;
                }
                case 4:
                {
                    int docId;
                    cout << "\n  \t       Enter the doctor's ID you want to remove.              ";
                    cin >> docId;
                    if (findDoctorInHospital(docId) != nullptr)
                    {

                        removeDoctorFromHospital(docId);

                    }
                    else
                    {
                        cout << "Invalid Doc ID" << endl;
                    }
                    break;
                }
                case 5:
                {
                    menu();
                    break;
                }
                default:
                {
                    cout << "invalid choice" << endl;
                    break;
                }
                }
                break;
            }
            case 2:
            {
                printInstructionsForPatient();
                cout << "Please Enter your choice :"
                     << " ";
                cin >> opt3;
                switch (opt3)
                {
                case 1:
                {
                    inputPatientInfo();
                    break;
                }
                case 2:
                {
                    int patientId;
                    cout << "  \t       Enter the patient's ID you want to see.              " << endl;
                    cin >> patientId;
                    Patient *patient = findPatientInHospital(patientId);
                    if (patient == nullptr)
                    {
                        cout << "No Patient found" << endl;
                        break;
                    }
                    patient->display();
                    cout << "\n";
                    break;
                }
                case 3:
                {
                    displayDetailAllPatientInHospital();
                    break;
                }
                case 4:
                {
                    int patientId;
                    cout << "\n  \t       Enter the Patient's ID you want to remove.              ";
                    cin >> patientId;
                    if (findPatientInHospital(patientId) != nullptr)
                    {

                        removePatientFromHospital(patientId);
                    }
                    else
                    {
                        cout << "Invalid patient ID" << endl;
                    }
                    break;
                }
                case 5:
                {

                    menu();
                    break;
                }

                default:
                {
                    cout << "invalid choice" << endl;
                    break;
                }
                }
                break;
            }
            case 3:
            {
                printInstructionsForDepartment();
                cout << "Please Enter your choice :"
                     << " ";
                cin >> opt4;
                switch (opt4)
                {
                case 1:
                {

                    addDepartment();
                    break;
                }
                case 2:
                {
                    displayDetailAllDepartmentInHospital();
                    break;
                }
                case 3:
                {
                    int deptId;
                    cout << "\n  \t       Enter the Department ID you want to remove.              ";
                    cin >> deptId;
                    if (findDepartmentinHospital(deptId) != nullptr)
                    {

                        removeDepartmentFromHospital(deptId);
                    }
                    else
                    {
                        cout << "Invalid dept ID" << endl;
                    }
                    break;
                }
                case 4:
                {
                    menu();
                    break;
                }
                default:
                {
                    cout << "invalid choice" << endl;
                    break;
                }
                }
                break;
            }
            case 4:
            {
                int m;
                int id;
                cout << "\n  \t       Enter the Patient's Id               : ";
                cin >> id;
                cout << "\n  \t       Enter the number of days admitted    : ";
                cin >> m;
                Patient *p = findPatientInHospital(id);

                if (p == nullptr)
                {
                    cout << " Invalid patient Id" << endl;
                    break;
                }
                cout << "Id: " << p->getId() << endl;
                cout << "Name: " << p->getName() << endl;
                cout << "Address: " << p->getAddress() << endl;
                cout << "Total amount to be paid: " << 10000 * m;
                break;
            }
            case 5:
            {
                mainMenu();
                break;
            }
            default:
            {
                cout << "invalid choice" << endl;
                break;
            }
            }
        }
    }

    string
    getName()
    {
        return this->name;
    }
    void setName(string name)
    {
        this->name = name;
    }
    int getId()
    {
        return this->Id;
    }
    void setId(int Id) { this->Id = Id; }
};

Receptionist *Receptionist ::instance = nullptr;
int Receptionist ::uniqueRoomId = 900;

#endif