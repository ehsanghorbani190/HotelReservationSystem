#include <stdio.h>
#include <string.h>
#include "vars.c"
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
