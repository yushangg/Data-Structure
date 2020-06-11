#include<stdio.h>
struct student {
	char number[3];
	double score1;
	double score2;
	double score3;
	double sum;
	double average;
};
int main() {
	int i;
	struct student s[5];
	for (i = 0; i < 5; i++) {
		scanf("%s", s[i].number);
		scanf("%lf", &s[i].score1);
		scanf("%lf", &s[i].score2);
		scanf("%lf", &s[i].score3);
		s[i].sum = s[i].score1 + s[i].score2 + s[i].score3;
		s[i].average = s[i].sum / 3;
	}
	char *best_number;
	best_number = s[0].number;
	double best_sum = s[0].sum;
	for(i = 1; i < 5; i++) {
		if (best_sum < s[i].sum) {
			best_number = s[i].number;
			best_sum = s[i].sum;
		}
	}
	printf("number score1 score2 score3 average\n");
	for (i = 0; i < 5; i++) {
		printf("  %s    %.1lf   %.1lf   %.1lf    %.2lf\n",s[i].number,s[i].score1,s[i].score2,s[i].score3,s[i].average);
	}
	printf("The best student is ");
	printf("%s",best_number);
	printf(",sum=");
	printf("%.1lf", best_sum);
	return 0;
}