#include "Account.h"

Account::Account(string id, string username, string password, string type){
    this->id = id;
    this->username = username;
    this->password = password;
    this->type = type;
}

vector<Account> loadAccounts(string filepath)
{
    ifstream in(filepath);
    string line, field;
    vector<Account> array; // the 2D array
    vector<string> v;      // array of values for one line only

    while (getline(in, line)) // get next line in file
    {
        v.clear();
        stringstream ss(line);

        while (getline(ss, field, ',')) // break line into comma delimitted fields
        {
            v.push_back(field); // add each field to the 1D array
        }
        Account user(v[0], v[1], v[2], v[3]);
        array.push_back(user); // add the 1D array to the 2D array
    }
    return array;
}


void loginView()
{   //load all accounts
    vector <Account> Accounts = loadAccounts("db/accounts.csv");
    
    cout << "Please login first! " << endl;
    string username_input;
    string password_input;

    //enter username
    cout << "Username:";
    getline(cin, username_input);
    cout << "Password:";

    password_input = getLineHidden();
    for(size_t i = 0; i< Accounts.size();i++){
        if(Accounts[i].username == username_input && Accounts[i].password == password_input){
            return menuView(Accounts[i]);
        }
    }
    // if not found the account that user try to login
    cout << "This Account is invalid! Please try again." << endl;
    return loginView();
};

bool Account::changePassword()
{
    string new_password, old_password;

    cout << endl << "Enter your old password:";
    old_password = getLineHidden();
    if (old_password != this->password)
    {
        cout << "Invalid password!" << endl;
        return false;
    }
    cout << "Your new password:";

    new_password = getLineHidden();
    this->password = new_password;
    cout << "Successfully change password!";
    return true;
}

void menuView(Account user)
{
    system("cls");
    cout << "Welcome " + user.username + '!' << endl ;
    cout << "-------------------------"<<endl;
    cout << "1. ViewDetail " << endl;
    cout << "2. SignOut" << endl;

    // get the user input option
    char option;
    option = _getch();
    cout << option;
    if (option == '2'){
        system("cls");
        return loginView();
    }
    else{
        system("cls");
        if(user.type == "student")
            return studentView(user);
            
    }

}


void studentView(Account user){
    cout << "Information:" << endl;
    cout << "Position: " << user.type << endl;
    cout << "Class: "+getClassByStudentId(user.id)<<endl; 
    cout << "Current courses attending: "<<endl;
    auto courses = getCoursesByStudentId(user.id);
    for(int i = 0; i < courses.size(); i++){
        cout << "- " + courses[i] << endl;
    }
    cout << "------------------------------------------------" <<endl;
    cout <<"press 'q' to back...";
    _getch();
    return;

}