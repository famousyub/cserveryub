#nclude <string.h>
#include <time.h>
#include <stdio.h> 
#include <stdlib.h>
#include <mysql.h>
#include <stdbool.h>
#include "bs.h"
#include "models/account.h"
#include "models/session.h"


Account *accountNew(int id, int createdAt, char *name,
                    char *email, char *username)
{
    Account *account = malloc(sizeof(Account));

    account->id        = id;
    account->createdAt = createdAt;
    account->name      = bsNew(name);
    account->email     = bsNew(email);
    account->username  = bsNew(username);

    return account;
}

void finish_with_error(MYSQL *con)
{
  fprintf(stderr, "%s\n", mysql_error(con));
  mysql_close(con);
  return NULL;
}

Account *accountGetById(  MYSQL *con,     int id  ) {
	
	
	if (id == -1) return NULL;

     Account *account = NULL;
	 
	 char query[1024];
	 
	 sprintf( query , "SELECT id, createdAt, name, email, username FROM cars WHERE id=%d" , id);

if (mysql_query(con, query))
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







 //MYSQL_RES *res;
  // MYSQL_ROW row;
   
    // MYSQL_ROW row = mysql_fetch_row(con);
	 
	    //while ((row = mysql_fetch_row(res)) != NULL){
			
			
			account = accountNew(   (int) row[0] ,
                           (int) row[1] ,
                         (char *) row[2] ,
                         (char *) row[3] ,
                         (char *) row[4] );
			
			
		//}
		
		  mysql_free_result(result);
		
		return account;


}


const char * convertTimeToStr( time_t temp ) {
	
	char s[100];
     int rc;
     time_t y;
     struct tm *timeptr;

     temp = time(NULL);
     timeptr = localtime(&temp);
	 rc = strftime(s,sizeof(s),"Today is %A, %b %d.\nTime:  %r", timeptr);
	 
	 return  s;
}

Account *accountCreate(MYSQL *con,, char *name,
                       char *email, char *username, char *password)
{
	
	int rc;
    Account *account = NULL;
	
	 char query[1024];
	 
	  char *escapedName  = bsEscape(name);
    char *escapedEmail = bsEscape(email);
	 
	 sprintf( query , "INSERT INTO accounts(createdAt, name, email, username, password) values ( %s, %s , %s, %s,%s)  " , convertTimeToStr( time(NULL)),     escapedName , escapedEmail , username, password  )
	
	 if (mysql_query(con, query)) { 
	 
	 finish_with_error(con);
	 
	 
	 }
	 
	 account  = accountGetByEmail(con, email);
	 return account ;
}


Account *accountGetByEmail(MYSQL *con, char *email){
	
	 if (!email) return NULL;

    Account *account = NULL;
	
	
	char query[1024];
	 
	 sprintf( query , "SELECT id, createdAt, name, email, username FROM cars WHERE email =%s" , email);

if (mysql_query(con, query))
{

   finish_with_error(con);
}	
// MYSQL_RES *res;
  // MYSQL_ROW row;
   
     //MYSQL_ROW row = mysql_fetch_row(con);
	 
	    //while ((row = mysql_fetch_row(res)) != NULL){
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


			
			account = accountNew(   (int) row[0] ,
                           (int) row[1] ,
                         (char *) row[2] ,
                         (char *) row[3] ,
                         (char *) row[4] );
			
			
		//}
		
		return account;

	
	
}

Account *accountGetBySId(MYSQL *con,, char *sid){
	
	 if (!sid) return NULL;

    Session *session = sessionGetBySId(con, sid);
    if (!session) return NULL;
	
	
	
	 Account *account = NULL;
	 
	 char query[1024];
	 
	 sprintf( query , "SELECT id, createdAt, name, email, username FROM accounts WHERE id=%d" , id);

if (mysql_query(con, query))
{

   finish_with_error(con);
}	
 //MYSQL_RES *res;
  // MYSQL_ROW row;
   
   //  MYSQL_ROW row = mysql_fetch_row(con);
	 
	    //while ((row = mysql_fetch_row(res)) != NULL){
			
			
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


			
			account = accountNew(   (int) row[0] ,
                           (int) row[1] ,
                         (char *) row[2] ,
                         (char *) row[3] ,
                         (char *) row[4] );
			
			
		//}
		
		return account;

	
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
ListCell *accountSearch(MYSQL *con, char *query, int page)
{
	
	 int rc;
    Account *account = NULL;
    ListCell *accounts = NULL;
	
	char queryql[2048] =      "SELECT id, createdAt, name, email, username FROM accounts WHERE name     LIKE '%' || %s || '%'    OR email    LIKE '%' || %s || '%'   OR username LIKE '%' || %s || '%' ORDER BY createdAt DESC LIMIT 10 OFFSET %s";
	char data[2048] =;
		 sprintf( data , "SELECT id,createdAt, email, username ,name FROM accounts WHERE name  LIKE  '%%%s%%' OR email  LIKE   '%%%s%%'  OR username LIKE  '%%%s%%' ORDER BY createdAt  DESC LIMIT 10 OFFSET %d;" , query,query,query,page);
		 
		 if (mysql_query(con, query)){
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
    
account = accountNew(   (int) row[0] ,
                           (int) row[1] ,
                         (char *) row[2] ,
                         (char *) row[3] ,
                         (char *) row[4] );
			
      
  }
        accounts = listCons(account, sizeof(Account), accounts);
		
  mysql_free_result(result);
  
  return accounts;
	
}


bool accountCheckUsername(MYSQL *con, char *username){
	
	 if (!username) return false;


	
	
	char query[1024];
	 
	 sprintf( query , "SELECT id FROM accounts WHERE username =%s" , username);
	 
	 
	 
	 if (mysql_query(con,query)){
		 
		 return false;
	 }
	 
	 return true;
	
}

bool accountCheckEmail(MYSQL *con, char *email) {
	
	if (!username) return false;


	
	
	char query[1024];
	 
	 sprintf( query , "SELECT id FROM accounts WHERE username =%s" , username);
	 
	 
	 
	 if (mysql_query(con,query)){
		 
		 return false;
	 }
	 
	 return true;
}
void accountDel(Account *account)
{
    bsDel(account->name);
    bsDel(account->email);
    bsDel(account->username);
    free(account);
}