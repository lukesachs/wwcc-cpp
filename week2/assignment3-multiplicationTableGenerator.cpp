#include <iostream>
#include <iomanip>  // For setw function
using namespace std;

int main() {
    int start, end;

    cout << "Multiplication Table Generator" << endl << endl;

    cout << "Enter starting number: ";
    cin >> start;

    cout << "Enter ending number: ";
    cin >> end;

    // Validate input
    if (start > end) {
        cout << "Error: Starting number must be less than ending number." << endl;
        return 1;
    }

    cout << endl;

    for(int row = start-1; row <= end; row++){
        
        for(int col = start-1; col <= end; col++){
        
            if(row == start-1 && col == start-1){
            cout << setw(5) << " |";
            continue;
            }
        
            if(col == start-1){
                cout << setw(3) << row << " |";
                continue;
            }

            if(row == start-1){
                cout  << setw(3) << col << " |";
                continue;
            }
        
            cout << setw(3) << col*row << " |";
        
        }

        cout << "\n";
        
        if(row==start-1){
            for(int col = start-1; col <= end; col++){
                cout << setw(5) << "----|";
            }
            cout << "\n";
        }
    }

    return 0;
}