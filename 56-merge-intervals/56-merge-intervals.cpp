class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        stack<vector<int>>s;
        int i=0;
        int n=intervals.size();
        while(i<n)
        {
            if(s.empty())
            {   s.push({intervals[i][0],intervals[i][1]});}
            
            else
            {  vector<int>top=s.top();
                if(top[1]>=intervals[i][0])
                {
                    s.pop();
                    int end=max(top[1],intervals[i][1]);
                    s.push({top[0],end});
                }
             else
             {s.push({intervals[i][0],intervals[i][1]});}
            }
              i++;
        }
        
      vector<vector<int>>ans;
        while(!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
        
    }
};