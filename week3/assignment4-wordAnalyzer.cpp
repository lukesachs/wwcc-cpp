#include <iostream>
#include <string>
using namespace std;

int countVowels(string word);
int countConsonants(string word);
bool isPalindrome(string word);
char firstLetter(string word);
string reverse(string word);

int main() {
    char again = 'y';
    string word;


    do{
        cout << "Enter a word: ";
        cin >> word;
        
        if(word.length() != 0){

            cout << "Word Analysis:" << endl;
            cout << "-------------" << endl;
            cout << "Original word: " << word << endl;
            cout << "Number of vowels: " << countVowels(word) << endl;
            cout << "Number of consonants: " << countConsonants(word) << endl;
            cout << "First letter: " << firstLetter(word) << endl;
            cout << "Reversed: " << reverse(word) << endl;
            cout << "Is palindrome: ";
            if(isPalindrome(word)){
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
            do{
                cout << "\nWould you like to analyze another word? (y/n): ";
                cin >> again;
                    
                if(again != 'y' && again != 'n'){
                    cout << "\nError: incorrect input.\nMust enter y or n." << endl;

                }
            } while(again != 'y' && again != 'n');
        } else {
            cout << "\n\nError: word not inputted.\n" << endl;
        }
    } while(again == 'y');
    
    return 0;
}

int countVowels(string word){
    int count = 0;
    char c;
    const string vowels = "aeiou";
    for(int i = 0; i < word.length(); i++){
        c = tolower(word[i]);
        if(vowels.find(c) != -1){
            count++;
        }
    }
    return count;
}

int countConsonants(string word){
    int count = 0;
    char c;
    const string consonants = "bcdfghjklmnppqrstvwxyz";
    for(int i = 0; i < word.length(); i++){
        c = tolower(word[i]);
        if(consonants.find(c) != -1){
            count++;
        }
    }
    return count;
}

char firstLetter(string word){
    const string letters = "abcdefghijklmnopqrstuvwxyz";
    char c;
    int i = 0;
    int count = 0;
    do {
        i = count;
        c = tolower(word[i]);
        count++;
    } while(letters.find(c) ==-1);
    return word[i];
}

string reverse(string word){
    string r;
    int length = word.length();
    for(int i = 0; i<=length; i++){
        r = r + word[length - i];

    }
    return r;
}

bool isPalindrome(string word){
    bool pal = true;
    int length = word.length();

    for(int i = 0; i<length; i++){
        if(tolower(word[length - i-1]) != tolower(word[i])){
            pal = false;
        }
    }
    return pal;
}