#include "Appointment.h"
#include "Record.h"

using namespace std;

/// main record menu
void recordMenu(vector<record>& recordVec, vector<appointment>& appointmentVec){
    cout << "1. Add new record" << endl;
    cout << "2. Update a record" << endl;
    cout << "3. Print all records" << endl;
    cout << "4. Go back" << endl;

    int choice=0;
    cin >> choice;
    if (choice == 1)
    {
        addNewRecord(recordVec);
    }
    else if (choice == 2)
    {
        updateRecord(recordVec, appointmentVec);
    }
    else if (choice == 3)
    {
        printAllRecords(recordVec);
    }
    else if (choice == 4)
    {
        return;
    }
}

// 1. add new record
void addNewRecord(vector<record>& recordVec){
    int id=0, p_id=0;
    string n="";

    cout << endl << "Record ID: ";
    cin >> id;
    cout << "Patient ID: ";
    cin >> p_id;
    cout << "Notes: ";
    cin >> n;

    //adds one to record vector
    recordVec.push_back(record());
    int vSize = recordVec.size();
    //sets new values
    recordVec[vSize-1].setID(id);
    recordVec[vSize-1].setPatientID(p_id);
    recordVec[vSize-1].setNotes(n);
}

// 2. update patient record
void updateRecord(vector<record>& recordVec, vector<appointment>& appointmentVec){
    int id=0;
    int pos=0, apptPos=0;
    int choice=0;

    //gets correct pos
    cout << "Please enter the ID of the record you would like to update: ";
    cin >> id;

    for (size_t i=0; i<recordVec.size(); ++i)
    {
        if (recordVec[i].getID() == id)
        {
            pos = i;
        }
    }

    cout << "What information would you like to update for this record?" << endl;
    cout << "1. ID" << endl;
    cout << "2. Patient ID" << endl;
    cout << "3. Notes" << endl;
    cout << "4. Diagnosis ID" << endl;
    cout << "5. Prescribed Medication" << endl;
    cin >> choice;

    cout << endl << "Please enter the new value: ";
    if (choice == 1)
    {
        int newValue;
        cin >> newValue;
        recordVec[pos].setID(newValue);
    }
    else if (choice == 2)
    {
        int newValue;
        cin >> newValue;
        recordVec[pos].setPatientID(newValue);
    }
    else if (choice == 3)
    {
        string newValue;
        cin >> newValue;
        recordVec[pos].setNotes(newValue);
    }
    else if (choice == 4)
    {
        //sets new value in appointment vector
        for (size_t j=0; j<appointmentVec.size(); ++j)
        {
            if (appointmentVec[j].getPatientID() == recordVec[pos].getPatientID())
            {
                apptPos = j;
            }
        }
        int newValue;
        cin >> newValue;
        appointmentVec[apptPos].setDiagnosisID(newValue);
    }
    else if (choice == 5)
    {
        //sets the new value in the appointment vector
        for (size_t j=0; j<appointmentVec.size(); ++j)
        {
            if (appointmentVec[j].getPatientID() == recordVec[pos].getPatientID())
            {
                apptPos = j;
            }
        }
        string newValue;
        cin >> newValue;
        appointmentVec[apptPos].setPrescribedMedication(newValue);
    }
}

// 3. show all records
void printAllRecords(vector<record> recordVec){
    for (size_t i=0; i<recordVec.size(); ++i)
    {
        recordVec[i].print();
    }
}

void record::print()
{
    cout << endl << "ID: " << getID() << endl;
    cout << "Patient ID: " << getPatientID() << endl;
    cout << "Notes: " << getNotes() << endl << endl;
}

int record::getID(){
    return id;
}
int record::getPatientID(){
    return patient_id;
}
string record::getNotes(){
    return notes;
}
void record::setID(int in){
    id = in;
}
void record::setPatientID(int in){
    patient_id = in;
}
void record::setNotes(string in){
    notes = in;
}
