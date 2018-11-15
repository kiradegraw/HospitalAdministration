#ifndef RECORD_H_INCLUDED
#define RECORD_H_INCLUDED
#include <iostream>
#include <vector>

using namespace std;

class patient;

class record {
    int id;
    int patient_id;
    string notes;

public:
    record()
    {
        id = 0;
        patient_id = 0;
        notes = "";
    }
    //get functions
    int getID();
    int getPatientID();
    string getNotes();
//set functions
    void setID(int in);
    void setPatientID(int in);
    void setNotes(string in);

    void print();
};

void recordMenu(vector<record>& recordVec, vector<appointment>& appointmentVec);
void addNewRecord(vector<record>& recordVec);
void updateRecord(vector<record>& recordVec, vector<appointment>& appointmentVec);
void printAllRecords(vector<record> recordVec);

#endif // RECORD_H_INCLUDED
