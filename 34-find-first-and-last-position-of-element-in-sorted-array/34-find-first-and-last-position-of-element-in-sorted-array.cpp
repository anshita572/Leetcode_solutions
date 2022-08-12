class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans;
        auto it1=lower_bound(nums.begin(),nums.end(),target);
        int first=it1-nums.begin();
        if(it1 != nums.end() && nums[first]==target)
        {ans.push_back(first);}
        else
        {ans.push_back(-1);}
        auto it2=upper_bound(nums.begin(),nums.end(),target);
        int last=it2-nums.begin();
        last-=1;
        if(last>=0 && nums[last]==target)
        {ans.push_back(last);}
        else
        {ans.push_back(-1);}
        return ans;
    }
};