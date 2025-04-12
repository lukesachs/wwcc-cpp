#include<iostream>

int main() {
    int n;
    int count = 1;
    std::cout << "Enter a number (1-9): ";
    std::cin >> n;
    while(count<=n){
        for(int i = 0; i<count; i++){
            std::cout << count << " ";
        }
        std::cout << std::endl;
        count++;
    }


}