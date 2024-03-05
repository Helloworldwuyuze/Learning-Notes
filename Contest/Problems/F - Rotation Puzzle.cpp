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
const int N = 10 + 10;
const int M = 1e6 + 10;

int n,m;
int a[N][N],b[N][N];

bool check(){
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            if(b[i][j]!=(i-1)*m+j)  return false;
    return true;
}

const int dx[]={0,1,0,1};
const int dy[]={0,0,1,1};

void change(int minn,int minm,int maxn,int maxm){
    for(int i=minn,ii=maxn;i<=ii;++i,--ii){
        for(int j=minm,jj=maxm;j<=jj||i<ii&&j<=maxm;++j,--jj){
            swap(b[i][j],b[ii][jj]);
        }
    }
}

void Print(){
    DBG;
    for(int i=1;i<=n;++i,cout<<endl)
        for(int j=1;j<=m;++j)   cout<<b[i][j]<<" ";
}

bool flag;
void dfs(int t,int maxx,int op){
    // Print();
    if(flag)    return ;
    if(t==maxx){
        if(check()) flag=true;
        return ;
    }
    for(int i=0;i<4;++i){
        if(i==op)   continue;
        change(1+dx[i],1+dy[i],n-1+dx[i],m-1+dy[i]);
        dfs(t+1,maxx,i);
        change(1+dx[i],1+dy[i],n-1+dx[i],m-1+dy[i]);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)   cin>>a[i][j];
    memcpy(b,a,sizeof(a));
    if(check()){ cout<<0<<endl; return 0;}
    // Print();
    for(int i=1;i<=20;++i){
        // cout<<i<<endl;
        flag=false;
        memcpy(b,a,sizeof(a));
        dfs(0,i,-1);
        if(flag==true){
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}