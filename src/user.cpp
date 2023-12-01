using namespace std;
#include<string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "./../include/global.hh"
#include "./../include/user.hh"
#include "./../include/hospital.hh"

user::user()
{
    id = -1;
    account = "";
    password = "";
    authority = -1;
}

void user::fillMap()
{
    fstream f;
    f.open("./data/users.csv", ios::in);
    string temp;
    //skipping the first row containing column headers;
    getline(f >> ws, temp);
    //analyzing each entry afterwards;
    while (getline(f >> ws, temp))
    {
        user p;
        //creating a string stream object to read from string 'temp';
        stringstream s(temp);
        string s1,s2;
        //reading from the string stream object 's';
        getline(s,s2,',');
        getline(s, p.account, ',');
        getline(s, p.password, ',');
        getline(s, s1, ',');
        p.id = strToNum(s2);
        p.authority = strToNum(s1);
        hospital::usersList[p.id] = p;
    }
    f.close();
    return;
}
void user::saveMap()
{
    fstream f;
    f.open("./data/temp.csv", ios::out);
    // `le first line conataining column headers:
    f << "userID,userName,userPassword,userAuthority\n";
    for (auto i : hospital::usersList)
        f << i.second.id << "," << i.second.account << "," << i.second.password  << "," << i.second.authority << endl;
    f.close();
    remove("./data/users.csv");
    rename("./data/temp.csv", "./data/users.csv");
    return;
}


void user::sign_up_user()
{
    cout<<"\nHello! New to the system? Let's create an account for you.";
    while(1)
    {
        cout<<"\nPlease enter your account name(can't be empty or a reserved name):";
        getline(cin >> ws, account);
        cout<<"\nPlease check your account name:  "<<account<<"\nIs this suitable for you? Enter Y to continue, N to rename, any other to break up\n";
        char order;
        cin>>order;
        if(order=='Y') break;
        else if (order=='N') continue;
        else {
            cout<<"\nReturn to the main menu...\n";
            return;
        }
    }
    while(1)
    {
        cout<<"\nPlease enter your password(can't be empty or contain space):";
        getline(cin >> ws, password);
        cout<<"\nPlease check your password:  "<<password<<"\nIs this suitable for you? Enter Y to continue, N to rewrite, any other to break up\n";
        char order1;
        cin>>order1;
        if(order1=='Y') break;
        else if (order1=='N') continue;
        else {
            cout<<"\nReturn to the main menu...\n";
            return;
        }        
    }
    while(1)
    {
        cout<<"\nPlease select your category of authority:";
        cout<<"\n===========================================";
        cout<<"\n[1]APPOINTMENT CONSULTANT";
        cout<<"\n[2]DOCTOR SUPERVISOR";
        cout<<"\n[3]PATINET SUPERVISOR";
        cout<<"\n[4]NURSE SUPERVISOR";
        cout<<"\n[5]DRIVER SUPERVISOR";
        cout<<"\n[6]AMBULANCE SUPERVISOR";
        cout<<"\n===========================================";
        cout<<"\nPlease enter your category of authority:";
        int auth;
        cin>>auth;
        if (auth<1 or auth>6 )
            cout<<"\nInvalid authority.Please enter again.";
        else {
            authority=auth;break;
            }
    }
    if (hospital::usersList.rbegin() != hospital::usersList.rend())
        id = ((hospital::usersList.rbegin())->first) + 1;
    else
        id = 1;

    hospital::usersList[id] = *this;            
    cout<<"\nRegister successfully!";
    cout<<"\nYour account:\n"<<account;
    cout<<"\nYour authority:\n"<<authority<<endl;
    return;
}

int user::user_find(string tempname)
{
	for (int i = 0; i < hospital::usersList.size(); i++)
	{
		if (hospital::usersList[i].account == tempname)
        {   //cout<<"found!!  "<<i<<endl;
			return i;}
	}
    //cout<<"not Found!!"<<endl;
	return -1;//not fuoud
}

int user::login_in_user()
{
	string tempname;
	string tempword;
	cout << endl << "Please enter your account name：";
    getline(cin >> ws, tempname);
	int a = user_find(tempname);
	if (a == -1)
	{
		cout << endl<<"-----This account doesn't exist！Return to the main menu-----"<<endl<<endl;
		return -1;
	}
	else {
		cout << endl << "Please enter your password：";
		cin >> tempword;
		if (tempword == hospital::usersList[a].password)
		{
			cout << endl << "-----Login in successfully!-----" << endl;

			return hospital::usersList[a].authority;
		}
		else {
			cout << endl << "-----Wrong password!Return to the main menu-----" << endl<<endl;
			return -1;
		}
	}
}

