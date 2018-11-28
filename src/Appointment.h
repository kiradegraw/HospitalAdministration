#ifndef APPOINTMENT_H_INCLUDED
#define APPOINTMENT_H_INCLUDED
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class slot;
class doctor;
class patient;

class appointment {
    int id;
    int doctor_id;
    int patient_id;
    int slot_id;
    string reason;
    int diagnosis_id;
    string prescribed_medication;
public:
    appointment()
    {
        id = 0;
        doctor_id = 0;
        patient_id = 0;
        slot_id = 0;
        reason = "";
        diagnosis_id = 0;
        prescribed_medication = "";
    }
    //get functions
    int getID();
    int getDoctorID();
    int getPatientID();
    int getSlotID();
    string getReason();
    int getDiagnosisID();
    string getPrescribedMedication();
    //set functions
    void setID(int inID);
    void setDoctorID(int inDoctorID);
    void setPatientID(int inPatientID);
    void setSlotID(int inSlotID);
    void setReason(string inReason);
    void setDiagnosisID(int inDiagnosisID);
    void setPrescribedMedication(string inMedication);

    void print();
};

void appointmentMenu(vector<appointment>& appointmentVec, vector<slot>& slotVec, vector<doctor> doctorVec, vector<patient> patientVector);
void addNewAppointment(vector<appointment>& appointmentVec, vector<slot>& slotVec);
void updateAppointment(vector<appointment>& appointmentVec, vector<slot>& slotVec);
void searchApptsByDoctor(vector<appointment> appointmentVec, vector<doctor> doctorVec);
void searchApptsByPatient(vector<appointment> appointmentVec, vector<patient> patientVector);
void cancelAppointment(vector<appointment>& appointmentVec, vector<slot>& slotVec);

#endif // APPOINTMENT_H_INCLUDED
