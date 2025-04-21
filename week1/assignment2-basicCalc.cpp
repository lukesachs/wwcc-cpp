#include <iostream>

int main() {
    double num1, num2;

    std::cout << "Enter the first number: " << std::endl;
    std::cin >> num1;
    
    std::cout << "Enter the second number: " << std::endl;
    std::cin >> num2;

    std::cout << "Results: " << std::endl;
    std::cout << "Sum: " << num1 << " + " << num2 <<  " = " << num1 + num2 << std::endl;
    std::cout << "Difference: " << num1 << " - " << num2 <<  " = " << num1 - num2 << std::endl;
    std::cout << "Product: " << num1 << " * " << num2 <<  " = " << num1 * num2 << std::endl;
    std::cout << "Qoutient: " << num1 << " / " << num2 <<  " = " << num1 / num2 << std::endl;
    return 0;
}