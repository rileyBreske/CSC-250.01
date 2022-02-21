//Riley Breske
//Week 5 Lab

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

int getScore(int testNum) {
    int score;
    cout << "enter a test score";
	cin >> score; 
    cout << "The score of Test " << testNum << " is " << score << "\n"; 
    return score;
}

float calcAverage(int scoreArray[5], int lowest) {
    float average;
    average = (scoreArray[1] + scoreArray[2] + scoreArray[3] + scoreArray[4] + scoreArray[5] - lowest) / 4;
    return average;
}


int findLowest(int scoreArray[5]) {
    int lowest = scoreArray[0];

	if (scoreArray[2] < lowest){
		lowest = scoreArray[2];}
	if (scoreArray[3] < lowest){
		lowest = scoreArray[3];}
	if (scoreArray[4] < lowest){
		lowest = scoreArray[4];}
	if (scoreArray[5] < lowest){
		lowest = scoreArray[5];}

	cout << "The lowest score is " << lowest << endl;
	return lowest;
}

int main() {    
    int scoreArray[5];
    int testScore = 0;
    float avg = 0.0;
    int total = 0; 
    int lowest; 

    //populate the array
    for (int i = 1; i <= 5; i++) {
	    scoreArray[i - 1] = getScore(i);
    }

    cout << findLowest(scoreArray[5]); 
    return 0;
}