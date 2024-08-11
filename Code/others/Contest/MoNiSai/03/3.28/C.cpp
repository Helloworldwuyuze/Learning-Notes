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

#define fi first
#define se second
#define pb push_back
#define mk make_pair
#define DBG cerr << __LINE__ << ' ' << __FUNCTION__ << endl

#define DRE default_random_engine
#define UID uniform_int_distribution
#define y0 Y0
#define y1 Y1

#define pi acos(-1)
#define eps (1e-8)

using namespace std;

#define int long long
const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N = 26 + 10;
const int M = 2e4;
const int MOD = 1e9 + 7;

int n;
char c1[N],c2[N],c3[N];
int a[N];
bool flag[N];

bool check(){
    int k=0;
    // bool flag=(a[1]==1)&(a[2]==0)&(a[3]==3)&(a[4]==4)&(a[5]==2);
    for(int i=n;i;--i){
        // if(flag)    cout<<a[c1[i]-'A'+1]<<" "<<a[c2[i]-'A'+1]<<" "<<a[c3[i]-'A'+1]<<" "<<k<<endl;
        if(a[c1[i]-'A'+1]==-1||a[c2[i]-'A'+1]==-1||a[c3[i]-'A'+1]==-1){ k=-1; continue;}
        if(k==-1){
            if((a[c1[i]-'A'+1]+a[c2[i]-'A'+1])%n!=a[c3[i]-'A'+1]&&(a[c1[i]-'A'+1]+a[c2[i]-'A'+1]+1)%n!=a[c3[i]-'A'+1])  return false;
            if((a[c1[i]-'A'+1]+a[c2[i]-'A'+1])/n!=(a[c1[i]-'A'+1]+a[c2[i]-'A'+1]+1)/n)  k=-1;
            else    k=(a[c1[i]-'A'+1]+a[c2[i]-'A'+1])/n;
            continue;
        }else if((a[c1[i]-'A'+1]+a[c2[i]-'A'+1]+k)%n!=a[c3[i]-'A'+1]) return false;
        k=(a[c1[i]-'A'+1]+a[c2[i]-'A'+1]+k)/n;
        // if(flag)    cout<<a[c1[i]-'A'+1]<<" "<<a[c2[i]-'A'+1]<<" "<<a[c3[i]-'A'+1]<<" "<<k<<endl;
    }
    return true;
}

void dfs(int location){
    if(!check())    return ;
    // cout<<location<<endl;
    // for(int i=1;i<=n;++i)
    //     if(a[c1[i]-'A'+1]==-1)  cout<<"x";
    //     else    cout<<a[c1[i]-'A'+1];
    // cout<<endl;
    // for(int i=1;i<=n;++i)
    //     if(a[c2[i]-'A'+1]==-1)  cout<<"x";
    //     else    cout<<a[c2[i]-'A'+1];
    // cout<<endl;
    // for(int i=1;i<=n;++i)
    //     if(a[c3[i]-'A'+1]==-1)  cout<<"x";
    //     else    cout<<a[c3[i]-'A'+1];
    // cout<<endl;
    if(location==n+1){
        if(check()){
            for(int i=1;i<=n;++i)   cout<<a[i]<<" ";
            exit(0);
        }
        return ;
    }
    for(int i=0;i<n;++i){
        if(flag[i]) continue;
        a[location]=i;
        // cout<<i<<" "<<flag[i]<<" "<<check()<<" "<<location<<endl;
        // for(int j=1;j<=n;++j)
        //     if(a[c1[j]-'A'+1]==-1)  cout<<"x";
        //     else    cout<<a[c1[j]-'A'+1];
        // cout<<endl;
        // for(int j=1;j<=n;++j)
        //     if(a[c2[j]-'A'+1]==-1)  cout<<"x";
        //     else    cout<<a[c2[j]-'A'+1];
        // cout<<endl;
        // for(int j=1;j<=n;++j)
        //     if(a[c3[j]-'A'+1]==-1)  cout<<"x";
        //     else    cout<<a[c3[j]-'A'+1];
        // cout<<endl;
        // if(!check()){ a[location]=-1; continue;}
        flag[i]=true;
        dfs(location+1);
        flag[i]=false;
        a[location]=-1;
    }
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
    memset(a,-1,sizeof(a));
    cin>>n>>(c1+1)>>(c2+1)>>(c3+1);
    dfs(1);
	return 0;
}