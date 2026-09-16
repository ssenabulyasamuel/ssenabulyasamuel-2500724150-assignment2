#include <iostream>

int main() {
    const int numberOfStudents = 8;
    const int numberOfQuestions = 10;

    const char answerKey[numberOfQuestions] = {
        'D', 'B', 'D', 'C', 'C', 'D', 'A', 'E', 'A', 'D'
    };

    const char studentAnswers[numberOfStudents][numberOfQuestions] = {
        {'A', 'B', 'A', 'C', 'C', 'D', 'E', 'E', 'A', 'D'},
        {'D', 'B', 'A', 'B', 'C', 'A', 'E', 'E', 'A', 'D'},
        {'E', 'D', 'D', 'A', 'C', 'B', 'E', 'E', 'A', 'D'},
        {'C', 'B', 'A', 'E', 'D', 'C', 'E', 'E', 'A', 'D'},
        {'A', 'B', 'D', 'C', 'C', 'D', 'E', 'E', 'A', 'D'},
        {'B', 'B', 'E', 'C', 'C', 'D', 'E', 'E', 'A', 'D'},
        {'B', 'B', 'A', 'C', 'C', 'D', 'E', 'E', 'A', 'D'},
        {'E', 'B', 'E', 'C', 'C', 'D', 'E', 'E', 'A', 'D'}
    };

    for (int student = 0; student < numberOfStudents; student++) {
        int correctAnswers = 0;

        for (int question = 0; question < numberOfQuestions; question++) {
            if (studentAnswers[student][question] == answerKey[question]) {
                correctAnswers++;
            }
        }

        std::cout << "Student " << student << ": "
                  << correctAnswers << " correct answers out of "
                  << numberOfQuestions << "\n";
    }

    return 0;
}