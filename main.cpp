
#include "student.h"

int main(){
    Student A;
    A.password = "helloworld";
    string myuser = getLineHidden();
    A.changePassword();
    return 0;
}