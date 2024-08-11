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
int n,a[N],vis[N],pre,ans,vis1[N],maxx;
signed main(){
	freopen("meximum.in","r",stdin);
	freopen("meximum.out","w",stdout);
	read(n);
	for(int i=1;i<=n;i++){
		read(a[i]);
		maxx=max(maxx,a[i]);
		vis[a[i]]++;
	}
	for(int i=0;i<=maxx+1;i++){
		if(vis[i]==0){
			pre=i;
			break;
		}
	}
	//cout<<pre<<endl;
	for(int i=1;i<=n;i++){
		int cnt=pre;
		for(int j=0;j<=maxx+1;j++){
			vis1[j]=vis[j];
		}
		for(int j=n-1;j>=i;j--){
			vis1[a[j+1]]--;
			if(vis1[a[j+1]]==0&&a[j+1]<cnt){
				//cout<<i<<" "<<j<<" "<<a[j+1]<<" "<<cnt<<endl;
				cnt=a[j+1];
			}
			ans+=cnt;
		}
		ans+=pre;
		vis[a[i]]--;
		if(vis[a[i]]==0&&a[i]<pre){
			pre=a[i];
		}
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
    return 0;
}

