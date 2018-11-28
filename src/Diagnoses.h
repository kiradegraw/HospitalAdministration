#ifndef DIAGNOSES_H_INCLUDED
#define DIAGNOSES_H_INCLUDED
#include <vector>
#include <iostream>

using namespace std;

class diagnoses {
    int id;
    string disease_name;

public:
    diagnoses()
    {
        id = 0;
        disease_name= "";
    }
    //get functions
    int getID();
    string getDiseaseName();
//set functions
    void setID(int in);
    void setDiseaseName(string in);

};

void readInDiagnoses(vector<diagnoses>& diagnosesVec);

#endif // DIAGNOSES_H_INCLUDED
