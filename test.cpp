#include "leptjson.h"
#include <cstdio>

int PassCnt,TotCnt,main_ret;

void Check(int type){
    TotCnt++;
    if(type == LEPT_PARSE_OK)
        PassCnt++;
    else{
        printf("Expect %d But %d\n", LEPT_PARSE_OK, type);
        main_ret = 1;
    }
}

void test_lept_null(){
    lept_value v;
    v.type = LEPT_NULL;
    char ch[10];
    ch[0] = 'n',ch[1] = 'u',ch[2] = 'l',ch[3] = 'l';
    Check(lept_parse(&v, ch));
}

void test_lept_true(){
    lept_value v;
    v.type = LEPT_NULL;
    char ch[10];
    ch[0] = 't',ch[1] = 'r',ch[2] = 'u',ch[3] = 'e';
    Check(lept_parse(&v, ch));
}

void test_lept_false(){
    lept_value v;
    v.type = LEPT_NULL;
    char ch[10];
    ch[0] = 'f',ch[1] = 'a',ch[2] = 'l',ch[3] = 's',ch[4] = 'e';
    Check(lept_parse(&v, ch));
}

void test_lept_parse(){
    test_lept_null();
    test_lept_true();
    test_lept_false();
}

int main(){
    freopen("test_outcome.out", "w", stdout);
    test_lept_parse();
    printf("%d/%d passed",PassCnt,TotCnt);
    fclose(stdout);
    return main_ret;
}
