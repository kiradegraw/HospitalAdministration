#ifndef PATIENT_H_INCLUDED
#define PATIENT_H_INCLUDED
#include <iostream>
#include <vector>

using namespace std;

class diagnoses;
class date_time;

class patient {
    int id;
    int doctor_id;
    int record_id;
    string name;
    string phone;
    char gender;
    string email;
    string blood_type;

public:
    patient ()
    {
        id = 0;
        doctor_id = 0;
        record_id = 0;
        name = "";
        phone = "";
        gender = 'z';
        email = "";
        blood_type = "";
    }
//getters
    int getID();
    int getDoctorID();
    int getRecordID();
    string getName();
    string getPhone();
    char getGender();
    string getEmail();
    string getBloodType();
//setters
    void setID(int inID);
    void setDoctorID(int inD_ID);
    void setRecordID(int inR_ID);
    void setName(string inName);
    void setPhone(string inPhone);
    void setGender(char inGender);
    void setEmail(string inEmail);
    void setBloodType(string inBlood);

    void print();
};

void readInPatients(vector<patient>& patientVector);

void patientMenu(vector<patient>& patientVector, vector<doctor> doctorVec, vector<date_time> dateTimeVec, vector<appointment> appointmentVec, vector<slot> slotVec, vector<diagnoses> diagnosesVec);
void addNewPatient(vector<patient>& patientVector);
void updatePatient(vector<patient>& patientVector);
void deletePatient(vector<patient>& patientVector);
void printPatients(vector<patient> patientVector, vector<doctor> doctorVec, vector<diagnoses> diagnosesVec, vector<appointment> appointmentVec); //not finished
void searchByNameOrEmail(vector<patient> patientVector, vector<doctor> doctorVec, vector<diagnoses> diagnosesVec, vector<appointment> appointmentVec); // not finished
void searchByDoctor(vector<patient> patientVector, vector<doctor> doctorVec); //not finished
void searchAppointmentsByTime(vector<patient> patientVector, vector<date_time> dateTimeVec, vector<appointment> appointmentVec, vector<slot> slotVec);





#endif // PATIENT_H_INCLUDED
