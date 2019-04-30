#include <iostream>
#include <string>
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

int main() {
    string s1="abcad", s2="daba";
    int ans = LCS(s1, s2);
    cout <<ans<<endl;
    return 0;
}