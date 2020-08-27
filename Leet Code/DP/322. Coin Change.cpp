/*
You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:

Input: coins = [1, 2, 5], amount = 11
Output: 3 
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1

*/



class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
  		
  		int n = coins.size();
  		if(n<1) {
  			return 0;
  		}      

  		vector<int> minCoins(amount+1,INT_MAX-9);
  		minCoins[0] = 0;
  		for(int i = 1;i<=amount;i++) {
  			for(int j = 0;j<n;j++) {
  				if(i>=coins[j]) {
  					minCoins[i] = min(minCoins[i], minCoins[i-coins[j]] + 1);
  				}
  			}
  		}

  		return minCoins[amount] == INT_MAX-9?-1:minCoins[amount];
    }
};