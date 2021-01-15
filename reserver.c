#include <stdio.h>
#include <conio.h>
#include <string.h>
#include "vars.c"

int __add_new_user(){
    char pwd[255] , temp;
    int i = 0, j = 0;
    for (; users[j].roomNumber != -1; j++);
    if(j>=1000) {
        printf("There's no empty room :(");
        return 0;
    }
    printf("Please Enter username:\n");
    scanf("%s" , users[j].username);
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
    strcpy(users[j].password , pwd);
    printf("Please Enter sex:\n");
    scanf("%s" , users[j].sex);
    printf("Please Enter phone number:\n");
    scanf("%s" , users[j].phoneNumber);
    printf("Please Enter age:\n");
    scanf("%d" , &users[j].age);
    printf("Please Enter date:\n");
    scanf("%s" , users[j].date);
    printf("Please Enter roomNumber:\n");
    scanf("%d" , &users[j].roomNumber);
    printf("User Added Succesfully");
    return 1;
}//Ali , ali
int __delete_reservation(char username[]){
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
int __search_by_username(char username[]){
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
int __search_by_room_number(int roomNumber){

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

void __change_reserver_info(struct RESERVER * reserver , char  username[255] , char  password[255]){
    strcpy((*reserver).username , username);
    strcpy((*reserver).password , password);
}