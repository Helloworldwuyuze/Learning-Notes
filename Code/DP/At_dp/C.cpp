#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
const int M = 2e5 + 10;

int n,a[N][3],f[N][3];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i)   cin>>a[i][0]>>a[i][1]>>a[i][2];
    for(int i=1;i<=n;++i)
        for(int j=0;j<3;++j)
            f[i][j]=max(f[i-1][(j+1)%3]+a[i][j],f[i-1][(j+2)%3]+a[i][j]);
    cout<<max(max(f[n][0],f[n][1]),f[n][2])<<endl;
    return 0;
}