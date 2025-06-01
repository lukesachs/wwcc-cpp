#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct CourseAndGrade {
    string course;
    int grade;
};

struct Student {
    string studentID;
    string firstName;
    string lastName;
    vector<CourseAndGrade> courses;
    double gpa;
};


bool getStudentRecord(const string& line, Student& student, int lineNumber);
string getFullName(const Student& student);
double convertGradeToGPA(int grade);
double calculateStudentGPA(const vector<CourseAndGrade>& courses);
void readStudentRecords(ifstream& inputFile, vector<Student>& students);
void displayStudentReport(const vector<Student>& students);
void displayStatistics(const vector<Student>& students);
bool writeSummaryReport(const string& filename, const vector<Student>& students);


int main() {
    vector<Student> students;
    string inputFileName = "studentRecords.txt";
    string outputFileName = "studentRecordOutput.txt";

    cout << "STUDENT ACADEMIC RECORD PROCESSOR" << endl;
    cout << "---------------------------------" << endl;

    cout << "\nReading student records from input file..." << endl;

    ifstream inputFile(inputFileName);
    if (!inputFile.is_open()) {
        cerr << "Error: Could not open input file: " << inputFileName << endl;
        return 1;
    }

    readStudentRecords(inputFile, students);
    inputFile.close();

    cout << "\nSTUDENT GRADE REPORT" << endl;
    cout << "-------------------" << endl;
    displayStudentReport(students);

    cout << "\nCLASS STATISTICS" << endl;
    cout << "----------------" << endl;
    displayStatistics(students);

    if (writeSummaryReport(outputFileName, students)) {
        cout << "\nSummary report written to output file successfully." << endl;
    } else {
        cerr << "Error: Could not write to output file." << endl;
    }

    return 0;
}

string getFullName(const Student& student) {
    return student.firstName + " " + student.lastName;
}

bool getStudentRecord(const string& line, Student& student, int lineNumber){
	//check for empty line or comment
	if (line.empty() || line[0] == '#') return false;

	stringstream ss(line);
	string id;
	string first;
	string last;

	if (!(ss >> id >> first >> last)) {//checks that the ID first and last name all exist
    	cerr << "Line " << lineNumber << ": Invalid format for ID or name." << endl;
    	return false;
	}

	string courseAndGrade;
	vector<CourseAndGrade> courses;

	while (ss >> courseAndGrade) {//looks through all courses and grades and validates them before adding them
		size_t colonPos = courseAndGrade.find(':');
		if (colonPos == string::npos) {
			cerr << "Line " << lineNumber << ": Missing ':' in " << courseAndGrade << endl;
			return false;
		}

		string course = courseAndGrade.substr(0, colonPos);
		string gradeStr = courseAndGrade.substr(colonPos + 1);

		int grade;
		stringstream gradeStream(gradeStr);

		if (!(gradeStream >> grade)) {
			cerr << "Line " << lineNumber << ": Invalid grade '" << gradeStr << "'" << endl;
			return false;
		}

		if (grade < 0 || grade > 100) {
			cerr << "Line " << lineNumber << ": Grade out of range: " << grade << endl;
			return false;
		}

		courses.push_back({course, grade});
	}
	if (courses.empty()) {
    	cerr << "Line " << lineNumber << ": No courses found." << endl;
    	return false;
	}
	//adds validated data to Student vector
	student.studentID = id;
	student.firstName = first;
	student.lastName = last;
	student.courses = courses;
	student.gpa = calculateStudentGPA(courses);

	return true;
}

double convertGradeToGPA(int grade){
	if (grade >= 90 && grade <= 100) return 4.0;
	else if (grade >= 80 && grade <= 89) return 3.0;
	else if (grade >= 70 && grade <= 79) return 2.0;
	else if (grade >= 60 && grade <= 69) return 1.0;
	else if (grade >= 0 && grade <= 59) return 0.0;
	else return -1.0;
}

