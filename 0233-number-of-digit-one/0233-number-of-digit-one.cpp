class Solution {
public:
        int getLength(int n)
    {
        string s= to_string (n);
        int len=s.length();
        // while(n!=0)
        // {
        //     n=n/10;
        //     len++;
        // }
        return len;
        
    }
    int countDigitOne(int n) {
        if(n==0)
        {return 0;}
        if(n<10)
        {return 1;}
        int len=getLength(n);
        int base=pow(10,len-1);
        int remainder=n%base;
        int firstDigit=n/base;
        int startingDig1=0;
        if(firstDigit==1)
        {startingDig1=n-base+1;}
        else
        {startingDig1=base;}
        return countDigitOne(remainder)+(firstDigit*countDigitOne(base-1))+startingDig1 ;
        
//         int count=0;
//         for(int i=0;i<=n;i++)
//         {string s=to_string(i);
//          int len=s.length();
//          for(int j=0;j<len;j++)
//          {if(s[j]==1)
//          {count++;}
//          }
//           cout<<count;  
//         }
//         return count;
        
        
        
    }
};