
  
#ifndef MODELS_POST_H
#define MODELS_POST_H

#include <mysql.h>

#include "list.h"

#define MAX_BODY_LEN 65536

typedef struct Post {
    int id;
    int createdAt;
    int authorId;

    char *body;
} Post;

Post     *postNew(int, int, int, char *);
Post     *postCreate(MYSQL * , int, char *);
Post     *postGetById(MYSQL * , int);
ListCell *postGetLatest(MYSQL * , int, int);
ListCell *postGetLatestGraph(MYSQL * , int, int);
void      postDel(Post *);

#endif