//**********************************************************
// Author: Orlando Cerralta
// Date: 12.09.2020
// Desc: This program reads the students' name followed by their test score
//      from the user, then outputs the students' name, test score, and grade.
//      The program finally prints the highest score and the students with the
//      highest score. 
// Focus: use of structs
//**********************************************************
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// global constants
const int TOTAL_STUDENTS = 5;

// student type definition
struct student_t {
    string  firstName;
    string  lastName;
    int     testScore;
    char    grade;
};

// function prototypes
void initialize(student_t student[], int listSize);
void readData(student_t student[], int listSize);
char findGrade(int score);  // finds grade for the corresponding score
void getGrade(student_t student[], int listSize);  // gets grade for each student
void displayStudents(student_t student[], int listSize); // displays student data
int  findHScore(student_t student[], int listSize); // finds index of highest score
void displayTopStudents(student_t student[], int listSize, int hScore);

int main() {
    // Var Declarations
    student_t   student[TOTAL_STUDENTS];
    int         highestScore = 0;

    
    initialize(student, TOTAL_STUDENTS);

    // intro
    cout << "Welcome, this program reads the name and test scores of " << TOTAL_STUDENTS << " students" 
        << endl << "and displays the grade of each student, as well as the highest score and which"
        << endl << "among the class have the highest test score!" << endl << endl;
    
    // retrieve data
    readData(student, TOTAL_STUDENTS);
    getGrade(student, TOTAL_STUDENTS);

    // display results
    cout << endl;
    displayStudents(student, TOTAL_STUDENTS);
    cout << endl;

    highestScore = findHScore(student, TOTAL_STUDENTS);
    cout << "Top Test Score: " << student[highestScore].testScore << endl;
    
    cout << "Student(s) with highest score:  ";
    displayTopStudents(student, TOTAL_STUDENTS, highestScore);
    cout << endl;

    return 0;
}

// initialize
void initialize(student_t student[], int listSize) {
    for (int i = 0; i < listSize; i++) {
        student[i].firstName = "";
        student[i].lastName = "";
        student[i].testScore = 0;
        student[i].grade = ' ';
    }
    return;
}

// readData: read name and score of each student
void readData(student_t student[], int listSize) {
    for (int i = 0; i < listSize; i++) {
        cout << "Enter student #" << i + 1 << "'s first name: ";
        cin >> student[i].firstName;
        cout << "Enter student's last name: ";
        cin >> student[i].lastName;
        cout << "Enter student's test score: ";
        cin >> student[i].testScore;
        while(!cin) {
            cin.clear();
            cin.ignore(100, '\n');

            cout << "Invalid test score, please try again: ";
            cin >> student[i].testScore;
        }
    }
    return;
}

// findGrade: recieves score returns its corresponding letter grade 
char findGrade(int score) {
    char grade;

    if (score > 100)
        grade = '?';
    else if (score >= 90)
        grade = 'A';
    else if (score >= 80)
        grade = 'B';
    else if (score >= 70)
        grade = 'C';
    else if (score >= 60)
        grade = 'D';
    else
        grade = 'F';

    return grade;
}

// getGrade: reads each student's test score and assigns corresponding letter grade to member .grade
void getGrade(student_t student[], int listSize) {
    for (int i = 0; i < listSize; i++)
        student[i].grade = findGrade(student[i].testScore);

    return;
}

// displayStudents: creates a table and displays the students name, score and grade to the screen
void displayStudents(student_t student[], int listSize) {
    cout << left;
    cout << "Class Results" << endl;
    cout << setw(15) << "LAST NAME" << setw(15) << "FIRST NAME" 
        << setw(7) << "SCORE" << setw(7) << "GRADE" << endl;
    cout << setfill('-') << setw(44) << "" << setfill(' ') << endl;
    for (int i = 0; i < listSize; i++) {
        //  if name is long, only display the first 13 characters 
        //to keep table looking clean using <string>'s substring function
        cout << setw(15) << student[i].lastName.substr(0, 13) 
            << setw(15) << student[i].firstName.substr(0, 13)
            << setw(7) << student[i].testScore 
            << setw(7) << student[i].grade << endl;
    }
    return;
}

// findHScore: finds index of student with the highest testScore
int findHScore(student_t student[], int listSize) {
    // assume the first student in the list has the highest score
    int hScore = 0; // index for student with highest score

    for (int i = 1; i < listSize; i++) {
        if (student[i].testScore > student[hScore].testScore)
            hScore = i;
    }

    return hScore;
}

// displayTopStudents: displays student(s) with the highest test score
void displayTopStudents(student_t student[], int listSize, int topScore) {
    int alsoHasScore = 0; // counter & flag for number of students with the same score

    // Search number of students with highest score
    // Since we know the first instance of the highest score is topScore,
    //start from the index following topScore
    for (int i = topScore + 1; i < listSize; i++) {
        if (student[i].testScore == student[topScore].testScore)
            alsoHasScore++;
    }

    cout << student[topScore].lastName << ", " << student[topScore].firstName;

    // check if there were multiple students with the same score
    if (alsoHasScore > 0) {
        for (int i = topScore + 1; alsoHasScore > 0 && i < listSize; i++) {
            if (student[i].testScore == student[topScore].testScore) {
                cout << ";  " << student[i].lastName << ", " << student[i].firstName;
                alsoHasScore--;
            }
        }
    }

    return;
}
