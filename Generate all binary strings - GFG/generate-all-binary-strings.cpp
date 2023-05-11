//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
vector<string>v;
    void solve(int num , string s){
        if(s.size()==num){
            v.push_back(s);
            s="";
            return;
        }
        if(s.size()==0||s[s.size()-1]=='0'){
            solve(num,s+'0');
            solve(num,s+'1');
        }if(s[s.size()-1]=='1'){
            solve(num,s+'0');
        }
    }
    void generateBinaryStrings(int num){
        //Write your code
        string s="";
        solve(num,s);
        for(auto i:v){
            cout<<i<<" ";
        }
    }
};

//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;


    while(t--){
        //Input
        int n; cin >> n;

        Solution obj;
        obj.generateBinaryStrings(n);
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends