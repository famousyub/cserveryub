#ifndef MODELS_SESSION_H
#define MODELS_SESSION_H

#include <mysql.h>

typedef struct Session {
    int id;
    int createdAt;
    int accountId;

    char *sessionId;
} Session;

Session *sessionNew(int, int, int, char *);
Session *sessionGetBySId(MYSQL * , char *);
Session *sessionCreate(MYSQL * , char *, char *);
void     sessionDel(Session *);

#endif