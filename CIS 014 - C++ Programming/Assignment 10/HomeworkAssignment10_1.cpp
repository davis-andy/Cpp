/**
 * Assignment #10.1
 * DUE: 11/17
 * NAME: Andy Davis
 * PURPOSE: Determine the route that earns you the maximum amount of points from a pinball type game.
*/

#include <iostream>
#include <vector>
using namespace std;

class CIS14 {
public:
    int getMaxPoints(vector<vector<int> > &maze);
}; 

/**
 * FUNCTION NAME: 
 *      getMaxPoints
 * PURPOSE: 
 *      Calculate the max number of points achieved when cascading down a pyramid
 * PARAMETER:
 * 		vector<vector<int>> &maze
 * RETURN VALUE:
 *      int: max total points
*/

int CIS14::getMaxPoints(vector<vector<int>> &maze){
    int currentPos = 0;
    int i = maze.size()-2;
    int result;
    
    
    for (i; i >= 0; i--){
        if (maze[i].empty()) return 0;
        for (currentPos; currentPos < maze[i].size(); currentPos++){
            if (maze[i+1][currentPos] > maze[i+1][currentPos+1]){
                maze[i][currentPos] += maze[i+1][currentPos];
            }
            else{
                maze[i][currentPos] += maze[i+1][currentPos+1];
            }
        }
        
        currentPos = 0;
    }
    
    result = maze[0][0];

    return result;
}


int main() {
    vector<vector<int>> maze = {{2}, {4,1}, {5,3,8}, {1,6,7,3}}; 
    vector<vector<int>> mazeB = {{0}, {4,1}, {5,3,8}, {1,6,7,3}}; 
    vector<vector<int>> mazeC = {{1}, {1,1}, {1,1,1}, {1,1,1,1}}; 
    vector<vector<int>> mazeD = {{3}, {7,4}, {2,4,6}, {8,5,9,3}}; 
    vector<vector<int>> mazeE = {{1}, {1,22305}, {1,29394,1}, {1,1,1234,1}, {1,1,3,1,10}};
    vector<vector<int>> mazeF = {{}, {}, {}, {}}; 

    CIS14 cis;

    cout <<  cis.getMaxPoints(maze) << endl; //18
    cout <<  cis.getMaxPoints(mazeB) << endl; //16
    cout <<  cis.getMaxPoints(mazeC) << endl; //4
    cout <<  cis.getMaxPoints(mazeD) << endl; //23
    cout <<  cis.getMaxPoints(mazeE) << endl; //52937
    cout <<  cis.getMaxPoints(mazeF) << endl; //0
    
}