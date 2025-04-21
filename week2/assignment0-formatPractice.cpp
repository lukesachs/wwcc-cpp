#include <iostream>
#include <cstdio>   // For printf function
using namespace std;

int main() {
    // Sample variables to display
    int integer_value = 42;
    float float_value = 3.14159265f;
    double double_value = 3.14159265;
    char char_value = 'X';
    const char* string_value = "Hello, World!";

    printf("Format Specifier Practice\n");
    printf("------------------------\n\n");

    printf("Integer formats:\n");
    //prints integer_value as decimal with %d
    printf("Decimal: %d\n", integer_value);
    //prints hexadecimal value of integer_value with %x
    printf("Hexadecimal: %#x\n", integer_value);
    //prints Octal value of integer_value with %o
    printf("Octal: %o\n", integer_value);
    //prints with width 5 through %5i
    printf("Decimal: |%5d|\n", integer_value);
    //prints with width 5 but left aligned through %-5i
    printf("Decimal: |%-5d|\n\n", integer_value);

    printf("Float formats:\n");
    //prints float
    printf("Default: %f\n", float_value);
    //prints with precision 2 using %.2
    printf("With precision (2): %.2f\n", float_value);
    //prints scientific nototaion of the float value using %e
    printf("Scientific: %e\n", float_value);
    //prints the fixed precision using %.4
    printf("Fixed with precision (4): %.4f\n\n", float_value);

    printf("Character and String formats:\n");
    //%c prints single character
    printf("Character: %c\n",char_value);
    //%s prints string of characters
    printf("String: %s\n", string_value);
    //%20s allows for the string to have a width of 20, filling the extra space with whitespace
    printf("String with width (20): |%20s|\n", string_value);


    return 0;
}