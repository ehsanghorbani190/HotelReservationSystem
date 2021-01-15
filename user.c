#include <stdio.h>
#include <string.h>
void UserDelete(struct USER * user){
    (*user).roomNumber = -1;
}
void UUserUpdate(struct USER *  user , char newuser[] , char newpass[]){
    strcpy((*user).username , newuser);
    strcpy((*user).password , newpass);
}
void UserExtend(struct USER * user ,char newdate[]){
    strcpy((*user).date , newdate);
}
