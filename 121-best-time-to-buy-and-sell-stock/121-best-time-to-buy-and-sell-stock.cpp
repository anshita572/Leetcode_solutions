class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=INT_MAX;
        int profit=0;
        int temp_profit=0;
        int n=prices.size();
        for(int i=0;i<n;i++)
        {
            mini=min(prices[i],mini);
            temp_profit=prices[i]-mini;
            if(temp_profit > profit)
            {profit=temp_profit;}
        }
       
        return profit;
    }
};