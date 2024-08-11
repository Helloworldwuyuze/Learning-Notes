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

    #define pi acos(-1)
    #define eps (1e-8)

    using namespace std;

    const int INF = 0x3f3f3f3f;
    typedef pair<int,int> PII;
    typedef pair<int,PII> PIII;
    const int N = 1e2 + 10;
    const int M = 1e6 + 10;

    int h,w,n;
    int x=1,y=1,f=0;
    bool a[N][N];
    const int dx[]={-1,0,1,0};
    const int dy[]={0,1,0,-1};

    int main(){
        ios::sync_with_stdio(false);
        cin.tie(0), cout.tie(0);
        cin>>h>>w>>n;
        for(int i=1;i<=n;++i){
            if(a[x][y]==0)  a[x][y]=1, f=(f+1)%4, x+=dx[f], y+=dy[f];
            else    a[x][y]=0, f=(f-1+4)%4, x+=dx[f], y+=dy[f];
            x=(x-1+h)%h+1, y=(y-1+w)%w+1;
        }
        for(int i=1;i<=h;++i,cout<<endl)
            for(int j=1;j<=w;++j){
                if(a[i][j]) cout<<"#";
                else    cout<<'.';
            }
        return 0;
    }