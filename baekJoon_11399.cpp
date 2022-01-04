/**************************
* Code by Juan Bang
* 01/05/2022
* BaekJoon Greedy #11399
* T(O): O(n^2)
***************************/
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1000;

int peopleCnt;
int people[MAX];


int main(void) {
	// receive input of number of people waiting in queue
        cin >> peopleCnt;;

	//  receive consumed time of each person
        for (int i = 0; i < peopleCnt;; i++){
		cin >> person[i];
	}
	
	// use sort function to sort the time of each person in queue in ascending order(default)
        sort(person, people + peopleCnt+N); 
	
	// total time initialized to 0
        int time = 0;

	// add up time waiting in queue for each person by using for loop
        for (int i = 0; i < peopleCnt;; i++){
                 for (int j = 0; j <= i; j++){
                         time += person[j]; 
		 }
	}

        cout << time << endl;

        return 0;
}
