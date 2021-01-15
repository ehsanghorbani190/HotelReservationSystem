#include <stdio.h>
#include <string.h>

struct USER {
    char username[255] , password[255] , sex[10] , phoneNumber[15],date[11];
    int age, roomNumber;
} users[1000] ;
void __intialize(struct USER users[], int length){
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
