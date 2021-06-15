class Solution{
public:
    int dp[105][105];
    int calc(vector<int>&v,int i, int j){
        if(i>=j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans= INT_MAX;
        for(int k=i;k<=j-1;k++){
            int temp=  calc(v,i,k)+ calc(v,k+1,j)+ v[i-1]*v[k]*v[j];
            ans=min(ans,temp);
        }
        return dp[i][j]=ans;
    }
    int matrixMultiplication(int N, int arr[]){
        memset(dp,-1,sizeof(dp));
        vector<int>v;
        for(int i=0;i<N;i++){
            v.push_back(arr[i]);
        }
        return calc(v,1,N-1);
    }
};
