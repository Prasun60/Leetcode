//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int solve(int ind,int price[],int target,vector<vector<int>>&dp){
        if(ind==1){
             if(target%1==0){
                 return price[ind-1]*(target);
             }else{
                 return 0;
             }
        }
        if(dp[ind-1][target]!=-1) return dp[ind-1][target];
        
        int nottake=solve(ind-1,price,target,dp);
        int take=0;
        if(ind<=target){
            take= price[ind-1]+solve(ind,price,target-ind,dp);
        }
        return dp[ind-1][target]=max(take,nottake);
    }
    int cutRod(int price[], int n) {
        vector<vector<int>>dp(n,(vector<int>(n+1,-1)));
        return solve(n,price,n,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends