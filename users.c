#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<mysql.h>
#define PORT 3306


int  coo (  MYSQL *con,const char *host , const char *usr, const char * pswd , const char *dbname )
{
	
	
	  if (con == NULL)
  {
      fprintf(stderr, "%s\n", mysql_error(con));
	  return 0;
      exit(1);
  }

  if (mysql_real_connect(con, host,usr,pswd,
          dbname, 0, NULL, 0) == NULL)
  {
      fprintf(stderr, "%s\n", mysql_error(con));
      mysql_close(con);
	  return 0;
      exit(1);
  }

 if (mysql_query(con, "CREATE TABLE cars(id INT PRIMARY KEY AUTO_INCREMENT, name VARCHAR(255), price INT)")) {
   return    finish_with_error(con);
  }

if (mysql_query(con, "INSERT INTO cars VALUES(1,'Audi',52642)")) {
    return   finish_with_error(con);
  }

  if (mysql_query(con, "INSERT INTO cars VALUES(2,'Mercedes',57127)")) {
   return    finish_with_error(con);
  }

  if (mysql_query(con, "INSERT INTO cars VALUES(3,'Skoda',9000)")) {
      finish_with_error(con);
  }

  if (mysql_query(con, "INSERT INTO cars VALUES(4,'Volvo',29000)")) {
   return    finish_with_error(con);
  }

  if (mysql_query(con, "INSERT INTO cars VALUES(5,'Bentley',350000)")) {
      return finish_with_error(con);
  }

  if (mysql_query(con, "INSERT INTO cars VALUES(6,'Citroen',21000)")) {
      return finish_with_error(con);
  }

  if (mysql_query(con, "INSERT INTO cars VALUES(7,'Hummer',41400)")) {
    return   finish_with_error(con);
  }

  if (mysql_query(con, "INSERT INTO cars VALUES(8,'Volkswagen',21600)")) {
      return finish_with_error(con);
  }


	
}

void showCars(  MYSQL *con,const char *host , const char *usr, const char * pswd , const char *dbname ){
	

  if (con == NULL)
  {
      fprintf(stderr, "mysql_init() failed\n");
      exit(1);
  }

  if (mysql_real_connect(con, host,usr,pswd,
        dbname, 0, NULL, 0) == NULL)
  {
      finish_with_error(con);
  }

  if (mysql_query(con, "SELECT * FROM cars"))
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

int main(int argc , const char *argv[] ) 
{
	MYSQL *con = mysql_init(NULL);
	
	coo(con,"127.0.0.1","root","","godb");
	
	  mysql_close(con);
}