#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <ios>    //used to get stream size
#include <limits> //used to get numeric limits
#include <stdio.h>
using namespace std;

#include "./include/global.hh"
#include "./include/hospital.hh"
#include "./include/address.hh"
#include "./include/person.hh"
#include "./include/appointment.hh"
#include "./include/patient.hh"
#include "./include/doctor.hh"
#include "./include/nurse.hh"
#include "./include/driver.hh"
#include "./include/ambulance.hh"
#include "./include/user.hh"

const char* RESET = "\033[Om";
const char* FRONT_RED = "\033[31m";
const char* FRONT_YELLOW="\033[33m";
const char* FRONT_BLUE = "\033[34m";
const char* FRONT_DG = "\033[36m";
const char* BACK_WHITE = "\033[47m";
const char* BOLD="\033[1m";

void appointmentsMenu();
void patientsMenu();
void doctorsMenu();
void nursesMenu();
void driversMenu();
void ambulancesMenu();

void appointmentsMenu()
{
    bool exit = false;
    while (!exit)
    {
        int purpose = 0;
        printf("%s",FRONT_YELLOW);
        cout << "\nSelect your option here:\n\n";
        cout << "\n================================================================================\n";
        cout << "[1] : Book an appointment\n";
        cout << "[2] : Get appointment details\n";
        cout << "[3] : Show all appointments\n\n";
        cout << "[-1] : EXIT\n";
        cout << "================================================================================\n\n";
        cout << "Enter your choice: ";
        cin >> purpose;

        if (purpose == 1)
        {
            appointment a;
            a.book();
        }
        else if (purpose == 2)
        {
            appointment a;
            a.getDetails();
            a.printDetails();
        }
        else if (purpose == 3)
        {
            hospital::printAppointments();
        }
        else if (purpose == -1)
        {
            exit = true;
            break;
        }
        else
        {
            cout << "Invalid choice!\n";
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clearing cin buffer;

        cout << endl;
        cout << "\nPress ENTER to continue...\n";
        cout << endl;

        getchar();
    }
    return;
}

void patientsMenu()
{
    bool exit = false;
    while (!exit)
    {
        int purpose = 0;
        printf("%s",FRONT_YELLOW);
        cout << "\nSelect your option here:\n\n";
        cout << "\n================================================================================\n";
        cout << "[1] : Register a new patient\n";
        cout << "[2] : Get patient details\n";
        cout << "[3] : Hospitalize a registered patient\n";
        cout << "[4] : Report a patient's death\n";
        cout << "[5] : Discharge a patient or their body\n";
        cout << "[6] : Fetch patient details from history\n";
        cout << "[7] : Get details of all registered patients\n\n";
        cout << "[-1] : EXIT\n";
        cout << "================================================================================\n\n";
        cout << "Enter your choice: ";
        cin >> purpose;

        if (purpose == 1)
        {
            patient p;
            p.addPerson();
        }
        else if (purpose == 2)
        {
            patient p;
            p.getDetails(1);
            p.printDetails();
        }
        else if (purpose == 3)
        {
            patient p;
            p.hospitalize();
        }
        else if (purpose == 4)
        {
            patient p;
            p.reportADeath();
        }
        else if (purpose == 5)
        {
            patient p;
            p.removePerson();
        }
        else if (purpose == 6)
        {
            patient p;
            p.getDetailsFromHistory();
        }
        else if (purpose == 7)
        {
            hospital::printPatients();
        }
        else if (purpose == -1)
        {
            exit = true;
            break;
        }
        else
        {
            cout << "Invalid choice!\n";
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clearing cin buffer;

        cout << endl;
        cout << "\nPress ENTER to continue...\n";
        cout << endl;

        getchar();
    }
    return;
}

void doctorsMenu()
{
    bool exit = false;
    while (!exit)
    {
        int purpose = 0;
        printf("%s",FRONT_YELLOW);
        cout << "\nSelect your option here:\n\n";
        cout << "\n================================================================================\n";
        cout << "[1] : Register a new doctor\n";
        cout << "[2] : Get doctor details\n";
        cout << "[3] : Remove a doctor\n";
        cout << "[4] : Fetch doctor details from history\n";
        cout << "[5] : Get details of all registered doctors\n\n";
        cout << "[-1] : EXIT\n";
        cout << "================================================================================\n\n";
        cout << "Enter your choice: ";
        cin >> purpose;

        if (purpose == 1)
        {
            doctor d;
            d.addPerson();
        }
        else if (purpose == 2)
        {
            doctor d;
            d.getDetails(1);
            d.printDetails();
        }
        else if (purpose == 3)
        {
            doctor d;
            d.removePerson();
        }
        else if (purpose == 4)
        {
            doctor d;
            d.getDetailsFromHistory();
        }
        else if (purpose == 5)
        {
            hospital::printDoctors();
        }
        else if (purpose == -1)
        {
            exit = true;
            break;
        }
        else
        {
            cout << "Invalid choice!\n";
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clearing cin buffer;

        cout << endl;
        cout << "\nPress ENTER to continue...\n";
        cout << endl;

        getchar();
    }
    return;
}

void nursesMenu()
{
    bool exit = false;
    while (!exit)
    {
        int purpose = 0;
        printf("%s",FRONT_YELLOW);
        cout << "\nSelect your option here:\n\n";
        cout << "\n================================================================================\n";
        cout << "[1] : Register a new nurse\n";
        cout << "[2] : Get nurse details\n";
        cout << "[3] : Remove a nurse\n";
        cout << "[4] : Fetch nurse details from history\n";
        cout << "[5] : Get details of all registered nurses\n\n";
        cout << "[-1] : Log out\n";
        cout << "================================================================================\n\n";
        cout << "Enter your choice: ";
        cin >> purpose;

        if (purpose == 1)
        {
            nurse n;
            n.addPerson();
        }
        else if (purpose == 2)
        {
            nurse n;
            n.getDetails(1);
            n.printDetails();
        }
        else if (purpose == 3)
        {
            nurse n;
            n.removePerson();
        }
        else if (purpose == 4)
        {
            nurse n;
            n.getDetailsFromHistory();
        }
        else if (purpose == 5)
        {
            hospital::printNurses();
        }
        else if (purpose == -1)
        {
            exit = true;
            break;
        }
        else
        {
            cout << "Invalid choice!\n";
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clearing cin buffer;

        cout << endl;
        cout << "\nPress ENTER to continue...\n";
        cout << endl;

        getchar();
    }
    return;
}

void driversMenu()
{
    bool exit = false;
    while (!exit)
    {
        int purpose = 0;
        printf("%s",FRONT_YELLOW);
        cout << "\nSelect your option here:\n\n";
        cout << "\n================================================================================\n";
        cout << "[1] : Register a new driver\n";
        cout << "[2] : Get driver details\n";
        cout << "[3] : Remove a driver\n";
        cout << "[4] : Fetch driver details from history\n";
        cout << "[5] : Get details of all registered drivers\n\n";
        cout << "[-1] : EXIT\n";
        cout << "================================================================================\n\n";
        cout << "Enter your choice: ";
        cin >> purpose;

        if (purpose == 1)
        {
            driver d;
            d.addPerson();
        }
        else if (purpose == 2)
        {
            driver d;
            d.getDetails(1);
            d.printDetails();
        }
        else if (purpose == 3)
        {
            driver d;
            d.removePerson();
        }
        else if (purpose == 4)
        {
            driver d;
            d.getDetailsFromHistory();
        }
        else if (purpose == 5)
        {
            hospital::printDrivers();
        }
        else if (purpose == -1)
        {
            exit = true;
            break;
        }
        else
        {
            cout << "Invalid choice!\n";
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clearing cin buffer;

        cout << endl;
        cout << "\nPress ENTER to continue...\n";
        cout << endl;

        getchar();
    }
    return;
}

void ambulancesMenu()
{
    bool exit = false;
    while (!exit)
    {
        int purpose = 0;
        printf("%s",FRONT_YELLOW);
        cout << "\nSelect your option here:\n\n";
        cout << "\n================================================================================\n";
        cout << "[1] : Add an ambulance\n";
        cout << "[2] : Send an ambulance\n";
        cout << "[3] : Get ambulance details\n";
        cout << "[4] : Report ambulance arrival\n";
        cout << "[5] : Remove an ambulance\n";
        cout << "[6] : Fetch ambulance details from history\n";
        cout << "[7] : Get details of all registered ambulances\n\n";
        cout << "[-1] : EXIT\n";
        cout << "================================================================================\n\n";
        cout << "Enter your choice: ";
        cin >> purpose;

        if (purpose == 1)
        {
            ambulance a;
            a.addAmbulance();
        }
        else if (purpose == 2)
        {
            ambulance a;
            a.send();
        }
        else if (purpose == 3)
        {
            ambulance a;
            a.getDetails(1);
            a.printDetails();
        }
        else if (purpose == 4)
        {
            ambulance a;
            a.reportArrival();
        }
        else if (purpose == 5)
        {
            ambulance a;
            a.removeAmbulance();
        }
        else if (purpose == 6)
        {
            ambulance a;
            a.getDetailsFromHistory();
        }
        else if (purpose == 7)
        {
            hospital::printAmbulances();
        }
        else if (purpose == -1)
        {
            exit = true;
            break;
        }
        else
        {
            cout << "Invalid choice!\n";
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clearing cin buffer;

        cout << endl;
        cout << "\nPress ENTER to continue...\n";
        cout << endl;

        getchar();
    }
    return;
}

void admin_main_menu()
{
    while(1)
    {
        int category = 0;
        printf("%s",FRONT_DG);
        cout<<"\nYou now login in as Administrator.";
        cout << "\nSelect your category here:\n\n";
        cout << "\n================================================================================\n";
        cout << "[01] : APPOINTMENTS\n";
        cout << "[02] : PATIENTS\n";
        cout << "[03] : DOCTORS\n";
        cout << "[04] : NURSES\n";
        cout << "[05] : DRIVERS\n";
        cout << "[06] : AMBULANCES\n\n";
        cout << "[-1] : EXIT\n";
        cout << "\n================================================================================\n";

        cout << "Please enter your choice: ";
        cin >> category;
        cout << "\n";
        if (category == -1)
        {
            cout << "\n================================================================================\n";
            cout << "\nNow return to the main menu...\n";
            cout << "\n================================================================================\n";
            break;
        }
        else if (category == 1)
        {
            appointmentsMenu();
        }
        else if (category == 2)
        {
            patientsMenu();
        }
        else if (category == 3)
        {
            doctorsMenu();
        }
        else if (category == 4)
        {
            nursesMenu();
        }
        else if (category == 5)
        {
            driversMenu();
        }
        else if (category == 6)
        {
            ambulancesMenu();
        }
        else
        {
            cout << "\nInvalid Choice!\n";
        }

        cout << endl;
    }
}

void login_in_display()
{
	while (1)
	{
		string order;
		printf("%s",FRONT_YELLOW);
        cout<<"\nWelcome to hospital information manage system!Before you start...\n";
		cout << "===============================================" << endl;
		cout << "1.Login in 2.Sign up 3.Exit " << endl;
		cout << "===============================================" << endl;
		cout << "Please enter your order："<<endl;
		cin >> order;
		if (order == "2")
		{
			user temp;
			temp.sign_up_user();
		}
		else if (order == "1")
		{
			user temp;
            int auth  =temp.login_in_user();
            cout<<"\n";
			switch(auth)
            {
                case 0:
                    admin_main_menu();
                    break;
                case 1:
                    cout<<"\nYou now login in as appointment consultant.\n";
                    appointmentsMenu();
                    break;
                case 2:
                    cout<<"\nYou now login in as doctor supervisor.\n";
                    doctorsMenu();
                    break;
                case 3:
                    cout<<"\nYou now login in as patient supervisor.\n";
                    patientsMenu();
                    break;
                case 4:
                    cout<<"\nYou now login in as nurse supervisor.\n";
                    nursesMenu();
                    break;
                case 5:
                    cout<<"\nYou now login in as driver supervisor.\n";
                    driversMenu();
                    break;
                case 6:
                    cout<<"\nYou now login in as ambulance supervisor.\n";
                    ambulancesMenu();
                    break;
                    //do nothing
            }
            
        }
		
        else if (order == "3")
            {
                cout<<"\n==========================================================";
                cout << "\nThanks for using the system! Bye for now:)";
                cout<<"\n==========================================================\n";
                break;
            }
        else {cout<<"\nWrong order.Try again.\n";}
	}
}


int main()
{
    fstream f;
    f.open("./data/appointments.csv", ios::in);
    string temp, s, header;
    getline(f, header);
    getline(f, temp);
    f.close();
    stringstream str(temp);
    getline(str, s, ',');
    getline(str, s, ',');
    int dd, mm, yyyy;
    printf("%s",FRONT_BLUE);
    if (s != "")
        cout << "\n\n\nLast usage date (DD-MM-YYYY) : " << s.substr(6, 2) + "-" + s.substr(4, 2) + "-" + s.substr(0, 4) + "\n";
    cout<<"\nWelcome to the hospital information management system!";
    cout << "\nBefore we start,please enter today's date (DD-MM-YYYY) :\n\nEnter Day: ";
    cin >> dd;
    while (dd < 1 || dd > 31)
    {
        cout << "Invalid Day! Please enter a valid day: ";
        cin >> dd;
    }
    cout << "Enter Month: ";
    cin >> mm;
    while (mm < 1 || mm > 12)
    {
        cout << "Invalid Month! Please enter a valid month: ";
        cin >> mm;
    }
    cout << "Enter Year (YYYY): ";
    cin >> yyyy;
    yyyymmdd = yyyy * 10000 + mm * 100 + dd;
    if (stoi(((s == "") ? ("0") : (s))) < yyyymmdd)
    {
        f.open("./data/temp.csv", ios::out);
        f << header << "\n";
        f.close();
        remove("./data/appointments.csv");
        rename("./data/temp.csv", "./data/appointments.csv");
        fstream fout("./data/temp.csv", ios::out);
        f.open("./data/doctors.csv", ios::in);
        getline(f, temp);
        fout << temp << endl;
        while (getline(f, temp))
        {
            if (temp.size())
                temp[temp.size() - 1] = '0';
            fout << temp << endl;
        }
        f.close();
        fout.close();
        remove("./data/doctors.csv");
        rename("./data/temp.csv", "./data/doctors.csv");
    }
    else if (stoi(s) > yyyymmdd && s != "")
    {
        cout << "\nEntered date detected wrong!\nToday's date can't be older than the last usage date, which is : "
             << s.substr(6, 2) + "-" + s.substr(4, 2) + "-" + s.substr(0, 4) + "\n";
        return 0;
    }
    // filling maps with data from csv files;
    {
        doctor d1;
        patient p;
        nurse n;
        driver d2;
        ambulance a1;
        appointment a2;
        user u;
        d1.fillMap();
        p.fillMap();
        n.fillMap();
        d2.fillMap();
        a1.fillMap();
        a2.fillMap();
        u.fillMap();
        // NOTE:
        // fill drivers' Map before ambulances' Map;
        // fill doctors' and patients' Map before appointments' Map;
    }
    
    login_in_display();

    // saving data inside maps by overwriting it on the files
    {
        doctor d1;
        patient p;
        nurse n;
        driver d2;
        ambulance a1;
        appointment a2;
        user u;
        d1.saveMap();
        p.saveMap();
        n.saveMap();
        d2.saveMap();
        a1.saveMap();
        a2.saveMap();
        u.saveMap();
    }

    return 0;
}
