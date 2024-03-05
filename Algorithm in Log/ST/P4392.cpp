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
const int N = 1e6 + 10;
const int M = 1e6 + 10;

int n,m,k,t,tt;
int a[N],st[N][22],mx[N];
bool flag;

int query(int l,int r,bool f){
    if(f)   return min(st[l][tt],st[r-(1<<tt)+1][tt]);
    return max(st[l][tt],st[r-(1<<tt)+1][tt]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n>>m>>k;
    t=log(n)/log(2)+1; tt=log(m)/log(2);
    for(int i=1;i<=n;++i)   cin>>a[i], st[i][0]=a[i];
    for(int j=1;j<=t;++j)
        for(int i=1;i+(1<<j)-1<=n;++i)
            st[i][j]=max(st[i][j-1],st[i+(1<<j-1)][j-1]);
    for(int i=1;i+m-1<=n;++i)   mx[i]=query(i,i+m-1,0);
    memset(st,0,sizeof(st));
    for(int i=1;i<=n;++i)   st[i][0]=a[i];
    for(int j=1;j<=t;++j)
        for(int i=1;i+(1<<j)-1<=n;++i)
            st[i][j]=min(st[i][j-1],st[i+(1<<j-1)][j-1]);
    for(int i=1;i+m-1<=n;++i)
        if(mx[i]-query(i,i+m-1,1)<=k) cout<<i<<endl, flag=true;
    if(!flag)   cout<<"NONE"<<endl;
    return 0;
}