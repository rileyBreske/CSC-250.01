// basic file operations


#include <iostream> 
#include <fstream>
#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand

using namespace std;


double getAverage(vector<int>& Vec, const int size);
double getSum(vector<int>& Vec, const int size);
double getMedian(vector<int>& Vec, const int size);


//main function
int main () {
	string file;					//user selection for which file theyd like to open. 
	const int size = 101;			//size for number array in the file.
	vector<int> Vec;				//array creation

	//file = "C:\\Users\\rilob\\OneDrive\\Desktop\\test.txt";

	for (int i = 0; i < size; ++i) { Vec.push_back(i); } //fill vector with 1 - 100

	cout << "What file would you like to open?" << endl;		
	cin >> file;									//allow user to fill file string to select desired file.
	ofstream nums;	
	nums.open(file);
		if (!nums) { // file couldn't be opened
			cerr << "Error: file could not be opened" << endl;
			exit(1);
		}

	cout << "Writing this to a file.\n";
	nums << "here are your numbers below.\n";
		for (int i = 0; i < size; i++) { 
		nums << Vec[i] << " ";						//cycles through vector to fill file with numbers
		if (i % 5 == 0) { nums << endl; }			//ends line every 5 numbers
		}  

	cout << "numbers printed." << endl;				//update to console

	nums << "Average of the numbers above: " << getAverage(Vec, size) << endl;
	cout << "numbers averaged." << endl;			//update to console

	nums << "Sum of the numbers above: " << getSum(Vec, size) << endl; 
	cout << "numbers summed." << endl;				//update to console

	nums << "Median of the numbers above: " << getMedian(Vec, size) << endl; 
	cout << "median found." << endl;				//update to console


	nums.close();
	return 0;
}

double getAverage(vector<int>& Vec, const int size) {
	int i, sum = 0;
	double avg;

	for (i = 0; i < size; ++i) {
		sum += Vec[i];
	}
	avg = double(sum) / size;

	return avg;
}

double getSum(vector<int>& Vec, const int size) {
	int i, sum = 0;
	double avg;

	for (i = 0; i < size; ++i) {
		sum += Vec[i];
	}

	return sum;
}

double getMedian(vector<int>& Vec, const int size) {
	int median, i = 0; 
	
	for (i = 0; i < size / 2; ++i) {
		median = Vec[i];
	}

	return median; 
}