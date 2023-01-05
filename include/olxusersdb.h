#pragma once
#include"server.h"
#define STATUS_OK 102
#define STATUS_NOT_AUTH 101
typedef struct dbclient{
    sv_user_t client;
    bool auth;
}dbclient_t;
void CreateDBClient(dbclient_t* db);
void ClearDBClient(dbclient_t* db);
typedef struct RES_status{
    sv_packres_t pack;
    int code;
}RES_status_t;
void CreateRES_status(RES_status_t* status);
sv_json_construct_t RES_status_getjson(RES_status_t* pk);
typedef struct REQ_auth{
    sv_packreq_t pack;
    char authcode[200];
}REQ_auth_t;
void CreateREQ_auth(REQ_auth_t* auth);
bool REQ_auth_jsontoobject(REQ_auth_t* auth,json_value* values);
void REQ_auth_process(REQ_auth_t* auth,sv_user_t* user);

bool CheckAuth(sv_user_t* user,sv_packreq_t* pkreq);

typedef struct REQ_checkauthclient{
    sv_packreq_t pack;
    char name[100];
    char password[20];
}REQ_checkauthclient_t;
void CreateREQ_checkauthclient(REQ_checkauthclient_t* setdb);
bool REQ_checkauthclient_jsontoobject(REQ_checkauthclient_t* authclient,json_value* values);
void REQ_checkauthclient_process(REQ_checkauthclient_t* setdb,sv_user_t* user);
void InitREQPack(sv_server_t* server);