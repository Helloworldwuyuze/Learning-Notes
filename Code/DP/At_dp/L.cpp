#include<bits/stdc++.h>

using namespace std;

#define int long long
const int N = 3e3 + 10;
const int M = 1e2 + 10;
#define endl '\n'
const int INF = 0x3f3f3f3f;

int n,a[N];
int f[N][N];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    for(int len=1;len<=n;++len)
        for(int i=1;i+len-1<=n;++i){
            int j=i+len-1;
            if((n-len)&1)   f[i][j]=min(f[i+1][j]-a[i],f[i][j-1]-a[j]);
            else    f[i][j]=max(f[i+1][j]+a[i],f[i][j-1]+a[j]);
        }
    // for(int len=1;len<=n;++len,cout<<endl)
    //     for(int i=1;i+len-1<=n;++i)
    //         cout<<f[i][i+len-1]<<" ";
    cout<<f[1][n]<<endl;
    return 0;
}