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
const int N = 3e5 + 10;
const int M = 1e6 + 10;

int T,n,m;
int u[N],v[N];
int fa[N];

int find(int x){ return x==fa[x]?fa[x]:(fa[x]=find(fa[x]));}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n>>m;
        for(int i=1;i<=m;++i)   cin>>u[i]>>v[i];
        for(int i=1;i<=n;++i)   fa[i]=i;
        for(int i=1;i<=m;++i){
            int fu=find(u[i]), fv=find(v[i]);
            if(fu==fv)  continue;
            fa[fu]=fv;
        }
        bool flag=false;
        for(int i=1;i<n;++i)
            if(find(i)!=find(i+1))  flag=true;
        if(!flag){
            cout<<"No"<<endl;
            continue;
        }
        cout<<"Yes"<<endl;
        int idx;
        for(int i=2;i<=n;++i)
            if(find(i)!=find(1))    cout<<1<<" "<<i<<endl, idx=i;
        for(int i=2;i<=n;++i)
            if(find(i)==find(1))    cout<<i<<" "<<idx<<endl;
    }
    return 0;
}
//rzjx24baxmvuf73e
