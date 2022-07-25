class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>arr1(n);
        vector<int>arr2(n);
        int prefix_sum=0;
        int suffix_sum=0;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            prefix_sum=max(height[i],prefix_sum);
            arr1[i]=prefix_sum;
        }
         for(int j=n-1;j>=0;j--)
        {
            suffix_sum=max(height[j],suffix_sum);
             arr2[j]=suffix_sum;
        }
        for(int k=0;k<n;k++)
        {
            ans=ans+(min(arr1[k],arr2[k])-height[k]);
        }
        return ans;
    }
};