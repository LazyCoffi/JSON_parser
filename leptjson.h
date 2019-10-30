#ifndef LEPTJSON_H__
#define LEPTJSON_H__

typedef enum
{
    LEPT_NULL,
    LEPT_FALSE,
    LEPT_TRUE,
    LEPT_NUMBER,
    LEPT_OBJECT,
    LEPT_STRING
} lept_type;

class lept_value {
public:
    lept_type type;
};

enum
{
    LEPT_PARSE_OK = 0,
    LEPT_PARSE_EXPECT_VALUE,
    LEPT_PARSE_INVALID_VALUE,
    LEPT_PARSE_ROOT_NOT_SINGULAR
};

int lept_parse(lept_value *v, char *json);

lept_value get_lept_type(lept_value *v);

#endif