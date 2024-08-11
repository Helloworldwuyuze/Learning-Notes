#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<stack>
#include<algorithm>
#include<map>
#include<iomanip>
#include<unordered_map>

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
// #define endl '\n'

using namespace std;

const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 1e3 + 10;
const int M = 1e6 + 10;
const int dx[] = {0,1,0,-1,1,1,-1,-1};
const int dy[] = {1,0,-1,0,-1,1,-1,1};

int n,h,w;
bool ma[N][N];

void solve(int x,int y,int n,int h){
	// cout<<x<<" "<<y<<" "<<n<<" "<<h<<endl;
	if(n==1){
		for(int i=0;i<8;++i){
			int xx = x+1+dx[i], yy=y+1+dy[i];
			ma[xx][yy]=true;
		}
		return ;
	}
	int mx = x+h/3, my = y+h/3;
	for(int i=0;i<8;++i){
		int xx = mx+dx[i]*h/3, yy = my+dy[i]*h/3;
		solve(xx, yy, n-1, h/3);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n;
	if(n==0){ cout<<"#"<<endl; return 0;}
	h = w = pow(3,n);
	solve(1, 1, n, h);
	for(int i=1;i<=h;++i,cout<<endl)
		for(int j=1;j<=w;++j)
			if(ma[i][j])	cout<<'#';
			else	cout<<'.';
	return 0;
}