class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string ans="";
        int index=0;
        while(index < indices.size())
        {
        for(int i=0;i<indices.size();i++)
        {
           if(indices[i]==index)
           {ans.push_back(s[i]);
           break;}
        }
            index++;
        }
        return ans;
    }
};