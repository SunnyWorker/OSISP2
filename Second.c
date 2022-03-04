#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

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
