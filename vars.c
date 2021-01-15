//NOTE: in case of deletion of admin.dat , uncomment the comments below and compile this file to recover admin.dat
/*
#include <stdio.h>
#include <string.h>
*/
struct USER {
    char username[255] , password[255] , sex[10] , phoneNumber[15],date[11];
    int age, roomNumber;
} users[1000] ;
struct RESERVER {
    char username[255] , password[255];
} reservers[6];
struct ADMIN{
    char username[255] , password[255];
} admin;
/*
int main(){
    FILE * file = fopen("admin.dat" , "wb");
    strcpy(admin.username , "admin");
    strcpy(admin.password , "admin");
    fwrite(&admin ,sizeof(struct ADMIN) , 1 , file);
    fclose (file);
}
*/