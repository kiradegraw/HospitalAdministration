#include "Date_Time.h"
#include <iostream>
#include <fstream>

using namespace std;

///read in all values
void readInDateTime(vector<date_time>& dateTimeVec){
    ifstream inFile;
    inFile.open("Date_Time.txt");
    int numDates=0;
    int id=0, day=0, month=0, year=0, hours=0, minutes=0;
    char amPm='z';
    inFile >> numDates;
    dateTimeVec.resize(numDates);

    for (int i=0; i<numDates; ++i)
    {
        inFile >> id >> day >> month >> year >> hours >> minutes >> amPm;
        dateTimeVec[i].setID(id);
        dateTimeVec[i].setDay(day);
        dateTimeVec[i].setMonth(month);
        dateTimeVec[i].setYear(year);
        dateTimeVec[i].setHours(hours);
        dateTimeVec[i].setMinutes(minutes);
        dateTimeVec[i].setAM_PM(amPm);
    }
}

// function for > operator
bool date_time::operator>(date_time dt2) const{
    //check year, month, day, hour, minute, am/pm until known
    if (year > dt2.year)
    {
        return true;
    }
    else if (year == dt2.year)
    {
        if (month > dt2.month)
        {
            return true;
        }
        else if (month == dt2.month)
        {
            if (day > dt2.day)
            {
                return true;
            }
            else if (day == dt2.day)
            {
                if (AM_PM == 'a' && dt2.AM_PM == 'p')
                {
                    return false;
                }
                else if (AM_PM == 'p' && dt2.AM_PM == 'a')
                {
                    return true;
                }
                else
                {
                    if (hours > dt2.hours)
                    {
                        return true;
                    }
                    else if(hours == dt2.hours)
                    {
                        if(minutes > dt2.minutes)
                        {
                            return true;
                        }
                        else if(minutes == dt2.minutes)
                        {
                            return false;
                        }
                    }
                }
            }
        }
    }
    return false;
}

bool date_time::operator<(date_time dt2) const{
    //check year, month, day, hour, minute, am/pm until known
    if (year < dt2.year)
    {
        return true;
    }
    else if (year == dt2.year)
    {
        if (month < dt2.month)
        {
            return true;
        }
        else if (month == dt2.month)
        {
            if (day < dt2.day)
            {
                return true;
            }
            else if (day == dt2.day)
            {
                if (AM_PM == 'p' && dt2.AM_PM == 'a')
                {
                    return false;
                }
                else if (AM_PM == 'a' && dt2.AM_PM == 'p')
                {
                    return true;
                }
                else
                {
                    if (hours < dt2.hours)
                    {
                        return true;
                    }
                    else if(hours == dt2.hours)
                    {
                        if(minutes < dt2.minutes)
                        {
                            return true;
                        }
                        else if(minutes == dt2.minutes)
                        {
                            return false;
                        }
                    }
                }
            }
        }
    }
    return false;
}

void date_time::print(){
    cout << month << '/' << day << '/' << year << "  " << hours << ':' << minutes << " " << AM_PM;
    cout << endl;
}

int date_time::getID(){
    return id;
}
int date_time::getDay(){
    return day;
}
int date_time::getMonth(){
    return month;
}
int date_time::getYear(){
    return year;
}
int date_time::getHours(){
    return hours;
}
int date_time::getMinutes(){
    return minutes;
}
char date_time::getAM_PM(){
    return AM_PM;
}
void date_time::setID(int in){
    id = in;
}
void date_time::setDay(int in){
    day = in;
}
void date_time::setMonth(int in){
    month = in;
}
void date_time::setYear(int in){
    year = in;
}
void date_time::setHours(int in){
    hours = in;
}
void date_time::setMinutes(int in){
    minutes = in;
}
void date_time::setAM_PM(char in){
    AM_PM = in;
}
