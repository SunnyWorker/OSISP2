
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
int main(int argc, char *argv[]) {
if(argc<3) {
        fprintf(stderr,"Not enough arguments!\n");
        exit(EXIT_FAILURE);     
}
FILE *file;
file = fopen(argv[1],"r");
if(file==NULL) {
fprintf(stderr,"Not found file exception!\n");
exit(EXIT_FAILURE);
}
char c = 0;
int k = 0,a = 0,i = 0;
while(argv[2][i]!=0) {
	if(argv[2][i]<'0' || argv[2][i]>'9') {
		fprintf(stderr,"Wrong input!\n");
		exit(EXIT_FAILURE);
	}
	else {
		k*=10;
		k+=argv[2][i]-48;
		if(k<0) {
			fprintf(stderr,"Error. Too big number!\n");
			exit(EXIT_FAILURE);
		}
	}
	i++;
}

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
