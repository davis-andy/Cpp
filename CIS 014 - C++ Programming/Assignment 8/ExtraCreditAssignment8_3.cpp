/**
 * Assignment #8.3
 * DUE: 11/3
 * NAME: Andy Davis
 * PURPOSE: Extra credit
*/

#include <iostream>
#include <vector>
using namespace std;


/**
 * FUNCTION NAME: getLegoCombinations
 * PURPOSE: 
 *      Create a wall of (target_height) units high 
 * 		with the lengths of lego bricks given by (lego_heights)
 * PARAMETER:
 * 		vector<int> &lego_heights
 *      int target_height
 * RETURN VALUE:
 * 		int output
 * FUNCTION SIGNATURE:
 *      int getLegoCombinations(vector<int> &lego_heights, int target_height)
*/

int getLegoCombinations(vector<int> &lego_heights, int target_height){
	vector<int> height(target_height+1);
	vector<vector<int> > result(lego_heights.size()+1, height);

    for (int i = 0; i <= lego_heights.size(); i++) {
		result[i][0] = 1; //there is 1 way to get a height of 0 (no bricks)
    }

	for (int j = 1; j <= target_height; j++) {
		result[0][j] = 0; //initialize to 0
	}


	for (int x = 1; x <= lego_heights.size(); x++) {
		for (int y = 1; y <= target_height; y++){
			if (lego_heights[x-1] <= y) { //if brick height is less than target height
				result[x][y] = result[x-1][y] + result[x][y-lego_heights[x-1]]; //include
			}
			else {
				result[x][y] = result[x-1][y]; //do not include
			}
		}
	}
	
	if (target_height == 0){ //for homework reasons, no ways to return a height of 0
	    return 0;
	}
    
    return result[lego_heights.size()][target_height];
}


int main() {
    vector<int> a = {1,2,5};
    vector<int> b = {5};
    cout << getLegoCombinations(a, 3) << endl;  //2
    cout << getLegoCombinations(a, 0) << endl;  //0
    cout << getLegoCombinations(a, 7) << endl;  //6
    cout << getLegoCombinations(b, 9) << endl;  //0
}


/*
Dynamic Programming: Bottom-up –

Create a solution matrix. (solution[items+1][goal+1]).

Base Cases:
--if goal=0 then just return 0.
--if no items given, 0 ways to change the goal.


Rest of the cases:
--For every item we have an option to include it in solution or exclude it.
--Check if the item value is less than or equal to the goal needed, 
   if yes then we will find ways by including that item and excluding that item.
1. Include the item: reduce the goal by item value and use the sub problem solution (goal-v[i]).
2. Exclude the item: solution for the same goal without considering that item.
--If item value is greater than the goal then we can’t consider that item, 
   so solution will be without considering that item.
*/