#include "Doctor.h"

///read in all values
void readInDoctors(vector<doctor>& doctorVec){
    ifstream inFile;
    inFile.open("Doctors.txt");
    int numDoctors=0;
    int id=0;
    string phone="", name="", username="", password="", skill="";
    inFile >> numDoctors;
    doctorVec.resize(numDoctors);

    for (int i=0; i<numDoctors; ++i)
    {
        inFile >> id >> username >> password >> name >> phone >> skill;
        doctorVec[i].setID(id);
        doctorVec[i].setUsername(username);
        doctorVec[i].setPassword(password);
        doctorVec[i].setName(name);
        doctorVec[i].setPhone(phone);
        doctorVec[i].setSkill(skill);
    }
}

/// main doctor menu
void doctorMenu(vector<doctor>& doctorVec, vector<appointment> appointmentVec){
    cout << "1. View all Doctors" << endl;
    cout << "2. Update Doctor's info" << endl;
    cout << "3. Delete Doctor" << endl;
    cout << "4. Search Doctor by Name" << endl;
    cout << "5. Go back" << endl;

    int choice=0;
    cin >> choice;
    if (choice == 1)
    {
        printDoctors(doctorVec);
    }
    else if (choice == 2)
    {
        updateDoctor(doctorVec);
    }
    else if (choice == 3)
    {
        deleteDoctor(doctorVec, appointmentVec);
    }
    else if (choice == 4)
    {
        searchDoctorByName(doctorVec);
    }
    else if (choice == 5)
    {
        return;
    }
}

// 1. print all doctors
void printDoctors(vector<doctor> doctorVec){
    for (size_t i=0; i<doctorVec.size(); i++)
    {
        doctorVec[i].print();
    }
}


// 2. update doctor
void updateDoctor(vector<doctor>& doctorVec){
    int id=0;
    int pos=0;
    int choice=0;
    char cont='N';

    cout << "Please enter the ID of the doctor you would like to update: ";
    cin >> id;

    // get correct doctor pos
    for (size_t i=0; i<doctorVec.size(); ++i)
    {
        if (doctorVec[i].getID() == id)
        {
            pos = i;
        }
    }
    do
    {
        //menu for update
    cout << "What information would you like to update for this doctor?" << endl;
    cout << "1. ID" << endl;
    cout << "2. Username" << endl;
    cout << "3. Password" << endl;
    cout << "4. Name" << endl;
    cout << "5. Phone Number" << endl;
    cout << "6. Skill" << endl;
    cin >> choice;

    if (choice == 1)
    {
        cout << "Current ID: " << doctorVec[pos].getID() << endl;
        cout << endl << "Please enter the new ID: ";
        int newValue;
        cin >> newValue;
        doctorVec[pos].setID(newValue);
        cout << "New ID: " << doctorVec[pos].getID() << endl;
    }
    else if (choice == 2)
    {
        cout << "Current Username: " << doctorVec[pos].getUsername() << endl;
        cout << endl << "Please enter the new username: ";
        string newValue;
        cin >> newValue;
        doctorVec[pos].setUsername(newValue);
        cout << "New Username: " << doctorVec[pos].getUsername() << endl;
    }
    else if (choice == 3)
    {
        cout << "Current Password: " << doctorVec[pos].getPassword() << endl;
        cout << endl << "Please enter the new password: ";
        string newValue;
        cin >> newValue;
        doctorVec[pos].setPassword(newValue);
        cout << "New Password: " << doctorVec[pos].getPassword() << endl;
    }
    else if (choice == 4)
    {
        cout << "Current Name: " << doctorVec[pos].getName() << endl;
        cout << endl << "Please enter the new name: ";
        string newValue;
        cin >> newValue;
        doctorVec[pos].setName(newValue);
        cout << "New Name: " << doctorVec[pos].getName() << endl;
    }
    else if (choice == 5)
    {
        cout << "Current Phone Number: " << doctorVec[pos].getPhone() << endl;
        cout << endl << "Please enter the new phone number: ";
        string newValue;
        cin >> newValue;
        doctorVec[pos].setPhone(newValue);
        cout << "New Phone Number: " << doctorVec[pos].getPhone() << endl;
    }
    else if (choice == 6)
    {
        cout << "Current Skill: " << doctorVec[pos].getSkill() << endl;
        cout << endl << "Please enter the new skill: ";
        string newValue;
        cin >> newValue;
        doctorVec[pos].setSkill(newValue);
        cout << "New Skill: " << doctorVec[pos].getSkill() << endl;
    }
    cout << endl << endl << "Would you like to continue updating? (Y/N): ";
    cin >> cont;
    }
    while (cont=='Y');
    //update for as long as user wants
    cout << endl << "Doctor Updated" << endl << endl;
}

// 3. delete doctor
void deleteDoctor(vector<doctor>& doctorVec, vector<appointment> appointmentVec){
    int id=0;
    int pos=0;
    bool currentAppt=0;
    cout << "Please enter the ID of the doctor you would like to delete: ";
    cin >> id;

    //gets correct pos
    for (size_t i=0; i<doctorVec.size(); ++i)
    {
        if (doctorVec[i].getID() == id)
        {
            pos = i;
        }
    }

    //checks if the doctor has any current appts
    for(size_t i=0; i<appointmentVec.size(); ++i)
    {
        if (appointmentVec[i].getDoctorID()==id)
        {
            currentAppt=1;
        }
    }
    //if the doctor has appts then he/she cannot be deleted
    if (currentAppt==1)
    {
        cout << endl << "This doctor still has current appointments. You must cancel the "
            << "appointments before deleting this doctor." << endl << endl;
    }
    else
    {
        doctorVec.erase(doctorVec.begin()+ pos);
        cout << endl << "Doctor Deleted" << endl << endl;
    }
}

// 4. Search doctor by name
void searchDoctorByName(vector<doctor> doctorVec){
    int pos=999;
    string name="";

    //gets doctor pos
    cout << "Enter the Doctor's Name: ";
    cin >> name;
    for (size_t i=0; i<doctorVec.size(); ++i)
    {
        if (name == doctorVec[i].getName())
        {
            pos = i;
        }
    }
    if (pos==999)
    {
        cout << endl << "Doctor does not exist" << endl << endl;
    }
    else
    {
        doctorVec[pos].print();
    }
}


void doctor::print(){
    cout << endl << "ID: " << getID() << endl;
    cout << "Username: " << getUsername() << endl;
    cout << "Password: " << getPassword() << endl;
    cout << "Name: " << getName() << endl;
    cout << "Phone: " << getPhone() << endl;
    cout << "Skill: " << getSkill() << endl << endl;
}

int doctor::getID(){
    return id;
}
string doctor::getUsername(){
    return username;
}

string doctor::getPassword(){
    return password;
}

string doctor::getName(){
    return name;
}

string doctor::getPhone(){
    return phone;
}

string doctor::getSkill(){
    return skill;
}

void doctor::setID(int inID){
    id = inID;
}

void doctor::setUsername(string inUsername){
    username = inUsername;
}

void doctor::setPassword(string inPassword){
    password = inPassword;
}

void doctor::setName(string inName){
    name = inName;
}

void doctor::setPhone(string inPhone){
    phone = inPhone;
}

void doctor::setSkill(string inSkill){
    skill = inSkill;
}
