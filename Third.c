#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

FILE *file;
file = fopen(argv[1],"r");
char c = 0;
int k,a = 0;
sscanf(argv[2],"%d",&k);

while(!feof(file)) {
	c = getc(file);
	if(c==10) a++;
	if(a==k && a!=0) {
		printf("\nClick ENTER to continue");
		getchar();
		a=0;
	}
	else printf("%c",c);
}

fclose(file);

}
