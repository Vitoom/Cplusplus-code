#include <iostream>
#include <vector>
#define INF (1<<30)
using namespace std;

int dp(int S, vector<int>& Coin, vector<int>& d){
    int& ans = d[S];
    if(ans != -1) return ans;
    ans = -INF;
    for(auto i=Coin.begin(); i!=Coin.end(); ++i){
        if(S>=(*i)) ans = max(ans, dp(S-(*i), Coin, d)+1);
    }
    return ans;
}

int main() {
    int S=16;
    vector<int> Coin = {1,5,4,8,7,9};
    vector<int> d(S+1, -1);
    d[0] = 0;
    int result = dp(S, Coin, d);
    for(auto i=Coin.begin(); i!=Coin.end(); ++i)
        cout<<*i<<' ';
    cout<<endl;
    for(auto i=d.begin(); i!=d.end(); ++i)
        cout<<*i<<' ';
    cout<<endl;
    cout<<result<<endl;
    return 0;
}