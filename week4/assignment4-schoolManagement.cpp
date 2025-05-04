#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
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
    Course studentCourses [5];
    double gpa;
};


void initializeData(Student &students, int i);

void printStudent(const Student &students, double &sum, const int NUM_CLASSES);

void averageGPA(double sum, double &average, const int NUM_STUDENTS);

Student *findStudentUsingID(vector<Student> &students, int id);

Student *findStudentUsingCourseCode(vector<Student> &students, string courseCode, int i, const int NUM_COURSES);


int main()
{
    const int NUM_STUDENTS = 3;
    const int NUM_COURSES = 5;

    //Student students[NUM_STUDENTS];
    vector<Student> students(NUM_STUDENTS);

    //initialized sample data
    for(int i = 0; i < NUM_STUDENTS; i++)
    {
        initializeData(students[i], i);
    }
    
    cout << "SCHOOL MANAGEMENT SYSTEM" << endl;
    cout << "------------------------" << endl;
    cout << "Student Information:\n" << endl;

    double sum = 0.0;

    for(int i = 0; i < NUM_STUDENTS; i++)
    {
        printStudent(students[i], sum, NUM_COURSES);
    }

    double average = 0.0;

    averageGPA(sum, average, NUM_STUDENTS);

    int inputID;
    cout << "\nEnter student ID to search: ";
    cin >> inputID;

    Student* findID = findStudentUsingID(students, inputID);
    if(findID != nullptr)
    {
        cout << "Student found:" << endl;
        cout << "  " << findID->person.name << " (ID: " << findID->studentID << ")" << endl;
        cout << "  GPA: " << findID->gpa;
    } else 
    {
        cout << "Student ID not found." << endl;
    }

    string courseCode;
    cout << "\nEnter course code to find students: ";
    cin >> courseCode;
    Student* findCourseCode;
    int n = 0;
    for(int i = 0; i < NUM_STUDENTS; i++)
    {
        findCourseCode = findStudentUsingCourseCode(students, courseCode, i, NUM_COURSES);
        if(findCourseCode != nullptr)
        {
            if(n == 0)
            {
                cout << "Students taking " << courseCode << ":" << endl;
            }
            cout << "  " << findCourseCode->person.name << " (ID: " << findCourseCode->studentID << ")" << endl;
            n++;
        }
    }
    
    if(n == 0)
    {
        cout << "No students taking " << courseCode << endl;
    }

    return 0;
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

            students.studentCourses [0].courseCode = "CS101";
            students.studentCourses [0].courseName = "Introduction to Programming";
            students.studentCourses [0].creditHours = 3;

            students.studentCourses [1].courseCode = "MATH201";
            students.studentCourses [1].courseName = "Calculus II";
            students.studentCourses [1].creditHours = 4;

            students.studentCourses [2].courseCode = "PHYS101";
            students.studentCourses [2].courseName = "Physics I";
            students.studentCourses [2].creditHours = 4;

            students.studentCourses [3].courseCode = "ENG105";
            students.studentCourses [3].courseName = "English Composition";
            students.studentCourses [3].creditHours = 3;

            students.studentCourses [4].courseCode = "HIST100";
            students.studentCourses [4].courseName = "World History";
            students.studentCourses [4].creditHours = 3;

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

            students.studentCourses [0].courseCode = "CS101";
            students.studentCourses [0].courseName = "Introduction to Programming";
            students.studentCourses [0].creditHours = 3;

            students.studentCourses [1].courseCode = "MATH101";
            students.studentCourses [1].courseName = "Calculus I";
            students.studentCourses [1].creditHours = 4;

            students.studentCourses [2].courseCode = "CHEM101";
            students.studentCourses [2].courseName = "Chemistry I";
            students.studentCourses [2].creditHours = 4;

            students.studentCourses [3].courseCode = "SOC200";
            students.studentCourses [3].courseName = "Introduction to Sociology";
            students.studentCourses [3].creditHours = 3;

            students.studentCourses [4].courseCode = "ART105";
            students.studentCourses [4].courseName = "Drawing Fundamentals";
            students.studentCourses [4].creditHours = 2;
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

            students.studentCourses [0].courseCode = "CS201";
            students.studentCourses [0].courseName = "Data Structures";
            students.studentCourses [0].creditHours = 3;

            students.studentCourses [1].courseCode = "MATH201";
            students.studentCourses [1].courseName = "Calculus II";
            students.studentCourses [1].creditHours = 4;

            students.studentCourses [2].courseCode = "BIO101";
            students.studentCourses [2].courseName = "Biology I";
            students.studentCourses [2].creditHours = 4;

            students.studentCourses [3].courseCode = "PSYCH101";
            students.studentCourses [3].courseName = "Introduction to Psychology";
            students.studentCourses [3].creditHours = 3;

            students.studentCourses [4].courseCode = "ECON200";
            students.studentCourses [4].courseName = "Microeconomics";
            students.studentCourses [4].creditHours = 3;
        break;
    }
}

void printStudent(const Student &students, double &sum, const int NUM_CLASSES){

    cout << "ID: " << students.studentID << " - " << students.person.name << endl;
    cout << "Age: " << students.person.age << endl;
    cout << "Address: " << students.person.address.street << ", " << students.person.address.city << ", " << students.person.address.state << " " << students.person.address.ZipCode << endl;
    cout << "GPA: " << students.gpa << endl;
    cout << "Courses:" << endl;

    for(int i = 0; i < NUM_CLASSES; i++)
    {
        cout << "  " << students.studentCourses [i].courseCode << ": " << students.studentCourses [i].courseName << " (" << students.studentCourses [i].creditHours << " credits)" << endl;
    }

    cout << endl;
    sum += students.gpa;

}

void averageGPA(double sum, double &average, const int NUM_STUDENTS)
{
    average = sum/static_cast<double>(NUM_STUDENTS);
    cout << "Average GPA: " << fixed << setprecision(2) << average << endl;
}

Student* findStudentUsingID(vector<Student> &students, int id)
{
    for(int i = 0; i < students.size(); i++)
    {
        if(students[i].studentID == id){
            return &students[i];
        }
    }
    return nullptr;
}

Student *findStudentUsingCourseCode(vector<Student> &students, string courseCode, int i, const int NUM_COURSES)
{
    for( i; i < students.size(); i++)
    {
        for(int n = 0; n < NUM_COURSES; n++)
        {
            if(students[i].studentCourses[n].courseCode == courseCode){
                return &students[i];
            }
        }
    }
    return nullptr;

}
