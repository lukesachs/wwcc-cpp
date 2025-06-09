#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>
#include <cctype>
#include <iomanip>
#include <sstream>
#include <chrono>
#include <numeric>
#include <memory>
using namespace std;

// general media class
class MediaItem {
protected:
    // general variables for media
    string title;
    string creator;// director/author/artist
    int year;
    double rating;
    int duration;// minutes or pages
    vector<string> genres;
    vector<string> tags;
    int timesPlayed;
    string lastPlayed; //YYYY-MM-DD

public:
    // Constructor
    MediaItem(const string& t, const string& c, int y, double r, int d,
              const vector<string>& g, const vector<string>& tg,
              int times, const string& last)
        : title(t), creator(c), year(y), rating(r), duration(d),
          genres(g), tags(tg), timesPlayed(times), lastPlayed(last) {}

    // Getters
    double getRating() const { return rating; }
    const string& getTitle() const { return title; }
    const vector<string>& getGenres() const { return genres; }
    const vector<string>& getTags() const { return tags; }
    const string& getDateAdded() const { return lastPlayed; }

    // allows song, book, and movie to override general media item print info
    virtual void printInfo() const {
        cout << "Title: " << title << endl
             << "Creator: " << creator << endl
             << "Year: " << year << endl
             << "Rating: " << rating << endl
             << "Duration: " << duration << endl
             << "Times Played: " << timesPlayed << endl
             << "Last Played: " << lastPlayed << endl;
    }

    // clean up class
    virtual ~MediaItem() = default;
};

// Derived class for movies
class Movie : public MediaItem {
private:
    int runtime;
    string studio;

public:
    // movie constructor
    Movie(const string& t, const string& director, int y, double r, int d,
          const vector<string>& g, const vector<string>& tg, int times,
          const string& last, int run, const string& stu)
        : MediaItem(t, director, y, r, d, g, tg, times, last),
          runtime(run), studio(stu) {}

    // Override printInfo for movies
    void printInfo() const override {
        cout << "[MOVIE] " << title << " (" << year << ") " << string(static_cast<int>(rating), '*') << endl
             << "Director: " << creator << endl
             << "Runtime: " << runtime << " minutes" << endl
             << "Studio: " << studio << endl
             << "Times Played: " << timesPlayed << endl
             << "Last Played: " << lastPlayed << endl << endl;
    }
};

// Derived class for books
class Book : public MediaItem {
private:
    int pages;
    string publisher;

public:
    // book constructor
    Book(const string& t, const string& author, int y, double r, int d,
         const vector<string>& g, const vector<string>& tg, int times,
         const string& last, int p, const string& pub)
        : MediaItem(t, author, y, r, d, g, tg, times, last),
          pages(p), publisher(pub) {}
    
    // Override printInfo for books
    void printInfo() const override {
        cout << "[BOOK] " << title << " (" << year << ") " << string(static_cast<int>(rating), '*') << endl
             << "Author: " << creator << endl
             << "Pages: " << pages << endl
             << "Publisher: " << publisher << endl
             << "Times Played: " << timesPlayed << endl
             << "Last Played: " << lastPlayed << endl << endl;
    }
};

// Derived class for songs
class Song : public MediaItem {
private:
    string album;

public:
    // song constructor
    Song(const string& t, const string& artist, int y, double r, int d,
         const vector<string>& g, const vector<string>& tg, int times,
         const string& last, const string& alb)
        : MediaItem(t, artist, y, r, d, g, tg, times, last),
          album(alb) {}

    // Override printInfo for songs
    void printInfo() const override {
        cout << "[SONG] " << title << " (" << year << ") " << string(static_cast<int>(rating), '*') << endl
             << "Artist: " << creator << endl
             << "Album: " << album << endl
             << "Times Played: " << timesPlayed << endl
             << "Last Played: " << lastPlayed << endl << endl;
    }
};

// Collection class that manages all media items
class MediaCollection {
private:

    vector<unique_ptr<MediaItem>> collection;

    // filtering media items by rating over 4.0
    function<bool(const MediaItem&)> highRated = [](const MediaItem& item) {
        return item.getRating() >= 4.0;
    };

