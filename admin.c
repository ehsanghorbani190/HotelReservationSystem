#include <stdio.h>
#include <string.h>
#include "vars.c"
int __admin_delete_user__by_username(char username[]){
    for (int i = 0; i < 1000; i++)
    {
        if(strcmp(users[i].username , username) == 0) {
            users[i].roomNumber = -1;
            printf("Reservation Deleted successfully");
            return 1;
        }
    }
    printf("No User Found with given username");
    return 0;
}
int __admin_delete_user__by_roomNumber(int roomNumber){
    for (int i = 0; i < 1000; i++)
    {
        if(users[i].roomNumber == roomNumber) {
            users[i].roomNumber = -1;
            printf("Reservation Deleted successfully");
            return 1;
        }
    }
    printf("No User Found with given username");
    return 0;
}
int __add_new_reserver(){
    char pwd[255] , temp;
    int i = 0, j = 0;
    for (; reservers[j].username[0] != '\0'; j++);
    if(j>=6) {
        printf("We have enough reservers");
        return 0;
    }
    printf("Please Enter username:\n");
    scanf("%s" , reservers[j].username);
    printf("Please Enter password:\n");
    do {
        temp = getch();
        printf("X");
        if(temp != 13) {
            pwd[i] = temp;
            i++;
        }
        if(temp == '\b'){
            printf("\b");
            pwd[i] = '\0';
            i--;
        }
    }while(temp != 13);
    pwd[i] ='\0';
    strcpy(reservers[j].password , pwd);
    return 1;
}
int __delete_reserver(char username[]){
    for (int i = 0; i < 1000; i++)
    {
        if(strcmp(reservers[i].username , username) == 0) {
            reservers[i].username[0] = '\0';
            printf("Reserver Deleted successfully");
            return 1;
        }
    }
    printf("No Reserver Found with given username");
    return 0;
}
void __change_reserver_info(char  username[255] , char  password[255]){
    strcpy(admin.username , username);
    strcpy(admin.password , password);
}
int __admin_search_by_username(char username[]){
    int isFound= 0;
   for (int i = 0; i < 1000; i++)
    {
        if(strstr(users[i].username , username) != NULL) {
            isFound = 1;
            printf("User : %s , Age : %d ,  Reserve Date : %s , Phone number : %s , RoomNumber : %d",users[i].username , users[i].age , users[i].date , users[i].phoneNumber , users[i].roomNumber );
        }
    } 
    if(isFound){
        return 1;
    }
    else{
        printf("No User Found with given username");
        return 0;
    }
}
int __admin_search_by_room_number(int roomNumber){

for (int i = 0; i < 1000; i++)
    {
        if(users[i].roomNumber == roomNumber) {
            printf("User : %s , Age : %d ,  Reserve Date : %s , Phone number : %s is in the room with RoomNumber : %d",users[i].username , users[i].age , users[i].date , users[i].phoneNumber , users[i].roomNumber );
            return 1;
        }
    } 
    printf("No User Found with given room number");
    return 0;
}
int __admin_search_reserver_by_username(char username[]){
    int isFound= 0;
   for (int i = 0; i < 1000; i++)
    {
        if(strstr(reservers[i].username , username) != NULL) {
            isFound = 1;
            printf("Reserver : %s" , reservers[i].username );
        }
    } 
    if(isFound){
        return 1;
    }
    else{
        printf("No User Found with given username");
        return 0;
    }
}