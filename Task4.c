#include<stdio.h>
#include<string.h>

char *removeNewline(char *l) {
	char *p = strchr(l,'\n');
	*p ='\0'; 
	return l;
	}


int main(){
	FILE *f = fopen("dictionary.txt" , "r");
	FILE *fp = fopen("jumbles.txt" , "r");
	char str[30] = "";
	char strjum[30] = "",jum[30] = "";

	while ((fgets(strjum,30,fp)) != NULL)
	{
		strcpy(jum,removeNewline(strjum));
		// printf("%s",removeNewline(strjum));
		while ((fgets(str,30,f)) != NULL)
		{
			printf("%s : %s",jum,str);
			// printf("%s\n",removeNewline(str));
		}
		rewind(f);

	}
	fclose(fp);
	fclose(f);

	// printf("File Jumbles");
	// printf("\nDic = %d",l);
	// printf("\nJumbles = %d",p);
return 0;
}