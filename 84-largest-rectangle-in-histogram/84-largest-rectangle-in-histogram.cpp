class Solution {
public:
    vector<int>nextSmallerElement(vector<int>& heights,
                                   int n)
    {
        stack<int>s;
        s.push(-1);
        vector<int>ans(n);
        for(int i=n-1;i>=0;i--)
        {
            int num=heights[i];
            while(s.top()!=-1 && heights[s.top()] >=num)
            {
                s.pop();
            }
            ans[i]=s.top();
            s.push(i); //while calculating next we are                              using index
        }
        return ans;
    }
    vector<int>prevSmallerElement(vector<int>& heights,int n)
    {
        stack<int>s;
        s.push(-1);
        vector<int>ans(n);
        for(int i=0;i<n;i++)
        {
            int num=heights[i];
            while(s.top()!=-1 && heights[s.top()] >=num)
            {
                s.pop();
            }
            ans[i]=s.top();
            s.push(i); //while calculating prev we are                              using index
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>prev(n);
        prev=prevSmallerElement(heights,n);
        vector<int>next(n);
        next=nextSmallerElement(heights,n);
         int area=INT_MIN;
        for(int i=0;i<n;i++)
        {   int l=heights[i];
            
           if(next[i]==-1)
           {
               next[i]=n;
           }
         int b=next[i]-prev[i]-1;
            int newArea=l*b;
            area=max(area,newArea);
        }
        return area;
    }
};