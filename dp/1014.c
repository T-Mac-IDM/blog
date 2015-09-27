#include <stdio.h>

//nums of original marbles at every value
int nums[120001];
//after binary-tunning, every single marble at every value
int things[20001];
//dp size = 20000*6/2 = 60000
int dp[60001];

void binary_tune() {
	int index_things = 0;
	for (int i = 0;i < 6;i++) {
		int ori = nums[i];
		int tmp = 1;
		while (ori != 0) {
			if ((ori % 2) == 1) {
				things[index_things] = tmp;
				nums[tmp]
				index_things++;
			}			
			tmp = tmp << 1;
			ori = ori >> 1;	
		}
	}
	for(int i = 0;i < 8;i++)
		printf("%d ",things[i]);
}

int main() {
	while(scanf("%d %d %d %d %d %d", nums+1, nums+2, nums+3, nums+4, nums+5, nums+6)) {
		if ((nums[1] | nums[2] | nums[3] | nums[4] | nums[5] | nums[6]) == 0)
			break;
		binary_tune();
		//for (int i = 0; i < 6; i++)
		//	printf("%d ", nums[i]); 
		//printf("\n");
	}
}
