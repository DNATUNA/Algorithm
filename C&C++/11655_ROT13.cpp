#include<stdio.h>
#include<string.h>
int main() {
	char c=' ';
	while ((c = getchar()) != '\n') {
		if (c > 64 && c < 91) {
			if(c+13<91) printf("%c", c + 13);
			else printf("%c", (c + 13)%91+65);
		}
		else if (c > 96 && c < 123) {
			if(c+13<123) printf("%c", c + 13);
			else printf("%c", (c + 13) % 122 + 96);
		}
		else printf("%c", c);
	}
}