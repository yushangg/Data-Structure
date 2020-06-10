#include<stdio.h>
#include<string>
struct student {
	char number[3];
	int score1;
	int score2;
	int score3;
	int sum;
	int average;
};
int main() {
	student s[5];
	for (int i = 0; i < 5; i++) {
		scanf("%s", s[i].number);
		scanf("%d", &s[i].score1);
		scanf("%d", &s[i].score2);
		scanf("%d", &s[i].score3);
		s[i].sum = s[i].score1 + s[i].score2 + s[i].score3;
		s[i].average = s[i].sum / 3;
	}
	char *best_number;
	best_number = s[0].number;
	int best_sum = s[0].sum;
	for(int i = 1; i < 5; i++) {
		if (best_sum > s[i].sum) {
			best_number = s[i].number;
			best_sum = s[i].sum;
		}
	}
	printf("number score1 score2 score3 average\n");
	for (int i = 0; i < 5; i++) {
		printf("  %s      %d     %d     %d      %d\n",s[i].number,s[i].score1,s[i].score2,s[i].score3,s[i].average);
	}
	printf("The best student is ");
	printf("%s",best_number);
	printf(",sum=");
	printf("%d", best_sum);
}


