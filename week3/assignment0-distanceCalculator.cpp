#include <iostream>
#include <cstdio> 
#include <cmath>
using namespace std;

// Function prototype
double calculateDistance(double x1, double y1, double x2, double y2);

int main() {
    double x1;
    double y1;
    double x2;
    double y2;
    cout << "Enter the coordinates of the first point\n";
    cout << "x1: ";
    cin >> x1;
    cout << "y1: ";
    cin >> y1;

    cout << "Enter the coordinates of the second point\n";
    cout << "x2: ";
    cin >> x2;
    cout << "y2: ";
    cin >> y2;
    
    double distance = calculateDistance(x1, y1, x2, y2);

    printf("The distance between (%g,%g) and (%g,%g) is: %.2f", x1, y1, x2, y2, distance);
    return 0;
}

// Function definition
double calculateDistance(double x1, double y1, double x2, double y2) {
    return double (sqrt(pow((x2-x1),2)+pow((y2-y1),2)));
}