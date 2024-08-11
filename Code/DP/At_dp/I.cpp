#include<bits/stdc++.h>

using namespace std;

const int N = 3e3 + 10;
const int M = 1e2 + 10;

double p[N];
int n;
double f[N][N];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i)   cin>>p[i];
    f[0][0]=1;
    for(int i=1;i<=n;++i){
        for(int j=0;j<=i;++j){
            if(j!=0)    f[i][j]+=f[i-1][j-1]*p[i];
            f[i][j]+=f[i-1][j]*(1-p[i]);
        }
    }
    double ans=0;
    for(int i=ceil(1.0*n/2);i<=n;++i)   ans+=f[n][i];
    cout<<fixed<<setprecision(12)<<ans<<endl;
    return 0;
}