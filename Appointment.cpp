#include "Doctor.h"
#include "Appointment.h"
#include <iostream>
#include <vector>
#include <fstream>


using namespace std;

void appointmentMenu(vector<appointment>& appointmentVec, vector<doctor> doctorVec){
    cout << "1. Show all appointments for a doctor" << endl;
    cout << "2. Show all appointments for a patient" << endl;
    cout << "3. Update an appointment" << endl;
    cout << "4. Book a new appointment" << endl;
    cout << "5. Cancel an appointment" << endl;
    cout << "6. Go back" << endl;

    int choice=0;
    cin >> choice;
    if (choice == 1)
    {
        searchApptsByDoctor(appointmentVec, doctorVec);
    }
    else if (choice == 2)
    {
        // appts for patient
    }
    else if (choice == 3)
    {
        updateAppointment(appointmentVec);
    }
    else if (choice == 4)
    {
        addNewAppointment(appointmentVec);
    }
    else if (choice == 5)
    {
        //cancel appt
    }
    else if (choice == 6)
    {

    }

}

// 4. Search appointments
void searchApptsByDoctor(vector<appointment> appointmentVec, vector<doctor> doctorVec){
    int pos=0;
    int id=0;

    cout << "Enter the Doctor's ID: ";
    cin >> id;
    for (int i=0; i<appointmentVec.size(); ++i)
    {
        if (appointmentVec[i].getID() == id)
        {
            appointmentVec[i].print();
        }
    }
}

void appointment::print(){
    cout << endl << getID() << endl;
    cout << getDoctorID() << endl;
    cout << getPatientID() << endl;
    cout << getSlotID() << endl;
    cout << getReason() << endl;
    cout << getDiagnosisID() << endl;
    cout << getPrescribedMedication() << endl << endl;
}


//4. add new appointment
void addNewAppointment(vector<appointment>& appointmentVec){
    int id=0, d_id=0, p_id=0, s_id=0, diag_id=0;
    string reason="", med="";

    cout << "What is the doctor ID? ";
    cin >> d_id;
    cout << "What is the patient ID? ";
    cin >> p_id;
    cout << "What is the slot ID? ";
    cin >> s_id;
    cout << "What is the appointment reason? ";
    cin >> reason;
    cout << endl << "Please choose 'update appointment' to add the diagnosis ID and prescribed "
        << "medication after the appointment." << endl;

    appointmentVec.push_back(appointment());
    int vSize = appointmentVec.size();
    id = vSize;

    appointmentVec[vSize-1].setID(id);
    appointmentVec[vSize-1].setDoctorID(d_id);
    appointmentVec[vSize-1].setPatientID(p_id);
    appointmentVec[vSize-1].setSlotID(s_id);
    appointmentVec[vSize-1].setReason(reason);
    appointmentVec[vSize-1].setDiagnosisID(diag_id);
    appointmentVec[vSize-1].setPrescribedMedication(med);
}

// 3. update appointment
void updateAppointment(vector<appointment>& appointmentVec){
    int id=0;
    int pos=0;
    int choice=0;
    char cont='N';

    cout << "Please enter the ID of the appointment you would like to update: ";
    cin >> id;

    for (int i=0; i<appointmentVec.size(); ++i)
    {
        if (appointmentVec[i].getID() == id)
        {
            pos = i;
        }
    }
    do
    {
    cout << endl << "What information would you like to update for this appointment?" << endl;
    cout << "1. Doctor ID" << endl;
    cout << "2. Patient ID" << endl;
    cout << "3. Slot ID" << endl;
    cout << "4. Reason" << endl;
    cout << "5. Diagnosis ID" << endl;
    cout << "6. Prescribed Medication" << endl;
    cin >> choice;


    if (choice == 1)
    {
        cout << "Current Doctor ID: " << appointmentVec[pos].getDoctorID() << endl;
        cout << endl << "Please enter the new value: ";
        int newValue;
        cin >> newValue;
        appointmentVec[pos].setDoctorID(newValue);
        cout << "New Doctor ID: " << appointmentVec[pos].getDoctorID() << endl;
    }
    else if (choice == 2)
    {
        cout << "Current Patient ID: " << appointmentVec[pos].getPatientID() << endl;
        cout << endl << "Please enter the new value: ";
        int newValue;
        cin >> newValue;
        appointmentVec[pos].setPatientID(newValue);
        cout << "New Patient ID: " << appointmentVec[pos].getPatientID() << endl;
    }
    else if (choice == 3)
    {
        cout << "Current Slot ID: " << appointmentVec[pos].getSlotID() << endl;
        cout << endl << "Please enter the new value: ";
        int newValue;
        cin >> newValue;
        appointmentVec[pos].setSlotID(newValue);
        cout << "New Slot ID: " << appointmentVec[pos].getSlotID() << endl;
    }
    else if (choice == 4)
    {
        cout << "Current Reason: " << appointmentVec[pos].getReason() << endl;
        cout << endl << "Please enter the new value: ";
        string newValue;
        cin >> newValue;
        appointmentVec[pos].setReason(newValue);
        cout << "New Reason: " << appointmentVec[pos].getReason() << endl;
    }
    else if (choice == 5)
    {
        cout << "Current Diagnosis ID: " << appointmentVec[pos].getDiagnosisID() << endl;
        cout << endl << "Please enter the new value: ";
        int newValue;
        cin >> newValue;
        appointmentVec[pos].setDiagnosisID(newValue);
        cout << "New Reason: " << appointmentVec[pos].getDiagnosisID() << endl;
    }
    else if (choice == 6)
    {
        cout << "Current Prescribed Medication: " << appointmentVec[pos].getPrescribedMedication() << endl;
        cout << endl << "Please enter the new value: ";
        string newValue;
        cin >> newValue;
        appointmentVec[pos].setPrescribedMedication(newValue);
        cout << "New Prescribed Medication: " << appointmentVec[pos].getPrescribedMedication() << endl;
    }
    cout << endl << endl << "Would you like to continue updating? (Y/N): ";
    cin >> cont;
    }
    while (cont=='Y');

}


int appointment::getID(){
    return id;
}

int appointment::getDoctorID(){
    return doctor_id;
}

int appointment::getPatientID(){
    return patient_id;
}

int appointment::getSlotID(){
    return slot_id;
}

string appointment::getReason(){
    return reason;
}

int appointment::getDiagnosisID(){
    return diagnosis_id;
}

string appointment::getPrescribedMedication(){
    return prescribed_medication;
}

void appointment::setID(int inID){
    id = inID;
}

void appointment::setDoctorID(int inDoctorID){
    doctor_id = inDoctorID;
}

void appointment::setPatientID(int inPatientID){
    patient_id = inPatientID;
}

void appointment::setSlotID(int inSlotID){
    slot_id = inSlotID;
}

void appointment::setReason(string inReason){
    reason = inReason;
}

void appointment::setDiagnosisID(int inDiagnosisID){
    diagnosis_id = inDiagnosisID;
}
void appointment::setPrescribedMedication(string inMedication){
    prescribed_medication = inMedication;
}
