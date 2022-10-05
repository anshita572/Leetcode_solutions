class Solution {
public:
    int solve(vector<int>& nums,int i,int j)
    {if(i>j)//base case
    {return 0;}
        int op1=nums[i]+min(solve(nums,i+1,j-1),solve(nums,i+2,j));
        int op2=nums[j]+min(solve(nums,i,j-2),solve(nums,i+1,j-1));
        int p1_score=max(op1,op2);
        return p1_score;
    }
    bool PredictTheWinner(vector<int>& nums) {
        int i=0;
        int j=nums.size()-1;
        int p1_score=solve(nums,i,j);
        int sum=0;
        for(int k=0;k<nums.size();k++)
        {sum+=nums[k];}
        int p2_score=sum-p1_score;
        if(p1_score>=p2_score)
        {return true;}
        else
        {return false;}
    }
};