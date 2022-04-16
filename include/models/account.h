#ifndef MODELS_ACCOUNT_H
#define MODELS_ACCOUNT_H

#include <stdio.h> 
#include <stdlib.h>
#include <mysql.h>
#include <stdbool.h>

include "list.h"

typedef struct Account {
    int id;
    int createdAt;

    char *name;
    char *email;
    char *username;
} Account;

Account  *accountNew(int, int, char *, char *, char *);
Account  *accountCreate(MYSQL *con, char *, char *, char *, char *);
Account  *accountGetById(MYSQL *con, int);
Account  *accountGetByEmail(MYSQL *con, char *);
Account  *accountGetBySId(MYSQL *con, char *);
ListCell *accountSearch(MYSQL *con, char *, int);
bool     accountCheckUsername(MYSQL *con, char *);
bool     accountCheckEmail(MYSQL *con, char *);
void     accountDel(Account *);

#endif