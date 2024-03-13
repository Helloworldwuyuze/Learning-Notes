#include<bits/stdc++.h>

using namespace std;

const int N = 1e4 + 10;
const int M = 1e2 + 10;
const int MOD = 1e9 + 7;

long long f[N][2][M],a[N],cnt;
int n,k;
char c[N];

long long dfs(int location,bool limit,int sum){
    if(location==0) return sum==0;
    if(f[location][limit][sum]!=-1) return f[location][limit][sum];
    int up=limit?a[location]:9;
    long long res=0;
    for(int i=0;i<=up;++i)
        res=(res+dfs(location-1,limit&(i==up),(sum+i)%n))%MOD;
    return f[location][limit][sum]=res;
}

int main(){
    memset(f,-1,sizeof(f));
    scanf("%s%d",c+1,&n);
    k=strlen(c+1);
    for(int i=1;i<=k;++i)
        a[i]=c[k-i+1]-'0';
    printf("%lld\n",(dfs(k,1,0)-1+MOD)%MOD);
    return 0;
}