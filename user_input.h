#ifndef USER_INPUT_H
#define USER_INPUT_H

// Function prototypes for user input handling
int getGender(const char *input);
int getActivityLevel(const char *input);
void loadTips(const char *filename, char tips[][256], int *numTips);
void saveResults(const char *filename, char gender, int age, float weight, char activityLevel, float waterIntake);

#endif
