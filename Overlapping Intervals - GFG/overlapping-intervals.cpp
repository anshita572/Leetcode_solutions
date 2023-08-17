//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>>ans;
        stack<pair<int,int>>st;
        sort(intervals.begin(),intervals.end());
        st.push({intervals[0][0],intervals[0][1]});
        for(int i = 1; i < n; i++){
            int top1 = st.top().first;
            int top2 = st.top().second;
            if(top2 >= intervals[i][0]){
                st.pop();
                int end = max(top2,intervals[i][1]);
                st.push({top1,end});
            }
            else{
                st.push({intervals[i][0],intervals[i][1]});
            }
        }
        while(!st.empty()){
            int top1 = st.top().first;
            int top2 = st.top().second;
            st.pop();
            ans.push_back({top1,top2});
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends