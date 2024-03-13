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
int n,q,a[N],x,vis[N],v[N];
priority_queue<int> q1;
stack<int> s2,s3;
void solve(){
	int sum=0;
	for(int i=1;i<=n;i++){
		while(1){
		//	cout<<vis[i]<<endl;
			if(vis[i]==1){
				break;
			}
			int y=s2.top();
			s2.pop();
			sum++;
			if(y==i){
				break;
			}
			q1.push(y);
		}
		while(!q1.empty()){
			int y=q1.top();
			q1.pop();
			s2.push(y);
		}
	}
	cout<<sum<<" ";
}
int main(){
	freopen("dizalo.in","r",stdin);
	freopen("dizalo.out","w",stdout);
	read(n,q);
    for(int i=1;i<=n;i++){
    	read(a[i]);
	}
	for(int i=n;i>=1;i--){
		s2.push(a[i]);
	}
	solve();
	while(q--){
		read(x);
		vis[a[x]]=1;
		for(int i=n;i>=1;i--){
			if(vis[a[i]]==1){
				continue;
			}
			s2.push(a[i]);
		}
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

