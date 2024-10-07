#include <iomanip>
#include <iostream>
#include <string>
#include <limits> // For numeric_limits
using namespace std;

const int MAX_STUDENTS = 20;

string names[MAX_STUDENTS];
double scores[MAX_STUDENTS];

void input_scores(int& count) {
    cout << "Enter number of students (max " << MAX_STUDENTS << "): ";

    while (true) {
        cin >> count;
        if (cin.fail() || count < 1 || count > MAX_STUDENTS) {
            cin.clear(); // Clear the error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Please enter a valid number of students (1 to " << MAX_STUDENTS << "): ";
        }
        else {
            cin.ignore(); // Clear the input buffer
            break;
        }
    }

    for (int i = 0; i < count; i++) {
        cout << "Enter name for student " << (i + 1) << ": ";
        getline(cin, names[i]); // Use getline to capture full names
        cout << "Enter score for " << names[i] << ": ";

        while (true) {
            cin >> scores[i];
            if (cin.fail() || scores[i] < 0 || scores[i] > 100) {
                cin.clear(); // Clear the error state
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                cout << "Please enter a valid score (0-100) for " << names[i] << ": ";
            }
            else {
                cin.ignore(); // Clear the input buffer
                break;
            }
        }
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
    if (count == 0) return 0; // Avoid division by zero
    return total_grades(count) / count;
}

// Function to display analysis of grades
void display_results(int count) {
    if (count == 0) return; // No results to display

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

        double score1 = -1, score2 = -1;
        for (int i = 0; i < count; i++) {
            if (names[i] == student1) score1 = scores[i];
            if (names[i] == student2) score2 = scores[i];
        }

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
