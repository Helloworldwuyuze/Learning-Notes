#include "q.h"
#include<vector>
#include<cmath>
#include<cstdio>
#include<iostream>

const int N = 1e6 + 10;
const int S = 1e3 + 10;

using namespace std;
#define pb push_back

int B, cnt;
vector<int> g[N];
int dis[N];
bool vis[N];

int solve(int n){
	B = sqrt(n);
	for(int i=1;i<=n;++i)
		if(!vis[i]){
			++cnt;
			for(int j=1;j<=n;++j)
				if(!vis[j] && Q(i, j, B))	g[cnt].pb(j), vis[j] = true;
		}
	if(n%B == 1){
		for(int i=1;i<=cnt;++i)
			for(int x:g[i])
				for(int y:g[i])
					if(x != y && Q(x, y, n-1)){
						if(C(x, y))	return x;
						else	return y;
					}
	}
//	for(int i=1;i<=cnt;++i,cout<<endl)
//		for(int x:g[i])	cout<<x<<" ";
//	cout<<endl;
	for(int i=2;i<=cnt;++i){
		for(int j=n;j;--j)
			if(Q(g[1][0], g[i][0], j)){
				dis[i] = j;
				break; 
			}
	}
//	for(int i=1;i<=cnt;++i)	cout<<dis[i]<<endl;
	for(int i=1;i<=cnt;++i){
		dis[i] = (dis[i]%B+B)%B;
		for(int j=1;j<=cnt;++j){
			int d1 = dis[i], d2 = B-dis[i], d3 = dis[j], d4 = B-dis[j], tmp = (n-1)%B; 
			if((d1+d3)%B == tmp || (d1+d4)%B == tmp || (d2+d3)%B == tmp || (d2+d4)%B == tmp){
				for(int x:g[i])
					for(int y:g[j]){
						if(Q(x, y, n-1)){
							if(C(x, y))	return x;
							else	return y;
						}
					}
			}
		}
	}
}
