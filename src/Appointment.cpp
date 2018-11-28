#include "Doctor.h"
#include "Patient.h"
#include "Date_Time.h"
#include "Slot.h"
#include "Appointment.h"

/// appointment menu
void appointmentMenu(vector<appointment>& appointmentVec, vector<slot>& slotVec, vector<doctor> doctorVec, vector<patient> patientVector){
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
        searchApptsByPatient(appointmentVec, patientVector);
    }
    else if (choice == 3)
    {
        updateAppointment(appointmentVec, slotVec);
    }
    else if (choice == 4)
    {
        addNewAppointment(appointmentVec, slotVec);
    }
    else if (choice == 5)
    {
        cancelAppointment(appointmentVec, slotVec);
    }
    else if (choice == 6)
    {
        return;
    }
}


// 1. Search appointments by doctor
void searchApptsByDoctor(vector<appointment> appointmentVec, vector<doctor> doctorVec){
    string name="";
    int id=0;

    //gets ID of appropriate doctor
    cout << "Enter the Doctor's name: ";
    cin >> name;
    for (size_t j=0; j<doctorVec.size(); ++j)
    {
        if (doctorVec[j].getName() == name)
        {
            id = doctorVec[j].getID();
        }
    }

    // gets all appointments associated to the doctor id
    for (size_t i=0; i<appointmentVec.size(); ++i)
    {
        if (appointmentVec[i].getDoctorID() == id)
        {
            cout << endl << "Doctor " << name << "'s Appointments:" << endl;
            appointmentVec[i].print();
        }
    }
}

// 2. Search appointments by patient
void searchApptsByPatient(vector<appointment> appointmentVec, vector<patient> patientVector){
    int id=0, choice=0;
    string name="", email="";

    cout << endl << "Would you like to search by the patient's name or email?" << endl;
    cout << "1. Name" << endl;
    cout << "2. Email" << endl;
    cin >> choice;

    if (choice == 1)
    {
        //searches for the correct patient id
        cout << "Enter the Patient's name: ";
        cin >> name;
        for (size_t j=0; j<patientVector.size(); ++j)
        {
            if (patientVector[j].getName() == name)
            {
                id = patientVector[j].getID();
            }
        }
    }
    else if (choice == 2)
    {
        //searches for the correct patient id
        cout << "Enter the Patient's email: ";
        cin >> email;
        for (size_t j=0; j<patientVector.size(); ++j)
        {
            if (patientVector[j].getEmail() == email)
            {
                name = patientVector[j].getName();
                id = patientVector[j].getID();
            }
        }
    }

    // lists all appointments associated with the patient id
    for (size_t i=0; i<appointmentVec.size(); ++i)
    {
        if (appointmentVec[i].getPatientID() == id)
        {
            cout << endl << "Patient " << name << "'s Appointments:" << endl;
            appointmentVec[i].print();
        }
    }
}

// 3. update appointment
void updateAppointment(vector<appointment>& appointmentVec, vector<slot>& slotVec){
    int id=0;
    int pos=0;
    int choice=0;
    char cont='N';

    // finds the pos of the appointment to be updated
    cout << "Please enter the ID of the appointment you would like to update: ";
    cin >> id;

    for (size_t i=0; i<appointmentVec.size(); ++i)
    {
        if (appointmentVec[i].getID() == id)
        {
            pos = i;
        }
    }
    do
    {
        // menu for updating appointment choices
    cout << endl << "What information would you like to update for this appointment?" << endl;
    cout << "1. Appointment ID" << endl;
    cout << "2. Doctor ID" << endl;
    cout << "3. Patient ID" << endl;
    cout << "4. Slot ID" << endl;
    cout << "5. Reason" << endl;
    cout << "6. Diagnosis ID" << endl;
    cout << "7. Prescribed Medication" << endl;
    cin >> choice;

    if (choice == 1)
    {
        cout << "Current ID: " << appointmentVec[pos].getID() << endl;
        cout << endl << "Please enter the new ID: ";
        int newValue;
        cin >> newValue;
        appointmentVec[pos].setID(newValue);
        cout << "New ID: " << appointmentVec[pos].getID() << endl;
    }
    else if (choice == 2)
    {
        cout << "Current Doctor ID: " << appointmentVec[pos].getDoctorID() << endl;
        cout << endl << "Please enter the new doctor ID: ";
        int newValue;
        cin >> newValue;
        appointmentVec[pos].setDoctorID(newValue);
        cout << "New Doctor ID: " << appointmentVec[pos].getDoctorID() << endl;
    }
    else if (choice == 3)
    {
        cout << "Current Patient ID: " << appointmentVec[pos].getPatientID() << endl;
        cout << endl << "Please enter the new patient ID: ";
        int newValue;
        cin >> newValue;
        appointmentVec[pos].setPatientID(newValue);
        cout << "New Patient ID: " << appointmentVec[pos].getPatientID() << endl;
    }
    else if (choice == 4)
    {
        int currentValue = appointmentVec[pos].getSlotID();
        cout << "Current Slot ID: " << currentValue << endl;
        cout << endl << "Please enter the new slot ID: ";
        int newValue;
        cin >> newValue;
        appointmentVec[pos].setSlotID(newValue);

        for (size_t i=0; i<slotVec.size(); ++i)
        {
            if (currentValue == slotVec[i].getID())
            {
                slotVec[i].setAvailability(1);
            }
            else if (newValue == slotVec[i].getID())
            {
                slotVec[i].setAvailability(0);
            }
        }

        cout << "New Slot ID: " << appointmentVec[pos].getSlotID() << endl;
    }
    else if (choice == 5)
    {
        cout << "Current Reason: " << appointmentVec[pos].getReason() << endl;
        cout << endl << "Please enter the new reason: ";
        string newValue;
        cin >> newValue;
        appointmentVec[pos].setReason(newValue);
        cout << "New Reason: " << appointmentVec[pos].getReason() << endl;
    }
    else if (choice == 6)
    {
        cout << "Current Diagnosis ID: " << appointmentVec[pos].getDiagnosisID() << endl;
        cout << endl << "Please enter the new diagnosis ID: ";
        int newValue;
        cin >> newValue;
        appointmentVec[pos].setDiagnosisID(newValue);
        cout << "New Diagnosis ID: " << appointmentVec[pos].getDiagnosisID() << endl;
    }
    else if (choice == 7)
    {
        cout << "Current Prescribed Medication: " << appointmentVec[pos].getPrescribedMedication() << endl;
        cout << endl << "Please enter the new prescribed medication: ";
        string newValue;
        cin >> newValue;
        appointmentVec[pos].setPrescribedMedication(newValue);
        cout << "New Prescribed Medication: " << appointmentVec[pos].getPrescribedMedication() << endl;
    }
    cout << endl << endl << "Would you like to continue updating? (Y/N): ";
    cin >> cont;
    }
    // do while the user still wants to update
    while (cont=='Y');
}

