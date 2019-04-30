#include <iostream>
#include <vector>
#define INF (1<<30)
using namespace std;

int dp(int S, vector<int>& Coin, vector<int>& maxv, vector<int>& minv){
    for(int i=1; i<=S; i++)
        for(int j=0; j<Coin.size(); j++)
            if(i>=Coin[j]){
                maxv[i] = max(maxv[i], maxv[i-Coin[j]]+1);
                minv[i] = min(minv[i], minv[i-Coin[j]]+1);
            }
}

void print_ans(vector<int>& d, vector<int>& Coin, int S) {
    if(S==0) cout<<endl;
    for(int i=0; i<Coin.size(); i++)
        if(S>=Coin[i] && d[S]==d[S-Coin[i]]+1){
            cout<<i<<' ';
            print_ans(d, Coin, S-Coin[i]);
            break;
        }
}

int main() {
    int S=16;
    vector<int> Coin = {1,5,4,8,7,9};
    vector<int> maxv(S+1, -INF);
    vector<int> minv(S+1, INF);
    minv[0] = maxv[0] = 0;
    dp(S, Coin, maxv, minv);
    cout<<maxv[S]<<' '<<minv[S]<<endl;
    print_ans(maxv, Coin, S);
    print_ans(minv, Coin, S);
    return 0;
}