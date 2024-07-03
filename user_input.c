#include <stdio.h>
#include <string.h>
#include "user_input.h"

// Function to convert gender input to a character
int getGender(const char *input) {
    if (strcmp(input, "Male") == 0 || strcmp(input, "male") == 0 || strcmp(input, "M") == 0 || strcmp(input, "m") == 0) {
        return 'M';
    } else if (strcmp(input, "Female") == 0 || strcmp(input, "female") == 0 || strcmp(input, "F") == 0 || strcmp(input, "f") == 0) {
        return 'F';
    } else {
        return 'M'; // Default to Male if unrecognized input
    }
}

// Function to convert activity level input to a character
int getActivityLevel(const char *input) {
    if (strcmp(input, "Low") == 0 || strcmp(input, "low") == 0) {
        return 'L';
    } else if (strcmp(input, "Medium") == 0 || strcmp(input, "medium") == 0) {
        return 'M';
    } else if (strcmp(input, "High") == 0 || strcmp(input, "high") == 0) {
        return 'H';
    } else {
        return 'L'; // Default to Low if unrecognized input
    }
}

// Function to load tips from a file into an array
void loadTips(const char *filename, char tips[][256], int *numTips) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Unable to open the tips file");
        return;
    }

    *numTips = 0;
    while (fgets(tips[*numTips], 256, file) != NULL) {
        // Remove newline character at the end if present
        size_t len = strlen(tips[*numTips]);
        if (len > 0 && tips[*numTips][len - 1] == '\n') {
            tips[*numTips][len - 1] = '\0';
        }
        (*numTips)++;
    }

    fclose(file);
}

// Function to save user inputs and results to a file
void saveResults(const char *filename, char gender, int age, float weight, char activityLevel, float waterIntake) {
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        perror("Unable to open the results file");
        return;
    }

    fprintf(file, "Gender: %c, Age: %d, Weight: %.2f kg, Activity Level: %c, Water Intake: %.2f liters\n",
            gender, age, weight, activityLevel, waterIntake);

    fclose(file);
}

