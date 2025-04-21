#include <iostream>
#include <cstdlib>  // For rand() function
#include <ctime>    // For time() function
using namespace std;

int main() {
    // Seed the random number generator
    srand(time(0));

    int flips;
    int heads = 0;
    int tails = 0;

    cout << "Coin Flip Simulator" << endl;
    cout << "How many flips would you like to simulate? ";
    cin >> flips;
    cout << "Simulating 100 coin flips... \n\n";
    for(int i = 0; i < flips; i++){
        if(rand()%2 == 0){
            heads++;
        } else {
            tails++;
        }
    }
    cout << "Results:\n";
    cout << "Heads: " << heads << " (" << static_cast<double>(heads)/flips*100 << "%)\n";
    cout << "Tails: " << tails << " (" << static_cast<double>(tails)/flips*100<< "%)\n";
    return 0;
}