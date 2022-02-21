//Riley Breske
//Week 4 Lab

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    const int numAns = 10; //stores the number of questions in the test as a constant.
    char corrAns[numAns]; //array to store the correct answers.
    string question[numAns]; //array to store the test questions.
    vector<char> userAns(numAns); //vector to store the users responses.
    // vector<int> incorrAns(numAns); //vector to log which question the user missed
    int i;
    int right = 0;
    int wrong = 0;
    int value;

    //Answer key
    corrAns[0] = 'A';
    corrAns[1] = 'B';
    corrAns[2] = 'D';
    corrAns[3] = 'A';
    corrAns[4] = 'D';
    corrAns[5] = 'C';
    corrAns[6] = 'C';
    corrAns[7] = 'A';
    corrAns[8] = 'B';
    corrAns[9] = 'C';

    //test questions
    question[0] = "What is 1+1?\nA) 2\nB) 1\nC) 3\nD) 4 ";
    question[1] = "What is 3-1?\nA) 1\nB) 2\nC) 3\nD) 4 ";
    question[2] = "What is 2+2?\nA) 1\nB) 2\nC) 3\nD) 4 ";
    question[3] = "What is 5-4?\nA) 1\nB) 2\nC) 3\nD) 4 ";
    question[4] = "What is 5-1?\nA) 1\nB) 2\nC) 3\nD) 4 ";
    question[5] = "What is 1+2?\nA) 1\nB) 2\nC) 3\nD) 4 ";
    question[6] = "What is 4-1?\nA) 1\nB) 2\nC) 3\nD) 4 ";
    question[7] = "What is 9-8?\nA) 1\nB) 2\nC) 3\nD) 4 ";
    question[8] = "You're 3rd place right now in a race. What place are you in when you pass the person in 2nd place?\nA) 2nd\nB) 1st\nC) 3rd\nD) none of the above. ";
    question[9] = "how many months have 28 days?\nA) 2\nB) 1\nC) all of them\nD) depends if theres a leap year of not ";

    //loop that cycles through test promt
    for (int i = 0; i < numAns; i++) {
        cout << "\n";
        cout << i + 1 << ") "<< question[i] << endl;
        cin >> userAns[i];
        userAns[i] = std::toupper(userAns[i]); //converts responses to uppercase letters
    }

    //loop that compares user responses to correct answers
    for (int i = 0; i < numAns; i++) {
        if (userAns[i] == corrAns[i]) {
            right++; //increments if user answered question correct
        }
        else {
            wrong++; //increments if user answered question incorrect, then displays so. 
            cout << "You got number " << i+1 << " Wrong.\n";

        }

    }

    cout << "correct responses: " << right << "\n";
    cout << "incorrect responses: " << wrong << "\n";
    cout << right * 10 << "%:";

    //displays pass or fail to user
    if (right >= 7) {
        cout << " You passed!\n";
    }
    else {
        cout << " you failed!\n";
    }
    
    return 0;
}
