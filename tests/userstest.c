#include <mysql.h>
#include <stdio.h>
#include <stdlib.h>

void finish_with_error(MYSQL *con)
{
  fprintf(stderr, "%s\n", mysql_error(con));
  mysql_close(con);
  exit(1);
}

void allUsers( MYSQL *con) {
	
	 if (mysql_query(con, "SELECT * FROM users"))
  {
      finish_with_error(con);
  }

  MYSQL_RES *result = mysql_store_result(con);

  if (result == NULL)
  {
      finish_with_error(con);
  }

  int num_fields = mysql_num_fields(result);

  MYSQL_ROW row;

  while ((row = mysql_fetch_row(result)))
  {
      for(int i = 0; i < num_fields; i++)
      {
          printf("%s ", row[i] ? row[i] : "NULL");
      }

      printf("\n");
  }

  mysql_free_result(result);
	
	
}


void userbyId( MYSQL *con , int id  )  {
	
	char data[1024] ; 
	
	
	  sprintf(   data ,  "SELECT username , email FROM users  WHERE id=%d" ,      id    );    
	puts(data);
	if (mysql_query(con,data))
  {
      finish_with_error(con);
  }
  
  
   MYSQL_RES *result = mysql_store_result(con);
   
   if (result == NULL)
  {
      finish_with_error(con);
  }
  
 MYSQL_ROW row = mysql_fetch_row(result);
 
 unsigned long *lengths = mysql_fetch_lengths(result);

  if (lengths == NULL) {
      finish_with_error(con);
  }
 
 printf("%s   %s" , row[0] , row[1]  );  
	
	  mysql_free_result(result);
	
	
}

void srach(MYSQL *con  , const char *query ,  int page)  {
	

	
	char queryql[2048] ;   
	char data[2048] ;
	sprintf( data , "SELECT id, email, username ,ccountry FROM users WHERE ccountry  LIKE  '%%%s%%' OR email  LIKE   '%%%s%%'  OR username LIKE  '%%%s%%' ORDER BY id  DESC LIMIT 10 OFFSET %d;" , query,query,query,page);
		 puts(data);
		 if (mysql_query(con, data)){
			      finish_with_error(con);
			 
		 }
		 
		 MYSQL_RES *result = mysql_store_result(con);

  if (result == NULL)
  {
      finish_with_error(con);
  }

  int num_fields = mysql_num_fields(result);

  MYSQL_ROW row;
  
   while ((row = mysql_fetch_row(result)))
  {
      for(int i = 0; i < num_fields; i++)
      {
          printf("%s ", row[i] ? row[i] : "NULL");
      }

      printf("\n");
  }

  mysql_free_result(result);
	
}
int main(int argc, char **argv)
{
  MYSQL *con = mysql_init(NULL);

  if (con == NULL)
  {
      fprintf(stderr, "mysql_init() failed\n");
      exit(1);
  }

  if (mysql_real_connect(con, "127.0.0.1", "root", "",
          "godb", 0, NULL, 0) == NULL)
  {
      finish_with_error(con);
  }

srach  (con ,  "ayoub" , 2);
//userbyId(con,1);
 //allUsers(con);
  mysql_close(con);

  exit(0);
}