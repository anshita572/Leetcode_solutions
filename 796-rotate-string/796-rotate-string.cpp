class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length())
        {return false;}
        if(s.compare(goal)==0)
        {return true;}
      queue<char>q1;
      queue<char>q2;
        for(int i=0;i<s.length();i++)
        {
            q1.push(s[i]);
            q2.push(goal[i]);
        }
        int count=0;
        while(count<goal.length())
        {
            char frontCh=q2.front();
            q2.pop();
            q2.push(frontCh);
            count++;
            if(q1==q2)
            {return true;}
        }
        return false;
    }
};
