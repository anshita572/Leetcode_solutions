class Solution {
public:
void merge(vector<int>& nums,int s,int e,int mid)
{int n1=mid-s+1;
int n2=e-mid;
vector<int>left(n1);
vector<int>right(n2);
int j=0;
for(int i=s;i<=mid;i++)
{left[j]=nums[i];
j++;}
int k=0;
for(int i=mid+1;i<=e;i++)
{right[k]=nums[i];
k++;}
int index=s;
int x=0;
int y=0;
while(x<n1 && y<n2)
{if(left[x]<right[y])
{nums[index]=left[x];
x++;
index++;}
else
{nums[index]=right[y];
y++;
index++;}
}
while(x<n1)
{nums[index]=left[x];
x++;
index++;}
while(y<n2)
{nums[index]=right[y];
y++;
index++;}

}
void solve(vector<int>& nums,int s,int e)
{//base case
if(s>=e)
{return;}
int mid=s+(e-s)/2;
solve(nums,s,mid); //left part
solve(nums,mid+1,e); //right part
merge(nums,s,e,mid);
}
    vector<int> sortArray(vector<int>& nums) {
       solve(nums,0,nums.size()-1);
        return nums;
    }
};