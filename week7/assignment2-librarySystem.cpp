#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Author{
private:
	string name;
	int birthYear;

public:
	//constructor
	Author(string n, int y) : name(n), birthYear(y){}

	//getters
	string getName()const {return name;}
	int getBirthYear()const {return birthYear;}

};

class Book{
private:
	string title;
	int pubYear;
	string ISBN;
	Author author;

public:
	//constructor
	Book(string t, int y, string i, Author a) : title(t), pubYear(y), ISBN(i), author(a){}

	//getters
	string getTitle()const {return title;}
	int getPubYear()const {return pubYear;}
	string getISBN()const {return ISBN;}
	Author getAuthor()const {return author;}

	void displayBookInfo();

};

class Library{
private:
	string libraryName;
	string address;
	vector<Book> books;

public:
	//constructor
	Library(string l, string a) : libraryName(l), address(a){}

	void addBook(const Book& b){
		books.push_back(b);
	}
	//getters
	string getLibraryName()const {return libraryName;}
	string getAddress()const{return address;}
	Book getBook(int i)const{return books[i];}

	void displayLibrary();
	void searchLibrary(string s);
};

void Book::displayBookInfo(){
	cout << "\"" << getTitle() << "\"" << " (" << getPubYear() << ")" << endl;
	cout << "   Author: " << getAuthor().getName() << " (born " << getAuthor().getBirthYear() << ")" << endl;
	cout << "   ISBN: " << getISBN() << endl;
	cout << endl;
}

void Library::displayLibrary(){
	cout << "Library: " << getLibraryName() << endl;
	cout << "Address: " << getAddress() << endl;
	cout << "\nCATALOG:" << endl;
	for(int i = 0; i < books.size(); i++){
		cout << i+1 << ". ";
		getBook(i).displayBookInfo();
	}
}

void Library::searchLibrary(string s){
	string temp = s;
	transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
	int n = 0;
	//check for author name
	for(int i = 0; i < books.size(); i++){
		string temp2 = getBook(i).getAuthor().getName();
		transform(temp2.begin(), temp2.end(), temp2.begin(), ::tolower);
		if(temp2.find(temp) != string::npos){
			if(n == 0){
				cout << "Books by " << getBook(i).getAuthor().getName() << endl;
			}
			cout << "- \"" << getBook(i).getTitle() << "\" (" << getBook(i).getPubYear() << ")" << endl;
			n++;
		}
	}
	cout << endl;
	int n1 = 0;
	//check for title
	for(int i = 0; i < books.size(); i++){
		string temp2 = getBook(i).getTitle();
		transform(temp2.begin(), temp2.end(), temp2.begin(), ::tolower);
		if(temp2.find(temp) != string::npos){
			if(n1 == 0){
				cout << "Books with title containing \"" << s << "\":" << endl;
			}
			cout << "- \"" << getBook(i).getTitle() << "\" (" << getBook(i).getPubYear()<< ")" << endl;
			n1++;
		}
	}
	if(n == 0 && n1 == 0){
		cout << "Error. Nothing Found for " << s << endl;
	}
	cout << endl;
}

int main(){
	Library library("Walla Walla Public Library", "238 E Alder St, Walla Walla");

	Author a1("F. Scott Fitzgerald", 1896);
	Author a2("Harper Lee", 1926);
	Author a3("George Orwell", 1903);
	Author a4("George R. R. Martin", 1948);

	Book b1("The Great Gatsby", 1925, "9780743273565", a1);
	library.addBook(b1);
	Book b2("To Kill a Mockingbird", 1960, "9780061120084", a2);
	library.addBook(b2);
	Book b3("1984", 1949, "9780451524935", a3);
	library.addBook(b3);
	Book b4("Animal Farm", 1945, "9780451526342", a3);
	library.addBook(b4);
	Book b5("A Game of Thrones", 1996, "0553103547", a4);
	library.addBook(b5);
	Book b6("A Clash of Kings", 1999, "0553108034", a4);
	library.addBook(b6);

	

	cout << "LIBRARY MANAGEMENT SYSTEM" << endl;
	cout << "-------------------------" << endl;
	cout << endl;
	
	library.displayLibrary();

	cout << "SEARCH RESULTS" << endl;
	library.searchLibrary("George R. R. Martin");
	library.searchLibrary("farm");
	library.searchLibrary("Brandon Sanderson");

	return 0;
}