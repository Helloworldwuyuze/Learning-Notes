#include<bits/stdc++.h>

using namespace std;

const int N = 3e3 + 10;
const int M = 1e2 + 10;

char c1[N],c2[N];
int f[N][N],pre[N][N];

void PRINT(int x,int y){
    if(x<=0||y<=0)  return ;
    if(pre[x][y]==1)    PRINT(x-1,y);
    else if(pre[x][y]==2)   PRINT(x,y-1);
    else    PRINT(x-1,y-1), cout<<c1[x];
}

int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0), cout.tie(0);
    scanf("%s%s",c1+1,c2+1);
    int len1=strlen(c1+1), len2=strlen(c2+1);
    for(int i=1;i<=len1;++i)
        for(int j=1;j<=len2;++j){
            f[i][j]=max(max(f[i-1][j],f[i][j-1]),(c1[i]==c2[j])*(f[i-1][j-1]+1));
            if(f[i][j]==f[i-1][j]) pre[i][j]=1;
            else if(f[i][j]==f[i][j-1])    pre[i][j]=2;
            else    pre[i][j]=3;
        }
    PRINT(len1,len2);
    cout<<endl;
    return 0;
}