/**
 * Assignment #7.1
 * DUE: 10/20
 * NAME: Andy Davis
 * PURPOSE: Create a function that recommends the maximum profit an investor can make 
 *      by placing AT MOST one buy and one sell order in the time slice 
 *      represented by the input vector.
*/

#include <iostream>
#include <vector>
using namespace std;


/**
 * FUNCTION NAME: getMaxProfit
 * PURPOSE: 
 *      The function recommends the maximum profit an investor can make 
 *      by placing AT MOST one buy and one sell order in the time slice 
 *      represented by the input vector
 * PARAMETER:
 * 		vector<int> &prices
 * RETURN VALUE:
 * 		int profit
 * FUNCTION SIGNATURE:
 *      int getMaxProfit(vector<int> &prices)
*/

int getMaxProfit(vector<int> &prices)
{
    int maxNum = 0;
    int minNum = prices[0];
    int pointMax = 0;
    int pointMin = 0;

    for (int i = 0; i < prices.size(); i++)
    {
        if (maxNum < prices[i]) 
        {
            maxNum = prices[i];
            pointMax = i;
        }
        if (minNum > prices[i]) 
        {
            minNum = prices[i];
            pointMin = i;
        }
    }

    if (pointMin < pointMax)
    {
        return maxNum - minNum;
    }
    else return 0;
}


int main() {
    vector<int> prices = {1,2,4};
    getMaxProfit(prices);
    return 0;
}


'''
TEST FAILED - 
INPUT: [9999999,999999,1,11111,2333,23333,2333,575,85,2,4,7,888868] 
YOUR OUTPUT: [0] 
EXPECTED: [888867]

TEST FAILED - 
INPUT: [32,78,1] 
YOUR OUTPUT: [0] 
EXPECTED: [46] 

TEST FAILED - 
INPUT: [33,83,14,12,11,10,9,8,7,1] 
YOUR OUTPUT: [0] 
EXPECTED: [50]
'''