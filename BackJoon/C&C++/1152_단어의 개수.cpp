#include<stdio.h>
#include<string.h>
int main(){
	int count=0;
	char a[1000001]="";
 
	scanf("%[^\n]", a);
 
	for(int i=0; i<strlen(a); ++i){
		if(a[i]==' ')count++;
 
		if(i==0&&a[i]==' ') count--;
		if(i==strlen(a)-1&&a[i]==' ') count--;
	}
 
	if(strlen(a)==0){
		printf("0");
		return 0;
	}
	printf("%d", count+1);
}