#ifndef SLOT_H_INCLUDED
#define SLOT_H_INCLUDED
#include <vector>

using namespace std;

class slot {
    int id;
    int date_id;
    int doctor_id;
    bool available;

public:
    slot()
    {
        id = 0;
        date_id = 0;
        doctor_id = 0;
        available = 0;
    }
    //get functions
    int getID();
    int getDateID();
    int getDoctorID();
    bool getAvailability();
//set functions
    void setID(int in);
    void setDateID(int in);
    void setDoctorID(int in);
    void setAvailability(bool in);

    void print();

};

void readInSlots(vector<slot>& slotVec);
void slotMenu(vector<slot>& slotVec, vector<doctor>& doctorVec, vector<date_time>& dateTimeVec);
void printSlots(vector<slot> slotVec);
void availableSlots(vector<slot> slotVec);
void unavailableSlots(vector<slot> slotVec);
void searchSlotsByDoctor(vector<slot> slotVec, vector<doctor>& doctorVec, vector<date_time> dateTimeVec);
void updateSlot(vector<slot>& slotVec);
void searchSlotsByTime(vector<slot> slotVec, vector<date_time> dateTimeVec);
void deleteSlot(vector<slot>& slotVec);


#endif // SLOT_H_INCLUDED
