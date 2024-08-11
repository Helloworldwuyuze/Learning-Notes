#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
const int M = 1e3 + 10;
//#define int long long
#define endl '\n'
const int INF = 0x3f3f3f3f3f3f3f3f;

int n,q,ans,L;
int Next[N],ver[N],head[N],tot=-1;
bool flag=true,flag2=true; 
void add(int x,int y){
	ver[++tot]=y;
	Next[tot]=head[x];
	head[x]=tot;
} 
int fa[N],son[N],f[N][M],fat[N];

int find(int x){
	return fat[x]==x?fat[x]:fat[x]=find(fat[x]);
}

void init(int x){
	if(son[x]==0)	return ;
	for(int i=head[x];~i;i=Next[i]){
		int y=ver[i];
//		cout<<y<<endl;
		if(son[x]==1)	fat[x]=y;
		init(y);
		if(son[y]==0)	continue;
		for(int j=1;j<=M-10;++j)
			if(j%son[y]==0)	f[x][j]+=f[y][j/son[y]];
			else	f[x][j]+=j;
	}
}

int dfs(int x,int w){
//	cout<<x<<" "<<w<<endl;
	x=find(x);
	if(son[x]==0)	return 0;
	if(w%son[x]!=0)	return w;
	if(w/son[x]<=1000)	return f[x][w/son[x]];
	int ans=0;
	for(int i=head[x];~i;i=Next[i]){
		int y=ver[i];
		ans+=dfs(y,w/son[x]);
	}
	return ans;
}

signed main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	memset(head,-1,sizeof(head));
	cin>>n;
	for(int i=2,x;i<=n;++i)
		cin>>x, fa[i]=x, add(x,i), son[x]++;
	for(int i=1;i<=n;++i)	fat[i]=i;
	init(1); 
	cin>>q;
	while(q--){
		int v,w;
		cin>>v>>w;
		cout<<dfs(v,w)<<endl;
	}
	return 0;
}

