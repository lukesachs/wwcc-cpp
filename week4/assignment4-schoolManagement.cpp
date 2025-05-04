#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//declare structs
struct Address {
    string city;
    string street;
    string state;
    int ZipCode;
};

struct Person {
    string name;
    int age;
    Address address;
};

struct Course {
    string courseCode;
    string courseName;
    int creditHours;
};

struct Student {
    Person person;
    int studentID;
    Course studentCouses[5];
    double gpa;
};


void initializeData(Student &students, int i);

void printStudent(const Student &students, const int NUM_STUDENTS, double &sum, const int NUM_CLASSES);

void averageGPA(double sum, double &average, const int NUM_STUDENTS);

int main()
{
    const int NUM_STUDENTS = 3;
    const int NUM_COURSES = 5;

    Student students[NUM_STUDENTS];

    //initialized sample data
    for(int i = 0; i > NUM_STUDENTS; i++)
    {
        initializeData(students[i], i);
    }
    
    cout << "SCHOOL MANAGEMENT SYSTEM" << endl;
    cout << "------------------------" << endl;
    
    cout << "Student Information:\n" << endl;

    double sum = 0.0;

    for(int i = 0; i < NUM_STUDENTS; i++)
    {
        printStudent(students[i], i, sum, NUM_COURSES);
    }
    
    cout << endl;

    double average = 0.0;

    averageGPA(sum, average, NUM_STUDENTS);

    
}


void initializeData(Student &students, int i){
    switch(i)
    {
        case 0:
            students.person.name = "Maria Rodriguez";
            students.studentID = 1001;
            students.person.age = 20;
            students.gpa = 3.85;

            students.person.address.street = "123 College Ave";
            students.person.address.city = "Berkley";
            students.person.address.state = "CA";
            students.person.address.ZipCode = 94704;

            students.studentCouses[0].courseCode = "CS101";
            students.studentCouses[0].courseName = "Introduction to Programming";
            students.studentCouses[0].creditHours = 3;

            students.studentCouses[1].courseName = "MATH201";
            students.studentCouses[1].courseName = "Calculus II";
            students.studentCouses[1].creditHours = 4;

            students.studentCouses[2].courseName = "PHYS101";
            students.studentCouses[2].courseName = "Physics I";
            students.studentCouses[2].creditHours = 4;

            students.studentCouses[3].courseName = "ENG105";
            students.studentCouses[3].courseName = "English Composition";
            students.studentCouses[3].creditHours = 3;

            students.studentCouses[4].courseName = "HIST100";
            students.studentCouses[4].courseName = "World History";
            students.studentCouses[4].creditHours = 3;

        break;

        case 1:
            students.person.name = "James Smith";
            students.studentID = 1002;
            students.person.age = 19;
            students.gpa = 3.42;

            students.person.address.street = "456 University Dr";
            students.person.address.city = "Berkley";
            students.person.address.state = "CA";
            students.person.address.ZipCode = 94704;

            students.studentCouses[0].courseCode = "CS101";
            students.studentCouses[0].courseName = "Introduction to Programming";
            students.studentCouses[0].creditHours = 3;

            students.studentCouses[1].courseName = "MATH101";
            students.studentCouses[1].courseName = "Calculus I";
            students.studentCouses[1].creditHours = 4;

            students.studentCouses[2].courseName = "CHEM101";
            students.studentCouses[2].courseName = "Chemistry  I";
            students.studentCouses[2].creditHours = 4;

            students.studentCouses[3].courseName = "SOC200";
            students.studentCouses[3].courseName = "Introduction to Sociology";
            students.studentCouses[3].creditHours = 3;

            students.studentCouses[4].courseName = "ART105";
            students.studentCouses[4].courseName = "Drawing Fundamentals";
            students.studentCouses[4].creditHours = 2;
        break;

        case 2:
            students.person.name = "Sarah Johnson";
            students.studentID = 1003;
            students.person.age = 21;
            students.gpa = 3.91;

            students.person.address.street = "789 Campus Rd";
            students.person.address.city = "Berkley";
            students.person.address.state = "CA";
            students.person.address.ZipCode = 94704;

            students.studentCouses[0].courseCode = "CS201";
            students.studentCouses[0].courseName = "Data Structures";
            students.studentCouses[0].creditHours = 3;

            students.studentCouses[1].courseName = "MATH201";
            students.studentCouses[1].courseName = "Calculus II";
            students.studentCouses[1].creditHours = 4;

            students.studentCouses[2].courseName = "BIO101";
            students.studentCouses[2].courseName = "Biology  I";
            students.studentCouses[2].creditHours = 4;

            students.studentCouses[3].courseName = "PSYCH101";
            students.studentCouses[3].courseName = "Introduction to Psychology";
            students.studentCouses[3].creditHours = 3;

            students.studentCouses[4].courseName = "ECON200";
            students.studentCouses[4].courseName = "Microeconomics ";
            students.studentCouses[4].creditHours = 3;
        break;
    }
}

void printStudent(const Student &students, int num, double &sum, const int NUM_CLASSES){

    cout << "ID: " << students.studentID << " - " << students.person.name << endl;
    cout << "Age: " << students.person.age << endl;
    cout << "Address: " << students.person.address.street << ", " << students.person.address.city << ", " << students.person.address.state << " " << students.person.address.ZipCode << endl;
    cout << "GPA: " << students.gpa << endl;
    cout << "Courses:" << endl;

    for(int i = 0; i < NUM_CLASSES; i++)
    {
        cout << "  " << students.studentCouses[i].courseCode << ": " << students.studentCouses[i].courseName << " (" << students.studentCouses[i].creditHours << " credits)" << endl;
    }

    cout << endl;
    sum += students.gpa;

}

void averageGPA(double sum, double &average, const int NUM_STUDENTS)
{
    average = sum/static_cast<double>(NUM_STUDENTS);
    cout << "Average GPA: " << average << endl;
}
