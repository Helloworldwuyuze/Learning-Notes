#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int inf=0x3f3f3f3f;
const int N=2e5+5;
int n,k,ans=inf;
char s[N];
int main(){
    freopen("joi.in","r",stdin);
    freopen("joi.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>k>>s;
    vector<int>js,os,is;
    for(int i=0;i<n;i++)
        if(s[i]=='J')js.push_back(i);
        else if(s[i]=='O')os.push_back(i);
        else is.push_back(i);
    for(int lj=0;lj<=js.size()-k;lj++){
        int res=0,rj=lj+k-1;
        res+=js[rj]-js[lj]-k+1;
        if(res>=ans){
            res-=js[rj]-js[lj]-k+1;
            continue;
        }
        for(int lo=upper_bound(os.begin(),os.end(),js[rj])-os.begin();lo<=os.size()-k;lo++){
            int ro=lo+k-1;
            res+=os[lo]-js[rj]-1;
            res+=os[ro]-os[lo]-k+1;
            if(res>=ans){
                res-=os[lo]-js[rj]-1;
                res-=os[ro]-os[lo]-k+1;
                continue;
            }
            for(int li=upper_bound(is.begin(),is.end(),os[ro])-is.begin();li<=is.size()-k;li++){
                int ri=li+k-1;
                res+=is[li]-os[ro]-1;
                res+=is[ri]-is[li]-k+1;
                ans=min(ans,res);
                res-=is[li]-os[ro]-1;
                res-=is[ri]-is[li]-k+1;
            }
            res-=os[lo]-js[rj]-1;
            res-=os[ro]-os[lo]-k+1;
        }
        res-=js[rj]-js[lj]-k+1;
    }
    if(ans==inf)cout<<-1;
    else cout<<ans;
    return 0;
}