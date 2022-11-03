class Solution {
public:
    void solve(vector<int>& jobs,vector<int>&work,int n,int k,int i,int max_ans,int & min_ans)
    {
        //base case
        if(i==n)
        {max_ans=*max_element(work.begin(),work.end());
        min_ans=min(min_ans,max_ans);
        return;}
        if(*max_element(work.begin(),work.end()) >= min_ans)
        {return;}
        for(int j=0;j<k;j++)
        {if(j>0 && work[j]==work[j-1]) //optimisation
        {continue;}
            work[j]=work[j]+jobs[i];
        solve(jobs,work,n,k,i+1,max_ans,min_ans);
        work[j]=work[j]-jobs[i];}
        
    }
    int minimumTimeRequired(vector<int>& jobs, int k) {
        sort(jobs.begin(),jobs.end(),greater<int>());
        int n=jobs.size();
        if(n==k)
        {return jobs[0];}
        vector<int>work(k);
        int max_ans=0;
        int min_ans=INT_MAX;
        int index=0;
        solve(jobs,work,n,k,index,max_ans,min_ans);
        return min_ans;
    }
};