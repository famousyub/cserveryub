#include <stdio.h> 
#include <stdlib.h>
#include <mysql.h>


MYSQL	*conn;

void process_result_set (MYSQL *conn, MYSQL_RES *res_set){
  MYSQL_FIELD		*field;
  MYSQL_ROW		row;
  unsigned int	i, col_len;
  
  while ((row = mysql_fetch_row (res_set)) != NULL){
    mysql_field_seek (res_set, 0);
    
    for (i = 0; i < mysql_num_fields (res_set); i++){
      field = mysql_fetch_field (res_set);
      printf (" %s |",row[i]);
    }
    printf("\n");
  }
  printf ("%lu rows returned\n", (unsigned long) mysql_num_rows (res_set));
}


int process_query (MYSQL *conn, char *query){

  MYSQL_RES *res_set;
  unsigned int field_count;
  
  if (mysql_query (conn, query) != 0){
    printf("process_query() failed");
    return -1;
  }
  
  res_set = mysql_store_result (conn);
  if (res_set != NULL){
    process_result_set (conn, res_set);
    mysql_free_result (res_set);
    return 0;
  }

  return -1;
}


int main (int argc, char *argv[]){
  char *host_name = "127.0.0.1";
  char *user_name = "root";
  char *password  = "";
  unsigned int port_num = 0;
  char *socket_name = NULL;
  char *db_name = "godb";
  int flags = 0;
  int i;

  for(i=0;i<100;i++){
  conn = mysql_init (NULL);
  
  if (mysql_real_connect (conn,host_name,user_name,password,db_name,port_num,socket_name,flags) == NULL){
    printf("mysql_real_connect() failed");
    return -1;
  }   
  
  process_query (conn,argv[1]);
  
  mysql_close (conn); 
  }
  return 0;
}

 
 
 /*
 
 CC = gcc 
INCLUDES = -I/usr/include/mysql -I. 
LIBS = -L/usr/local/lib/mysql -lmysqlclient -lm
 
    
PROG = main

OBJS = $(PROG).o 

all:: $(PROG) 
 
.c.o: $(CC) -c $(INCLUDES) $<

$(PROG).o: 

$(PROG): $(OBJS) $(CC) -o $@ $(OBJS) $(LIBS) 

clean:: rm -f $(PROG) $(OBJS) 
 */