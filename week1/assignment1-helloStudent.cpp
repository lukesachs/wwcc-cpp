#include <iostream>
#include <string>

using namespace std;

int main() {
    string name;
    string password;
    cout << "Enter your name: ";
    cin >> name;
    cout << "Hello, " << name << "! Welcome to C++!" <<endl;
    cout << "Please enter your password: ";
    cin >> password;
    cout << name << "! You should never share your password! (" << password << ")";
    return 0;
}