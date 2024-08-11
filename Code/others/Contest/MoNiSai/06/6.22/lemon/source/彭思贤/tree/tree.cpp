#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<iomanip>
#include<iostream>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<vector>
#define ll long long
#define DBG(x) cout << #x << "=" << x << endl
#define inf 0x3f3f3f3f
#define mod 1000000007
#define N 100005
using namespace std;
template <typename T>
void read(T& x) {
    x = 0;
    ll t = 1;
    char ch;
    ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') {
            t = -1;
        }
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    x *= t;
}
template <typename T, typename... Args>
void read(T& first, Args&... args) {
    read(first);
    read(args...);
}
template <typename T>
void write(T y) {
    T x = y;
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) {
        write(x / 10);
    }
    putchar(x % 10 + '0');
}
template <typename T, typename... Ts>
void write(T arg, Ts... args) {
    write(arg);
    if (sizeof...(args) != 0) {
        putchar(' ');
        write(args...);
    }
}
int n,q,a[N],x,y,f[30005][1005],deep[N],vis[N],ans;
vector<int> ve[N];
void dfs1(int root,int u,int fa){
	deep[u]=deep[fa]+1;
	f[root][deep[u]]+=a[u];
	for(int i=0;i<ve[u].size();i++){
		int v=ve[u][i];
		if(v==fa){
			continue;
		}
		dfs1(root,v,u);
	}
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	read(n,q);
	for(int i=1;i<=n;i++){
		read(a[i]);
	}
	for(int i=1;i<=n-1;i++){
		read(x,y);
		ve[x].push_back(y);
		ve[y].push_back(x);
	}
	deep[0]=-1;
	for(int i=1;i<=q;i++){
		int sum=0;
		read(x,y);
		if(y>=n){
			sum=0;
			ans^=i*sum;
		}
		else{
			if(vis[x]==0){
				dfs1(x,x,0);
				vis[x]=1;
			}
			sum=f[x][y];
			ans^=i*f[x][y];
		}
		if(q<=10000){
			cout<<sum<<endl;
		}
	}
	if(q>10000){
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
    return 0;
}

