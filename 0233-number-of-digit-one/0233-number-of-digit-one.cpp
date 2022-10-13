class Solution {
public:
    int getLength(int n)
    {
        string s= to_string (n);
        int len=0;
        while(n!=0)
        {
            n=n/10;
            len++;
        }
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
    }
};