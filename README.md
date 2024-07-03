# H2O Intake Calculator

H2O Intake Calculator is a simple C program that calculates the amount of water a person should drink in a day based on their gender, age, weight, and physical activity level. The program also provides some snarky and funny responses for invalid inputs and displays random tips about the benefits of drinking water.

## Table of Contents
1. [Features](#features)
2. [How to Compile and Run](#how-to-compile-and-run)
3. [Files](#files)
    - [H2in.c](#h2inc)
    - [calculation.h and calculation.c](#calculationh-and-calculationc)
    - [user_input.h and user_input.c](#user_inputh-and-user_inputc)
    - [validation.h and validation.c](#validationh-and-validationc)
    - [tips.txt](#tipstxt)
4. [Functions](#functions)
    - [H2in.c](#h2inc)
    - [calculation.h and calculation.c](#calculationh-and-calculationc)
    - [user_input.h and user_input.c](#user_inputh-and-user_inputc)
    - [validation.h and validation.c](#validationh-and-validationc)
5. [Adding More Snarky Responses and Tips](#adding-more-snarky-responses-and-tips)
6. [Credits](#credits)

## Features

- Calculates daily water intake based on user inputs.
- Validates user inputs and provides humorous feedback for invalid entries.
- Displays random tips about the benefits of drinking water.
- Saves user inputs and results to a file.
- Uses colors and clears the screen for a better user experience.
- Displays a program title in ASCII art.

## How to Compile and Run

To compile the program, use the following command:

`gcc -o H2in H2in.c calculation.c user_input.c validation.c`


To run the program, use the following command:

`./H2in`


## Files

- H2in.c
The main program file that handles user input and output.

- calculation.h and calculation.c
Contains the function to calculate water intake.

- user_input.h and user_input.c
Handles user input and loads tips from a file.

- validation.h and validation.c
Validates user inputs and provides snarky responses.

- tips.txt
Contains tips about the benefits of drinking water.

## Functions

### H2in.c
- `clearScreen()`: Clears the screen based on the operating system.
- `printTitle()`: Prints the program title in ASCII art.
- `printTips(const char tips[][256], int numTips)`: Prints a random tip from the tips array.
- `setColor(const char *color)`: Sets the text color based on the operating system.
- `resetColor()`: Resets the text color to default based on the operating system.

### calculation.h and calculation.c
- `float calculateWaterIntake(char gender, int age, float weight, char activityLevel)`: Calculates the daily water intake based on gender, age, weight, and physical activity level.

### user_input.h and user_input.c
- `int getGender(const char *input)`: Converts gender input to a character.
- `int getActivityLevel(const char *input)`: Converts activity level input to a character.
- `void loadTips(const char *filename, char tips[][256], int *numTips)`: Loads tips from a file into an array.
- `void saveResults(const char *filename, char gender, int age, float weight, char activityLevel, float waterIntake)`: Saves user inputs and results to a file.

### validation.h and validation.c
- `int validateAge(int age)`: Validates the age input and provides a snarky response if invalid.
- `int validateWeight(float weight)`: Validates the weight input and provides a snarky response if invalid.
- `int validateActivityLevel(const char *input)`: Validates the activity level input and provides a snarky response if invalid.
- `void printSnarkyResponse(int responseType)`: Prints a snarky response based on the response type.

## Adding More Snarky Responses and Tips

To add more snarky responses, update the `printSnarkyResponse` function in `validation.c`.
To add more tips, update the `tips.txt` file.

# Credits
This program was created by Medayoubadri.
