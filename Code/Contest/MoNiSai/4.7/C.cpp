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
typedef pair<int,bool> PII;
typedef pair<int,PII> PIII;
const int N = 5e5 + 10;
const int M = 5e5 + 10;
const int MOD = 1e9 + 7;

int n,m,l;
bool a[N];

int t[N][2],idx,sum[N];
int flag[N];

void insert(){
    int p=0;
    for(int i=1;i<=l;++i){
        if(!t[p][a[i]]) t[p][a[i]]=++idx;
        p=t[p][a[i]]; ++sum[p];
    }
    flag[p]++;
}

int query(){
    int p=0, ans=0;
    for(int i=1;i<=l;++i){
        if(!t[p][a[i]]) return ans;
        p=t[p][a[i]];   ans+=flag[p];
    }
    return ans+sum[t[p][0]]+sum[t[p][1]];
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>l;
        for(int j=1;j<=l;++j)   cin>>a[j];
        insert();
    }
    for(int i=1;i<=m;++i){
        cin>>l;
        for(int j=1;j<=l;++j)   cin>>a[j];
        cout<<query()<<endl;
    }
	return 0;
}