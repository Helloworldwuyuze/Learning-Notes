#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N=3e5+10;
int n;
int c[N],a[N];
ll ans;
signed main(){
    freopen("meximum.in","r",stdin);
    freopen("meximum.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i];
    for(int i=1;i<=n;++i){
        int k=0;
        for(int j=i;j<=n;++j){
            c[a[j]]=1;
            while(1){
                if(!c[k]){
                    ans+=k;
                    break;
                }
                k++;
            }
        }
        for(int j=i;j<=n;++j) c[a[j]]=0;
    }
    cout<<ans<<endl;
    return 0;
}
