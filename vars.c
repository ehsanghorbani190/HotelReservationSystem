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
void __intialize()
{
    FILE *adminfile;
    adminfile = fopen("admin.dat", "rb");
    if (!adminfile)
    {
        printf("No Admin data found.\n");
        exit(0);
    }
    fread(&admin, sizeof(struct ADMIN), 1, adminfile);
    fclose(adminfile);
    FILE *reservefile, *usersfile;
    reservefile = fopen("reserver.dat", "rb");
    if (!reservefile)
        for (int i = 0; i < 6; i++)
            reservers[i].username[0] = '\0';
    else
    {
        fread(&reservers, sizeof(struct RESERVER), 6, reservefile);
    }
    fclose(reservefile);
    usersfile = fopen("user.dat", "rb");
    if (!usersfile)
        for (int i = 0; i < 1000; i++)
            users[i].roomNumber = -1;
    else
    {
        fread(&users, sizeof(struct USER), 1000, usersfile);
    }
    fclose(usersfile);
}
void __summrize()
{
    FILE *adminfile, *userfile, *reserverfile;
    adminfile = fopen("admin.dat", "wb");
    fwrite(&admin, sizeof(struct ADMIN), 1, adminfile);
    fclose(adminfile);
    userfile = fopen("user.dat", "wb");
    fwrite(&users, sizeof(struct USER), 1000, userfile);
    fclose(userfile);
    reserverfile = fopen("reserver.dat", "wb");
    fwrite(&reservers, sizeof(struct RESERVER), 6, reserverfile);
    fclose(reserverfile);
}
/*
int main(){
    FILE * file = fopen("admin.dat" , "wb");
    strcpy(admin.username , "admin");
    strcpy(admin.password , "admin");
    fwrite(&admin ,sizeof(struct ADMIN) , 1 , file);
    fclose (file);
}
*/