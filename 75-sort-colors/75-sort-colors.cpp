class Solution {
public:
    void sortColors(vector<int>& arr) {
       int n=arr.size();
        int count0=0;
    int count1=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==0)
        {count0++;}
    }
    for(int i=0;i<n;i++)
    {
        if(arr[i]==1)
        {count1++;}
    }
    for(int i=0;i<count0;i++)
    {arr[i]=0;}
     for(int i=count0;i<count1+count0;i++)
    {arr[i]=1;}
    for(int i=count1+count0;i<n;i++)
    {arr[i]=2;}
        
    }
};