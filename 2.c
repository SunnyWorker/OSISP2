#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
printf("%d",argc);
if(argc<2) {
	fprintf(stderr,"Not enough arguments!\n");
	exit(EXIT_FAILURE);	
}
FILE *file;
file = fopen(argv[1],"w");
printf("Click CTRL+K to end this\n");
char c = ' ';

while(c!=11) {
putc(c,file);
scanf("%c",&c);
}
fclose(file);

}
