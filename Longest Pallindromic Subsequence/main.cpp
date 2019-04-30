#include <iostream>
#include <string>
#include <algorithm> // reverse
using namespace std;

int LCS(const string& s1, const string& s2){
    int len1 = s1.size();
    int len2 = s2.size();
    int dp[len1+1][len2+1];
    for(int i=0; i<len1; ++i) dp[i][0] = 0;
    for(int i=0; i<len2; ++i) dp[0][i] = 0;
    for(int i=1; i<=len1; ++i)
        for(int j=1; j<=len2; ++j){
            if(s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    return dp[len1][len2];
}

int LPS(string s){
    string s1(s);
    reverse(s1.begin(), s1.end());
    int l = LCS(s, s1);
    return s.size()-l;
}

int LPS1(string s){
    int n = s.length();
    int dp[n][n];
    for(int i=0; i<n; ++i){
        dp[i][i] = 0;
        if(i+1<n&&s[i]==s[i+1])
            dp[i][i+1] = 0;
        if(i+1<n&&s[i]!=s[i+1])
            dp[i][i+1] = 1;
    }
    for(int i=2; i<n; i++)
        for(int j=0; j<n; j++){
            if(j+i<n&&s[j]==s[j+i])
                dp[j][j+i] = dp[j+1][j+i-1];
            else if(j+i<n&&s[j]!=s[j+i])
                dp[j][j+i] = min(dp[j+1][j+i], dp[j][j+i-1]) + 1;
        }
    return dp[0][n-1];

}

int main() {
    string s = "abca";
    cout<<LPS1(s)<<endl;
    return 0;
}