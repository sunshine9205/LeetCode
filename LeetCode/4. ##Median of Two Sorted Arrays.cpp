double findKth(int a[],int m,int b[],int n,int k){
    if(m>n)
        return findKth(b,n,a,m,k);
    if(m==0)
        return b[k-1];
    if(k==1)
        return min(a[0],b[0]);
    
    int pa = min(k/2,m),pb = k-pa;
    if(a[pa-1]<b[pb-1]){
        return findKth(a+pa,m-pa,b,n,k-pa);
    }
    else if(a[pa-1]>b[pb-1]){
        return findKth(a,m,b+pb,n-pb,k-pb);
    }
    else
        return a[pa-1];
}


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size()+nums2.size();
        if(total & 0x1)
            return findKth(&nums1[0],nums1.size(),&nums2[0],nums2.size(),total/2+1);
        else
            return (findKth(&nums1[0],nums1.size(),&nums2[0],nums2.size(),total/2)+findKth(&nums1[0],nums1.size(),&nums2[0],nums2.size(),total/2+1))/2.0;
    }
};