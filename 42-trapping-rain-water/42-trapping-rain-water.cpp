class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int ans=0;
        int l=0;
        int r=n-1;
        int left_max=0;
        int right_max=0;
        
       while(l<=r)
        {
            if(height[l]<=height[r])
            {
                if(height[l]>=left_max)
                {left_max=height[l];}
                else //if(height[l]<left_max)
                {ans=ans+(left_max-height[l]);}
                l++;
            }
            else //if(height[l]>height[r])
            {
                if(height[r]>=right_max)
                {right_max=height[r];}
                else //if(height[r]<right_max)
                {ans=ans+(right_max-height[r]);}
                r--;
                    
            }
        }
        return ans;
    }
};