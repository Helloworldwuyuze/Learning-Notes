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
const int N = 3e4 + 10;
const int M = 2e6 + 10;
const int MOD = 1e9 + 7;

char c[N];
int n;

int t[N][2], fail[N], idx;
bool flag[N], vis[N];

void insert(char c[]){
    int p=0, len=strlen(c);
    for(int i=0;i<len;++i)
        p=t[p][c[i]-'0']?(t[p][c[i]-'0']):(t[p][c[i]-'0']=++idx);
    flag[p]=true;
}
queue<int> q;
void build(){
    for(int i=0;i<2;++i)
        if(t[0][i]) q.push(t[0][i]);
    while(q.size()){
        int p=q.front(); q.pop();
        for(int i=0;i<2;++i)
            if(t[p][i]) fail[t[p][i]]=t[fail[p]][i], q.push(t[p][i]), flag[p]|=flag[fail[p]];
            else    t[p][i]=t[fail[p]][i];
    }
}

void dfs(int x){
    // cout<<x<<endl;
    for(int i=0;i<2;++i)
        if(!vis[t[x][i]]&&!flag[t[x][i]])   vis[t[x][i]]=true, flag[t[x][i]]=true, dfs(t[x][i]), vis[t[x][i]]=false;
        else if(vis[t[x][i]]){
            cout<<"TAK"<<endl;
            exit(0);
        }
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>c, insert(c);
    // vis[0]=true;
    build(); dfs(0);
    cout<<"NIE"<<endl;
    return 0;
}