---
title: 杜教筛
date: 2024-3-25 15:20:42
tags: 算法笔记
mathjax: true
---

# 杜教筛

## 前置芝士

### 线性筛

保证每个数只被它的最小质因子筛到。为了达到这个目的，我们在枚举 $i$ 时只枚举比 $i$ 的最小质因子小或相等的质数。即：```if(i%p[j]==0)  break;```。因此保证了该筛法的**线性**。

### 积性函数

若函数 $f(x)$ 满足 $f(pq)=f(p)f(q)$，其中 $\gcd(p,q)=1$，则称函数 $f(x)$ 为**积性函数**。

大部分数论函数为积性函数。

### 狄利克雷卷积

定义对于两个函数 $f(x),g(x)$ 的运算 $(f*g)(x)=\sum\limits_{d\mid x}f(d)g(\frac{x}{d})$ 或 $\sum\limits_{d\mid x}f(\frac{x}{d})g(d)$，这个运算叫做 $f$ 与 $g$ 的**狄利克雷卷积**。

### 莫比乌斯反演

设函数 $g(x)=\sum\limits_{d\mid x}f(d)$，则 $f(x)=\sum\limits_{d\mid x}g(d)\mu(\frac{x}{d})$。这过程叫做**莫比乌斯反演**。

简单证明：给定条件 $g(n)=\sum\limits_{d\mid n}f(d)$ 可以写为 $g=f*\operatorname{1}$，两边同时卷 $\mu$ 得到 $g*\mu=f*\operatorname{1}*\mu=f*\epsilon=f$，即 $f=g*\mu$，这即为结论。

## 正文：杜教筛

杜教筛主要求的是积性函数的前缀和，但线性求法肯定不需要一个专门的名字，因此杜教筛能在 $O(n^{\frac{3}{4}})$ 内求出 $\sum\limits_{i=1}^nf(i)$。

### 做法

设函数 $g$ 是能够快速算出前缀和的函数，并且 $f*g$ 也能够快速算出前缀和，计 $S(n)=\sum\limits_{i=1}^nf(i)$，那么看推柿子：

$$\sum\limits_{i=1}^n(f*g)(x)$$

$$=\sum\limits_{i=1}^n\sum\limits_{d\mid i}g(d)f(\frac{i}{d})$$

$$=\sum\limits_{d=1}^ng(i)\sum\limits_{i}^{\left\lfloor\frac{n}{i}\right\rfloor}f(i)$$

$$=\sum g(i)S(\left\lfloor\frac{n}{i}\right\rfloor)$$

我们要求的是 $S(n)$，看 $g(1)S(n)$，显然有 $g(1)S(n)=\sum\limits_{i=1}^ng(i)S(\left\lfloor\frac{n}{i}\right\rfloor)-\sum\limits_{i=2}^ng(i)S(\left\lfloor\frac{n}{i}\right\rfloor)$，第一个求和显然等于 $\sum\limits_{i=1}^n(f*g)(x)$，第二个可以用整除分块进行 $O(\sqrt{n})$ 处理。这样就在小于线性的复杂度内求出了 $S(n)$。

值得注意的是，我们可以先进行 $[0,5\times 10^6]$ 内数据的预处理，这样就可以快很多。对于多组数据，我们可以使用 ```unordered_map``` 进行常数级记忆化优化来减小复杂度。

其中预处理的范围大概在 $n^{\frac{2}{3}}$，最终的时间复杂度在 $O(n^{\frac{2}{3}})$ 再加上记忆化即可通过模板题 $P4123$。

### CODE

```cpp
#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<stack>
#include<algorithm>
#include<map>
#include<unordered_map>

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
const int N = 6e5 + 10;
const int M = 6e5;

int mu[N],p[N],cnt;
long long phi[N];
unordered_map<int,int> sumu;
unordered_map<int,long long> sumphi;

void init(){
    mu[1]=phi[1]=1;
    for(int i=2;i<=M;++i){
        if(!p[i])   phi[i]=i-1, mu[i]=-1, p[++cnt]=i;
        for(int j=1;j<=cnt&&i*p[j]<=M;++j){
            p[i*p[j]]=1;
            if(i%p[j]==0){ phi[i*p[j]]=p[j]*phi[i]; break;}
            phi[i*p[j]]=phi[i]*phi[p[j]], mu[i*p[j]]=-mu[i];
        }
    }
    for(int i=1;i<=M;++i)   mu[i]+=mu[i-1], phi[i]+=phi[i-1];
}

int s1(int n){ return n;}
int seps(int n){ return n>=1;}
long long sid(long long n){ return n*(n+1)/2;}
int smu(int n){
    if(n<=M)    return mu[n];
    if(sumu[n]) return sumu[n];
    int res=0;
    for(unsigned int i=2;i<=n;++i){
        int j=n/(n/i);
        res+=(s1(j)-s1(i-1))*smu(n/i);
        i=j;
    }
    return sumu[n]=seps(n)-res;
}
long long sphi(unsigned int n){
    if(n<=M)    return phi[n];
    if(sumphi[n])   return sumphi[n];
    long long res=0;
    for(unsigned int i=2;i<=n;++i){
        unsigned int j=n/(n/i);
        res+=1ll*(s1(j)-s1(i-1))*sphi(n/i);
        i=j;
    }
    return sumphi[n]=sid(n)-res;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n,t;
    init();
    cin>>t;
    while(t--)  cin>>n,cout<<sphi(n)<<" "<<smu(n)<<endl;
    return 0;
}
```
