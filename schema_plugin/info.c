#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hiredis.h"

int main (int argc, char **argv)
{
    redisContext *context;
    redisReply *reply;

    context = redisConnect("127.0.0.1", 6379);
    if (context->err)
    {
        printf("Couldn't establish connection.\n");
        exit(1);
    }
    reply = redisCommand(context, "INFO");
    printf("reply->type %d\n", reply->type);
    printf("reply: %s\n", reply->str);
}
