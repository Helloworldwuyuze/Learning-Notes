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
const int N = 2.5e5 + 10;
const int M = 2e6 + 10;
const int MOD = 1e9 + 7;

int Hash(char c){
    switch(c){
        case 'A':{
            return 0;
            break;
        }case 'G':{
            return 1;
            break;
        }case 'C':{
            return 2;
            break;
        }case 'T':{
            return 3;
            break;
        }case '?':{
            return 4;
            break;
        }case '*':{
            return 5;
            break;
        }
        default:{
            return -1;
            break;
        }
    }
}
char c[N], s[N];
bitset<N> vis[N];

int tr[N][4], idx, flag[N], n, len;
bool ans[N];

void insert(char c[],int j){
    int len=strlen(c), p=0;
    for(int i=0;i<len;++i)
        p=tr[p][Hash(c[i])]?(tr[p][Hash(c[i])]):(tr[p][Hash(c[i])]=++idx);
    flag[p]=j;
}

void dfs(int x,int p){
    // cout<<"START"<<endl;
    // cout<<x<<" "<<p<<" "<<flag[p]<<" "<<s[x]<<" "<<Hash(s[x])<<endl;
    if(x==len){
        if(flag[p]) ans[flag[p]]=true;
        return ;
    }
    if(vis[x][p]==true)   return ;
    vis[x][p]=true;
    int xx=Hash(s[x]);
    if(0<=xx&&xx<4){
        if(tr[p][xx])   dfs(x+1,tr[p][xx]);
    }
    else if(xx==4){
        for(int i=0;i<4;++i)
            if(tr[p][i])   dfs(x+1,tr[p][i]);
    }
    else if(xx==5){
        dfs(x+1,p);
        for(int i=0;i<4;++i)
            if(tr[p][i])
                dfs(x,tr[p][i]);
    }
    // cout<<"END"<<endl;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
    cin>>s>>n; len=strlen(s);
    for(int i=1;i<=n;++i)
        cin>>c, insert(c,i);
    dfs(0,0);
    int sum=n;
    for(int i=1;i<=n;++i)   sum-=ans[i];
    cout<<sum<<endl;
    return 0;
}