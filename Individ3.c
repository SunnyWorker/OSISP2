#include <stdio.h>
#include <dirent.h>
#include <time.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>

void ReadCat(const char *ct, const char *con, int t1, int t2, int s1, int s2, FILE *file,int *a) {
	char s[200];
	char ss[200];
	int size, time;
	
	strcpy(s,ct);
	strcpy(ss,ct);
	
	struct dirent *d;
	struct stat buf;

	strcat(s,con);
	strcat(ss,con);

	if(strcmp(con,"")!=0) strcat(ss,"/");
	DIR *dr = opendir(ss);
	
	if(dr!=NULL) 
	{
		d = readdir(dr);
		while (d != NULL && strcmp(d->d_name,".")!=0) 
		{
			(*a)++;
			ReadCat(ss,d->d_name,t1,t2,s1,s2,file,a);
			d = readdir(dr);
		}
	}
	else {
		struct stat buf;
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

	closedir(dr);

	return;
}	

int main(int argc, char *argv[]) {
	char *path = argv[1];
	FILE *fl = fopen(argv[2],"w+t");
	int a = 0;
	int s1,s2,t1,t2;
	sscanf(argv[3],"%d",&t1);
	sscanf(argv[4],"%d",&t2);
	sscanf(argv[5],"%d",&s1);
	sscanf(argv[6],"%d",&s2);
	ReadCat(path,"",t1,t2,s1,s2,fl,&a);
	printf("Просмотренных файлов и каталогов = %d\n",a);
	fclose(fl);
}
