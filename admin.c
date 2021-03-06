#include <stdio.h>
#include <string.h>

int ADeleteUserUserName(char username[]){
    for (int i = 0; i < 1000; i++)
    {
        if(strcmp(users[i].username , username) == 0) {
            users[i].roomNumber = -1;
            printf("Reservation Deleted successfully\n");
            return 1;
        }
    }
    printf("No User Found with given username\n");
    return 0;
}
int ADeleteUserRoomNumber(int roomNumber){
    for (int i = 0; i < 1000; i++)
    {
        if(users[i].roomNumber == roomNumber) {
            users[i].roomNumber = -1;
            printf("Reservation Deleted successfully\n");
            return 1;
        }
    }
    printf("No User Found with given username\n");
    return 0;
}
int AddReserver(){
    char pwd[255] , temp;
    int i = 0, j = 0;
    for (; reservers[j].username[0] != '\0'; j++);
    if(j>=6) {
        printf("We have enough reservers\n");
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
int DeleteReserver(char username[]){
    for (int i = 0; i < 1000; i++)
    {
        if(strcmp(reservers[i].username , username) == 0) {
            reservers[i].username[0] = '\0';
            printf("Reserver Deleted successfully\n");
            return 1;
        }
    }
    printf("No Reserver Found with given username\n");
    return 0;
}
void AUpdate(char  username[255] , char  password[255]){
    strcpy(admin.username , username);
    strcpy(admin.password , password);
}
int ASearchUserUserName(char username[]){
    int isFound= 0;
   for (int i = 0; i < 1000; i++)
    {
        if(strstr(users[i].username , username) != NULL) {
            isFound = 1;
            printf("User : %s , Age : %d ,  Reserve Date : %s , Phone number : %s , RoomNumber : %d\n",users[i].username , users[i].age , users[i].date , users[i].phoneNumber , users[i].roomNumber );
        }
    } 
    if(isFound){
        return 1;
    }
    else{
        printf("No User Found with given username\n");
        return 0;
    }
}
int ASearchUserRoomNumber(int roomNumber){

for (int i = 0; i < 1000; i++)
    {
        if(users[i].roomNumber == roomNumber) {
            printf("User : %s , Age : %d ,  Reserve Date : %s , Phone number : %s is in the room with RoomNumber : %d\n",users[i].username , users[i].age , users[i].date , users[i].phoneNumber , users[i].roomNumber );
            return 1;
        }
    } 
    printf("No User Found with given room number\n");
    return 0;
}
int ASearchReserver(char username[]){
    int isFound= 0;
   for (int i = 0; i < 1000; i++)
    {
        if(strstr(reservers[i].username , username) != NULL) {
            isFound = 1;
            printf("Reserver : %s\n" , reservers[i].username );
        }
    } 
    if(isFound){
        return 1;
    }
    else{
        printf("No User Found with given username\n");
        return 0;
    }
}