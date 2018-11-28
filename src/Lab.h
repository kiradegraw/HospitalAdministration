#ifndef LAB_H_INCLUDED
#define LAB_H_INCLUDED
#include <vector>

using namespace std;
class date_time;


void labMenu(vector<date_time> dateTimeVec, vector<appointment>& appointmentVec, vector<slot>& slotVec);
void addNewLab(vector<date_time> dateTimeVec, vector<appointment>& appointmentVec, vector<slot>& slotVec);
void cancelLab(vector<appointment>& appointmentVec, vector<slot>& slotVec);
void printLabs(vector<appointment> appointmentVec);
bool validSlotID(int s_id, vector<date_time> dateTimeVec, vector<slot> slotVec);

#endif // LAB_H_INCLUDED
