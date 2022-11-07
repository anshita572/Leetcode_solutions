class Solution {
public:
    int maximum69Number (int num) {
        int temp_num=num;
        int digCount=0;
        int right_digCount=-1;
        while(temp_num>0)
        {int last_dig=temp_num%10;
        if(last_dig==6)
        {right_digCount=digCount;}
        digCount++;
        temp_num=temp_num/10;}
        // if(right_digCount==-1)
        // {return num;}
        int ans=num + 3*(pow(10,right_digCount));
         return ans;
    }
  
};