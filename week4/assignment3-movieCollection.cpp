#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Movie {
    string title;
    string director;
    int yearReleased;
    int duration;
    double rating;  
    string genre;
};

void getInfo(Movie &movieList, int n);
void displayMovie(Movie &movieList, int n);
void getStats(Movie &movieList, int n,  int &maxLength, int &index, double &sum, const int NUM_MOVIES);
void afterYear(Movie &movieList, int year);
bool checkInput(Movie &movieList);


int main(){
    const int NUM_MOVIES = 3;
    Movie movies[NUM_MOVIES];
    
    cout << "MOVIE COLLECTION MANAGER" << endl;
    cout << "------------------------" << endl;

    for(int i = 0; i < NUM_MOVIES; i++)
    {
        getInfo(movies[i], i);
        cout << endl;
        if(!checkInput(movies[i])){
            cout << "\nPlease try again." << endl;
            i--;
        }
    }

    cout << "\nYOUR MOVIE COLLECTION:" << endl;
    cout << "----------------------" << endl;

    for(int i = 0; i < NUM_MOVIES; i++)
    {
        displayMovie(movies[i], i);
        cout << endl;
    }

    int maxLength = 0;
    int index = 0;
    double sum = 0;
    cout << "Collection Statistics:" << endl;

    for(int i = 0; i < NUM_MOVIES; i++)
    {
        getStats(movies[i], i, maxLength, index, sum, NUM_MOVIES);
    }
    //not sure how to reference an array of structs in another function so I couldn't fit this in there.
    double average = sum/static_cast<double>(NUM_MOVIES);
    cout << "Average rating: " << fixed << setprecision(1) << average << "/10" << endl;
    cout << "Longest movie: " << movies[index].title << " (" << movies[index].duration << " minutes)"<< endl;

    cout << "\nEnter a year to find movies released after that year: ";
    int year;
    cin >> year;
    cout << "Movies released after " << year << ":" << endl;
    for(int i = 0; i < NUM_MOVIES; i++)
    {
        afterYear(movies[i], year);
    }
    return 0;
}

void getInfo(Movie &movieList, int n)
{

    cout << "Enter information for movie #" << n+1 << endl;
    cout << "Title: ";
    getline(cin, movieList.title);

    cout << "Director: ";
    getline(cin, movieList.director);

    cout << "Year released: ";
    cin >> movieList.yearReleased;

    cout << "Duration (minutes): ";
    cin >> movieList.duration;

    cout << "Rating (0-10): ";
    cin >> movieList.rating;

    cin.ignore();
    cout << "Genre: ";
    getline(cin, movieList.genre);
}

void displayMovie(Movie &movieList, int n)
{
    cout << n + 1 << ". " << movieList.title << " (" << movieList.yearReleased << ")" << endl;
    cout << "   Director: " << movieList.director << endl;
    cout << "   Duration: " << movieList.duration << " minutes" << endl;
    cout << "   Rating: " << movieList.rating << "/10" << endl;
    cout << "   Genre: " << movieList.genre << endl;
}

void getStats(Movie &movieList, int n, int &maxLength, int &index, double &sum, const int NUM_MOVIES)
{

    sum += movieList.rating;
    if(maxLength<movieList.duration)
    {
        maxLength = movieList.duration;
        index = n;
    }

}

void afterYear(Movie &movieList, int year)
{
    if(movieList.yearReleased>year){
        cout << "- " << movieList.title << " (" << movieList.yearReleased << ")" << endl;
    }
}

bool checkInput(Movie &movieList){
    //check string input
    int i = 1;
    if(movieList.director.empty() || movieList.title.empty() || movieList.genre.empty())
    {
        cout << "Cannot input empty string!" << endl;
        i = 0;
    }
    
    if(movieList.yearReleased < 1878 || movieList.yearReleased > 2025)
    {
        //checks that year is between current and first movie released.
        cout << "Input for year released is out of the possible range." << endl;
        i = 0;
    }

    if(movieList.duration < 1)
    {
        cout << "Movie duration not in possible range." << endl;
        i = 0;
    }

    if(movieList.rating > 10 || movieList.rating < 0)
    {
        cout << "Rating must be between 0-10!" << endl;
        i = 0;
    }

    if(i == 0)
    {
        return false;
    } else
    {
    return true;
    }
}