//4. add new appointment
void addNewAppointment(vector<appointment>& appointmentVec, vector<slot>& slotVec){
    int id=0, d_id=0, p_id=0, s_id=0, diag_id=0;
    string reason="", med="";
    bool allowed=0;

    cout << "What is the appointment ID? ";
    cin >> id;
    cout << "What is the doctor ID? ";
    cin >> d_id;
    cout << "What is the patient ID? ";
    cin >> p_id;

    //checks for available slot id, loops until user selects a valid slot
    do
    {
        cout << "What is the slot ID?  ";
        cin >> s_id;

        for (size_t j=0; j<slotVec.size(); ++j)
        {
            if (slotVec[j].getID() == s_id)
            {
                if (slotVec[j].getAvailability() == 0)
                {
                    cout << "Slot not available" << endl << endl;
                    allowed=0;
                }
                else
                {
                    allowed=1;
                }
            }
        }
    }
    while (allowed==0);

    cout << "What is the appointment reason? ";
    cin >> reason;
    // msg for user to update appt after it has concluded
    cout << endl << "Please choose 'update appointment' to add the diagnosis ID and prescribed "
        << "medication after the appointment." << endl << endl;

    // add one to end of appt vector
    appointmentVec.push_back(appointment());
    int vSize = appointmentVec.size();
    //sets all new values
    appointmentVec[vSize-1].setID(id);
    appointmentVec[vSize-1].setDoctorID(d_id);
    appointmentVec[vSize-1].setPatientID(p_id);
    appointmentVec[vSize-1].setSlotID(s_id);
    appointmentVec[vSize-1].setReason(reason);
    appointmentVec[vSize-1].setDiagnosisID(diag_id);
    appointmentVec[vSize-1].setPrescribedMedication(med);

    //sets availability to 0
    for (size_t i=0; i<slotVec.size(); ++i)
    {
        if (s_id == slotVec[i].getID())
        {
            slotVec[i].setAvailability(0);
        }
    }
}

// 5. cancel appointment
void cancelAppointment(vector<appointment>& appointmentVec, vector<slot>& slotVec){
    int id=0, s_id=0, pos=0;
    cout << "Please enter the ID of the appointment you would like to cancel: ";
    cin >> id;

    //gets the correct pos for the appointment
    for (size_t i=0; i<appointmentVec.size(); ++i)
    {
        if (appointmentVec[i].getID() == id)
        {
            pos = i;
            s_id = appointmentVec[i].getSlotID();
        }
    }
    appointmentVec.erase(appointmentVec.begin()+ pos); // erases appt

    //sets availability to 1
    for (size_t j=0; j<slotVec.size(); ++j)
    {
        if (s_id == slotVec[j].getID())
        {
            slotVec[j].setAvailability(1);
            cout << endl << "Appointment canceled. Slot now available." << endl << endl;
        }
    }
}

void appointment::print(){
    cout << endl;
    cout << "ID: " << getID() << endl;
    cout << "Doctor ID: " << getDoctorID() << endl;
    cout << "Patient ID: " << getPatientID() << endl;
    cout << "Slot ID: " << getSlotID() << endl;
    cout << "Reason: " << getReason() << endl;
    cout << "Diagnosis ID: " << getDiagnosisID() << endl;
    cout << "Prescribed Medication: " << getPrescribedMedication() << endl << endl;
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
