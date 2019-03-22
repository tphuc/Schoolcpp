#pragma once
#include <string>
#include "interface.h"
#include "csvhelper.h"
#include "query.h"

using namespace std;

struct Account {
    // Fields
    string id;
    string username;
    string password;
    string type;

    // Constructor
    Account(string id, string username, string password, string type);
    // Methods
    bool changePassword();
};

vector <Account> loadAccounts(string filepath);
string getAccountInfo(string username, string password);
string getStudentInfoByAccount(Account);


// Views
void loginView();
void menuView(Account);



void studentView(Account);
void adminView(Account);
