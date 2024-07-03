#include <stdio.h>
#include <string.h>
#include "validation.h"

// Function to validate age
int validateAge(int age) {
    if (age <= 0) {
        printSnarkyResponse(1);
        return 0;
    } else if (age > 120) {
        printSnarkyResponse(2);
        return 0;
    }
    return 1;
}

// Function to validate weight
int validateWeight(float weight) {
    if (weight <= 0) {
        printSnarkyResponse(3);
        return 0;
    } else if (weight > 500) {
        printSnarkyResponse(4);
        return 0;
    }
    return 1;
}

// Function to validate activity level
int validateActivityLevel(const char *input) {
    if (strcmp(input, "Low") == 0 || strcmp(input, "low") == 0 || 
        strcmp(input, "Medium") == 0 || strcmp(input, "medium") == 0 || 
        strcmp(input, "High") == 0 || strcmp(input, "high") == 0) {
        return 1;
    } else {
        printSnarkyResponse(5);
        return 0;
    }
}

// Function to print snarky responses
void printSnarkyResponse(int responseType) {
    switch (responseType) {
        case 1:
            printf("You should be dead or wait until you are born and then try this app. This isn't 'The Sixth Sense'.\n");
            break;
        case 2:
            printf("Are you sure you are over 120 years old? Are you a vampire from Twilight?\n");
            break;
        case 3:
            printf("You should be weightless or wait until you have some mass and then try this app. This isn't 'Interstellar'.\n");
            break;
        case 4:
            printf("Wow, that's bread-taking.. Are you sure you're not made of pure carbs? Time to cut back on the bakery runs!\n");
            break;
        case 5:
            printf("Invalid activity level. Please enter Low, Medium, or High. This isn't a Dragon Ball power level.\n");
            break;
        default:
            printf("Invalid input... (𓌻‸𓌻) ᴜɢʜ.\n");
            break;
    }
}

