#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

void Read(const char *c) {

DIR *dr = opendir(c);
struct dirent *d;
d = readdir(dr);
while (d != NULL) {
        printf("%s\n",d->d_name);
        d = readdir(dr);
}

}

int main(int argc, char *argv[]) {

Read("/");
printf("Home page\n");
Read("./");

}
