#pragma once
#include <string>
#include "interface.h"

using namespace std;

struct Student {
    string username;
    string password;
    bool changePassword();
};
Student loginView();