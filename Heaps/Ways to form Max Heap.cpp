long long mod= 1e9+7;
int cache[105][105];
long long nCr(int n, int r){
    if(r>n){
        return 0;
    }
    if(r==0 || r==n){
        return 1;
    }
    if(cache[n][r]!=-1){
        return cache[n][r];
    }
    return cache[n][r]= (nCr(n-1,r)+ nCr(n-1,r-1))%mod;
}
long long  dp(int n){
    if(n<=1){
        return 1;
    }
    int h= log2(n);
    long long  m= pow(2,h);
    long long  p= n- (pow(2,h)-1);
    long long L,R;
    if(n==1){
        L=0;
    }
    else if(p>=m/2){
        L= pow(2,h)-1;
    }
    else if(p<m/2){
        L= pow(2,h)-1 -(m/2 -p);
    }
    R= (n-1)-L;
    return    ((dp(L) *   dp(R))%mod   *   nCr(n-1,L))%mod  ;
}
int Solution::solve(int n) {
    memset(cache,-1,sizeof(cache));
    int ans= dp(n);
    return ans;
}
