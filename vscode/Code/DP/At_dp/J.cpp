#include<bits/stdc++.h>

using namespace std;

const int N = 3e2 + 10;
const int M = 2e5 + 10;
#define endl '\n'
const int INF = 0x3f3f3f3f;

int n,a[10],x;
double f[N][N][N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i)   cin>>x, a[x]++;
    for(int i=0;i<=n;++i)
        for(int j=0;j<=n;++j)
            for(int k=0;k<=n;++k){
                if(i+j+k>n||(i==0&&j==0&&k==0)) continue;
                if(i)   f[i][j][k]+=f[i-1][j+1][k]*i/(i+j+k);
                if(j)   f[i][j][k]+=f[i][j-1][k+1]*j/(i+j+k);
                if(k)   f[i][j][k]+=f[i][j][k-1]*k/(i+j+k);
                f[i][j][k]+=1.0*n/(i+j+k);
            }
    cout<<fixed<<setprecision(12)<<f[a[3]][a[2]][a[1]]<<endl;
    return 0;
}