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
#define int long long
#define DBG(x) cout << #x << "=" << x << endl
#define inf 0x3f3f3f3f
#define mod 1000000001
#define N 3000005
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
int n,cnt=1,vis[N],a[N];
int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1){
			ans=ans*a;
		}
		a=a*a;
		b=b>>1;
	}
	return ans;
}
bool check(int x){
	for(int i=1;i<=n;i++){
		vis[i]=0;
	}
	int k=0,tot=0;
	while(x){
		k++;
		if(x&1){
			a[++tot]=k;
			vis[k]=1;
		}
		x=x>>1;
	}
	for(int i=1;i<=tot;i++){
		if(vis[2*a[i]]==1||vis[3*a[i]]==1){
			return 0;
		}
	}
	return 1;
}
signed main(){
	freopen("select.in","r",stdin);
	freopen("select.out","w",stdout);
	read(n);
	int maxx=qpow(2,n);
	//cout<<maxx<<endl;
	for(int i=1;i<=maxx-1;i++){
		if(check(i)){
			cnt=(cnt+1)%mod;
		}
	}
	write(cnt);
	putchar('\n');
	fclose(stdin);
	fclose(stdout);
    return 0;
}

