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

const int INF = 0x3f3f3f3f;
typedef pair<int,bool> PII;
typedef pair<int,PII> PIII;
const int N = 1e6 + 10;
const int M = 5e5 + 10;
const int MOD = 1e9 + 7;

int n,a[N],q,m[N],now[N],x,i,j;
vector<int> wait[N],t;
int b[N],st[N],idx;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
    cin>>n;
    for(i=1;i<=n;++i)   cin>>a[i];
    cin>>q;
    for(i=1;i<=q;++i){
        cin>>m[i];
        st[i]=now[i]=idx+1;
        for(int j=1;j<=m[i];++j)    ++idx, cin>>b[idx];
        wait[b[now[i]]].pb(i);
        // cout<<st[i]<<" ";
    }
    // cout<<endl;
    for(i=1;i<=n;++i){
        // cout<<"###"<<i<<"###"<<endl;
        for(j=0;j<wait[a[i]].size();++j){
            x=wait[a[i]][j];
            now[x]++;
            // cout<<x<<" "<<now[x]<<" "<<b[now[x]]<<endl;;
            if(now[x]>=st[x]+m[x]) continue;
            if(b[now[x]]!=a[i])  wait[b[now[x]]].pb(x);
            else    t.pb(x);
        }
        wait[a[i]]=t;
        t.clear();
        // cout<<endl;
    }
    for(i=1;i<=q;++i)
        if(now[i]>=m[i]+st[i]) cout<<"TAK"<<endl;
        else    cout<<"NIE"<<endl;
	return 0;
}