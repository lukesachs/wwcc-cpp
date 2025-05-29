#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

void changeInts(int& x, int& y);
void usePointer(int* a, int* b);

int main(){


	cout << "MEMORY ADDRESS EXPLORER" << endl;
	cout << "-----------------------" << endl;

	int i = 42;
	double d = 4.14;
	char c = 'A';
	cout << "PART 1: Variable Memory Locations" << endl;
	cout << "---------------------------------" << endl;
	cout << endl;
	if (&i != nullptr && &d != nullptr && &c != nullptr) {
		cout << "Integer variable: " << i << " at address " << &i << endl;
		cout << "Double variable: " << d << " at address " << &d << endl; 
		cout << "Character variable: \'" << c << "\' at address " << &c << endl;
		cout << endl;
	}
	cout << "PART 2: Reference Demonstration" << endl;
	cout << "-------------------------------" << endl;

	int x = 10;
	int y = 20;
	cout << "Before reference function: x = " << x << ", y = " << y << endl;

	changeInts(x,y);

	cout << "After reference function: x = " << x << ", y = " << y << endl;

	cout << "(References allow direct modification of original variables)" << endl;
	cout << endl;
	int a = 5;
	int b = 15;

	cout << "PART 3: Pointer Demonstration" << endl;
	cout << "-----------------------------" << endl;
	cout << "Before pointer function: a = " << a << ", b = " << b << endl;
	
	cout << "Pointer addresses: a at " << &a << ", b at " << &b << endl;
	usePointer(&a, &b);
	cout << "After pointer function: a = 50, b = 150" << endl;

	cout << "(Pointers access original variables through their addresses)" << endl;
	cout << endl;

	cout << "PART 4: Array and Pointer Relationship" << endl;
	cout << "--------------------------------------" << endl;
	int arr[5] = {1, 2, 3, 4, 5};
	if (&arr != nullptr) {
		cout << "Array: [" << arr[0] << ", " << arr[1] << ", " << arr[2] << ", " << arr[3] << ", " << arr[4] << "]" << endl;
		cout << "Array name address: " << arr << endl;
		cout << "First element address: " << &arr[0] << " (same as array name!)" << endl;
		cout << "Second element via pointer arithmetic: " << *(arr + 1) << endl;
		cout << "Third element via pointer arithmetic: " << *(arr + 2) << endl;
	}

}

void changeInts(int& x, int& y){
	if (&x != nullptr && &y != nullptr) {
		x *= 10;
		y *= 10;
	}
}

void usePointer(int* a, int* b){
	if (a != nullptr && b != nullptr) {
        *a *= *a;
        *b *= *b;
    } else {
        cout << "Error. Null pointer" << endl;
    }

}