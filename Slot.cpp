#include "Doctor.h"
#include "Date_Time.h"
#include "Slot.h"
#include <fstream>
#include <iostream>


using namespace std;

///read in all values
void readInSlots(vector<slot>& slotVec){
    ifstream inFile;
    inFile.open("Slots.txt");
    int numSlots=0;
    int id=0, dt_id=0, dr_id=0;
    string available="";
    inFile >> numSlots;
    slotVec.resize(numSlots);

    for (int i=0; i<numSlots; ++i)
    {
        inFile >> id >> dt_id >> dr_id >> available;
        slotVec[i].setID(id);
        slotVec[i].setDateID(dt_id);
        slotVec[i].setDoctorID(dr_id);
        if (available == "available")
        {
            slotVec[i].setAvailability(1);
        }
        else
        {
            slotVec[i].setAvailability(0);
        }
    }
}

/// main slot menu
void slotMenu(vector<slot>& slotVec, vector<doctor>& doctorVec, vector<date_time>& dateTimeVec){
    cout << "1. Update a slot" << endl;
    cout << "2. Delete a slot" << endl;
    cout << "3. Show all slots" << endl;
    cout << "4. Show all available slots" << endl;
    cout << "5. Show all unavailable slots" << endl;
    cout << "6. Search for available slot by doctor's name" << endl;
    cout << "7. Show available slots by time range" << endl;
    cout << "8. Go back" << endl;

    int choice=0;
    cin >> choice;
    if(choice == 1)
    {
        updateSlot(slotVec);
    }
    else if (choice == 2)
    {
        deleteSlot(slotVec);
    }
    else if (choice == 3)
    {
        printSlots(slotVec);
    }
    else if (choice == 4)
    {
        availableSlots(slotVec);
    }
    else if (choice == 5)
    {
        unavailableSlots(slotVec);
    }
    else if (choice == 6)
    {
        searchSlotsByDoctor(slotVec, doctorVec, dateTimeVec);
    }
    else if (choice == 7)
    {
        searchSlotsByTime(slotVec, dateTimeVec);
    }
    else if (choice == 8)
    {
        return;
    }
}

// 1. update slot
void updateSlot(vector<slot>& slotVec){
    int id=0;
    int pos=0;
    int choice=0;
    char cont='N';

    //gets correct pos
    cout << "Please enter the ID of the slot you would like to update: ";
    cin >> id;

    for (size_t i=0; i<slotVec.size(); ++i)
    {
        if (slotVec[i].getID() == id)
        {
            pos = i;
        }
    }
    do
    {
    cout << endl << "What information would you like to update for this slot?" << endl;
    cout << "1. ID" << endl;
    cout << "2. Date ID" << endl;
    cout << "3. Doctor ID" << endl;
    cout << "4. Availability" << endl;
    cin >> choice;

    if (choice == 1)
    {
        cout << "Current ID: " << slotVec[pos].getID() << endl;
        cout << endl << "Please enter the new ID: ";
        int newValue;
        cin >> newValue;
        slotVec[pos].setID(newValue);
        cout << "New ID: " << slotVec[pos].getID() << endl;
    }
    else if (choice == 2)
    {
        cout << "Current Date ID: " << slotVec[pos].getDateID() << endl;
        cout << endl << "Please enter the new date ID: ";
        int newValue;
        cin >> newValue;
        slotVec[pos].setDateID(newValue);
        cout << "New Date ID: " << slotVec[pos].getDateID() << endl;
    }
    else if (choice == 3)
    {
        cout << "Current Doctor ID: " << slotVec[pos].getDoctorID() << endl;
        cout << endl << "Please enter the new doctor ID: ";
        int newValue;
        cin >> newValue;
        slotVec[pos].setDoctorID(newValue);
        cout << "New Doctor ID: " << slotVec[pos].getDoctorID() << endl;
    }
    else if (choice == 4)
    {
        cout << "Current Availability: ";
        int avail=0;
        char value;
        avail = slotVec[pos].getAvailability();
        if (avail == 1)
        {
            cout << "Available" << endl;
            cout << endl << "Would you like to change the availability to unavailable? (Y/N): ";
            cin >> value;
            if (value == 'Y')
            {
                slotVec[pos].setAvailability(0);
            }
        }
        else
        {
            cout << "Unavailable" << endl;
            cout << endl << "Would you like to change the availability to available? (Y/N): ";
            cin >> value;
            if (value == 'Y')
            {
                slotVec[pos].setAvailability(1);
            }
        }
    }
    cout << endl << endl << "Would you like to continue updating? (Y/N): ";
    cin >> cont;
    }
    while (cont=='Y');
    //loops until user says N
}

