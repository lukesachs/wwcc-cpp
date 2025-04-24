#include <iostream>
using namespace std;

//function prototype
void convertTemperature(char temp, double firstTemp, double &celsius, double &fahrenheit, double &kelvin);


int main() {
    //declaring variables
    char temp;
    double firstTemp, celsius, fahrenheit, kelvin;

    cout << "Enter a temperature value: ";
    cin >> firstTemp;
    cout << "\nEnter the unit (C for Celsius, F for Fahrenheit, K for Kelvin): ";
    cin >> temp;

    convertTemperature(temp, firstTemp, celsius, fahrenheit, kelvin);

    cout << "\n\nTemperature Conversions:" << endl;
    printf("Celsius: %.2f°C\n", celsius);
    printf("Fahrenheit: %.2f°F\n", fahrenheit);
    printf( "Kelvin: %.2fK\n", kelvin);

    return 0;
}

void convertTemperature(char temp, double firstTemp, double &celsius, double &fahrenheit, double &kelvin){
    switch (temp) {
    case 'C':
    celsius = firstTemp;
        fahrenheit = (celsius * 9 / 5) + 32;
        kelvin = celsius + 273.15;
    break;
    case 'F':
        fahrenheit = firstTemp;
        celsius = (fahrenheit - 32) * 5 / 9;
        kelvin = celsius + 273.15;
    break;
    case 'K':
        kelvin = firstTemp;
        celsius = kelvin - 273.15;
        fahrenheit = (celsius * 9 / 5) + 32;
    break;
    default:
        cout << "Invalid temperature unit" << endl;
    }


}