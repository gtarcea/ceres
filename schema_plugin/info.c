#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hiredis.h"

int main (int argc, char **argv)
{
    char *sep = "\n";
    char *colon;
    char *eol;
    char *word;
    char *info;
    char *c;
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
    info = strdup(reply->str);
    for (word = strtok(info, sep); word; word = strtok(NULL, sep))
    {
        colon = strchr(word, ':');
        if (colon)
        {
            *colon = 0;
            printf("%s : %s\n", word, ++colon);
        }
    }
}
