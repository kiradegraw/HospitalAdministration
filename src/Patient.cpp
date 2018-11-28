#include "Diagnoses.h"
#include "Doctor.h"
#include "Date_Time.h"
#include "Slot.h"
#include "Appointment.h"
#include "Patient.h"

using namespace std;

///read in all values
void readInPatients(vector<patient>& patientVector){
    ifstream inFile;
    inFile.open("Patients.txt");
    int numPatients=0;
    int id=0, d_id=0, r_id=0;
    string phone="", name="", email="", blood="";
    char gender='z';
    inFile >> numPatients;
    patientVector.resize(numPatients);

    for (int i=0; i<numPatients; ++i)
    {
        inFile >> id >> d_id >> r_id >> name >> phone >> gender >> email >> blood;
        patientVector[i].setID(id);
        patientVector[i].setDoctorID(d_id);
        patientVector[i].setRecordID(r_id);
        patientVector[i].setName(name);
        patientVector[i].setPhone(phone);
        patientVector[i].setGender(gender);
        patientVector[i].setEmail(email);
        patientVector[i].setBloodType(blood);
    }
}

/// main patient menu
void patientMenu(vector<patient>& patientVector, vector<doctor> doctorVec, vector<date_time> dateTimeVec, vector<appointment> appointmentVec, vector<slot> slotVec, vector<diagnoses> diagnosesVec){
    cout << "1. Add Patient" << endl;
    cout << "2. Update Patient's info" << endl;
    cout << "3. Delete Patient" << endl;
    cout << "4. View all Patients" << endl;
    cout << "5. Search for a patient by name/email" << endl;
    cout << "6. Search for a patient by doctor's name" << endl;
    cout << "7. Show patient's appointment by time range" << endl;
    cout << "8. Go back" << endl;

    int choice=0;
    cin >> choice;
    if (choice == 1)
    {
        addNewPatient(patientVector);
    }
    else if (choice == 2)
    {
        updatePatient(patientVector);
    }
    else if (choice == 3)
    {
        deletePatient(patientVector);
    }
    else if (choice == 4)
    {
        printPatients(patientVector, doctorVec, diagnosesVec, appointmentVec);
    }
    else if (choice == 5)
    {
        searchByNameOrEmail(patientVector, doctorVec, diagnosesVec, appointmentVec);
    }
    else if (choice == 6)
    {
        searchByDoctor(patientVector, doctorVec);
    }
    else if (choice == 7)
    {
        searchAppointmentsByTime(patientVector, dateTimeVec, appointmentVec, slotVec);
    }
    else if (choice == 8)
    {
        return;
    }
}

