#ifndef DOCTOR_H_INCLUDED
#define DOCTOR_H_INCLUDED
#include <iostream>
#include <vector>
#include <fstream>
#include "Appointment.h"

using namespace std;

class doctor{
    int id;
    string username;
    string password;
    string name;
    string phone;
    string skill;
public:
    doctor()
    {
        id = 0;
        username = "";
        password = "";
        name = "";
        phone = "";
        skill = "";
    }
    // doctor getters
    int getID();
    string getUsername();
    string getPassword();
    string getName();
    string getPhone();
    string getSkill();
    // doctor setters
    void setID(int inID);
    void setUsername(string inUsername);
    void setPassword(string inPassword);
    void setName(string inName);
    void setPhone(string inPhone);
    void setSkill(string inSkill);

    void print();
};

void readInDoctors(vector<doctor>& doctorVec);
void doctorMenu(vector<doctor>& doctorVec, vector<appointment> appointmentVec);
void printDoctors(vector<doctor> doctorVec);
void updateDoctor(vector<doctor>& doctorVec);
void deleteDoctor(vector<doctor>& doctorVec, vector<appointment> appointmentVec);
void searchDoctorByName(vector<doctor> doctorVec);

#endif // DOCTOR_H_INCLUDED
