class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int i=0;
        int buy=0;
        int sell=0;
        int profit=0;
        while(i<n-1)
        {
            while(i<n-1 && prices[i+1]<=prices[i])//(future < present),so buy in future
            {i++;}
            buy=prices[i];
            while(i<n-1 && prices[i+1]>prices[i])//(future > present),so sell in future
                  {i++;}
                sell=prices[i];
                profit=profit+(sell-buy);
        }
        return profit;
    }
};