// 1. add new patient
void addNewPatient(vector<patient>& patientVector){
    int id=0, d_id=0, r_id=0;
    string name="", phone="", email="", bloodType="";
    char gender='z';

    //user inputs new values
    cout << endl << "What is the patient's ID? ";
    cin >> id;
    cout << "What is the patient's Doctor ID? ";
    cin >> d_id;
    cout << "What is the patient's Record ID? ";
    cin >> r_id;
    cout << "What is the patient's name? ";
    cin >> name;
    cout << "What is the patient's phone number? ";
    cin >> phone;
    cout << "What is the patient's gender? (m/f) ";
    cin >> gender;
    cout << "What is the patient's email? ";
    cin >> email;
    cout << "What is the patient's blood type? ";
    cin >> bloodType;

    //increases vector
    patientVector.push_back(patient());
    int vSize = patientVector.size();

    //sets all new values for patient
    patientVector[vSize-1].setID(id);
    patientVector[vSize-1].setDoctorID(d_id);
    patientVector[vSize-1].setRecordID(r_id);
    patientVector[vSize-1].setName(name);
    patientVector[vSize-1].setPhone(phone);
    patientVector[vSize-1].setGender(gender);
    patientVector[vSize-1].setEmail(email);
    patientVector[vSize-1].setBloodType(bloodType);
    cout << endl << "Patient Added" << endl << endl;
}
// 2. update patient
void updatePatient(vector<patient>& patientVector){
    int id=0;
    int pos=0;
    int choice=0;
    char cont='N';

    cout << "Please enter the ID of the patient you would like to update: ";
    cin >> id;

    for (size_t i=0; i<patientVector.size(); ++i)
    {
        if (patientVector[i].getID() == id)
        {
            pos = i;
        }
    }
    do
    {
    cout << "What information would you like to update for this patient?" << endl;
    cout << "1. ID" << endl;
    cout << "2. Doctor ID" << endl;
    cout << "3. Record ID" << endl;
    cout << "4. Name" << endl;
    cout << "5. Phone Number" << endl;
    cout << "6. Gender" << endl;
    cout << "7. Email" << endl;
    cout << "8. Blood Type" << endl;
    cin >> choice;

    if (choice == 1)
    {
        cout << "Current ID: " << patientVector[pos].getID() << endl;
        cout << endl << "Please enter the new ID: ";
        int newValue;
        cin >> newValue;
        patientVector[pos].setID(newValue);
        cout << "New ID: " << patientVector[pos].getID() << endl;
    }
    else if (choice == 2)
    {
        cout << "Current Doctor ID: " << patientVector[pos].getDoctorID() << endl;
        cout << endl << "Please enter the new doctor ID: ";
        int newValue;
        cin >> newValue;
        patientVector[pos].setDoctorID(newValue);
        cout << "New Doctor ID: " << patientVector[pos].getDoctorID() << endl;
    }
    else if (choice == 3)
    {
        cout << "Current Record ID: " << patientVector[pos].getRecordID() << endl;
        cout << endl << "Please enter the new record ID: ";
        int newValue;
        cin >> newValue;
        patientVector[pos].setRecordID(newValue);
        cout << "New Record ID: " << patientVector[pos].getRecordID() << endl;
    }
    else if (choice == 4)
    {
        cout << "Current Name: " << patientVector[pos].getName() << endl;
        cout << endl << "Please enter the new name: ";
        string newValue;
        cin >> newValue;
        patientVector[pos].setName(newValue);
        cout << "New Name: " << patientVector[pos].getName() << endl;
    }
    else if (choice == 5)
    {
        cout << "Current Phone Number: " << patientVector[pos].getPhone() << endl;
        cout << endl << "Please enter the new phone number: ";
        string newValue;
        cin >> newValue;
        patientVector[pos].setPhone(newValue);
        cout << "New Phone Number: " << patientVector[pos].getPhone() << endl;
    }
    else if (choice == 6)
    {
        cout << "Current Gender: " << patientVector[pos].getGender() << endl;
        cout << endl << "Please enter the updated gender: ";
        char newValue;
        cin >> newValue;
        patientVector[pos].setGender(newValue);
        cout << "New Gender: " << patientVector[pos].getGender() << endl;
    }
    else if (choice == 7)
    {
        cout << "Current Email: " << patientVector[pos].getEmail() << endl;
        cout << endl << "Please enter the updated Email: ";
        string newValue;
        cin >> newValue;
        patientVector[pos].setEmail(newValue);
        cout << "New Email: " << patientVector[pos].getEmail() << endl;
    }
    else if (choice == 8)
    {
        cout << "Current Blood Type: " << patientVector[pos].getBloodType() << endl;
        cout << endl << "Please enter the updated Blood Type: ";
        string newValue;
        cin >> newValue;
        patientVector[pos].setBloodType(newValue);
        cout << "New Blood Type: " << patientVector[pos].getBloodType() << endl;
    }
    cout << endl << endl << "Would you like to continue updating? (Y/N): ";
    cin >> cont;
    }
    while (cont=='Y');
    //loops until user says N

    cout << endl << "Patient Updated" << endl << endl;
}

// 3. delete patient
void deletePatient(vector<patient>& patientVector){
    int id=0;
    int pos=0;
    cout << "Please enter the ID of the patient you would like to delete: ";
    cin >> id;

    //gets pos
    for (size_t i=0; i<patientVector.size(); ++i)
    {
        if (patientVector[i].getID() == id)
        {
            pos = i;
        }
    }
    //erases
    patientVector.erase(patientVector.begin()+ pos);
    cout << endl << "Patient Deleted" << endl << endl;
}

