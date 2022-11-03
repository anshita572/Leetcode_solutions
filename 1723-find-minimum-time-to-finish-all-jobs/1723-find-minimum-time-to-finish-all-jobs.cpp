class Solution {
public:
    void solve(vector<int>& jobs,vector<int>&work,int n,int k,int i,int work_array_max,int & ans)
    {
        //base case
        if(i==n)
        {work_array_max=*max_element(work.begin(),work.end());
        ans=min(ans,work_array_max);
        return;}
        if(*max_element(work.begin(),work.end()) >= ans) //optimisation
        {return;}
        for(int j=0;j<k;j++)
        {if(j>0 && work[j]==work[j-1]) //optimisation
        {continue;}
            work[j]=work[j]+jobs[i];
        solve(jobs,work,n,k,i+1,work_array_max,ans);//recursive call
        work[j]=work[j]-jobs[i];}//backtracking
        
    }
    int minimumTimeRequired(vector<int>& jobs, int k) {
        // sort(jobs.begin(),jobs.end(),greater<int>());
        int n=jobs.size();
        // if(n==k)
        // {return jobs[0];}//max element in jobs array after sorting in descending order
        vector<int>work(k);
        int work_array_max=0;
        int ans=INT_MAX;
        int index=0;
        solve(jobs,work,n,k,index,work_array_max,ans);
        return ans;
    }
};