# Unit Converter CLI
# Author: Nguyễn Đình Nam
# Description: A command-line unit converter supporting temperature, mass, and length conversions.

def menuInput(num_options = 2):
    while True:
        user_input = input(f"Enter your choice (1 - {num_options}): ").strip()

        if user_input == "":
            print("Input cannot be empty.")
            continue

        try:
            choice = int(user_input)
        except ValueError:
            print("Input must be a number.")
            continue

        if 1 <= choice <= num_options:
            print(f"You chose {choice}\n")
            return choice
        else:
            print(f"Input must be from 1 to {num_options}.")

def getValue():
    while True:
        user_input = input(f"Enter your value: ").strip()

        if user_input == "":
            print("Input cannot be empty.")
            continue

        try:
            user_input = float(user_input)
            return user_input
        except ValueError:
            print("Input must be a number.")
            continue

def convertTemperature(direction, value):
    match (direction):
        case 1: #imperial
            converted = (value - 32) / 1.8
        case 2: #metric
            converted = (value * 1.8) + 32
    return converted

def convertMass(direction, pair, value):
    match (direction):
        case 1: #imperial
            match (pair):
                case 1: #ounces to grams
                    converted = value * 28.3495
                case 2: #pounds to kilograms
                    converted = value / 2.20462
                case 3: #tons uk to tonnes metric
                    converted = value * 1.0160
        case 2: #metric
            match (pair):
                case 1: #ounces to grams
                    converted = value / 28.3495
                case 2: #pounds to kilograms
                    converted = value * 2.20462
                case 3: #tons uk to tonnes metric
                    converted = value * 0.9842
    return converted

def convertLength(direction, pair, value):
    match (direction):
        case 1: #imperial
            match (pair):
                case 1: #inches to centimeters
                    converted = value * 2.54
                case 2: #feet to meters
                    converted = value * 0.3048
                case 3: #miles to kilometers
                    converted = value * 1.60934
        case 2: #metric
            match (pair):
                case 1: #centimeters to inches
                    converted = value / 2.54
                case 2: #meters to feet
                    converted = value * 3.2809
                case 3: #kilometers to miles
                    converted = value / 1.609
    return converted

def main():
    print("==============================\n   UNIT CONVERTER PROGRAM\n==============================")

    while True:
        print("Choose a unit system to convert:")
        print("1. Imperial to Metric \n2. Metric to Imperial")

        convertDirection = menuInput(2)

        print("Choose a unit type to convert:")
        unitType = ["1. Temperature", "2. Mass", "3. Length"]
        for i in unitType:
            print(i)

        convertType = menuInput(3)

        match (convertType):
            case 2: #mass
                print("Choose a pair of unit to convert:")
                if convertDirection == 1: #imperial to metric
                    unitList = ["1. Ounces to Grams", "2. Pounds to Kilograms", "3. Tons to Tonnes"]
                    for i in unitList:
                        print(i)

                    convertPair = menuInput(3)
                
                else: #metric to imperial
                    unitList = ["1. Grams to Ounces", "2. Kilograms to Pounds", "3. Tonnes to Tons"]
                    for i in unitList:
                        print(i)

                    convertPair = menuInput(3)
                
            case 3: #length
                print("Choose a pair of unit to convert:")
                if convertDirection == 1: #imperial to metric
                    unitList = ["1. Inches to Centimeters", "2. Foot to Meters", "3. Miles to Kilometers"]
                    for i in unitList:
                        print(i)

                    convertPair = menuInput(3)
                
                else: #metric to imperial
                    unitList = ["1. Centimeters to Inches", "2. Meters to Foot", "3. Kilometers to Mile"]
                    for i in unitList:
                        print(i)

                    convertPair = menuInput(3)

        #input value to convert
        value = getValue()

        match (convertType):
            case 1:
                result = convertTemperature(convertDirection, value)
                match (convertDirection):
                    case 1:
                        print(f"Converted value: {result:.2f} C.\n")
                    case 2:
                        print(f"Converted value: {result:.2f} F.\n")
                
            case 2:
                match (convertDirection):
                    case 1: #imperial to metric
                        result = convertMass(convertDirection, convertPair, value)

                        match (convertPair):
                            case 1:
                                print(f"Converted value: {result:.2f} g.\n")
                            case 2:
                                print(f"Converted value: {result:.2f} kg.\n")
                            case 3:
                                print(f"Converted value: {result:.2f} t.\n")
                    case 2: #metric to imperial
                        result = convertMass(convertDirection, convertPair, value)

                        match (convertPair):
                            case 1:
                                print(f"Converted value: {result:.2f} oz.\n")
                            case 2:
                                print(f"Converted value: {result:.2f} lbs.\n")
                            case 3:
                                print(f"Converted value: {result:.2f} t.\n")
            
            case 3:
                match (convertDirection):
                    case 1: #imperial to metric
                        result = convertLength(convertDirection, convertPair, value)

                        match (convertPair):
                            case 1:
                                print(f"Converted value: {result:.2f} cm.\n")
                            case 2:
                                print(f"Converted value: {result:.2f} m.\n")
                            case 3:
                                print(f"Converted value: {result:.2f} km.\n")
                    case 2: #metric to imperial
                        result = convertLength(convertDirection, convertPair, value)

                        match (convertPair):
                            case 1:
                                print(f"Converted value: {result:.2f} in.\n")
                            case 2:
                                print(f"Converted value: {result:.2f} ft.\n")
                            case 3:
                                print(f"Converted value: {result:.2f} mil.\n")
        
        exit = input("Do you want to continue using the program? (y/n): ").strip().lower()

        if exit == "n":
            print("Program end.\n")
            break

main()