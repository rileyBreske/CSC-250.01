//Riley Breske
//Week 5 Lab
#include <iostream>
#include <iomanip>
using namespace std;

// function prototypes
void getScore(int &);
void calcAverage(int, int, int, int, int);
int findLowest(int, int, int, int, int);

int main() {
	int mainScore1, mainScore2, mainScore3, mainScore4, mainScore5;

	// gets the score of 5 tests from user
	for (int i = 1; i < 6; i++){
		if (i == 1) {
			getScore(mainScore1);
		}
		else if (i == 2) {
			getScore(mainScore2);
		}
		else if (i == 3) {
			getScore(mainScore3);
		}
		else if (i == 4) {
			getScore(mainScore4);
		}
		else if (i == 5) {
			getScore(mainScore5);
		}
	} // end of for loop

	calcAverage(mainScore1, mainScore2, mainScore3, mainScore4, mainScore5);

	return 0;
}

// retreives score, then validates it
void getScore(int &score) {
	int validScore;
	cout << "Enter the score of the test: ";
	cin >> validScore;
	// validate user entry
	while ((validScore < 0) || (validScore > 100)) {
		cout << "Please reenter a value between 0 and 100: " << endl;
		cin >> validScore;
	}// end of validation
	score = validScore;
}

// calls findLowest, then computes average, then displays info to user.
void calcAverage(int score1, int score2, int score3, int score4, int score5) {

	int dropScore = findLowest(score1, score2, score3, score4, score5);
	int sum = score1 + score2 + score3 + score4 + score5 - dropScore;
	double average = sum / 4.0;

	cout << "The average score of your tests is: " << average << endl;
    cout << "The lowest score of your tests is: " << dropScore << endl;
    cout << "The scores that were input were: " << score1 << ", " << score2 << ", " << score3 << ", " << score4 << ", " << score5 << "." << endl;
    cout << "The scores that were counted were: ";
        if (dropScore != score1) {
            cout << score1 << ", "; 
        }
        if (dropScore != score2) {
            cout << score2 << ", "; 
        }
        if (dropScore != score3) {
            cout << score3 << ", "; 
        }
        if (dropScore != score4) {
            cout << score4 << ", "; 
        }
        if (dropScore != score5) {
            cout << score5 << ", "; 
        }// end of if statements
        cout << endl;
}

// takes all 5 scores then drops the lowest one.
int findLowest(int score1, int score2, int score3, int score4, int score5) {
	int lowestScore;
	if (score1 <= score2) {
		lowestScore = score1;
	}
	else {
		lowestScore = score2;
	}
	if (score3 < lowestScore) {
		lowestScore = score3;
	}
	if (score4 < lowestScore) {
		lowestScore = score4;
	}
	if (score5 < lowestScore) {
		lowestScore = score5;
	} 
	return lowestScore;
}
