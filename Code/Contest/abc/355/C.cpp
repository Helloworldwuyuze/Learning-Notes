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
const int N = 2e3 + 10;
const int M = 2e5 + 10;

bool tag[N][N];
int n,t,x;
int r[N], h[N], fir, sec;

PII reHash(int x){
	return mk((x-1)/n+1,(x-1)%n+1);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>t;
	for(int i=1;i<=t;++i){
		cin>>x;
		PII coor=reHash(x);
		if(tag[coor.fi][coor.se]==false){
			++r[coor.fi], ++h[coor.se];
			if(r[coor.fi]==n||h[coor.se]==n){
				cout<<i<<endl;
				return 0;
			}
			if(coor.fi==coor.se){
				++fir;
				if(fir==n){ cout<<i<<endl; return 0;}
			}
			if(coor.fi+coor.se==n+1){
				++sec;
				if(sec==n){ cout<<i<<endl; return 0;}
			}
			tag[coor.fi][coor.se]=true;
		}
	}
	cout<<-1<<endl;
	return 0;
}