class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int rightsum=0;
        int leftsum=0;
        for(int i=0;i<n;i++)
        {
            sum=sum+nums[i];
          rightsum=sum;
        }
      //  rightsum=sum;
        for(int i=0;i<n;i++)
        { rightsum=rightsum-nums[i];
            if(leftsum==rightsum)
            {return i;}
            else
            {
               
                leftsum=leftsum+nums[i];
            }
        }
        return -1;
        
    }
};