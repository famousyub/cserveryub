#ifndef MODELS_LIKE_H
#define MODELS_LIKE_H


#include <stdbool.h>
#include <mysql.h>
typedef struct Like {
    int id;
    int createdAt;
    int accountId;
    int authorId;
    int postId;
} Like;

Like *likeNew(int, int, int, int, int);
Like *likeCreate(MYSQL * , int, int, int);
Like *likeDelete(MYSQL * , int, int, int);
bool  likeLiked(MYSQL * , int, int);
void  likeDel(Like *);

#endif