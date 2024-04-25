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
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 4e4 + 10;
const int M = 5e5 + 10;
const int MOD = 1e9 + 7;

int n, a[N], k, sa[N], rk[N], oldrk[N], w, height[N], st[N][20];

bool cmp(int x,int y){
    return rk[x]==rk[y]?rk[x+w]<rk[y+w]:rk[x]<rk[y];
}
int query(int l,int r){
    int t=log(r-l+1)/log(2);
    return min(st[l][t],st[r-(1<<t)+1][t]);
}

signed main(){
//	freopen("P2852_2.in","r",stdin);
//	freopen("P2852.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
    cin>>n>>k; --k;
    for(int i=1;i<=n;++i)   cin>>a[i], rk[i]=a[i], sa[i]=i;
    for(w=1;w<=n;w<<=1){
        sort(sa+1, sa+1+n, cmp);
        memcpy(oldrk, rk, sizeof(oldrk));
        for(int p=0, i=1;i<=n;++i){
            if(oldrk[sa[i]]==oldrk[sa[i-1]]&&oldrk[sa[i]+w]==oldrk[sa[i-1]+w])  rk[sa[i]]=p;
            else    rk[sa[i]]=++p;
        }
    }
    for(int i=1;i<=n;++i){
        if(!rk[i])  continue;
        int j=height[rk[i-1]];
        if(j)   --j;
        while(a[i+j]==a[sa[rk[i]-1]+j]) ++j;
        height[rk[i]] = st[rk[i]][0] = j;
    }
    // for(int i=1;i<=n;++i)   cout<<height[i]<<" ";
    // cout<<endl;
    // for(int i=1;i<=n;++i)   cout<<rk[i]<<" ";
    // cout<<endl;
    // for(int i=1;i<=n;++i)   cout<<sa[i]<<" ";
    // cout<<endl;
    int t=log(n)/log(2);
    for(int j=1;j<=t;++j)
        for(int i=1;i+(1<<j)-1<=n;++i)
            st[i][j]=min(st[i][j-1],st[i+(1<<j-1)][j-1]);
    int ans=0;
//    cout<<sa[2]<<endl;
    for(int i=1;i+k-1<=n;++i)   ans=max(ans,query(i,i+k-1));
    cout<<ans<<endl;
    return 0;
}
/*
20 2
3 3 3 2 2 2 3 3 3 2 2 3 3 1 2 3 2 3 2 3
*/
