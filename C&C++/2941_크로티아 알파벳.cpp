#include<stdio.h>
#include<string.h>
int main() {
	char txt[101] = "";
	int count = 0;
	scanf("%s", txt);

	for (int i = 0; i < strlen(txt); ++i){
		if (txt[i] == 'c') {
			if (txt[i+1] == '=' || txt[i+1] == '-') {
				count++; i++;
				continue;
			}
		}
		else if (txt[i] == 'd') {
			if (txt[i+1] == 'z') {
				if (txt[i+2] == '=') {
					count++; i++; i++;
					continue;
				}
			}
			else if(txt[i+1] == '-'){
				count++; i++;
				continue;
			}
		}
		else if (txt[i] == 'l') {
			if (txt[i+1] == 'j') {
				count++; i++;
				continue;
			}
		}
		else if (txt[i] == 'n') {
			if (txt[i + 1] == 'j') {
				count++; i++;
				continue;
			}
		}
		else if (txt[i] == 's') {
			if (txt[i + 1] == '=') {
				count++; i++;
				continue;
			}
		}
		else if (txt[i] == 'z') {
			if (txt[i + 1] == '=') {
				count++; i++;
				continue;
			}
		}
		count++;
	}

	printf("%d", count);

}
