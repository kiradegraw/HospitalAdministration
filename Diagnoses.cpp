#include "Diagnoses.h"
#include <fstream>

using namespace std;

///read in all values
void readInDiagnoses(vector<diagnoses>& diagnosesVec){
    ifstream inFile;
    inFile.open("Diagnosis.txt");
    int numDiagnoses=0;
    string disease="";
    inFile >> numDiagnoses;
    diagnosesVec.resize(numDiagnoses);

    for (int i=0; i<numDiagnoses; ++i)
    {
        inFile >> disease;
        diagnosesVec[i].setID(i);
        diagnosesVec[i].setDiseaseName(disease);
    }
}

int diagnoses::getID(){
    return id;
}
string diagnoses::getDiseaseName(){
    return disease_name;
}
void diagnoses::setID(int in){
    id = in;
}
void diagnoses::setDiseaseName(string in){
    disease_name = in;
}
