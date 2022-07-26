class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0;
        int r=0;
        int ans=INT_MAX;
        int sum=0;
        int n=nums.size();
        while(r<n)
        {
          sum=sum+nums[r];
             r++;
            while(sum >=target)
            {
                ans=min(ans,r-l);
                sum=sum-nums[l];
                l++;
            }
            
        }
        if(ans==INT_MAX)
        {ans=0;}
        return ans;
    }
};
