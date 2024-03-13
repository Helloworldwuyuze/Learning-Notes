#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
const int M = 2e5 + 10;
#define int long long
#define endl '\n'
const int INF = 0x3f3f3f3f3f3f3f3f;

int n,q,ans;
int Next[M],ver[M],head[N],tot=-1;
bool flag=true,flag2=true; 
void add(int x,int y){
	ver[++tot]=y;
	Next[tot]=head[x];
	head[x]=tot;
} 
int fa[N],son[N];

int dfs(int x,int w){
	if(son[x]==0)	return 0;
	if(w%son[x]!=0)	return w;
	int ans=0;
	for(int i=head[x];~i;i=Next[i]){
		int y=ver[i];
		if(y==fa[x])	continue;
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
	for(int i=2,x;i<=n;++i){
		cin>>x, fa[i]=x, add(i,x), add(x,i), son[x]++;
		if(fa[i]!=i-1)	flag=false;
		if(fa[i]!=1)	flag2=false;
	}
	cin>>q;
	while(q--){
		int v,w;
		cin>>v>>w;
		if(flag)	cout<<0<<endl;
		else if(flag2){
			if(v==1){
				if(w%(n-1)==0)	cout<<0<<endl;
				else	cout<<w<<endl;
			}else	cout<<0<<endl;
		}
		else	cout<<dfs(v,w)<<endl;
	}
	return 0;
}

