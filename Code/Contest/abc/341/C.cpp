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
const int N = 500 + 10;
const int M = 1e6 + 10;

int h,w,n,cnt;
char m[N][N];
char op[N];
set<PII> s;
int dx[N], dy[N], ans;
PII p[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>h>>w>>n;
    cin>>(op+1);
    for(int i=1;i<=h;++i)
        cin>>(m[i]+1);
    dx['U']=-1; dx['D']=1; dy['L']=-1, dy['R']=1;
    for(int x=2;x<h;++x){
        for(int y=2;y<w;++y){
            if(m[x][y]=='#')    continue;
            PII now=mk(x,y);
            bool flag=true;
            for(int i=1;i<=n;++i){
                now.fi+=dx[op[i]], now.se+=dy[op[i]];
                if(m[now.fi][now.se]=='#'){ flag=false; break;}
            }
            ans+=flag;
        }
    }
    cout<<ans<<endl;
    return 0;
}