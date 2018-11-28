#include "Date_Time.h"
#include "Appointment.h"
#include "Slot.h"
#include "Lab.h"

/// main lab menu
void labMenu(vector<date_time> dateTimeVec, vector<appointment>& appointmentVec, vector<slot>& slotVec){
    cout << "1. Create a new lab appointment" << endl;
    cout << "2. Cancel lab appointment" << endl;
    cout << "3. Show all lab appointments" << endl;
    cout << "4. Go back to main menu" << endl;

    int choice=0;
    cin >> choice;
    if (choice == 1)
    {
        addNewLab(dateTimeVec, appointmentVec, slotVec);
    }
    else if (choice == 2)
    {
        cancelLab(appointmentVec, slotVec);
    }
    else if (choice == 3)
    {
        printLabs(appointmentVec);
    }
    else if (choice == 4)
    {
        return;
    }
}

//1. add new appointment
void addNewLab(vector<date_time> dateTimeVec, vector<appointment>& appointmentVec, vector<slot>& slotVec){
    int id=0, d_id=0, p_id=0, s_id=0, diag_id=0;
    string reason="", med="";
    int date1=0, date2=0;
    bool allowed=0;
    int m1=0,y1=0,d1=0,m2=0,y2=0,d2=0;

    cout << "What is the appointment ID? ";
    cin >> id;
    cout << "What is the doctor ID? ";
    cin >> d_id;
    cout << "What is the patient ID? ";
    cin >> p_id;

    do
    {
        allowed=1;
        cout << "What is the slot ID? (must be greater than 30) ";
        cin >> s_id;

        for (size_t j=30; j<slotVec.size(); ++j)
        {
            if (slotVec[j].getID() == s_id)
            {
                date1 = slotVec[j].getDateID();
            }
        }
        // if date is not hinger than 30, it is not allowed
        if (date1==0)
        {
            cout << "Slot ID must be greater than 30" << endl << endl;
            allowed=0;
        }
        for (size_t i=30; i<slotVec.size(); ++i)
        {
            if (slotVec[i].getAvailability() == 0)
            {
                //checks if there is already an appt on that day
                date2 = slotVec[i].getDateID();
                for (size_t k=0; k<dateTimeVec.size(); ++k)
                {
                    if (dateTimeVec[k].getID() == date1)
                    {
                        m1 = dateTimeVec[k].getMonth();
                        y1 = dateTimeVec[k].getYear();
                        d1 = dateTimeVec[k].getDay();
                    }
                    if (dateTimeVec[k].getID() == date2)
                    {
                        m2 = dateTimeVec[k].getMonth();
                        y2 = dateTimeVec[k].getYear();
                        d2 = dateTimeVec[k].getDay();
                    }
                }
                if ((y1==y2) && (m1==m2) && (d1==d2))
                {
                    cout << "Only 1 lab appointment per day." << endl << endl;
                    allowed=0;
                }
            }
        }
    }
    while (allowed==0);
    //loops until the slot id is allowed

    cout << "What is the appointment reason? ";
    cin >> reason;

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
    cout << endl << "Lab scheduled. Please choose 'update appointment' to add the diagnosis ID and prescribed "
        << "medication after the appointment." << endl << endl;
}

// 2. cancel lab
void cancelLab(vector<appointment>& appointmentVec, vector<slot>& slotVec){
    int id=0, s_id=0, pos=0;
    cout << "Please enter the ID of the lab appointment you would like to cancel: ";
    cin >> id;

    //gets correct pos
    for (size_t i=0; i<appointmentVec.size(); ++i)
    {
        if (appointmentVec[i].getID() == id)
        {
            pos = i;
            s_id = appointmentVec[i].getSlotID();
        }
    }
    appointmentVec.erase(appointmentVec.begin()+ pos);

    //sets availability back to 1
    for (size_t j=30; j<slotVec.size(); ++j)
    {
        if (s_id == slotVec[j].getID())
        {
            slotVec[j].setAvailability(1);
            cout << endl << "Lab canceled. Slot now available." << endl << endl;
        }
    }
}

// 3. show all labs
void printLabs(vector<appointment> appointmentVec){

    for (size_t i=0; i<appointmentVec.size(); ++i)
    {
        if (appointmentVec[i].getSlotID() > 30)
        {
            appointmentVec[i].print();
        }
    }
}