// 4. view all patients
void printPatients(vector<patient> patientVector, vector<doctor> doctorVec, vector<diagnoses> diagnosesVec, vector<appointment> appointmentVec){
    int d_id=0;
    for (size_t i=0; i<patientVector.size(); i++)
    {
        //gets doctor name
        cout << endl << "ID: " << patientVector[i].getID() << endl;
        d_id = patientVector[i].getDoctorID();
        for (size_t j=0; j<doctorVec.size(); j++)
        {
            if (d_id == doctorVec[j].getID())
                cout << "Doctor Name: " << doctorVec[j].getName()<< endl;
        }
        if (appointmentVec.size()!=0)
        {
        for (size_t k=0; k<appointmentVec.size(); k++)
        {
            if (patientVector[i].getID() == appointmentVec[k].getPatientID())
            {
                if (appointmentVec[k].getDiagnosisID() != 0)
                {
                    int diag = appointmentVec[k].getDiagnosisID();
                    cout << "Diagnosis: ";
                    //gets diagnosis
                    for (size_t a=0; a<diagnosesVec.size(); a++)
                    {
                        if (diagnosesVec[a].getID() == diag)
                        {
                            cout << diagnosesVec[a].getDiseaseName() << endl;
                        }
                    }
                }
                else
                {
                    cout << "Diagnosis not determined yet" << endl;
                }
            }
        }
        }
        else
        {
            cout << "Diagnosis not determined yet" << endl;
        }
        cout << "Record ID: " << patientVector[i].getRecordID() << endl;
        cout << "Name: " << patientVector[i].getName() << endl;
        cout << "Phone: " << patientVector[i].getPhone() << endl;
        cout << "Gender: " << patientVector[i].getGender() << endl;
        cout << "Email: " << patientVector[i].getEmail() << endl;
        cout << "Blood Type: " << patientVector[i].getBloodType() << endl << endl;
    }
}

// 5. search for patient by name/email
void searchByNameOrEmail(vector<patient> patientVector, vector<doctor> doctorVec, vector<diagnoses> diagnosesVec, vector<appointment> appointmentVec){
    int choice=0;
    int pos=0;
    cout << "What would you like to search by?" << endl;
    cout << "1. Search by Name" << endl;
    cout << "2. Search by Email" << endl;
    cin >> choice;

    //gets pos patient from name/email
    if (choice==1)
    {
        string name="";
        cout << "Enter the Patient's Name: ";
        cin >> name;
        for (size_t i=0; i<patientVector.size(); ++i)
        {
            if (patientVector[i].getName() == name)
            {
                pos = i;
            }
        }
    }
    if (choice==2)
    {
        string email="";
        cout << "Enter the Patient's Email: ";
        cin >> email;
        for (size_t i=0; i<patientVector.size(); ++i)
        {
            if (patientVector[i].getEmail() == email)
            {
                pos = i;
            }
        }
    }
    int d_id=0;
    cout << endl << "ID: " << patientVector[pos].getID() << endl;
    d_id = patientVector[pos].getDoctorID();
    //gets doctor name
    for (size_t j=0; j<doctorVec.size(); j++)
    {
        if (d_id == doctorVec[j].getID())
            cout << "Doctor Name: " << doctorVec[j].getName()<< endl;
    }
    if (appointmentVec.size()!=0)
    {
    for (size_t k=0; k<appointmentVec.size(); k++)
    {
        if (patientVector[pos].getID() == appointmentVec[k].getPatientID())
        {
            if (appointmentVec[k].getDiagnosisID() != 0)
            {
                int diag = appointmentVec[k].getDiagnosisID();
                cout << "Diagnosis: ";
                //gets diagnosis
                for (size_t a=0; a<diagnosesVec.size(); a++)
                {
                    if (diagnosesVec[a].getID() == diag)
                    {
                        cout << diagnosesVec[a].getDiseaseName() << endl;
                    }
                }
            }
            else
            {
                cout << "Diagnosis not determined yet" << endl;
            }
        }
    }
    }
    else
    {
        cout << "Diagnosis not determined yet" << endl;
    }
    cout << "Record ID: " << patientVector[pos].getRecordID() << endl;
    cout << "Name: " << patientVector[pos].getName() << endl;
    cout << "Phone: " << patientVector[pos].getPhone() << endl;
    cout << "Gender: " << patientVector[pos].getGender() << endl;
    cout << "Email: " << patientVector[pos].getEmail() << endl;
    cout << "Blood Type: " << patientVector[pos].getBloodType() << endl << endl;
}

