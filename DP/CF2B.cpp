#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<stack>
#include<algorithm>
#include<map>

#include<bitset>
#include<set>

#include<deque>
#include<cassert>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<vector>
#include<random>

#define fi first
#define se second
#define pb push_back
#define mk make_pair
#define DBG cerr << __LINE__ << ' ' << __FUNCTION__ << endl

#define DRE default_random_engine
#define UID uniform_int_distribution
#define y0 Y0
#define y1 Y1

#define pi acos(-1)
#define eps (1e-8)

using namespace std;

const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e3 + 10;
const int M = 1e6 + 10;

int n,x,_[N][N][2],f[N][N][2],xx,yy,pre[N][N];
bool flag;

void dfs(int x,int y,bool t){
    if(x==1&&y==1)  return ;
    if(f[x-1][y][t]<f[x][y-1][t]){
        dfs(x-1,y,t);
        cout<<"D";
    }else{
        dfs(x,y-1,t);
        cout<<"R";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j){
            cin>>x;
            if(!x){flag=true; xx=i, yy=j; continue;}
            while(x%2==0)   _[i][j][0]++, x/=2;
            while(x%5==0)   _[i][j][1]++, x/=5;
        }
    memset(f,0x3f,sizeof(f));
    f[1][1][0]=_[1][1][0], f[1][1][1]=_[1][1][1];
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            for(int k=0;k<2;++k)
                if(!(i==1&&j==1))  f[i][j][k]=min(f[i-1][j][k],f[i][j-1][k])+_[i][j][k];
    int ans=min(f[n][n][1],f[n][n][0]);
    if(flag&&ans>=1){
        cout<<1<<endl;
        for(int i=1;i<xx;++i)   cout<<"D";
        for(int j=1;j<yy;++j)   cout<<"R";
        for(int i=xx;i<n;++i)   cout<<"D";
        for(int j=yy;j<n;++j)   cout<<"R";
        cout<<endl;
        return 0;
    }
    cout<<ans<<endl;
    dfs(n,n,f[n][n][0]>f[n][n][1]);
    // for(int i=1;i<=n;++i,cout<<endl)
        // for(int j=1;j<=n;++j)
            // cout<<f[i][j][0]<<" ";
    return 0;
}