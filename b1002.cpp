#include <stdio.h>
#include <string.h>

void trans(char c) {
    switch (c) {
        case '0':
            printf("ling");break;
        case '1':
            printf("yi");break;
        case '2':
            printf("er");break;
        case '3':
            printf("san");break;
        case '4':
            printf("si");break;
        case '5':
            printf("wu");break;
        case '6':
            printf("liu");break;
        case '7':
            printf("qi");break;
        case '8':
            printf("ba");break;
        case '9':
            printf("jiu");break;
        default:
            break;
    }

}

int main() {
	char s[100]={0},t[3]={0};
	int n[100]={0};
    int sum=0;
	gets(s);
	for (int i = 0; i < strlen(s) ; i++)
	{
		n[i] = s[i] - '0';
		sum = sum + n[i];
	}

    sprintf(t,"%d",sum);
    for(int i=0;i<strlen(t);i++) {
        trans(t[i]);
        if (i<strlen(t)-1)
        printf(" ");
    }

}

