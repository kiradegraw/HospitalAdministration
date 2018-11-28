#ifndef DATE_TIME_H_INCLUDED
#define DATE_TIME_H_INCLUDED
#include <vector>

using namespace std;

class date_time{
    int id;
    int day;
    int month;
    int year;
    int hours;
    int minutes;
    char AM_PM;

public:
    date_time()
    {
        id = 0;
        day = 0;
        month = 0;
        year = 0;
        hours = 0;
        minutes = 0;
        AM_PM = 'z';
    }
    //get functions
    int getID();
    int getDay();
    int getMonth();
    int getYear();
    int getHours();
    int getMinutes();
    char getAM_PM();
//set functions
    void setID(int in);
    void setDay(int in);
    void setMonth(int in);
    void setYear(int in);
    void setHours(int in);
    void setMinutes(int in);
    void setAM_PM(char in);

    void print();

    bool operator>(date_time dt2) const;
    bool operator<(date_time dt2) const;
};

void readInDateTime(vector<date_time>& dateTimeVec);


#endif // DATE_TIME_H_INCLUDED
