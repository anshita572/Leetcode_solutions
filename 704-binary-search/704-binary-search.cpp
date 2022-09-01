class Solution {
public:
    int recursive(vector<int>& nums, int target,int s,int e)
    {
        if(s>e)
    {return -1;}
        int mid=s+(e-s)/2;
        if(nums[mid]==target)
        {return mid;}
         else if(nums[mid]<target)
         {return recursive(nums,target,mid+1,e);}
        else
        {return recursive(nums,target,s,mid-1);}
       
    }
    int search(vector<int>& nums, int target) {
        int s=0;
        int e=nums.size()-1;
        return recursive(nums,target,s,e);
    }
};