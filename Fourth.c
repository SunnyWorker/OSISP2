#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
int main(int argc, char *argv[]) {

FILE *file;
FILE *file2;
file = fopen(argv[1],"r");
file2 = fopen(argv[2],"w");
if(file2==NULL) {
printf("FILE NOT FOUND EXEPTION!\n");
return 0;
}
struct stat buf;
lstat(argv[1], &buf);
chmod(argv[2], buf.st_mode);
//if(access(argv[1],2) && !access(argv[1],3)) chmod(argv[2],S_IREAD);
//if(!access(argv[1],2) && access(argv[1],3)) chmod(argv[2],S_IWRITE);
//if(access(argv[1],2) && access(argv[1],3)) chmod(argv[2],S_IREAD | S_IWRITE);
char c = 0;
while(!feof(file)) {
        c = getc(file);
        putc(c,file2);
}

fclose(file);
fclose(file2);

}

