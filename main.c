#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include "vars.c"
#include "admin.c"
#include "user.c"
#include "reserver.c"

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
int main()
{
    __intialize();
    int i = 0;
    char ch, username[255], password[255], temp;
    printf("Who are you ? admin(press a) , reserver(press r) or user(press u) ,[press amything else to exit]\n");
    ch = getch();
    printf("please enter your username:\n");
    scanf("%s", username);
    printf("please enter your password:\n");
    do
    {
        temp = getch();
        printf("X");
        if (temp != 13)
        {
            password[i] = temp;
            i++;
        }
        if (temp == '\b')
        {
            printf("\b");
            password[i] = '\0';
            i--;
        }
    } while (temp != 13);
    password[i] = '\0';
    if (ch == 'a' || ch == 'A')
    {
        if (strcmp(password, admin.password) == 0 && strcmp(username, admin.username) == 0)
        {
            while (ch != 27)
            {
                system("cls");
                printf("*******************\n");
                printf("Welcome to Hotel Reservation system ! You logged in as Admin.\n");
                printf("You can Remove a user(press 1)\nAdd a Reserver (press 2)\nRemove a Reserver(press 3)\nChange Your username and password(press 4)\nFind Reserver(press 5)\nFind a user(press 6)\n");
                ch = getch();
                if (ch == '1')
                {
                    system("cls");
                    printf("You can Remove a user\nBy Username(press 1)\nBy RoomNumber(press 2)");
                    ch = '\0';
                    ch = getch();
                    if (ch == '1')
                    {
                        char user[255];
                        printf("\nPlease enter User name:");
                        scanf("%s", user);
                        __admin_delete_user__by_username(user);
                        printf("press anything to go back to the menu");
                        getch();
                        ch = '\0';
                    }
                    else if (ch == '2')
                    {
                        int roomnum;
                        printf("\nPlease enter room Number:");
                        scanf("%d", &roomnum);
                        __admin_delete_user__by_roomNumber(roomnum);
                        printf("press anything to go back to the menu");
                        getch();
                        ch = '\0';
                    }
                }
                else if (ch == '2')
                {
                    __add_new_reserver();
                    printf("press anything to go back to the menu");
                    getch();
                    ch = '\0';
                }
                else if (ch == '3')
                {
                    char user[255];
                    printf("\nPlease enter User name:");
                    scanf("%s", user);
                    __delete_reserver(user);
                    printf("\npress anything to go back to the menu");
                    getch();
                    ch = '\0';
                }
                else if (ch == '4')
                {
                    char user[255], pass[255];
                    printf("Please enter new username:");
                    scanf("%s", user);
                    printf("Please enter new password:");
                    scanf("%s", pass);
                    __change_admin_info(user, pass);
                    printf("press anything to go back to the menu");
                    getch();
                    ch = '\0';
                }
                else if (ch == '5')
                {
                    char user[255];
                    printf("\nPlease enter User name:");
                    scanf("%s", user);
                    __admin_search_reserver_by_username(user);
                    printf("press anything to go back to the menu");
                    getch();
                    ch = '\0';
                }
                else if (ch == '6')
                {
                    system("cls");
                    printf("You can Find a user\nBy Username(press 1)\nBy RoomNumber(press 2)");
                    ch = '\0';
                    ch = getch();
                    if (ch == '1')
                    {
                        char user[255];
                        printf("\nPlease enter User name:");
                        scanf("%s", user);
                        __admin_search_by_username(user);
                        printf("press anything to go back to the menu");
                        getch();
                        ch = '\0';
                    }
                    else if (ch == '2')
                    {
                        int roomnum;
                        printf("\nPlease enter room Number:");
                        scanf("%d", &roomnum);
                        __admin_search_by_room_number(roomnum);
                        printf("press anything to go back to the menu");
                        getch();
                        ch = '\0';
                    }
                }
            }
        }
        else
        {
            printf("Invalid username or password. press anything to exit");
            getch();
            exit(0);
        }
    }
    else if (ch == 'r' || ch == 'R')
    {
        int islogged = 0, k = 0;
        for (; k < 6; k++)
        {
            if (strcmp(reservers[k].username, username) == 0 && strcmp(reservers[k].password, password) == 0)
            {
                islogged = 1;
                break;
            }
        }
        if (islogged)
        {
            while (ch != 27)
            {
                system("cls");
                printf("*******************\n");
                printf("Welcome to Hotel Reservation system ! You logged in as reserver.\n");
                printf("You can Add a reservation(press 1)\nRemove reservation by username(press 2)\nFind user(press 3)\nFind Reserver of a room(press 4)\nChange Your username and password(press 5)");
                ch = getch();
                if (ch == '1')
                {
                    __add_new_user();
                    printf("press anything to go back to the menu");
                    getch();
                    ch = '\0';
                }
                else if (ch == '2')
                {
                    char user[255];
                    printf("Please Enter username:");
                    scanf("%s", user);
                    __delete_reservation(user);
                    printf("press anything to go back to the menu");
                    getch();
                    ch = '\0';
                }
                else if (ch == '3')
                {
                    char user[255];
                    printf("Please Enter username:");
                    scanf("%s", user);
                    __search_by_username(user);
                    printf("press anything to go back to the menu");
                    getch();
                    ch = '\0';
                }
                else if (ch == '4')
                {
                    int roomnum;
                    printf("Please Enter room number:");
                    scanf("%d", &roomnum);
                    __search_by_room_number(roomnum);
                    printf("press anything to go back to the menu");
                    getch();
                    ch = '\0';
                }
                else if (ch == '5')
                {
                    char user[255], pass[255];
                    printf("Please enter new username:");
                    scanf("%s", user);
                    printf("Please enter new password:");
                    scanf("%s", pass);
                    __change_reserver_info(&reservers[k], user, pass);
                    printf("press anything to go back to the menu");
                    getch();
                    ch = '\0';
                }
            }
        }
        else
        {
            printf("No Reserver Found with this username and password");
            printf("press anything to exit");
            exit(0);
        }
    }
    else if (ch == 'u' || ch == 'U')
    {
        int islogged = 0, k = 0;
        for (; k < 1000; k++)
        {
            if (strcmp(users[k].username, username) == 0 && strcmp(users[k].password, password) == 0 && users[k].roomNumber != -1)
            {
                islogged = 1;
                break;
            }
        }
        if (islogged)
        {
            while (ch != 27)
            {
                system("cls");
                printf("*******************\n");
                printf("Welcome to Hotel Reservation system ! You logged in as User.\n");
                printf("You can continue your reservation(press 1)\nRemove your reservation(press 2)\nChange Your username and password(press 3)");
                ch = getch();
                if (ch == '1')
                {
                    char newdate[11];
                    printf("Please enter new date for reservation: (dd/mm/yyyy)\n");
                    scanf("%s", newdate);
                    __update_users_date(&users[k], newdate[]);
                    printf("press anything to go back to the menu");
                    getch();
                    ch = '\0';
                }
                else if (ch == '2')
                {
                    __delete_user(&users[k]);
                    exit(0);
                }
                else if (ch == '3')
                {
                    char user[255], pass[255];
                    printf("Please enter new username:");
                    scanf("%s", user);
                    printf("Please enter new password:");
                    scanf("%s", pass);
                    __change_info(&users[k], user, pass);
                    printf("press anything to go back to the menu");
                    getch();
                    ch = '\0';
                }
            }
        }
        else
        {
            printf("No User Found with this username and password");
            printf("press anything to exit");
            exit(0);
        }
    }
    __summrize();
}