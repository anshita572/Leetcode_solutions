class Solution {
public:
    double findMedianSortedArrays(vector<int>& array1, vector<int>& array2) {
        int n=array1.size();
        int m=array2.size();
        double i=0;
        double j=0;
        double count=0;
        double m1=-1;
        double m2=-1;
        for(int count=0;count<=(m+n)/2;count++)
        {m2=m1;
            if(i!=n && j!=m)
            {
               if(array1[i]>=array2[j])
               {m1=array2[j];
                   j++;
               }
               else
               {m1=array1[i];
                   i++;
               }
            }
            else if(i<n)
            {m1=array1[i];
                i++;
            }
            else //if(j<m)
            {m1=array2[j];
                j++;
            }
        }
        if((m+n)%2 ==1)
        {return m1;}
        else
        {return (m1+m2)/2;}
        
    
    }
    
};