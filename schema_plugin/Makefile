
info:
	$(CC) -c info.c -I../../redis/deps/hiredis/
	$(CC) -std=c99 -Wall -W -lm -pthread -g -ggdb -o redis_info info.o ../../redis/deps/hiredis/libhiredis.a

plugin:
	g++ -DMYSQL_DYNAMIC_PLUGIN -I/usr/local/mysql/include -I/Users/gtarcea/BZR/mysql-5.1/sql -bundle -fno-exceptions -o is_redis_table.dylib -Wall -W -lm -pthread -g -ggdb -I../../redis/deps/hiredis/ is_redis_table.cc ../../redis/deps/hiredis/libhiredis.a
