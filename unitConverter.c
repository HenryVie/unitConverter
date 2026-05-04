// Unit Converter CLI
// Author: Nguyễn Đình Nam
// Description: A command-line unit converter supporting temperature, mass, and length conversions.

#include <stdio.h>
#include <ctype.h>

int menuInput();
float getValue();
float convertTemperature(int direction, float value);
float convertMass(int direction, int pair, float value);
float convertLength(int direction, int pair, float value);

int main() {
    printf("==============================\n   UNIT CONVERTER PROGRAM\n==============================\n");

    while (1) {
        printf("Choose a unit system to convert:\n");
        printf("1. Imperial to Metric \n2. Metric to Imperial\n");

        int convertDirection = menuInput(2);

        printf("Choose a unit type to convert:\n");
        printf("1. Temperature \n2. Mass \n3. Length\n");

        int convertType = menuInput(3);
        int convertPair;

        switch (convertType) {
            case 2: //mass
                printf("Choose a pair of unit to convert:\n");
                if (convertDirection == 1) {
                    printf("1. Ounces to Grams \n2. Pounds to Kilograms \n3. Tons to Tonnes\n");
                    convertPair = menuInput(3);
                } //imperial to metric
                    
                
                else {
                    printf("1. Grams to Ounces \n2. Kilograms to Pounds \n3. Tonnes to Tons\n");
                    convertPair = menuInput(3);
                } //metric to imperial
                break;

            case 3: //length
                printf("Choose a pair of unit to convert:\n");
                if (convertDirection == 1) {
                    printf("1. Inches to Centimeters \n2. Foot to Meters \n3. Miles to Kilometers\n");
                    convertPair = menuInput(3);
                } //imperial to metric
                    
                else {
                    printf("1. Centimeters to Inches \n2. Meters to Foot \n3. Kilometers to Mile\n");
                    convertPair = menuInput(3);
                } //metric to imperial
                break;
            
        }

        float value = getValue();

        switch (convertType) {
            case 1: //temperature
                float result = convertTemperature(convertDirection, value);
                switch (convertDirection) {
                    case 1:
                        printf("Converted value: %.2f C.\n", result);
                        break;
                    case 2:
                        printf("Converted value: %.2f F.\n", result);
                        break;
                }
                break;
            case 2: //mass
                switch (convertDirection) {
                    case 1: //imperial to metric
                        result = convertMass(convertDirection, convertPair, value);

                        switch (convertPair) {
                            case 1:
                                printf("Converted value: %.2f g.\n", result);
                                break;
                            case 2:
                                printf("Converted value: %.2f kg.\n", result);
                                break;
                            case 3:
                                printf("Converted value: %.2f t.\n", result);
                                break;
                        }
                        break;
                    case 2: //metric to imperial
                        result = convertMass(convertDirection, convertPair, value);

                        switch (convertPair) {
                            case 1:
                                printf("Converted value: %.2f oz.\n", result);
                                break;
                            case 2:
                                printf("Converted value: %.2f lbs.\n", result);
                                break;
                            case 3:
                                printf("Converted value: %.2f t.\n", result);
                                break;
                        }
                        break;
                }
                break;
            case 3:
                switch (convertDirection) {
                    case 1: //imperial to metric
                        result = convertLength(convertDirection, convertPair, value);

                        switch (convertPair) {
                            case 1:
                                printf("Converted value: %.2f cm.\n", result);
                                break;
                            case 2:
                                printf("Converted value: %.2f m.\n", result);
                                break;
                            case 3:
                                printf("Converted value: %.2f km.\n", result);
                                break;
                        }
                    break;

                    case 2: //metric to imperial
                        result = convertLength(convertDirection, convertPair, value);

                        switch (convertPair) {
                            case 1:
                                printf("Converted value: %.2f in.\n", result);
                                break;
                            case 2:
                                printf("Converted value: %.2f ft.\n", result);
                                break;
                            case 3:
                                printf("Converted value: %.2f mil.\n", result);
                                break;
                        }
                    break;
                }
                break;
        }

        char quit;
        printf("Do you want to continue using the program? (y/n): ");        
        scanf(" %c", &quit);

        if (quit == 'y') {
            continue;
        }

        else if (quit == 'n') {
            printf("Program ends.");
            break;
        }
        else {
            printf("Invalid input. Progam end.");
            break;
        }
    }    
    return 0;
}

int menuInput(int option) {
    while (1) {
        int input;
        printf("Enter your choice (1 - %d): ", option);
                
        if (scanf("%d", &input) == 1) {
            if (1 <= input && input <= option) {
                printf("You chose %d\n", input);
                return input;
            }
            else {
                printf("Input must be from 1 to %d.\n", option);
            }
        }
        else {
            printf("Input must be a number.");
            while (getchar() != '\n');
        }
    }
}

float getValue() {
    while (1) {
        float input;
        printf("Enter your value: ");
        
        if (scanf("%f", &input) == 1) {
            return input;
        }
        else {
            printf("Input must be a number.");
            while (getchar() != '\n');
        }
    }
}

float convertTemperature(int direction, float value) {
    float converted;
    switch (direction) {
        case 1:
            converted = (value - 32) / 1.8;
            break;
        case 2:
            converted = (value * 1.8) + 32;
            break;
    }
    return converted;
}

float convertMass(int direction, int pair, float value) {
    float converted;
    switch (direction) {
        case 1: //imperial
            switch (pair) {
                case 1: //ounces to grams
                    converted = value * 28.3495;
                    break;
                case 2: //pounds to kilograms
                    converted = value / 2.20462;
                    break;
                case 3: //tons uk to tonnes metric
                    converted = value * 1.0160;
                    break;
            }
            break;
                
        case 2: //metric
            switch (pair) {
                case 1: //ounces to grams
                    converted = value / 28.3495;
                    break;
                case 2: //pounds to kilograms
                    converted = value * 2.20462;
                    break;
                case 3: //tons uk to tonnes metric
                    converted = value * 0.9842;
                    break;
            }
            break;
    }
    return converted;
}

float convertLength(int direction, int pair, float value) {
    float converted;
    switch (direction) {
        case 1: //imperial
            switch (pair) {
                case 1: //inches to centimeters
                    converted = value * 2.54;
                    break;
                case 2: //feet to meters
                    converted = value * 0.3048;
                    break;
                case 3: //miles to kilometers
                    converted = value * 1.60934;
                    break;
            }
            break;
                
        case 2: //metric
            switch (pair) {
                case 1: //centimeters to inches
                    converted = value / 2.54;
                    break;
                case 2: //meters to feet
                    converted = value * 3.2809;
                    break;
                case 3: //kilometers to miles
                    converted = value / 1.609;
                    break;
            }
            break;
    }
    return converted;
}