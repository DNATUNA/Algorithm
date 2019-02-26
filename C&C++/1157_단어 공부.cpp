#include<stdio.h>
#include<string.h>
int main(){
	int max=0, a[26]={0,}, check=0, al=0;
	char word[1000001]="";
		scanf("%s", word);
		for(int i=0; i<strlen(word); ++i){
		if(word[i]>64&&word[i]<91) a[word[i]-65]++;
		else if(word[i]>96&word[i]<123) a[word[i]-97]++;
	}
		for(int j=0; j<26; ++j)
			if(max<a[j]) max=a[j];
		
		for(int k=0; k<26; ++k)
			if(max==a[k]){
				check++;
				al=k;
			}
			
	if(check==1) printf("%c", al+65);
	else printf("?");
}