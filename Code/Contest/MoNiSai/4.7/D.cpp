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

#define int long long
const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e6 + 10;
const int M = 5e5 + 10;
const int MOD = 1e9 + 7;

struct edge{
    PII u,v;
    int h;
}e[N];
int fa[N], a[N], n, m, idx, ans[N], comdep[N], H;

int Hash(int x,int y){ return (x-1)*m+y;}
int find(int x){ return fa[x]==x?fa[x]:fa[x]=find(fa[x]);}

bool cmp(edge x,edge y){
	return x.h<y.h;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
    cin>>n>>m>>H;
    for(int i=1;i<=n;++i)
        for(int j=1;j<m;++j)    ++idx, cin>>e[idx].h, e[idx].u=mk(i,j), e[idx].v=mk(i,j+1), a[idx]=e[idx].h+1;
//    for(int i=1;i<=idx;++i)
//		cout<<e[i].u.fi<<" "<<e[i].u.se<<" "<<e[i].v.fi<<" "<<e[i].v.se<<" "<<e[i].h<<endl; 
    for(int i=1;i<n;++i)
        for(int j=1;j<=m;++j)   ++idx, cin>>e[idx].h, e[idx].u=mk(i,j), e[idx].v=mk(i+1,j), a[idx]=e[idx].h+1;
    sort(a+1,a+1+idx);
    int tot=unique(a+1,a+1+idx)-a-1;
    sort(e+1,e+1+idx,cmp);
//    for(int i=1;i<=idx;++i)
//        e[i].h=lower_bound(a+1,a+1+tot,e[i].h)-a;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j){
            int x=Hash(i,j);
            fa[x]=x, ans[x]=1; comdep[x]=1;
        }
//    cout<<"QAQ"<<endl; 
    int j=1;
    for(int i=1;i<=tot;++i){
//    	cout<<a[i]<<endl;
        if(a[i]>H)  break;
        while(e[j].h<a[i]&&j<=idx){
            int x=Hash(e[j].u.fi,e[j].u.se), y=Hash(e[j].v.fi, e[j].v.se);
            int fx=find(x), fy=find(y);
//            cout<<j<<' '<<e[j].u.fi<<" "<<e[j].u.se<<' '<<e[j].v.fi<<" "<<e[j].u.se<<' '<<fx<<' '<<fy<<' '<<ans[fx]<<' '<<comdep[fx]<<' '<<ans[fy]<<' '<<comdep[fx]<<endl;
            if(fx==fy){ ++j; continue;}
            fa[fy]=fx;
            ans[fx]=((ans[fx]+(a[i]-comdep[fx]))%MOD*(ans[fy]+(a[i]-comdep[fy]))%MOD)%MOD;
            comdep[fx]=a[i];
            ++j;
        }
    }
    int sum=1;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j){
            int x=Hash(i,j);
            if(find(x)==x)  sum=(sum*(ans[x]+H+1-comdep[x])%MOD)%MOD;
        }
    cout<<sum<<endl;
	return 0;
}