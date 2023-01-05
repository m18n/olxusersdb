#include"stdio.h"
#include"stdlib.h"
#include"olxdb.h"
int main(){
    printf("HELLO SERVER START BD\n");
    sv_server_t serv;
    sv_ServerInit(&serv,9997,10);
    InitREQPack(&serv);
    sv_ServerStart(&serv,sizeof(dbclient_t),CreateDBClient,ClearDBClient);
    // colum_t c[3];
    // c[0].mod=INTELECT;
    // strcpy(c[0].name,"id");
    // c[0].size=4;
    // c[0].type_colum=INT;

    // c[1].mod=NONE;
    // strcpy(c[1].name,"name_table");
    // c[1].size=150;
    // c[1].type_colum=STATIC_TEXT;

    // c[2].mod=NONE;
    // strcpy(c[2].name,"mod_table");
    // c[2].size=4;
    // c[2].type_colum=INT;
    // table_createtable("data_table",c,3);
    //table_open("data_table");
    return 0;
}