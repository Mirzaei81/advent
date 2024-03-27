#include <stdio.h>
#include <stdlib.h>
int main(){
	char up = '(';
	char down = ')';
	FILE*  fp= fopen("input1.txt","r");
	if (!fp){
		printf("couldn't find puzzle file\n");
	}
	
	fseek(fp,0l, SEEK_END);
	long l = ftell(fp);
	rewind(fp);
	char *puzztxt = malloc(sizeof(char)*(l+1));
	int ch;
	int i=0;
	while((ch = fgetc(fp)) != EOF){
		puzztxt[i]=ch;
		i+=1;
	};
	fclose(fp);
	puzztxt[i+1]=EOF;
	unsigned long floor =0;
	for(int i=0;i<l;i++){
		char cur = puzztxt[i];
		if(cur == up){
			floor+=1;
		}
		if(cur == down){
			floor-=1;
		}
		if (floor==-1){
			printf("%d\n",i+1);
		}
	}
	printf("%lu",floor);

}
