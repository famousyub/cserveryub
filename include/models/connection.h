#ifndef MODELS_CONNECTION_H
#define MODELS_CONNECTION_H

#include <mysql.h>

typedef struct Connection {
    int id;
    int createdAt;
    int account1Id;
    int account2Id;
} Connection;

Connection *connectionNew(int, int, int, int);
Connection *connectionCreate(MYSQL * ,int, int);
Connection *connectionGetByAccountIds(MYSQL *, int, int);
void        connectionDel(Connection *);

#endif