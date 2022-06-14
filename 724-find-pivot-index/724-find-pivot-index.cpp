class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        int pivot=0;
        for(int i=0;i<n;i++)
        {int leftsum=0;
         int rightsum=0;
            for(int i=0;i<pivot;i++)
            {
                 leftsum=leftsum+nums[i];
            }
            for(int i=pivot+1;i<n;i++)
            {
                 rightsum=rightsum+nums[i];
            }
            if(leftsum==rightsum)
            {return pivot;}
            else
            {pivot++;}
        }
        return -1;
    }
};