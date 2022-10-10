class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int len=arr.size();
        int count=0;
        for(int i=0;i<len;i++)
        {
            if(arr[i]==0)
            {count++;}
        }
        int new_len=len+count;
        for(int i=len-1,j=new_len-1;i>=0 && j>=0;i--,j--)
        {
            // if(j<len)
            // {arr[j]=arr[i];
            // if(arr[i]==0)
            // {j--;
            // arr[j]=arr[i];}
            // }
            if(arr[i]!=0)
            {
                if(j<len)
                {arr[j]=arr[i];}
                
            }
            else
            {
                if(j<len)
                {arr[j]=arr[i];}
                j--;
                if(j<len)
                {arr[j]=arr[i];}
            }
        }
    }
};