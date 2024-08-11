#include<bits/stdc++.h>

using namespace std;
const int N = 1e5 + 10;

FILE *f_in, *f_out, *f_ans, *f_score, *f_report;
int n, a[N], standered_answer, b[N], user_sum, user_answer, user_tot, user_fact_tot, user_score;

int main(int argc, char *argv[]){
    f_in = fopen(argv[1],"r");
	f_out = fopen(argv[2],"r");
	f_ans = fopen(argv[3],"r");
	user_score = atoi(argv[4]);
	f_score = fopen(argv[5],"w");
	f_report = fopen(argv[6],"w");
    fscanf(f_in, "%d", &n);
    for(int i=1;i<=n;++i)	fscanf(f_in, "%d", &a[i]);
    fscanf(f_ans, "%d", &standered_answer);
    fscanf(f_out, "%d", &user_answer);
    fscanf(f_out, "%d", &user_tot);
    for(int i=1;i<=user_tot;++i)	fscanf(f_out, "%d", &b[i]);
//    fprintf(f_report, "%d\n", user_answer);
//    fprintf(f_report, "%d\n", user_tot);
//    for(int i=1;i<=user_tot;++i)	fprintf(f_report, "%d ", b[i]);
    for(int i=1;i<=n;++i){
    	for(int j = user_tot; j; --j)
    		user_fact_tot += a[i] / b[j], a[i] -= (a[i]/b[j]) * b[j];
	}
	if(user_fact_tot!=user_answer)	fprintf(f_score, "%d", user_score * 0), fprintf(f_report, "Your answer is not exactly what your answer is.");
	else if(user_fact_tot>standered_answer){
		fprintf(f_score, "%d", user_score * 0);
		fprintf(f_report, "Your answer is bigger than the answer of std.");
		fprintf(f_report, "%d %d %d\n",user_answer, user_tot, user_fact_tot);
		for(int i=1;i<=user_tot;++i)
			fprintf(f_report, "%d ", b[i]);
		fprintf(f_report, "\n");
	}
	else if(user_fact_tot<standered_answer)	fprintf(f_score, "%d", user_score * 1), fprintf(f_report, "Your answer is even smaller than the answer of std!!!");
	else	fprintf(f_score, "%d", user_score * 1), fprintf(f_report, "Your answer is same as the answer of std!");
	
	fclose(f_in), fclose(f_out), fclose(f_ans);
	fclose(f_score), fclose(f_report);
    return 0;
}
