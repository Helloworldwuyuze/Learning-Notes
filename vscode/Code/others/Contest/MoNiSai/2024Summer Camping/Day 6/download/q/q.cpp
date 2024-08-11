#include "q.h"
#include<vector>
#include<cmath>

const int N = 1e6 + 10;
const int S = 1e3 + 10;

using namespace std;
#define pb push_back

int ans = 0, B, cnt;
vector<int> g[S];
int dis[S][S];
bool vis[N];

int solve(int n){
	B = sqrt(n);
	for(int i=1;i<=n;++i)
		if(!vis[i]){
			++cnt;
			for(int j=1;j<=n;++j)
				if(!vis[j] && Q(i, j, B))	g[cnt].pb(j), vis[j] = true;
		}
	for(int i=1;i<cnt;++i)
		for(int j=n;j;--j)
			if(Q(g[i][0], g[i+1][0], j)){
				dis[i][i+1] = j;
				break; 
			}
	for(int i=n;i;--i)
		if(Q(g[cnt][0], g[1][0], i)){
			dis[cnt][1] = i;
			break;
		}
	for(int i=1;i<=cnt;++i){
		for(int j=1;j<cnt;++j){
			int x = i, y = (x+j)%cnt, lst = (x+j-1)%cnt;
			dis[x][y] = dis[x][lst] + dis[lst][y];
		}
	}
	for(int i=1;i<=cnt;++i)
		for(int j=1;j<=cnt;++j){
			dis[i][j] = (dis[i][j]%B+B)%B;
			if(dis[i][j] == (n-1)%B){
				for(int x:g[i])
					for(int y:g[j])
						if(Q(x, y, n-1)){
							if(C(x, y))	return x;
							else	return y;
						}
			}
		}
}

int main(){
	
	return 0;
}