    // Checks if date added is within last 30 days
    function<bool(const MediaItem&)> recentlyAdded = [](const MediaItem& item) {
        istringstream ss(item.getDateAdded());
        int y, m, d;
        char dash;
        ss >> y >> dash >> m >> dash >> d;
        if (ss.fail()) return false;

        tm itemDate = {};
        itemDate.tm_year = y - 1900;
        itemDate.tm_mon = m - 1;
        itemDate.tm_mday = d;

        auto itemTime = chrono::system_clock::from_time_t(mktime(&itemDate));
        auto now = chrono::system_clock::now();
        auto days = chrono::duration_cast<chrono::hours>(now - itemTime).count() / 24;
        return days <= 30;
    };

public:
    // Add a media item
    void addMedia(unique_ptr<MediaItem> item) {
        collection.push_back(move(item));
    }

    // Adds media item to collection
    void addMediaItem();

    // Search media items by criteria
    void searchMediaItem();

    // Calculate average rating of all media items
    double calculateAverageRating() {
        if (collection.empty()) return 0.0;
        return accumulate(collection.begin(), collection.end(), 0.0,
            [](double sum, const auto& item) { return sum + item->getRating(); })
            / collection.size();
    }

    // Print all items in the total collection
    void printCollection() const {
        for (const auto& m : collection) {
            m->printInfo();
        }
    }

    // tallies media by type and gets average rating of each sub collection of media.
    void printSummary() const {
        int movies = 0, songs = 0, books = 0;
        double movieSum = 0.0, songSum = 0.0, bookSum = 0.0;

        for (const auto& item : collection) {
            // checks for type of media
            if (dynamic_cast<Movie*>(item.get())) {
                movies++;
                movieSum += item->getRating();
            } else if (dynamic_cast<Song*>(item.get())) {
                songs++;
                songSum += item->getRating();
            } else if (dynamic_cast<Book*>(item.get())) {
                books++;
                bookSum += item->getRating();
            }
        }

        int total = movies + songs + books;
        cout << endl << "Collection Summary: " << total << " items" << endl;

        if (movies > 0) {
            cout << "- Movies: " << movies << " items (avg rating: "
                 << fixed << setprecision(1) << (movieSum / movies) << ")" << endl;
        } else {
            cout << "- Movies: 0 items" << endl;
        }
        if (songs > 0) {
            cout << "- Songs: " << songs << " items (avg rating: "
                 << fixed << setprecision(1) << (songSum / songs) << ")" << endl;
        } else {
            cout << "- Songs: 0 items" << endl;
        }
        if (books > 0) {
            cout << "- Books: " << books << " items (avg rating: "
                 << fixed << setprecision(1) << (bookSum / books) << ")" << endl;
        } else {
            cout << "- Books: 0 items" << endl;
        }
    }
};

