#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

int main(){
    const int days = 7;
    int weekTemp[days];
    int temp;

    cout << "Temperature Tracker" << endl;
    cout << "------------------" << endl;
    
    for(int i = 0; i < days; i++){
        cout << "Enter temperature for day " << i+1 << ": ";
        cin >> temp;
        weekTemp[i] = temp;
    }

    int min = weekTemp[0];
    int minTempIndex = 0;
    int max = weekTemp[0];
    int maxTempIndex = 0;
    double average;
    cout << "\nTemperature Analysis:" << endl;

    for(int i = 0; i < days; i++){
        if(weekTemp[i] < min){
            min = weekTemp[i];
            minTempIndex = i;
        }
        if(weekTemp[i] > max){
            max = weekTemp[i];
            maxTempIndex = i;
        }
        average = average + weekTemp[i];
    }

    average = average/double(days);
    stringstream sstr;
    sstr << fixed << setprecision(1) << average;
    average = stod(sstr.str());

    cout << "Highest temperature: " << max << "°F (day " << maxTempIndex+1 << ")" << endl;
    cout << "Lowest temperature: " << min << "°F (day "<< minTempIndex+1 << ")" << endl;
    cout << "Average temperature: " << average << "°F" << endl;

    cout << "\nDays with above-average temperatures: " << endl;
    for(int i = 0; i < days; i++){
        if(weekTemp[i] > average){
            cout << "- Day " << i+1 << ": " << weekTemp[i] << "°F" << endl;
        }
    }
}