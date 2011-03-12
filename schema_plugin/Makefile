
info:
	$(CC) -c info.c -I../../redis/deps/hiredis/
	$(CC) -std=c99 -Wall -W -lm -pthread -g -ggdb -o redis_info info.o ../../redis/deps/hiredis/libhiredis.a

plugin:
	/usr/bin/c++   -DHAVE_CONFIG_H -DUNIV_MUST_NOT_INLINE -DHAVE_IB_GCC_ATOMIC_BUILTINS=1 -DHAVE_IB_ATOMIC_PTHREAD_T_GCC=1 -DSIZEOF_PTHREAD_T=8 -m64 -Wall -Wno-unused-parameter -fno-implicit-templates -fno-exceptions -fno-rtti -O -g -fno-common -felide-constructors -fno-strict-aliasing -DENABLED_DEBUG_SYNC -DUNIV_DEBUG -I/Users/gtarcea/source/mysql/mysql-5.5.9/include -I/Users/gtarcea/source/mysql/mysql-5.5.9/storage/innobase/include -I/Users/gtarcea/source/mysql/mysql-5.5.9/storage/innobase/handler -I/Users/gtarcea/source/mysql/mysql-5.5.9/sql -I/Users/gtarcea/source/mysql/mysql-5.5.9/regex -I/Users/gtarcea/source/mysql/mysql-5.5.9/extra/yassl/include -I/Users/gtarcea/source/mysql/mysql-5.5.9/extra/yassl/taocrypt/include -I/Users/gtarcea/source/mysql/mysql-5.5.9/zlib -I../../redis/deps/hiredis/ -o is_redis_table.o -c is_redis_table.cc
	/usr/bin/c++ is_redis_table.o ../../redis/deps/hiredis/libhiredis.a -bundle -Wl,-undefined -Wl,dynamic_lookup -fno-exceptions -o is_redis_table.dylib -Wall -W -lm -pthread -g -ggdb 
