class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>s;
        
        int maxi=0;
        for(int i=0;i<n;i++)
        {
           s.insert(nums[i]);
        }
        for(int i=0;i<n;i++)
        {
            if(s.count(nums[i]-1))
            {continue;}
            else
            {  int currentNum=nums[i];
             int count=0;
               // count=1;
                while(s.count(currentNum))
              {     currentNum++;
                    count++;  
              }
              maxi=max(maxi,count);
           }
          
        }
        return maxi;
    }
};