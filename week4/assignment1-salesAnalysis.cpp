#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

int main(){
    const int days = 7;
    const string weekNames[days] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    //test case
    //double sales[days] = {1240.50, 950.75, 1345.25, 1080.00, 1620.50, 2340.25, 1905.75};
    double sales[days];
    double amount = 0;
    int sat = 5;
    int sun = 6;
    cout << "WEEKLY SALES ANALYSIS" << endl;
    cout << "------------------" << endl;
    
    for(int i = 0; i < days; i++){
        cout << "Enter sales for " << weekNames[i] << ": ";
        cin >> amount;
        sales[i] = amount;
    }

    double min = sales[0];
    int minSalesIndex = 0;
    double max = sales[0];
    int maxSalesIndex = 0;
    double total = 0;

    for(int i = 0; i < days; i++){
        if(sales[i] < min){
            min = sales[i];
            minSalesIndex = i;
        }
        if(sales[i] > max){
            max = sales[i];
            maxSalesIndex = i;
        }
        total = total + sales[i];
    }

    double average = total / days;
    
    cout << "\nSales Summary:" << endl;
    cout << "Total Sales: $" << fixed << setprecision(2) << total << endl;
    cout << "Average Daily Sales: $" << fixed << setprecision(2) << average << endl;


    cout << "\nBest day: " << weekNames[maxSalesIndex] << " with $" << max << endl;
    cout << "Worst day: " << weekNames[minSalesIndex] << " with $" << min << endl;


    int n = 0;
    double weekendSales = 0.0;
    for(int i = 0; i < days; i++){
        if(sales[i] > average){
            n++;
        }
        if(i == sat || i == sun){
            weekendSales = weekendSales + sales[i];
        }
    }
    double weekendPercent = weekendSales / static_cast<double>(total) * 100;


    cout << "\nDays above average: " << n << endl;
    
    cout << "Weekend Sales: $" << fixed << setprecision(2) <<weekendSales << " (" << weekendPercent << "% of total)" << endl;

    return 0;
}