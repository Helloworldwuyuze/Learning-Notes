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
typedef pair<PII,PII> PPP;
const int N = 60 + 10;
const int M = 1e6 + 10;

int n;
char ma[N][N];
bool flag=false;
PII p1,p2;
queue<PPP> q;
int st[N][N][N][N];
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};

void bfs(){
    q.push(mk(p1,p2));
    while(!q.empty()){
        PII p1=q.front().fi, p2=q.front().se; q.pop();
        if(p1==p2){
            cout<<st[p1.fi][p1.se][p2.fi][p2.se]<<endl;
            return ;
        }
        for(int i=0;i<4;++i){
            int xx1=p1.fi+dx[i], yy1=p1.se+dy[i];
            int xx2=p2.fi+dx[i], yy2=p2.se+dy[i];
            if(ma[xx1][yy1]=='#')   xx1-=dx[i], yy1-=dy[i];
            if(ma[xx2][yy2]=='#')   xx2-=dx[i], yy2-=dy[i];
            PII pp1=mk(xx1,yy1), pp2=mk(xx2,yy2);
            if(pp1==p1&&pp2==p2||st[xx1][yy1][xx2][yy2])    continue;
            st[xx1][yy1][xx2][yy2]=st[p1.fi][p1.se][p2.fi][p2.se]+1;
            q.push(mk(pp1,pp2));
        }
    }
    cout<<-1<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j){
            cin>>ma[i][j];
            if(ma[i][j]=='P'&&!flag)    p1=mk(i,j), flag=true;
            if(ma[i][j]=='P'&&flag) p2=mk(i,j);
        }
    for(int i=0;i<=n+1;++i)   ma[i][0]=ma[0][i]=ma[i][n+1]=ma[n+1][i]='#';
    bfs();
    return 0;
}