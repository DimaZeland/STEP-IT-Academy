#include "Menu.h"

void
Menu::Calculator(void) const { // calculator
    bool flag = true;
    while (flag) {
        system("cls");
        cout << "Enter [first number] [math operator] [second number]: ";
        double firstNumber = 0, secondNumber = 0;
        char op = '+';
        cin >> firstNumber >> op >> secondNumber;
        try { // search for the elimination of division by zero

            double result{0.0};

            switch (op) {
                case '+': {
                    result = firstNumber + secondNumber;
                    break;
                }
                case '-': {
                    result = firstNumber - secondNumber;
                    break;
                }
                case '*': {
                    result = firstNumber * secondNumber;
                    break;
                }
                case '/': {
                    if (secondNumber == 0) throw 1;
                    result = firstNumber / secondNumber;
                    break;
                }
                case 'Z': {
                    result = pow(firstNumber, secondNumber);
                    break;
                }
                default: {
                    break;
                }
            }
            cout << result << endl;
        }
        catch (int) {
            cout << "\nCan not be divided by 0!\n";
        }
        cout << "\nTo continue working in the program, press 1, to exit - 0: ";
        cin >> flag;
    }
}

void
Menu::Converter(void) const { // currency converter
    bool flag = true;
    while (flag) {
        system("cls");
        cout << "Enter <value> and <currency[EUR, USD]>: ";
        float value = 0;
        std::string valuta = "EUR";
        cin >> value >> valuta;

        constexpr float euruah = 32.10f;
        constexpr float usduah = 27.50f;

        float result = (valuta == "EUR") ? value * euruah : value * usduah;

        cout << endl << value << ' ' << valuta << " is " << result << " UAH\n";
        cout << "To continue working in the program, press 1, to exit - 0: ";
        cin >> flag;
    }
}

void
Menu::ConverterWeight(void) const { // weight converter
    bool flag = true;
    while (flag) {
        system("cls");
        cout
                << "Enter <value>, <type weight[kg, gramm, tonna, centner]>, <type converter[kg, gramm, tonna, centner]>: ";

        double value = 0;
        std::string typeWeight = "kg";
        std::string typeConverter = "gramm";

        cin >> value >> typeWeight >> typeConverter;

        double firstValue = value;
        int FirstTypeWeight = typeWeight.at(0);
        int FirstTypeConverter = typeConverter.at(0);

        switch (FirstTypeWeight) { // to gramm
            case 107: // k
                value *= 1000; // kg to gramm
                break;
            case 103: // g
                break;
            case 116: // k
                value *= 1000000; // ton to gramm
                break;
            case 99: // k
                value *= 100000; // hundredweight to gramm
                break;
            default:
                break;
        }

        // convert
        switch (FirstTypeConverter) { //from gramm to
            case 107: // k
                value /= 1000; // to gramm
                break;
            case 103: // g
                break;
            case 116: // k
                value /= 1000000; // ton to gramm
                break;
            case 99: // k
                value /= 100000; // hundredweight to gramm
                break;
            default:
                break;
        }

        cout << endl << firstValue << ' ' << typeWeight << " is " << value << ' ' << typeConverter << endl;
        cout << "To continue working in the program, press 1, to exit - 0: ";
        cin >> flag;
    }
}

void
Menu::ProgramInterface() const { // program interface

    unsigned short action = 0;
    float distance = 0.0f, litersPer100km = 0.0f, oilPrice = 0.0f;

    do {
        cout
                << "Please select an action (1 - calculator, 2 - currency converter, 3 - converter weight, 4 - trip cost calculation, 0 - exit):";
        cin >> action;
        system("cls");
        switch (action) {
            case 1:
                Menu::Calculator();
                break;
            case 2:
                Menu::Converter();
                break;
            case 3:
                Menu::ConverterWeight();
                break;
            case 4:
                cout
                        << "\nEnter the distance, the consumption of gasoline (liters per 100 km), the cost of a liter of gasoline:";
                cin >> distance >> litersPer100km >> oilPrice;
                cout << "\nThe cost of the trip is " << Menu::CostTrip(distance, litersPer100km, oilPrice) << "$\n";
                break;
            case 0:
                cout << "\nThe exit was successful! Bye!\n";
                break;
            default:
                cout << "\nInvalid Input!";
                break;
        }
    } while (action);
}