// 6. search for patient by doctor
void searchByDoctor(vector<patient> patientVector, vector<doctor> doctorVec){
    int id=0;
    string name="";

    cout << "Enter the Doctor's name: ";
    cin >> name;
    //prints patient by appropriate doctor
    for (size_t j=0; j<doctorVec.size(); ++j)
    {
        if (doctorVec[j].getName() == name)
        {
            id = doctorVec[j].getID();
            for (size_t i=0; i<patientVector.size(); ++i)
            {
                if (patientVector[i].getDoctorID() == id)
                {
                    patientVector[i].print();
                }
            }
        }
    }
}

// 7. Search patient appointments by time
void searchAppointmentsByTime(vector<patient> patientVector, vector<date_time> dateTimeVec, vector<appointment> appointmentVec, vector<slot> slotVec){
    int date=0;
    int d1=0,d2=0,m1=0,m2=0,y1=0,y2=0;
    int h1=0,h2=0, min1=0,min2=0;
    char symbol='z', amPm1='z', amPm2='z';

    date_time dt1;
    date_time dt2;

    //user enters 2 date/times
    cout << "Search patient appointments by time range" << endl << endl;
    cout << "Enter the first date: (mm/dd/yyyy hours:minutes 'a' for AM, 'p' for PM)" << endl;
    cin >> m1 >> symbol >> d1 >> symbol >> y1 >> h1 >> symbol >> min1 >> amPm1;

    cout << endl << "Enter the second date: (mm/dd/yyyy hours:minutes 'a' for AM, 'p' for PM)" << endl;
    cin >> m2 >> symbol >> d2 >> symbol >> y2 >> h2 >> symbol >> min2 >> amPm2;

    //create two new date time objects
    dt1.setDay(d1);
    dt1.setMonth(m1);
    dt1.setYear(y1);
    dt1.setHours(h1);
    dt1.setMinutes(min1);
    dt1.setAM_PM(amPm1);

    dt2.setDay(d2);
    dt2.setMonth(m2);
    dt2.setYear(y2);
    dt2.setHours(h2);
    dt2.setMinutes(min2);
    dt2.setAM_PM(amPm2);

    //prints patient if appt date is between the two dates given by user
    for (size_t i=0; i<appointmentVec.size(); ++i)
    {
        int p_id=0;
        int s_id=0;
        s_id = appointmentVec[i].getSlotID();
        for (size_t k=0; k<slotVec.size(); ++k)
        {
            if (slotVec[k].getID() == s_id)
            {
                date = slotVec[k].getDateID();
                for (size_t j=0; j<dateTimeVec.size(); ++j)
                {
                    if (dateTimeVec[j].getID() == date)
                    {
                        //calls overloaded operator on date time
                        if((dateTimeVec[j]>dt1) && (dateTimeVec[j]<dt2))
                        {
                            p_id = appointmentVec[i].getPatientID();
                            for (size_t a=0; a<patientVector.size(); ++a)
                            {
                                if (patientVector[a].getID() == p_id)
                                {
                                    patientVector[a].print();
                                }
                            }
                        }
                    }
                }
            }
        }

    }
}

void patient::print(){
    cout << endl << "ID: " << getID() << endl;
    cout << "Doctor ID: " << getDoctorID() << endl;
    cout << "Record ID: " << getRecordID() << endl;
    cout << "Name: " << getName() << endl;
    cout << "Phone: " << getPhone() << endl;
    cout << "Gender: " << getGender() << endl;
    cout << "Email: " << getEmail() << endl;
    cout << "Blood Type: " << getBloodType() << endl << endl;
}

// patient getters
int patient::getID(){
    return id;
}
int patient::getDoctorID(){
    return doctor_id;
}
int patient::getRecordID(){
    return record_id;
}
string patient::getName(){
    return name;
}
string patient::getPhone(){
    return phone;
}
char patient::getGender(){
   return gender;
}
string patient::getEmail(){
    return email;
}
string patient::getBloodType(){
    return blood_type;
}


// patient setters
void patient::setID(int inID){
    id = inID;
}
void patient::setDoctorID(int inD_ID){
    doctor_id = inD_ID;
}
void patient::setRecordID(int inR_ID){
    record_id = inR_ID;
}
void patient::setName(string inName){
    name = inName;
}
void patient::setPhone(string inPhone){
    phone = inPhone;
}
void patient::setGender(char inGender){
    gender = inGender;
}
void patient::setEmail(string inEmail){
    email = inEmail;
}
void patient::setBloodType(string inBlood){
    blood_type = inBlood;
}

