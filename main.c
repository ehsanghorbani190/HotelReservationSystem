#include <stdio.h>
#include "vars.c"
void __intialize(int length){
    for (int i = 0; i < length; i++) users[i].roomNumber = -1;
    for (int i = 0; i < 6; i++) reservers[i].username[0] = '\0';
}
//'\0'000 