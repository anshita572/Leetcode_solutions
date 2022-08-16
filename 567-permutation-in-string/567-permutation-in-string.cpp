class Solution {
public:
    bool checkEqual(int arr1[26],int arr2[26])
    {for(int i=0;i<26;i++)
    {if(arr1[i]!=arr2[i])
        {return false;}
    }
     return true;
    }
    bool checkInclusion(string s1, string s2) {
        int arr1[26]={0};
        for(int i=0;i<s1.length();i++)
        {int count1=0;
        count1=s1[i]-'a';
        arr1[count1]++;}
        int windowSize=s1.length();
        //for 1st window
        int j=0;
        int arr2[26]={0};
        while(j<windowSize && j<s2.length())
        {
            int count2=0;
            count2=s2[j]-'a';
            arr2[count2]++;
            j++;
        }
        if(checkEqual(arr1,arr2))
        {return true;}
        else //process next windows
        {while(j<s2.length())
        {
            int count2=0;
            count2=s2[j]-'a';
            arr2[count2]++;
            char prevChar=s2[j-windowSize];
            count2=prevChar-'a';
            arr2[count2]--;
            j++;
            if(checkEqual(arr1,arr2))
            {return true;}
        }}
        return false;
    }
};