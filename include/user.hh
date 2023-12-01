#ifndef USER 
#define USER
using namespace std;
#include<string>

class user
{
private:
    int id;
    string account;
    string password;
    int authority;
public:
    user();
    void fillMap();
    void saveMap();
    void sign_up_user();
    int user_find(string tempname);
    int login_in_user();

};








#endif // !USER #define USER