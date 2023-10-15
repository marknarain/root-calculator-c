// root_c.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include "root.h"

int main()
{
    //char input[100] = "123";
    char input[100];
    int decimalPlaces;

    printf("Enter a number (Max. 9999999999999999) only positive integer numbers, no decimal places):\n");
    scanf_s("%99s", input, (unsigned int)sizeof(input));

    input[99] = '\0';

    if (strlen(input) > 16) {
        printf("\nYou made a wrong entry. Please start the program again.\n\n");
        exit(0);
    }

    int* pArray = splitNumber(input);

    if (pArray == 0) {
        printf("\nYou made a wrong entry. Please start the program again.\n\n");
        exit(0);
    }

    /*
    The max. number of digits is determined by the size of the entered number. 
    9 is the number of digits, this program can calculate, - pArray[0] + 1 because pArray[0] gives us the
    the number of digits before the comma of the result. The first digit doesn't count yet.
    */

    int maxAllowed = 8 - pArray[0];
    
    printf("How many decimal places do you wish to see? (Max: %d)\n", maxAllowed);
    scanf_s("%d", &decimalPlaces);
    
    int* pRootNum = root(input, decimalPlaces);
    
    if ((pRootNum == 0) || (decimalPlaces < 0) || (decimalPlaces > maxAllowed)) {
        printf("\nYou made a wrong entry. Please start the program again.\n\n");
        exit(0);
    }

    printf("\nThe result is:\n");

    for (int i = 0; i < (pRootNum[0]-1); i++) {
        if (i == pRootNum[1]-1) {
            printf(",");
            printf("%d", pRootNum[i + 2]);
            continue;
        }
        printf("%d", pRootNum[i + 2]);
    }

    printf("\n\n");

    pArray = 0;
}