class Solution {
public:
    int dp[1005][2][105];
    int helper(int i, int own, int k, vector<int>&prices){
        if(i==prices.size() || k==-1){
            return 0;
        }
        if(dp[i][own][k]!=-1){
            return dp[i][own][k];
        }
        if(own){
            int op1= prices[i]+ helper(i+1,0,k-1,prices);
            int op2= helper(i+1,1,k,prices);
            return dp[i][own][k]=max(op1,op2);
        }
        else{
            int op1= -prices[i]+helper(i+1,1,k,prices);
            int op2= helper(i+1,0,k,prices);  // buy it
            return dp[i][own][k]=max(op1,op2); // dont buy it
        }
    }
    int maxProfit(int k,vector<int>& prices) {
        if(k==0){
            return 0;
        }
        memset(dp,-1,sizeof(dp));
        return helper(0,0,k-1,prices);
    }
};
