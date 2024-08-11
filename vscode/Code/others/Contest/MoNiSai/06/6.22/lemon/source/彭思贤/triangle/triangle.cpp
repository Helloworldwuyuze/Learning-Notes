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
#define N 300005
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
int n,m,x,y;
vector<int> ve[N];
ll ans=1,sum=0;
int main(){
	freopen("triangle.in","r",stdin);
	freopen("triangle.out","w",stdout);
	read(n,m);
	for(int i=1;i<=m;i++){
		read(x,y);
		ve[x].push_back(y);
		ve[y].push_back(x);
	}
	ans=1ll*n*1ll*(n-1)*1ll*(n-2)/6;
	for(int i=1;i<=n;i++){
		sum+=1ll*ve[i].size()*1ll*(n-1-ve[i].size());
	}
	sum=sum/2;
	ans-=sum;
	write(ans);
	putchar('\n');
	fclose(stdin);
	fclose(stdout);
    return 0;
}

