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
    int profit = 0;
    int temp = 0

    for (int i = prices.size() - 1; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            temp = prices[i] - prices[j];
        }
        if (temp > profit) 
        {
            profit = temp;
        }
    }

    return profit;
}


int main() {
    vector<int> prices = {1,2,4};
    getMaxProfit(prices);
    return 0;
}