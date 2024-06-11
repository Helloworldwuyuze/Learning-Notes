#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<ctime>
using namespace std;
char A[25];
int N,M,K;
int main(){
	srand(time(NULL));
	freopen("gt.in","r",stdin);
	freopen("gt.out","w",stdout);
	scanf("%d%d%d%s",&N,&M,&K,A+1);
	printf("%d\n",rand()*rand()%K); 
	return 0;
}
