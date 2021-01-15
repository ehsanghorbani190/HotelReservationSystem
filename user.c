#include <stdio.h>
#include <string.h>
void __delete_user(struct USER * user){
    (*user).roomNumber = -1;
}
void __chage_info(struct USER *  user , char newuser[] , char newpass[]){
    strcpy((*user).username , newuser);
    strcpy((*user).password , newpass);
}
void __update_users_date(struct USER * user ,char newdate[]){
    strcpy((*user).date , newdate);
}
