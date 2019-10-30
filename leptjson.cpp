#include "leptjson.h"
#include <assert.h>
#include <cstdlib>

void lept_parse_whitespace(char *s){
    while(*s == ' ' || *s == '\t' || *s == '\n' || *s == '\r')
        s ++;
}

bool lept_parse_root_singular(char *c){
    lept_parse_whitespace(c);
    if(*c != '\0')
        return false;
    return true;
}

int lept_parse_null(char *s,lept_value* v){
    char* c;
    assert(*s == 'n');
    s ++;
    if(s[0] != 'u' || s[1] != 'l' || s[2] != 'l')
        return LEPT_PARSE_INVALID_VALUE;
    s += 3,c = s;
    if(!lept_parse_root_singular(c))
        return LEPT_PARSE_ROOT_NOT_SINGULAR;
    v->type = LEPT_NULL;
    return LEPT_PARSE_OK;
}

int lept_parse_true(char *s,lept_value* v){
    char *c;
    assert(*s == 't');
    s ++;
    if(s[0] != 'r' || s[1] != 'u' || s[2] != 'e')
        return LEPT_PARSE_INVALID_VALUE;
    s += 3,c = s;
    if(!lept_parse_root_singular(c))
        return LEPT_PARSE_ROOT_NOT_SINGULAR;
    v->type = LEPT_TRUE;
    return LEPT_PARSE_OK;
}

int lept_parse_false(char *s,lept_value* v){
    char *c;
    assert(*s == 'f');
    s ++;
    if(s[0] != 'a' || s[1] != 'l' || s[2] != 's' || s[3] != 'e')
        return LEPT_PARSE_INVALID_VALUE;
    s += 4,c = s;
    if(!lept_parse_root_singular(c))
        return LEPT_PARSE_ROOT_NOT_SINGULAR;
    v->type = LEPT_FALSE;
    return LEPT_PARSE_OK;
}
int lept_parse_value(char *s, lept_value *v){
    switch(*s){
        case 'n' :
            return lept_parse_null(s, v);
        case 't' :
            return lept_parse_true(s, v);
        case 'f' :
            return lept_parse_false(s, v);
        case '\0' :
            return LEPT_PARSE_EXPECT_VALUE;
        default :
            return LEPT_PARSE_INVALID_VALUE;
    }
}

int lept_parse(lept_value *v,char* json){
    assert(v != NULL);
    char *s = json;
    v->type = LEPT_NULL;
    lept_parse_whitespace(s);
    return lept_parse_value(s,v);
}

lept_type lept_get_type(lept_value *v){
    assert(v != NULL);
    return v->type;
}
