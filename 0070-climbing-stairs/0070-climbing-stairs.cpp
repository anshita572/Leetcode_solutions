class Solution {
public:
    int climbStairs(int N) {
        if(N==1)
        {return 1;}
        if(N==2)
        {return 2;}
        int a=1;
        int b=2;
        int c;
        for(int i=3;i<=N;i++)
        {c=(a+b);
            a=b;
            b=c;
        }
        return c;
    }
};