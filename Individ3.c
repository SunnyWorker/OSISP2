#include <stdio.h>
#include <dirent.h>
#include <time.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int CheckInput(char ok[]) {
	int k = 0, i = 0;
	while(ok[i]!=0) {
        	if(ok[i]<'0' || ok[i]>'9') {
                	fprintf(stderr,"Input not number!\n");
                	exit(EXIT_FAILURE);
        	}
        	else {
                	k*=10;
                	k+=ok[i]-48;
        	}
        	i++;
	}
	if(k<0) {
		fprintf(stderr,"Too big number");
		exit(EXIT_FAILURE);
	}
	return k;
}

void ReadCat(const char *ct, const char *con, int t1, int t2, int s1, int s2, FILE *file,int *a) {
	char s[200];
	//char ss[200];
	int size, time;
	
	strcpy(s,ct);
	//strcpy(ss,ct);
	
	struct dirent *d;
	strcat(s,con);
	//strcat(ss,con);
	struct stat buf;
        stat(s,&buf);

	//if(strcmp(con,"")!=0) strcat(ss,"/");
	if(S_ISDIR(buf.st_mode)) 
	{
		if(strcmp(con,"")!=0) strcat(s,"/");
		DIR *dr = opendir(s);
		d = readdir(dr);
		while (d != NULL && strcmp(d->d_name,".")!=0) 
		{
			(*a)++;
			ReadCat(s,d->d_name,t1,t2,s1,s2,file,a);
			d = readdir(dr);
		}
		closedir(dr);
	}
	else if(S_ISREG(buf.st_mode)) {
	
		if(stat(s,&buf)==0) 
		{
			time = buf.st_ctime;
			size = buf.st_size;
			(*a)++;
			if(size>=s1 && size<=s2 && time>=t1 && time<=t2) 
			{
				fputs(s,file);
				fprintf(file,"\n");
				fputs(ctime(&buf.st_ctime),file);
				fprintf(file,"%d\n",size);
			} 
		}
	}

	return;
}	

int main(int argc, char *argv[]) {
	if(argc<7) {
        	fprintf(stderr,"Not enough arguments!\n");
        	exit(EXIT_FAILURE);     
	}

	char *path = argv[1];
	FILE *fl = fopen(argv[2],"w+t");
	int a = 0;
	int s1,s2,t1,t2;
	t1 = CheckInput(argv[3]);
	t2 = CheckInput(argv[4]);
	s1 = CheckInput(argv[5]);
	s2 = CheckInput(argv[6]);
	if(t1<0 || t2<0 || s1<0 || s2<0 || t1>t2 || s1>s2) {
		printf("Number are incorrect!\n");
		exit(EXIT_FAILURE);
	}

	ReadCat(path,"",t1,t2,s1,s2,fl,&a);
	printf("Просмотренных файлов и каталогов = %d\n",a);
	fclose(fl);
}
