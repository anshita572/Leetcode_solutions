class Solution {
public:
    double findMedianSortedArrays(vector<int>& array1, vector<int>& array2) {    
        int n1=array1.size();
             int n2=array2.size();
        if(n2 < n1)
        {return findMedianSortedArrays(array2,array1);}
        int total=n1+n2;
             int l=0;
             int h=n1;
        
        while(l<=h)
        {
             int cut1=l+(h-l)/2;//array1 m kahan cut lgega (<=>mid of binary search)
             int cut2=((total+1)/2-cut1); //array2 m kahan cut lgega
             int left1=cut1==0 ? INT_MIN:array1[cut1-1];
              int left2=cut2==0 ? INT_MIN:array2[cut2-1];
             int right1=cut1==n1 ? INT_MAX :array1[cut1];
            int right2=cut2==n2 ? INT_MAX :array2[cut2];
    //ideal partition : arr1[mid-1]<arr2[arr2_element] && arr2[arr2_element]<mid
            if( left1<=right2 && left2<=right1)
            { 
                 double median=0.0;
               if(total % 2==0)
               {int left_max=max(left1,left2);
               int right_min=min(right1,right2);
               median=(left_max+right_min)/2.0;}
             else
             {int left_max=max(left1,left2);
             median=left_max;}
              return median;   
            }
          else if(left1>right2)
            {h=cut1-1;}
            else//if(left2>right1)
            {l=cut1+1;}
        }
            return 0.0;
         
        
    }
};