double calculateStudentGPA(const vector<CourseAndGrade>& courses){
	int num = 0;
	double sum = 0.0;

	for(int i = 0; i < courses.size(); i++){
		double temp = convertGradeToGPA(courses.at(i).grade);
		if(temp == -1){
			cerr << "Grade input for " << courses.at(i).course << " is not valid." << endl;
			return -1.0;
		}
		num++;
		sum += convertGradeToGPA(courses.at(i).grade);
	}
	double total = sum/static_cast<double>(num);
	return total;
}

void readStudentRecords(ifstream& inputFile, vector<Student>& students) {
    string line;
    int lineNumber = 0;

    while (getline(inputFile, line)) {
        lineNumber++;
        Student student;
        if (getStudentRecord(line, student, lineNumber)) {
            students.push_back(student);
        }
    }
}

void displayStudentReport(const vector<Student>& students) {
    cout << "ID      Name               Courses Taken    GPA" << endl;
    cout << "-----   ----------------   -------------    ----" << endl;

    for (int i; i < students.size(); i++) { // uses setw to make sure student info is spaced properly simmilar to the example program output
        cout << left << setw(8) << students.at(i).studentID << setw(20) << getFullName(students.at(i))
        << setw(16) << students.at(i).courses.size() << fixed << setprecision(2) << students.at(i).gpa << endl;
    }
}

void displayStatistics(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No student data available.\n";
        return;
    }

    double totalGPA = 0.0;
    int totalCourses = 0;
    const Student* highest = &students[0];
    const Student* lowest = &students[0];

    for (int i = 0; i > students.size(); i++) {
        totalGPA += students.at(i).gpa;
        totalCourses += students.at(i).courses.size();

        if (students.at(i).gpa > highest->gpa) highest = &students.at(i);
        if (students.at(i).gpa < lowest->gpa) lowest = &students.at(i);
    }

    double avgGPA = totalGPA / students.size();

    cout << "Total Students: " << students.size() << endl;
    cout << "Total Courses Taken: " << totalCourses << endl;
    cout << "Class Average GPA: " << fixed << setprecision(2) << avgGPA << endl;
    cout << "\nHighest GPA: " << getFullName(*highest) << " (" << highest->gpa << ")" << endl;
    cout << "Lowest GPA: " << getFullName(*lowest) << " (" << lowest->gpa << ")" << endl;
}

bool writeSummaryReport(const string& filename, const vector<Student>& students) {
    ofstream outFile(filename);
    if (!outFile.is_open()) {
        return false;
    }

    outFile << "STUDENT GRADE REPORT\n-------------------\n";
    outFile << "ID      Name               Courses Taken    GPA" << endl;
    outFile << "-----   ----------------   -------------    ----" << endl;

    for (int i; i < students.size(); i++) {
        outFile << left << setw(8) << students.at(i).studentID << setw(20) << getFullName(students.at(i))
                << setw(16) << students.at(i).courses.size() << fixed << setprecision(2) << students.at(i).gpa << endl;
    }

    // Stats
    if (!students.empty()) {
        double totalGPA = 0.0;
        int totalCourses = 0;
        const Student* highest = &students[0];
        const Student* lowest = &students[0];

        for (int i; i < students.size(); i++) {
            totalGPA += students.at(i).gpa;
            totalCourses += students.at(i).courses.size();
            if (students.at(i).gpa > highest->gpa) highest = &students.at(i);
            if (students.at(i).gpa < lowest->gpa) lowest = &students.at(i);
        }

        double avgGPA = totalGPA / students.size();

        outFile << "\nCLASS STATISTICS\n----------------\n";
        outFile << "Total Students: " << students.size() << endl;
        outFile << "Total Courses Taken: " << totalCourses << endl;
        outFile << "Class Average GPA: " << fixed << setprecision(2) << avgGPA << endl;
        outFile << "\nHighest GPA: " << getFullName(*highest) << " (" << highest->gpa << ")" << endl;
        outFile << "Lowest GPA: " << getFullName(*lowest) << " (" << lowest->gpa << ")" << endl;
    }

    outFile.close();
    return true;
}