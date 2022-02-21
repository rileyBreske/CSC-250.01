/*Riley Breske
*Searching and Sorting
*Week 6
*/
#include <iostream>     // std::cout
#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand

using namespace std;

// random generator function:
int rng (int i) { return rand()%i;}

//function to call and print vector
void printvector(vector<int> myvector){
	for(int i=0;i<myvector.size();++i)
		cout<<myvector[i]<<" ";
	cout<<"\n";
}

//bubblesort function
void bubbleSort(vector<int>& myvector)
{
    bool swap = true;
    while(swap)
    {
        swap = false;
        for (int i = 0; i < myvector.size()-1; i++)
        {
            if (myvector[i]>myvector[i+1] )
            {
                myvector[i] += myvector[i+1];
                myvector[i+1] = myvector[i] - myvector[i+1];
                myvector[i] -= myvector[i+1];
                swap = true;
            }
        }
    }
}

// Linear Search function
int LinearSearch(vector<int> myvector, int key) {
   int i;
   
   for (i = 0; i < 1000; ++i) {
      if (myvector[i] == key) {
         return i;
      }
   }
    return -1; //number not found
}

//partition function for quicksort
int Partition(vector<int> &myvector, int start, int end){
	
	int pivot = end;
	int j = start;
	for(int i=start;i<end;++i){
		if(myvector[i]<myvector[pivot]){
			swap(myvector[i],myvector[j]);
			++j;
		}
	}
	swap(myvector[j],myvector[pivot]);
	return j;
	
}

//quick sort function
void Quicksort(vector<int> &myvector, int start, int end ){

	if(start<end){
		int p = Partition(myvector,start,end);
		Quicksort(myvector,start,p-1);
		Quicksort(myvector,p+1,end);
	}
	
}

int main () {
  srand ( unsigned ( time(0) ) );
  vector<int> myvector;
  int key; 
  int keyIndex;


/*
*After Vector (myvector) initalization the numbers a randomly sorted
*/
  // set some values:
  for (int i=1; i<1000; ++i) myvector.push_back(i); // 1 2 3 4 5 6 7 8 9

  // using rng function:
  random_shuffle ( myvector.begin(), myvector.end(), rng);

  // print out content of myvector function:
  cout << "myvector contains:";
  printvector(myvector);
  cout << '\n' << '\n';


/*
*Allows to user to select the number to search in the randomly sorted vector.
*the number is then searched and displayed with the corresponding index
*/
cout << "Enter a value between 1 and 1000: ";
   cin >> key;
    if (!(key >= 1) || !(key <= 1000)){
        cout << "Please enter a value with-in range (1-1000):";
        cin >> key;
    }

   keyIndex = LinearSearch(myvector, key);
   
   if (keyIndex == -1) {
      cout << key << " was not found." << endl;
   }
   else {
      cout << "Found " << key << " at index " << keyIndex << "." << '\n'<<endl;
   }


/*
*Allows user to select the sorting algorithm to be used on the vector
*/
  cout << "What sorting method would you like to use?\nA) Bubble Sort\nB) Quick sort\n";
  char userSelect;
  cin >> userSelect;

if (userSelect == 'A'||userSelect == 'a'){cout << "A was selected";
bubbleSort(myvector);
printvector(myvector);
}
else if (userSelect == 'B'||userSelect == 'b'){cout << "B was selected";
Quicksort(myvector,0,myvector.size()-1);
printvector(myvector);
}

else {cout<<"Please enter a vaild selection: A, B";
cin >> userSelect;
}
  return 0;
}
