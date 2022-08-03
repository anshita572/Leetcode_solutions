class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=INT_MAX;
        int mini2=INT_MAX;
        int profit=0; //overall profit
         int profit2=0;
        int temp_profit=0; //profit if sold now
        int n=prices.size();
        for(int i=0;i<n;i++)
        {
            mini=min(prices[i],mini);
            temp_profit=prices[i]-mini;
            if(temp_profit > profit)
            {profit=temp_profit;}
            mini2=min(prices[i]-profit,mini2);
                profit2=max(profit2,prices[i]-mini2);
        }
        return profit2;
    }
};