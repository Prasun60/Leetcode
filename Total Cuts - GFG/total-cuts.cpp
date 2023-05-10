//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
     int totalCuts(int n,int k,vector<int> &arr){
        vector<int> gre(n),sma(n);


        int mini=INT_MAX;
        int maxi=INT_MIN;


        for(int i=0;i<n;i++){
            maxi=max(maxi,arr[i]);
            gre[i]=maxi;
            mini=min(mini,arr[n-1-i]);
            sma[n-1-i]=mini;
        }


        int ans=0;
        for(int i=1;i<n;i++){
            if(gre[i-1]+sma[i]>=k)
                ans++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N,K;
        cin>>N>>K;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution ob;
        cout<<ob.totalCuts(N,K,A)<<endl;
    }
    return 0;
}
// } Driver Code Ends