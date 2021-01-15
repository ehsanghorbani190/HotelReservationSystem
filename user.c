#include <stdio.h>
#include <string.h>
#include "vars.c"
void __intialize(int length){
    for (int i = 0; i < length; i++) users[i].roomNumber = -1;
}
void __delete_user(struct USER * user){
    (*user).roomNumber = -1;
}
void __chage_info(struct USER *  user , char newuser[] , char newpass[]){
    strcpy((*user).username , newuser);
    strcpy((*user).password , newpass);
}
void __delete_user(struct USER * user ,char newdate[]){
    strcpy((*user).date , newdate);
}
