#include "student.h"


bool loginView(){
    /* return User object after user login */
    cout << "Please login first! " << endl;
    string username_input;
    string password_input = "";
    cout << "Username:";
    getline(cin, username_input);
    cout << "Password:";

    
    char c = _getch();
    while(c != '\r')
    {
        cout << "*";
        password_input += c;
        c = _getch();
    }
    cout << endl;

    
    // find user from file
    // ... code here
    // user = findUser(username_input, password_input)

    // !!! testing only
    Student user;
    user.username = username_input;
    user.password = password_input;


    return true;
};


bool Student::changePassword(){
    string new_password, old_password;

    cout << endl << "Enter your old password:";
    old_password = getLineHidden();
    if(old_password != this->password){
        cout << "Invalid password!" << endl;
        return false;
    }
    cout << "Your new password:";
    
    new_password = getLineHidden();
    this->password = new_password;
    cout << "Successfully change password!" ;
    return true;
}