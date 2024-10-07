//#include "//Daniel Gebrezgiabhier\source\repos\header.cpp\"
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

const int MAX_STUDENTS = 20;

string names[MAX_STUDENTS];
double scores[MAX_STUDENTS];
 
void input_scores(int& count) {
    cout << "Enter number of students (max " << MAX_STUDENTS << "): ";
    cin >> count;

    

    for (int i = 0; i < count; i++) {
        cout << "Enter name for student " << (i + 1) << ": ";
        cin >> names[i];
        cout << "Enter score for " << names[i] << ": ";
        cin >> scores[i];
    }
}

// Function to calculate total score
double total_grades(int count) {
    double sum = 0;
    for (int i = 0; i < count; i++) {
        sum += scores[i];
    }
    return sum;
}

// Function to calculate average score
double average_grades(int count) {
    double total_score = total_grades(count);
    return total_score / count;
}

// Function to display analysis of grades
void display_results(int count) {
    double total_score = total_grades(count);
    double average = average_grades(count);
    double highest = scores[0];
    double lowest = scores[0];
    string above_average[MAX_STUDENTS];
    int above_count = 0;

    for (int i = 0; i < count; i++) {
        if (scores[i] > highest) highest = scores[i];
        if (scores[i] < lowest) lowest = scores[i];
        if (scores[i] > average) {
            above_average[above_count++] = names[i];
        }
    }

    cout << fixed << setprecision(2);
    cout << "\nGrade Analysis:\n";
    cout << "Total Score: " << total_score << endl;
    cout << "Average Score: " << average << endl;
    cout << "Highest Score: " << highest << endl;
    cout << "Lowest Score: " << lowest << endl;
    cout << "Students Above Average: ";

    for (int i = 0; i < above_count; i++) {
        cout << above_average[i] << " ";
    }
    cout << endl;
}

// Function to compare grades of two students
void compare_results(int count) {
    while (true) {
        string student1, student2;
        cout << "\nEnter the first student's name to compare (or type 'exit' to finish): ";
        cin >> student1;
        if (student1 == "exit") {
            break;
        }

        cout << "Enter the second student's name to compare: ";
        cin >> student2;

        // Search for the two students
        double score1 = -1, score2 = -1;
        for (int i = 0; i < count; i++) {
            if (names[i] == student1) {
                score1 = scores[i];
            }
            if (names[i] == student2) {
                score2 = scores[i];
            }
        }

        // Check if both scores were found
        if (score1 != -1 && score2 != -1) {
            if (score1 > score2) {
                cout << student1 << " has a higher score than " << student2 << "." << endl;
            }
            else if (score1 < score2) {
                cout << student2 << " has a higher score than " << student1 << "." << endl;
            }
            else {
                cout << student1 << " and " << student2 << " have the same score." << endl;
            }
        }
        else {
            cout << "One or both student names are not found in the records." << endl;
        }
    }
}



int main() {
    int count = 0; 

    input_scores(count);      
    display_results(count);    
    compare_results(count);     

    return 0;
}
