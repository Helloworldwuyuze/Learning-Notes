#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<stack>
#include<algorithm>
#include<map>

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
#define endl '\n'

#define pi acos(-1)
#define eps (1e-8)
#define null nullptr

using namespace std;

#define int long long
const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 4e5 + 10;
const int M = 2e5 + 10;

struct seg{
    int ls[N<<2], rs[N<<2], mx[N<<2];
    bool tag[N<<2];
    void push_up(int p){
        tag[p] = tag[p<<1] | tag[p<<1|1];
        ls[p] = tag[p<<1] ? ls[p<<1] : ls[p<<1] + ls[p<<1|1];
        rs[p] = tag[p<<1|1] ? rs[p<<1|1] : rs[p<<1|1] + rs[p<<1];
        mx[p] = max(max(mx[p<<1], mx[p<<1|1]), rs[p<<1] + ls[p<<1|1]);
    }
    void build(int p,int l,int r){
        if(l==r)    return (void)(tag[p] = false, ls[p] = rs[p] = mx[p] = 1);
        int mid = l+r>>1;
        build(p<<1, l, mid), build(p<<1|1, mid+1, r);
        push_up(p);
    }
    void update(int p,int l,int r,int x){
        if(l==r)    return (void)(tag[p] = true, rs[p] = ls[p] = mx[p] = 0);
        int mid=l+r>>1;
        if(x<=mid)  update(p<<1, l, mid, x);
        else    update(p<<1|1, mid+1, r, x);
        push_up(p);
        // cout<<p<<" "<<l<<" "<<r<<" "<<x<<" "<<mx[p]<<" "<<ls[p]<<" "<<rs[p]<<" "<<tag[p]<<endl;
    }
}seg1, seg2;
int h, w, n;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
    cin>>w>>h>>n;
    seg1.build(1, 1, w*2-1), seg2.build(1, 1, h*2-1);
    // cout<<seg1.mx[1]<<" "<<seg2.mx[1]<<endl;
    while(n--){
        char op; int x;
        cin>>op>>x;
        if(op=='H'){
            seg2.update(1, 1, h*2-1, 2*x);
        }else{
            seg1.update(1, 1, w*2-1, 2*x);
        }
        int m1 = seg1.mx[1], m2 = seg2.mx[1];
        // cout<<m1<<" "<<m2<<" ";
        cout<<((m1+1)/2) * ((m2+1)/2)<<endl;
    }
	return 0;
}