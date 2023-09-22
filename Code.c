//Importation of standard libraries
#include <stdio.h>
#include <string.h>//String manipulation functions
#include <stdlib.h>

//Defining the constant values
#define maxSize 101//maximum length of the string array
#define sSize 26

// Initialization of variables
int top = -1;
int stackString[maxSize];//stack array

// Implementation of function to check if the stack is empt
int emptyStack() {
    return top == -1;
}

// Implementation of function to check if the stack is full
int fullStack() {
    return top == maxSize - 1;
}

//Implementation of push function
void pushStack(int value) {
    if (fullStack()) {
        return;
    }
    top++;
    stackString[top] = value;
}

//implementation of pop function
int popStack() {
    if (emptyStack()) {
        return -1;
    }
    int value = stackString[top];
    top--;
    return value;
}

//implementation of main function
int main() {
	//Declaration of variables
    char string[maxSize];
    int k, m, n, length, count = 0;
    
    //Get user input for string
    printf("Enter the string: ");
	scanf("%s", string);//Read Input
	
	//check if the string only contains lowercase letters
	for (m = 0; m < strlen(string); m++) {
        if (!islower(string[m])) {
        	printf("Your string includes uppercase letters!");
            printf("Please enter only lowercase letters: ");
            scanf("%s", string);//Re-Input 
        }
	}
	
	//Get user input for k 
	printf("Enter the value for K: ");
	scanf("%d", &k);
	
    length = strlen(string);//Lenth of the string

	//Initialization of sub string
    int subString[26] = {0};

    for (m = 0; m < k; m++) {
        int index = string[m] - 'a';
        subString[index]++;
        if (subString[index] == 2) { // Change from 1 to 2
            pushStack(index);
        }
    }

	//Incrementation of substring 
    for (m= k; m <= length; m++) {
        int max_freq = 0;
        for (n = 0; n < 26; n++) {
            if (subString[n] > max_freq) {
                max_freq = subString[n];
            }
        }
        if (max_freq > 1) {
            count++;
        }

        if (m < length) {
            int indexOut = string[m - k] - 'a';
            subString[indexOut]--;
            if (subString[indexOut] == 1) { //push if duplicates available 
                pushStack(indexOut);
            }
            int indexIn = string[m] - 'a';
            subString[indexIn]++;
            if (subString[indexIn] == 2) { //pop if duplicates are not available 
                popStack();
            }
        }
    }
    
    printf("Number of Operations without duplicates: %d\n", count);
    return 0;
}
