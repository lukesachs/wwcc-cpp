#include <iostream>

using namespace std;

int main() {
    double temperature;
    char unit;
    double newTemp;
    
    cout << "Temperature Converter" << endl;
    
    cout << "enter tempertaure value: " << endl;
    cin >> temperature;

    cout << "Enter unit (C for Celsius, F for Fahrenheit): " << endl;
    cin >> unit;

    if (unit == 'C') {
        newTemp = (temperature*9/5)+32;
        cout << temperature << "°C is equal to " << newTemp << "°F"<< endl;
    } else {
        newTemp = (temperature-32)*5/9;
        cout << temperature << "°F is equal to " << newTemp << "°C"<< endl;
    }
    
    
    return 0;
}
