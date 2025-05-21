#include<iostream>
#include <string>
using namespace std;


class Student {
private:
    int ID;
    double GPA;
    string name;

public:
    // Constructor
    Student(int i, double g, string n) : ID(i), GPA(g), name(n){}
	//Getters
	int getID()const {return ID;}
	double getGPA()const {return GPA;}
	string getName()const {return name;}

	//setter
	void setGPA(double newGPA){
		cout << endl;
		if(0.0 > newGPA || newGPA > 4.0){
			cout << "GPA must be within the range of 0.0-4.0" << endl;
		} else {
			GPA = newGPA;
			cout << "Updating " << name << "'s GPA to " << GPA << "..." << endl;
	}
	cout << endl;
	}

	void displayStudentInfo(){
		cout << "ID: " << ID << " - " << name << endl;
		cout << "GPA: " << GPA << endl;
		cout << endl;
	}

};

class Course {
private:
    string code;
    string title;
    int creditHours;

public:
    // Constructor
    Course(string c, string t, int h) : code(c), title(t), creditHours(h) {}

	string getCode()const {return code;}
	string getTitle()const {return title;}
	int getCreditHours()const {return creditHours;}

	//setters
	void setCode(string c){code = c;}
	void setTitle(string t){title = t;}
	void setCreditHours(int h){creditHours = h;}

	void displayCourseInfo(){
		cout << code << ": " << title << " (" << creditHours << " credits)" << endl;
	}

};

int main(){

	Student alex(1001, 3.75, "Alex Johnson");
	Student maria(1002, 3.92, "Maria Garcia");
	Student jamal(1003, 3.45, "Jamal Williams");
	Course CS("CS101", "Introduction to Programming", 3);
	Course math("MATH201", "Calculus II", 4);

	cout << "UNIVERSITY MANAGEMENT SYSTEM" << endl;
	cout << "----------------------------" << endl;
	cout << endl;

	cout << "Student Information:" << endl;
	
	alex.displayStudentInfo();
	maria.displayStudentInfo();
	jamal.displayStudentInfo();

	cout << "Course Information:" << endl;
	CS.displayCourseInfo();
	math.displayCourseInfo();
	maria.setGPA(4.5);
	maria.setGPA(4.0);

	cout << "Updated Student Information:" << endl;
	maria.displayStudentInfo();

		return 0;
}