#include <mysql_priv.h>
#include <sys/sysinfo.h>
#include <string.h>
#include "hiredis.h"

bool schema_table_store_record(THD *thd, TABLE *table);

static ST_FIELD_INFO sys_usage_fields[] =
{
  {"REDIS_INFO", 255, MYSQL_TYPE_STRING, 0, 0, 0, 0},
  {"VALUE", 20, MYSQL_TYPE_STRING, 0, 0, 0, 0},
  {0, 0, MYSQL_TYPE_NULL, 0, 0, 0, 0}
};

#define INSERT(NAME,VALUE)                            \
  table->field[0]->store(NAME, strlen(NAME), cs);   \
  table->field[1]->store(VALUE, strlen(VALUE), cs);                      \
  if (schema_table_store_record(thd, table))          \
    return 1;

int fill_sys_usage(THD *thd, TABLE_LIST *tables, COND *cond)
{
    CHARSET_INFO *cs= system_charset_info;
    TABLE *table= tables->table;
    char *colon;
    char *info, *word;
    char *other;
    char *sep = "\n";
    redisReply *reply;
    redisContext *context = redisConnect("127.0.0.1", 6379);
    if (context->err)
    {
        return 1;
    }

    reply = redisCommand(context, "INFO");
    info = strdup(reply->str);
    for (word = strtok(info, sep); word; word = strtok(NULL, sep))
    {
        colon = strchr(word, ':');
        if (colon)
        {
            *colon = 0;
            other = ++colon;
            INSERT(word, other);
        }
    }

  return 0;
}

int redis_usage_init(void *p)
{
  ST_SCHEMA_TABLE *schema= (ST_SCHEMA_TABLE*) p;
  schema->fields_info= sys_usage_fields;
  schema->fill_table= fill_sys_usage;
  return 0;
  }

struct st_mysql_information_schema is_redis_info =
{ MYSQL_INFORMATION_SCHEMA_INTERFACE_VERSION };

mysql_declare_plugin(is_redis_info)
{
  MYSQL_INFORMATION_SCHEMA_PLUGIN,
  &is_redis_info,
  "REDIS_INFO",
  "V. Glenn Tarcea (glenn.tarcea@gmail.com)",
  "Information about redis resource usage",
  PLUGIN_LICENSE_GPL,
  redis_usage_init,
  NULL,
  0x0010,
  NULL,
  NULL,
  NULL
}
mysql_declare_plugin_end;

