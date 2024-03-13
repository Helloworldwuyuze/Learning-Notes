#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
const int M = 1e2 + 10;
#define endl '\n'
const int INF = 0x3f3f3f3f;

int n,k,a[M];
bool f[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;++i)   cin>>a[i];
    for(int i=1;i<=k;++i){
        for(int j=1;j<=n;++j)
            if(i>=a[j]) f[i]|=!f[i-a[j]];
    }
    if(f[k])    cout<<"First"<<endl;
    else    cout<<"Second"<<endl;
    return 0;
}