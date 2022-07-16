class Solution {
public:
    vector<int> rearrangeArray(vector<int>& arr) {
        vector<int>positive,negative;
        int n=arr.size();
	    for(int i=0;i<n;i++)
	    {
	        if(arr[i]>=0)
	        {positive.push_back(arr[i]);}
	        else// if(arr[i]<0)
	        {negative.push_back(arr[i]);}
	    }
	    //merge both subaarays into arr
	    int i=0,j=0,k=0;
	    while(i<n)
	    {
	       
	        if(j<positive.size())
	        {
	            arr[i++]=positive[j++];
	        }
	          if(k<negative.size())
	        {
	            arr[i++]=negative[k++];
	        }
	        
	    }
        return arr;
//         int n=nums.size();
//         vector<int>ans(n);
//         int positiveIndex=0;
//         int negativeIndex=1;
        
//         for(int i=0;i<n;i++)
//         {
//             if(nums[i]>0)
//             {ans[positiveIndex]=nums[i];
//             positiveIndex=positiveIndex+2;}
//             else if(nums[i]<0)
//             {ans[negativeIndex]=nums[i];
//             negativeIndex=negativeIndex+2;}
//         }
//         return ans;
    }
};