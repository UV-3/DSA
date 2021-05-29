int merge(vector<int>&nums, int start , int mid, int end){
    int invc=0;
    int i=start,j=mid+1,k=0;
    vector<int>temp(end-start+1);
    while(i<=mid && j<=end){
        if(nums[i]<=nums[j]){
            temp[k]=nums[i];
            i++;k++;
        }
        else{
            invc+= (mid-i+1);
            temp[k]=nums[j];
            j++;k++;
        }
    }
    while(i<=mid){
        temp[k]=nums[i];
        i++;k++;
    }
    while(j<=end){
        temp[k]=nums[j];
        j++;k++;
    }
    for(int i=start;i<=end;i++){
        nums[i]=temp[i-start];
    }
    return invc;
}
int mergesort(vector<int>&nums, int start , int end){
    int invc=0;
    if(start<end){
        int mid=(start+end)/2;
        invc+=mergesort(nums,start,mid);
        invc+= mergesort(nums,mid+1,end);
        invc+= merge(nums,start,mid,end);
    }
    return invc;
}
int Solution::countInversions(vector<int> &A) {
    vector<int>nums=A;
    int n=nums.size();
    int ans=mergesort(nums,0,n-1);
    return ans;
}
