#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define lenstr 30

char cmpfunc( const void *a, const void *b) {
  return *(char*)a - *(char*)b;
}

int main(){
	FILE *f = fopen("dictionary.txt" , "r");
	FILE *fp = fopen("jumbles.txt" , "r");
	char str[lenstr] = "",newstr[lenstr] = "";
	char jum[lenstr] = "",newjum[lenstr] = "";

	while ((fgets(jum,lenstr,fp)) != NULL)
	{
		int l = 0;
		jum[strlen(jum)-1] ='\0';
		strcpy(newjum,jum);
		qsort(newjum,strlen(newjum),sizeof(char),cmpfunc);
		printf("%s",jum);
		while ((fgets(str,lenstr,f)) != NULL)
		{
			str[strlen(str)-1] ='\0';
			strcpy(newstr,str);
			qsort(newstr,strlen(newstr),sizeof(char),cmpfunc);
			if(strlen(newjum) == strlen(newstr)){
				if(strcmp(newjum,newstr) == 0){
					printf(" : %s",str);
					l++;
				}
			}
		}
		if(l == 0 ){
				printf(" : Not Match");
			}
		printf("\n");
		rewind(f);
	}
	fclose(fp);
	fclose(f);
return 0;
}
