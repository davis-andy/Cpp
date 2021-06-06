/**
 * Assignment #7.2
 * DUE: 10/20
 * NAME: Andy Davis
 * PURPOSE: Create a function that recommends the maximum profit an investor can make 
 *      by placing AS MANY buy-sell orders as you may in the time slice 
 *      represented by the input vector
*/

#include <iostream>
#include <vector>
using namespace std;


/**
 * FUNCTION NAME: getMaxProfit
 * PURPOSE: 
 *      The function recommends the maximum profit an investor can make 
 *      by placing AS MANY buy-sell orders as you may in the time slice 
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
    int j = 1;

    for (int i = 0; i < prices.size(); i++)
    {
        if (prices[i] < prices[j])
        {
            profit += prices[j] - prices[i];
            j++;
        }
        else j++;
    }

    return profit;
}


int main() {
    vector<int> prices = {1,2,4};
    cout << getMaxProfit(prices);
    return 0;
}