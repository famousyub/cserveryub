#include "httpd.h"





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
int main(int c, char** v)
{
    serve_forever("12913");
    return 0;
}

void route()
{
    ROUTE_START()

    ROUTE_GET("/")
    {
        printf("HTTP/1.1 200 OK\r\n\r\n");
        printf("Hello! You are using %s", request_header("User-Agent"));
    }

    ROUTE_POST("/")
    {
        printf("HTTP/1.1 200 OK\r\n\r\n");
        printf("Wow, seems that you POSTed %d bytes. \r\n", payload_size);
        printf("Fetch the data using `payload` variable.");
    }
	
	
	
	 ROUTE_GET("/home")
    {
		
		  FILE *f  = fopen("home.xhtml","r");
		  const char *data ;
	       char dat[1024];
		  
	/*if(f==NULL) {
		
		strcpy("error",data);
		printf("%s",data);
	}
	
	
	while(fgets(dat,500,f) !=NULL) {
		   printf("%s",dat);
			
	}
		  */
		  
        printf("HTTP/1.1 200 OK\r\n\r\n");
        printf("Hello! You are using %s", request_header("User-Agent"));
    }
  
    ROUTE_END()
}