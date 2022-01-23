class Solution {
public:
    int dfs(vector<int>arr, int k, int idx, int n, vector<int> &dp){
        if(idx >= n){
            return 0;
        }
        
        if(dp[idx]!=-1)return dp[idx];  
        
        int maxTillNow = 0, sum = 0;
        for(int i=idx;i<min(idx+k, n);i++){
            maxTillNow = max(maxTillNow, arr[i]);
            sum = max(sum, dfs(arr, k, i+1, n, dp) + maxTillNow*(i-idx+1));
        }
        return dp[idx] = sum;
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n =arr.size();
        vector<long long int> dp(n, -1);
        return dfs(arr, k, 0, n, dp);
    }
};