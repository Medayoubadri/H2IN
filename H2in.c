#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#endif
#include "calculation.h"
#include "user_input.h"
#include "validation.h"

// Function prototypes
void clearScreen();
void printTitle();
void printTips(const char tips[][256], int numTips);
void setColor(const char *color);
void resetColor();

int main() {
    char genderStr[10];
    char gender;
    int age;
    float weight;
    char activityLevelStr[10];
    char activityLevel;
    float waterIntake;
    char continueFlag;

    // Array to store tips and the number of tips loaded
    char tips[100][256];
    int numTips = 0;

    // Load tips from the file
    loadTips("tips.txt", tips, &numTips);

    clearScreen();
    printTitle();

    do {
        // Get user input for gender
        printf("Enter your gender (Male/Female): ");
        scanf("%s", genderStr);
        gender = getGender(genderStr);

        // Get and validate user input for age
        do {
            printf("Enter your age: ");
            scanf("%d", &age);
        } while (!validateAge(age));

        // Get and validate user input for weight
        do {
            printf("Enter your weight (in kg): ");
            scanf("%f", &weight);
        } while (!validateWeight(weight));

        // Get and validate user input for physical activity level
        do {
            printf("Enter your physical activity level (Low/Medium/High): ");
            scanf("%s", activityLevelStr);
        } while (!validateActivityLevel(activityLevelStr));

        // Convert activity level to a character
        activityLevel = getActivityLevel(activityLevelStr);

        // Calculate water intake
        waterIntake = calculateWaterIntake(gender, age, weight, activityLevel);

        // Display the calculated water intake
        setColor("green");
        printf("You should drink %.2f liters of water per day.\n", waterIntake);
        resetColor();

        // Save results to file
        saveResults("results.txt", gender, age, weight, activityLevel, waterIntake);

        // Display a random tip
        printTips(tips, numTips);

        // Check if the user wants to perform another calculation
        printf("Do you want to calculate again? (Y/N): ");
        scanf(" %c", &continueFlag);
    } while (continueFlag == 'Y' || continueFlag == 'y');

    return 0;
}

// Function to clear the screen based on the operating system
void clearScreen() {
    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #else
        system("clear");
    #endif
}

// Function to set the text color based on the operating system
void setColor(const char *color) {
    #if defined(_WIN32) || defined(_WIN64)
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        if (strcmp(color, "green") == 0) {
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
        } else if (strcmp(color, "red") == 0) {
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
        }
        // Add more colors as needed
    #else
        if (strcmp(color, "green") == 0) {
            printf("\033[0;32m");
        } else if (strcmp(color, "red") == 0) {
            printf("\033[0;31m");
        }
        // Add more colors as needed
    #endif
}

// Function to reset the text color to default based on the operating system
void resetColor() {
    #if defined(_WIN32) || defined(_WIN64)
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    #else
        printf("\033[0m");
    #endif
}

// Function to print the program title in ASCII art
void printTitle() {
    printf("\n");
    printf(" /$$   /$$  /$$$$$$  /$$$$$$ /$$   /$$\n");
    printf("| $$  | $$ /$$__  $$|_  $$_/| $$$ | $$\n");
    printf("| $$  | $$|__/  \\ $$  | $$  | $$$$| $$\n");
    printf("| $$$$$$$$  /$$$$$$/  | $$  | $$ $$ $$\n");
    printf("| $$__  $$ /$$____/   | $$  | $$  $$$$\n");
    printf("| $$  | $$| $$        | $$  | $$\\  $$$\n");
    printf("| $$  | $$| $$$$$$$$ /$$$$$$| $$ \\  $$\n");
    printf("|__/  |__/|________/|______/|__/  \\__/\n");
    printf("\n");
}

// Function to print a random tip from the tips array
void printTips(const char tips[][256], int numTips) {
    if (numTips > 0) {
        printf("%s\n", tips[rand() % numTips]);
    } else {
        printf("No tips available.\n");
    }
}
