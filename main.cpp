#include <iostream>
#include <vector>
#include "Doctor.h"
#include "Patient.h"
#include "Date_Time.h"
#include "Slot.h"
#include "Diagnoses.h"
#include "Record.h"
#include "Appointment.h"
#include "Lab.h"

using namespace std;

void menu(int& choice);

int main()
{
    /// create all vectors, read values into vectors from input file
    int choice=0;
    vector<patient> patientVector;
    vector<doctor> doctorVec;
    vector<date_time> dateTimeVec;
    vector<slot> slotVec;
    vector<diagnoses> diagnosesVec;
    vector<appointment> appointmentVec;
    vector<record> recordVec;
    readInPatients(patientVector);
    readInDoctors(doctorVec);
    readInDateTime(dateTimeVec);
    readInSlots(slotVec);
    readInDiagnoses(diagnosesVec);

    /// loop until user wants to exit
    do
    {
    cout << "Welcome to HMS. Please choose an action: " << endl << endl;
    menu(choice);
    if (choice == 1){
        appointmentMenu(appointmentVec, slotVec, doctorVec, patientVector);
    }
    else if (choice == 2){
        slotMenu(slotVec, doctorVec, dateTimeVec);
    }
    else if (choice == 3){
        doctorMenu(doctorVec, appointmentVec);
    }
    else if (choice == 4){
        patientMenu(patientVector, doctorVec, dateTimeVec, appointmentVec, slotVec, diagnosesVec);
    }
    else if (choice == 5){
        recordMenu(recordVec, appointmentVec);
    }
    else if (choice == 6){
        labMenu(dateTimeVec, appointmentVec, slotVec);
    }
    else if (choice == 7){
        return 0;
    }
    }
    while (choice != 7);

    return 0;
}

/// main menu
void menu(int& choice){
    cout << "1. Manage Appointments" << endl;
    cout << "2. Manage Slots" << endl;
    cout << "3. Manage Doctors" << endl;
    cout << "4. Manage Patients" << endl;
    cout << "5. Manage Patients' Records" << endl;
    cout << "6. Manage Labs" << endl;
    cout << "7. Exit" << endl << endl;

    cin >> choice;
}
