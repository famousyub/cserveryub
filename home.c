#include "home.h"

#include <string.h>
#include<stdlib.h>
#include<stdio.h>


const char *reader(FILE *f,const char *d,const char *fn)

{
	
	
	const char *data ;
	char dat[1024];
	
	if(f==NULL) {
		
		strcpy("error",data);
		return data ;
	}
	
	
	while(fgets(dat,500,f) !=NULL) {
		   printf("%s",dat);
			
	}
	
	return "good";
	
	
}

int main()  {
	FILE *f  = fopen("home.xhtml","r");
	
	puts(reader(f,"r","home.xhtml"));
	
	return 0;
}