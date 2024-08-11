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
#define endl '\n'

using namespace std;

const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 7e2 + 10;
const int M = 1e6 + 10;

int n, m, yx, yy, vx, vy;
char ma[N][N];
bool tag[N][N];

queue<PII> qy, qv;
void attack(int x,int y){
	
}
void BFS(){
	qy.push(mk(yx, yy)), qv.push(mk(vx, vy));
	attack(vx, vy);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j){
			cin>>ma[i][j];
			if(ma[i][j]=='V')	vx = i, vy = j;
			if(ma[i][j]=='Y')	yx = i, yy = j;
		}
	BFS();
	return 0;
}