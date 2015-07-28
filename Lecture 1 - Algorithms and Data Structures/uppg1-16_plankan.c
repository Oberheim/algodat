#include <stdio.h>

int count;

int main(void) {
	count = 0;
	int l, result, maxResult;
	printf("Plankans längd? ");
	scanf("%d", &l);

	result = length(l,0,0);

	int counter = 0;

	printf("Det finns %d olika sätt\n", count);
}

int length(int goal_l, int current_l, int plank_l) {
	current_l += plank_l;
	if(current_l == goal_l) {
		count +=1;
		return count;
	}
	if(current_l > goal_l) {
		return 0;
	}

	length(goal_l, current_l, 1);
       	length(goal_l, current_l, 2);
      	length(goal_l, current_l, 3);
}