// 2. delete slot
void deleteSlot(vector<slot>& slotVec){
    int id=0;
    int pos=0;
    cout << "Please enter the ID of the slot you would like to delete: ";
    cin >> id;

    //gets correct pos
    for (size_t i=0; i<slotVec.size(); ++i)
    {
        if (slotVec[i].getID() == id)
        {
            pos = i;
        }
    }
    //erases slot
    slotVec.erase(slotVec.begin()+ pos);
    cout << endl << "Slot Deleted " << endl << endl;
}

// 3. show all slots
void printSlots(vector<slot> slotVec)
{
    for (size_t i=0; i<slotVec.size(); ++i)
    {
        slotVec[i].print();
    }
}

// 4. available slots
void availableSlots(vector<slot> slotVec){
    //only prints slots where available is 1
    cout << endl << "Available Slots: " << endl;
    for (size_t i=0; i<slotVec.size(); ++i)
    {
        if (slotVec[i].getAvailability() == 1)
        {
            slotVec[i].print();
        }
    }
}

// 5. unavailable slots
void unavailableSlots(vector<slot> slotVec){
    //only prints slots where available is 0
    cout << endl << "Unavailable Slots: " << endl;
    for (size_t i=0; i<slotVec.size(); ++i)
    {
        if (slotVec[i].getAvailability() == 0)
        {
            slotVec[i].print();
        }
    }
}

// 6. Search slots by doctor
void searchSlotsByDoctor(vector<slot> slotVec, vector<doctor>& doctorVec, vector<date_time> dateTimeVec){
    int id=0;
    string name="";

    cout << "Enter the Doctor's name: ";
    cin >> name;
    //get doctor id
    for(size_t j=0; j<doctorVec.size(); j++)
    {
        if (doctorVec[j].getName() == name)
        {
            id = doctorVec[j].getID();
        }
    }

    for (size_t i=0; i<slotVec.size(); ++i)
    {
    int doc=0;
    int date=0;
    bool avail=0;
        if (slotVec[i].getDoctorID() == id)
        {
        cout << endl;
        cout << "ID: " << slotVec[i].getID() << endl;
        date = slotVec[i].getDateID();
        for (size_t j=0; j<dateTimeVec.size(); j++)
        {
            if (dateTimeVec[j].getID() == date)
            {
                cout << "Date: ";
                dateTimeVec[j].print();
            }
        }
        doc = slotVec[i].getDoctorID();
        for (size_t j=0; j<doctorVec.size(); j++)
        {
            //if slot has same doctor id then print
            if (doctorVec[j].getID() == doc)
                cout << "Doctor: " << doc << '-' << doctorVec[j].getName() << endl;
        }
        avail = slotVec[i].getAvailability();
        if (avail==1)
        {
            cout << "Available Slot";
        }
        else
            cout << "Unavailable Slot";
        cout << endl << endl;
        }
    }
}

// 7. Search slots by time
void searchSlotsByTime(vector<slot> slotVec, vector<date_time> dateTimeVec){
    int date=0;
    int d1=0,d2=0,m1=0,m2=0,y1=0,y2=0;
    int h1=0,h2=0, min1=0,min2=0;
    char symbol='z', amPm1='z', amPm2='z';

    date_time dt1;
    date_time dt2;

    //user input two dates
    cout << "Search slots by time range" << endl << endl;
    cout << "Enter the first date: (mm/dd/yyyy hours:minutes 'a' for AM, 'p' for PM)" << endl;
    cin >> m1 >> symbol >> d1 >> symbol >> y1 >> h1 >> symbol >> min1 >> amPm1;

    cout << "Enter the second date: (mm/dd/yyyy hours:minutes 'a' for AM, 'p' for PM)" << endl;
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

    for (size_t i=0; i<slotVec.size(); ++i)
    {
        if (slotVec[i].getAvailability() == 1)
        {
            date = slotVec[i].getDateID();
            for (size_t j=0; j<dateTimeVec.size(); ++j)
            {
                if (dateTimeVec[j].getID() == date)
                {
                    //calls overloaded operator functions
                    if((dateTimeVec[j]>dt1) && (dateTimeVec[j]<dt2))
                    {
                        slotVec[i].print();
                    }
                }
            }
        }
    }
}

void slot::print(){
    cout << endl;
    cout << "ID: " << getID() << endl;
    cout << "Date ID: " << getDateID() << endl;
    cout << "Doctor ID: " << getDoctorID() << endl;
    if (getAvailability() == 1)
    {
        cout << "Available" << endl << endl;
    }
    else
    {
        cout << "Unavailable" << endl << endl;
    }
}

int slot::getID(){
    return id;
}
int slot::getDateID(){
    return date_id;
}
int slot::getDoctorID(){
    return doctor_id;
}
bool slot::getAvailability(){
    return available;
}
void slot::setID(int in){
    id = in;
}
void slot::setDateID(int in){
    date_id = in;
}
void slot::setDoctorID(int in){
    doctor_id = in;
}
void slot::setAvailability(bool in){
    available = in;
}
