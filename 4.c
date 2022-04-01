#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
int main(int argc, char *argv[]) {
if(argc<3) {
        fprintf(stderr,"Not enough arguments!\n");
        exit(EXIT_FAILURE);     
}

FILE *file;
FILE *file2;
file = fopen(argv[1],"r");
file2 = fopen(argv[2],"w");
if(file==NULL) {
	fprintf(stderr,"FILE NOT FOUND EXEPTION!\n");
	return 1;
}
struct stat buf;
lstat(argv[1], &buf);
chmod(argv[2], buf.st_mode);

char c = 0;
while(!feof(file)) {
	c = getc(file);
	putc(c,file2);
}

fclose(file);
fclose(file2);

}
