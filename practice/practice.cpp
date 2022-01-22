#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSplits(string s) {
        vector<char> visit1(26, 0), visit2(26, 0);
        int n = s.length();
        vector<int> prefix(n), suffix(n);
        
        prefix[0] = 1;
        visit1[s[0]-'a'] = 1;
        for(int i=1;i<n;i++){
            if(visit1[s[i]-'a'] == 0){
                prefix[i] = prefix[i-1]+1;
                visit1[s[i]-'a'] = 1;
            }else{
                prefix[i] = prefix[i-1];
            }
        }

        suffix[n-1] = 1;
        visit2[s[n-1]-'a'] = 1;
        for(int i=n-2;i>=0;i--){
            if(visit2[s[i]-'a'] == 0){
                suffix[i]= suffix[i+1]+1;
                visit2[s[i]-'a'] = 1;
            }else{
                suffix[i] = suffix[i+1];
            }
        }

        for(auto i:prefix) cout<<i<<" ";
            cout<<endl;
        for(auto i:suffix) cout<<i<<" ";
            cout<<endl;
    }
};

int main(){
    return 0;
}

