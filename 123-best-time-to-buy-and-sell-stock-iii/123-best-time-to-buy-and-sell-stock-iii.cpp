class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini1=INT_MAX;
        int mini2=INT_MAX;
        int profit1=0; 
        int profit2=0;
        int temp_profit1=0; 
        int temp_profit2=0;
        int netBuyPrice=0;
        int n=prices.size();
        for(int i=0;i<n;i++)
        {
            mini1=min(prices[i],mini1);
            temp_profit1=prices[i]-mini1;
            if(temp_profit1 > profit1)
            {profit1=temp_profit1;}
            netBuyPrice=prices[i]-profit1;
            mini2=min(netBuyPrice,mini2);
            temp_profit2=prices[i]-mini2;
             if(temp_profit2 > profit2)
            {profit2=temp_profit2;}
        }
        return profit2;
    }
};