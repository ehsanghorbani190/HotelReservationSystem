#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include "vars.c"
#include "admin.c"
#include "user.c"
#include "reserver.c"


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
                        ADeleteUserUserName(user);
                    }
                    else if (ch == '2')
                    {
                        int roomnum;
                        printf("\nPlease enter room Number:");
                        scanf("%d", &roomnum);
                        ADeleteUserRoomNumber(roomnum);
                    }
                }
                else if (ch == '2') AddReserver();
                else if (ch == '3')
                {
                    char user[255];
                    printf("\nPlease enter User name:");
                    scanf("%s", user);
                    DeleteReserver(user);
                }
                else if (ch == '4')
                {
                    char user[255], pass[255];
                    printf("Please enter new username:");
                    scanf("%s", user);
                    printf("Please enter new password:");
                    scanf("%s", pass);
                    AUpdate(user, pass);
                }
                else if (ch == '5')
                {
                    char user[255];
                    printf("\nPlease enter User name:");
                    scanf("%s", user);
                    ASearchReserver(user);
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
                        ASearchUserUserName(user);
                    }
                    else if (ch == '2')
                    {
                        int roomnum;
                        printf("\nPlease enter room Number:");
                        scanf("%d", &roomnum);
                        ASearchUserRoomNumber(roomnum);
                    }
                }
                printf("press anything to go back to the menu");
                getch();
                ch = '\0';
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
                printf("Welcome to Hotel Reservation system ! You logged in as Reserver.\n");
                printf("You can Add a reservation(press 1)\nRemove reservation by username(press 2)\nFind user(press 3)\nFind Reserver of a room(press 4)\nChange Your username and password(press 5)");
                ch = getch();
                if (ch == '1') AddUser();
                else if (ch == '2')
                {
                    char user[255];
                    printf("Please Enter username:");
                    scanf("%s", user);
                    RDeleteUser(user);
                }
                else if (ch == '3')
                {
                    char user[255];
                    printf("Please Enter username:");
                    scanf("%s", user);
                    RSearchUserName(user);
                }
                else if (ch == '4')
                {
                    int roomnum;
                    printf("Please Enter room number:");
                    scanf("%d", &roomnum);
                    RSearchRoomNumber(roomnum);
                }
                else if (ch == '5')
                {
                    char user[255], pass[255];
                    printf("Please enter new username:");
                    scanf("%s", user);
                    printf("Please enter new password:");
                    scanf("%s", pass);
                    RUpdate(&reservers[k], user, pass);
                }
                printf("press anything to go back to the menu");
                getch();
                ch = '\0';
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
                    UserExtend(&users[k], newdate);
                }
                else if (ch == '2')
                {
                    UserDelete(&users[k]);
                    exit(0);
                }
                else if (ch == '3')
                {
                    char user[255], pass[255];
                    printf("Please enter new username:");
                    scanf("%s", user);
                    printf("Please enter new password:");
                    scanf("%s", pass);
                    UUserUpdate(&users[k], user, pass);
                }
                printf("press anything to go back to the menu");
                getch();
                ch = '\0';
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