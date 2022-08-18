class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length())
        {return false;}
        if(s.compare(goal)==0)
        {return true;}
        int partition=1;
        for(int i=partition;i<s.length();i++)
        {
            string X=s.substr(0,partition);
            string val=s.substr(partition,s.length());
            val=val+X;
            if(val.compare(goal)==0)
            {return true;}
            else
            {partition++;}
        }
        return false;
    }
};