void MediaCollection::addMediaItem() {
    cout << "Select media type to add:" << endl;
    cout << "1. Movie" << endl;
    cout << "2. Song" << endl;
    cout << "3. Book" << endl;
    cout << "Choice: ";
    int choice;
    while (!(cin >> choice) || choice < 1 || choice > 3) {// validate choice
        cout << "Invalid choice. Please enter 1, 2, or 3: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }
    cin.ignore();

    // general data
    string title, creator, dateAdded;
    int year, durationOrPages, timesAccessed;
    double rating;
    vector<string> genres, tags;

    cout << "Title: ";
    getline(cin, title);

    cout << "Creator (Author/Director/Artist): ";
    getline(cin, creator);

    cout << "Year Released: ";
    while (!(cin >> year) || year < 1900 || year > 2100) {
        cout << "Enter a valid year (1900–2100): ";
        cin.clear();
        cin.ignore(1000, '\n');
    }

    cout << "Rating (1.0 to 5.0): ";
    while (!(cin >> rating) || rating < 1.0 || rating > 5.0) {
        cout << "Enter a valid rating (1.0–5.0): ";
        cin.clear();
        cin.ignore(1000, '\n');
    }

    cout << "Duration or Pages: ";
    while (!(cin >> durationOrPages) || durationOrPages <= 0) {
        cout << "Enter a positive number: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }

    cin.ignore();
    cout << "Genres (comma-separated): ";
    string inputGenre;
    getline(cin, inputGenre);
    stringstream gss(inputGenre); string g;
    while (getline(gss, g, ',')) {
        g.erase(g.begin(), find_if(g.begin(), g.end(), [](char c) { return !isspace(c); }));
        g.erase(find_if(g.rbegin(), g.rend(), [](char c) { return !isspace(c); }).base(), g.end());
        if (!g.empty()) genres.push_back(g);
    }

    cout << "Tags (comma-separated): ";
    string inputTags;
    getline(cin, inputTags);
    stringstream tss(inputTags); string t;
    while (getline(tss, t, ',')) {
        t.erase(t.begin(), find_if(t.begin(), t.end(), [](char c) { return !isspace(c); }));
        t.erase(find_if(t.rbegin(), t.rend(), [](char c) { return !isspace(c); }).base(), t.end());
        if (!t.empty()) tags.push_back(t);
    }

    cout << "Times Accessed: ";
    while (!(cin >> timesAccessed) || timesAccessed < 0) {
        cout << "Enter a non-negative number: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }

    cin.ignore();
    cout << "Date Added (YYYY-MM-DD): ";
    getline(cin, dateAdded);


    if (choice == 1) {//movie specific variables
        string director, studio;
        int runtime;

        director = creator;

        cout << "Runtime (minutes): ";
        while (!(cin >> runtime) || runtime <= 0) {
            cout << "Enter a positive runtime: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }
        cin.ignore();

        cout << "Studio: ";
        getline(cin, studio);

        collection.push_back(make_unique<Movie>(
            title, director, year, rating, durationOrPages, genres, tags,
            timesAccessed, dateAdded, runtime, studio
        ));
    } else if (choice == 2) {//song specific variables
        string artist, album;

        artist = creator;

        cout << "Album: ";
        getline(cin, album);

        collection.push_back(make_unique<Song>(
            title, artist, year, rating, durationOrPages, genres, tags,
            timesAccessed, dateAdded, album
        ));
    } else if (choice == 3) {//book specific variables
        string author, publisher;
        int pages;

        author = creator;

        cout << "Pages: ";
        while (!(cin >> pages) || pages <= 0) {
            cout << "Enter a valid page count: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }
        cin.ignore();

        cout << "Publisher: ";
        getline(cin, publisher);

        collection.push_back(make_unique<Book>(
            title, author, year, rating, durationOrPages, genres, tags,
            timesAccessed, dateAdded, pages, publisher
        ));
    }
}

// search through media collection
void MediaCollection::searchMediaItem() {
    int option;
    cout << endl
         << "Search Options:" << endl
         << "1. Search by Title" << endl
         << "2. Filter by Genre" << endl
         << "3. Filter by Tag" << endl
         << "4. High-Rated (≥ 4.0)" << endl
         << "5. Recently Added (last 30 days)" << endl
         << "Enter option: ";
    cin >> option;
    cin.ignore();

    vector<const MediaItem*> results;

    switch (option) {
        case 1: {
            string title;
            cout << "Enter title keyword: ";
            getline(cin, title);
            for (const auto& item : collection) {
                if (item->getTitle().find(title) != string::npos) {
                    results.push_back(item.get());
                }
            }
            break;
        }
        case 2: {
            string genre;
            cout << "Enter genre keyword: ";
            getline(cin, genre);
            for (const auto& item : collection) {
                for (const string& g : item->getGenres()) {
                    if (g.find(genre) != string::npos) {
                        results.push_back(item.get());
                        break;
                    }
                }
            }
            break;
        }
        case 3: {
            string tag;
            cout << "Enter tag keyword: ";
            getline(cin, tag);
            for (const auto& item : collection) {
                for (const string& t : item->getTags()) {
                    if (t.find(tag) != string::npos) {
                        results.push_back(item.get());
                        break;
                    }
                }
            }
            break;
        }
        case 4: {
            for (const auto& item : collection) {
                if (highRated(*item)) {
                    results.push_back(item.get());
                }
            }
            break;
        }
        case 5: {
            for (const auto& item : collection) {
                if (recentlyAdded(*item)) {
                    results.push_back(item.get());
                }
            }
            break;
        }
        default:
            cout << "Invalid option." << endl;
            return;
    }

    cout << endl << "Found " << results.size() << " items: " << endl;
    cout << "------------------------------------------------------------" << endl;
    if (results.empty()) {
        cout << "No items matched your search." << endl;
    } else {
        for (const auto& item : results) {
            item->printInfo();
        }
    }

    char sortChoice;
        cout << "Sort results? (y/n): ";
        cin >> sortChoice;
        cin.ignore();

        if (tolower(sortChoice) == 'y') {
            cout << "1. By title  2. By year  3. By rating" << endl;
            cout << "Choice: ";
            int sortOption;
            cin >> sortOption;
            cin.ignore();

            switch (sortOption) {
                case 1:
                    sort(results.begin(), results.end(),
                         [](const MediaItem* a, const MediaItem* b) {
                             return a->getTitle() < b->getTitle();
                         });
                    cout << "\nResults sorted by title...\n" << endl;
                    break;
                case 2:
                    sort(results.begin(), results.end(),
                         [](const MediaItem* a, const MediaItem* b) {
                             return a->getDateAdded() < b->getDateAdded(); // or use year if available
                         });
                    cout << "\nResults sorted by year...\n" << endl;
                    break;
                case 3:
                    sort(results.begin(), results.end(),
                         [](const MediaItem* a, const MediaItem* b) {
                             return a->getRating() > b->getRating();
                         });
                    cout << "\nResults sorted by rating...\n" << endl;
                    break;
                default:
                    cout << "Invalid sort option. Displaying unsorted results.\n" << endl;
                    break;
            }
            for (const auto& item : results) {
                item->printInfo();
        }
        }
}

int main() {
    MediaCollection collection;

    // added some media to start to help speed up testing my program
    collection.addMedia(make_unique<Movie>(
        "Inception", "Christopher Nolan", 2010, 4.8, 148,
        vector<string>{"Sci-Fi", "Thriller"}, vector<string>{"dream", "mind-bending"},
        25, "2024-05-01", 148, "Warner Bros"));

    collection.addMedia(make_unique<Movie>(
        "Interstellar", "Christopher Nolan", 2014, 4.7, 169,
        vector<string>{"Sci-Fi", "Adventure"}, vector<string>{"space", "time dilation"},
        30, "2024-05-03", 169, "Paramount Pictures"));

    collection.addMedia(make_unique<Song>(
        "HUMBLE.", "Kendrick Lamar", 2017, 4.6, 177,
        vector<string>{"Hip-Hop", "Rap"}, vector<string>{"trap", "anthem"},
        120, "2024-05-10", "DAMN."));

    collection.addMedia(make_unique<Song>(
        "Man in the Box", "Alice in Chains", 1990, 4.5, 280,
        vector<string>{"Grunge", "Alternative Rock"}, vector<string>{"classic", "dark"},
        95, "2024-05-12", "Facelift"));

    collection.addMedia(make_unique<Book>(
        "A Game of Thrones", "George R.R. Martin", 1996, 4.8, 694,
        vector<string>{"Fantasy", "Epic"}, vector<string>{"Winterfell", "dragons"},
        60, "2024-05-07", 694, "Bantam Books"));

    collection.addMedia(make_unique<Book>(
        "A Clash of Kings", "George R.R. Martin", 1998, 4.7, 768,
        vector<string>{"Fantasy", "Epic"}, vector<string>{"Westeros", "battles"},
        55, "2024-05-08", 768, "Bantam Books"));


    collection.printSummary();

    int choice;
    do {
        cout << endl << "Main Menu ===" << endl;
        cout << "1. View Collection" << endl;
        cout << "2. Search Items" << endl;
        cout << "3. Add Media Item" << endl;
        cout << "4. View Summary" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                collection.printCollection();
                break;
            case 2:
                collection.searchMediaItem();
                break;
            case 3:
                collection.addMediaItem();
                break;
            case 4:
                collection.printSummary();
                break;
            case 5:
                cout << "\nExiting program......" << endl;
                break;
            default:
                cout << "Invalid option, try again." << endl;
        }
    } while (choice != 5);

    return 0;
}