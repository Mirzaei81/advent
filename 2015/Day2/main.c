#include "stdio.h"
#include <stdint.h>
#include "stdlib.h"
#include <limits.h>

int wraping(int* arr){
	int smallest = INT_MAX;
	int idx;
	for(int i=0;i<3;i++){
		if(smallest>arr[i]){
			smallest = arr[i];
			idx=i;
		}
	}
	int second_smallest = INT_MAX;
	for (int i = 0; i < 3; i++) {
		if (arr[i] <= second_smallest && arr[i] >= smallest && i!=idx) {
			second_smallest = arr[i];
		}
	}
	int res = 2*smallest+2*second_smallest;
	return res;
}

int main(){
	FILE *fp = fopen("./i.txt","r");
	char c; 
	long WrapingPaper =0;
	int sides[3];
	int SidePos=0;
	char num[10];
	int numPos=0;
	while((c=getc(fp))!=EOF){
		switch (c) {
			case 'x':
				num[numPos] = '\0';
				sides[SidePos] = atoi(num);
				SidePos+=1;
				numPos=0;
				break;
			case '\n':
				num[numPos] = '\0';
				sides[SidePos] = atoi(num);
				int perfectBow = sides[0]*sides[1]*sides[2];
				int  aroundSide= wraping(sides);
				printf("%dx%dx%d\taround:%d\tVol:%d\tTotal:%d\n",sides[0],sides[1],sides[2],
				   aroundSide,perfectBow,perfectBow+aroundSide);
				WrapingPaper +=  perfectBow + aroundSide;
				SidePos=0;
				numPos=0;
				break;
			default:
				num[numPos] = c;
				numPos+=1;
				break;
		}
	}
	printf("%ld",WrapingPaper);
	return 0;
}
