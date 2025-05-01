#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include<vector>
using namespace std;

int getTotalChar(string s);
int getWordCount(string s, vector<string>& wordList);
int getSenteceCount(string s);
double getAverageWordLength(vector<string> wordList) ;
string containsEmoji(string s);
void longerThan(vector<string> wordList, const int minLength);
string properCaps(vector<string> wordList);
int main(){
    const int minLength = 5;
    
    cout << "TEXT MESSAGE ANALYZER" << endl;
    cout << "---------------------" << endl;

    string message;
    vector<string> wordList;
    vector<int> punct;
    cout << "Enter your message: ";
    getline(cin, message);

    cout << "\nMessage analysis: " << endl;
    cout << "Total characters: " << getTotalChar(message) << endl;
    cout << "Word count: " << getWordCount(message, wordList) << endl;
    cout << "Sentence count: " << getSenteceCount(message) << endl;
    cout << "Average word length: " << getAverageWordLength(wordList) << endl;
    cout << "Contains emoji: " << containsEmoji(message) << endl;
    cout << "\nWords longer than 5 characters:" << endl;
    longerThan(wordList, minLength);
    cout << "\nProperly capitalized message: \n" << properCaps(wordList) << endl;

    return 0;
}


int getTotalChar(string s){
    int totalChar = 0;

    for(int i = 0; i < s.length(); i++){
        if(s[i] != ' '){
            totalChar++;
        }
    }
    return totalChar;
}

int getWordCount(string s, vector<string>& wordList){
    stringstream sstr(s);
    string word;
    int wordCount = 0;
    while(sstr>>word){
        wordCount++;
        wordList.push_back(word);
    }
    return wordCount;
}

int getSenteceCount(string s){
    int sentence = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '.' || s[i] == '?' || s[i] == '!'){
            sentence++;
        }
    }
    return sentence;
}

double getAverageWordLength(vector<string> wordList){
    double average = 0;
    int num = wordList.size();
    stringstream s;
    for(int i = 0; i < num; i++){
        average += wordList[i].length();
    }
    
    average = average/num;
    s << fixed << setprecision(1) << average;
    s >> average;
    return average;
}

string containsEmoji(string s){
    if(s.find(":)") != string::npos || s.find(":(") != string::npos || s.find(":D") != string::npos || s.find(":P") != string::npos){
    return "Yes";
    } else {
        return "No";
    }
}

void longerThan(vector<string> wordList, const int minLength){
    int num = wordList.size();
    int num2;
    string word;
    for(int i = 0; i < num; i++){
        word = wordList[i];
        char lastChar = word.back();
        if (lastChar == '.' || lastChar == '?' || lastChar == '!') {
            word.pop_back();
        }

        if(word.length() > minLength){
            cout << "- " << word << endl;
        }
    }
}

string properCaps(vector<string> wordList){
    int num = wordList.size();
    string sentence;
    for(int i = 0; i < num; i++){
        if(i == 0){
            wordList[i][0] = toupper(wordList[i][0]);
        }
        if(i < num - 1 && (wordList[i].find("!") != string::npos || wordList[i].find(".") != string::npos || wordList[i].find("?") != string::npos)){
            wordList[i+1][0] = toupper(wordList[i+1][0]);
        }
        sentence = sentence + wordList[i] + " ";
    }
    return sentence;
}