#ifdef __unix__
#include <stdio.h>
#endif

#include "PrintTypesAsASN1.h"

#ifdef __linux__
#include <pthread.h>

static pthread_mutex_t g_printing_mutex = PTHREAD_MUTEX_INITIALIZER;

#endif

void PrintASN1MyInteger(const char *paramName, const asn1SccMyInteger *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    //printf("%s MyInteger ::= ", paramName);
    printf("%s ", paramName);
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData));
    #else
    printf("%d", (*pData));
    #endif
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintASN1Counter(const char *paramName, const asn1SccCounter *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    //printf("%s Counter ::= ", paramName);
    printf("%s ", paramName);
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData));
    #else
    printf("%d", (*pData));
    #endif
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintASN1T_Int32(const char *paramName, const asn1SccT_Int32 *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    //printf("%s T-Int32 ::= ", paramName);
    printf("%s ", paramName);
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData));
    #else
    printf("%d", (*pData));
    #endif
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintASN1T_UInt32(const char *paramName, const asn1SccT_UInt32 *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    //printf("%s T-UInt32 ::= ", paramName);
    printf("%s ", paramName);
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData));
    #else
    printf("%d", (*pData));
    #endif
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintASN1T_Runtime_Error(const char *paramName, const asn1SccT_Runtime_Error *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    //printf("%s T-Runtime-Error ::= ", paramName);
    printf("%s ", paramName);
    if ((*pData).kind == T_Runtime_Error_noerror_PRESENT) {
        printf("noerror:");
        #if WORD_SIZE==8
        printf("%"PRId64, (*pData).u.noerror);
        #else
        printf("%d", (*pData).u.noerror);
        #endif
    }
    else if ((*pData).kind == T_Runtime_Error_encodeerror_PRESENT) {
        printf("encodeerror:");
        #if WORD_SIZE==8
        printf("%"PRId64, (*pData).u.encodeerror);
        #else
        printf("%d", (*pData).u.encodeerror);
        #endif
    }
    else if ((*pData).kind == T_Runtime_Error_decodeerror_PRESENT) {
        printf("decodeerror:");
        #if WORD_SIZE==8
        printf("%"PRId64, (*pData).u.decodeerror);
        #else
        printf("%d", (*pData).u.decodeerror);
        #endif
    }
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintASN1T_Int8(const char *paramName, const asn1SccT_Int8 *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    //printf("%s T-Int8 ::= ", paramName);
    printf("%s ", paramName);
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData));
    #else
    printf("%d", (*pData));
    #endif
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintASN1T_UInt8(const char *paramName, const asn1SccT_UInt8 *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    //printf("%s T-UInt8 ::= ", paramName);
    printf("%s ", paramName);
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData));
    #else
    printf("%d", (*pData));
    #endif
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintASN1T_Boolean(const char *paramName, const asn1SccT_Boolean *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    //printf("%s T-Boolean ::= ", paramName);
    printf("%s ", paramName);
    printf("%s", (int)(*pData)?"TRUE":"FALSE");
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintASN1T_Null_Record(const char *paramName, const asn1SccT_Null_Record *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    //printf("%s T-Null-Record ::= ", paramName);
    printf("%s ", paramName);
    printf("{");
    printf("}");
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintASN1PID_Range(const char *paramName, const asn1SccPID_Range *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    //printf("%s PID-Range ::= ", paramName);
    printf("%s ", paramName);
    #if WORD_SIZE==8
    printf("%"PRId64, (*pData));
    #else
    printf("%d", (*pData));
    #endif
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

void PrintASN1PID(const char *paramName, const asn1SccPID *pData)
{
    (void)paramName;
    (void)pData;
#ifdef __linux__
    pthread_mutex_lock(&g_printing_mutex);
#endif
#ifdef __unix__
    //printf("%s PID ::= ", paramName);
    printf("%s ", paramName);
    switch((*pData)) {
    case 0:
        printf("activationlog");
        break;
    case 1:
        printf("boothelper00f");
        break;
    case 2:
        printf("brokerlock00g");
        break;
    case 3:
        printf("brokertest002a");
        break;
    case 4:
        printf("deathreport00c");
        break;
    case 5:
        printf("escapertest002b");
        break;
    case 6:
        printf("function-1");
        break;
    case 7:
        printf("function-10");
        break;
    case 8:
        printf("function-11");
        break;
    case 9:
        printf("function-12");
        break;
    case 10:
        printf("function-13");
        break;
    case 11:
        printf("function-14");
        break;
    case 12:
        printf("function-15");
        break;
    case 13:
        printf("function-16");
        break;
    case 14:
        printf("function-17");
        break;
    case 15:
        printf("function-18");
        break;
    case 16:
        printf("function-19");
        break;
    case 17:
        printf("function-2");
        break;
    case 18:
        printf("function-20");
        break;
    case 19:
        printf("function-21");
        break;
    case 20:
        printf("function-22");
        break;
    case 21:
        printf("function-23");
        break;
    case 22:
        printf("function-24");
        break;
    case 23:
        printf("function-3");
        break;
    case 24:
        printf("function-4");
        break;
    case 25:
        printf("function-5");
        break;
    case 26:
        printf("function-6");
        break;
    case 27:
        printf("function-7");
        break;
    case 28:
        printf("function-8");
        break;
    case 29:
        printf("function-9");
        break;
    case 30:
        printf("hal00d");
        break;
    case 31:
        printf("mqueuecallback12");
        break;
    case 32:
        printf("monitorcallback");
        break;
    case 33:
        printf("monitoring00a");
        break;
    case 34:
        printf("paketizer002c");
        break;
    case 35:
        printf("prot00if");
        break;
    case 36:
        printf("prot05ifin");
        break;
    case 37:
        printf("prot05ifout");
        break;
    case 38:
        printf("rcvacn01");
        break;
    case 39:
        printf("rcvacn02");
        break;
    case 40:
        printf("rcvacn03");
        break;
    case 41:
        printf("rcvacn04");
        break;
    case 42:
        printf("receiver001");
        break;
    case 43:
        printf("receiver011");
        break;
    case 44:
        printf("receiver012");
        break;
    case 45:
        printf("receiver013");
        break;
    case 46:
        printf("receiver014");
        break;
    case 47:
        printf("receiver015");
        break;
    case 48:
        printf("receiver016");
        break;
    case 49:
        printf("receiver017");
        break;
    case 50:
        printf("receiver018");
        break;
    case 51:
        printf("receiver019");
        break;
    case 52:
        printf("receiver020");
        break;
    case 53:
        printf("samrh71core00h");
        break;
    case 54:
        printf("sendacn");
        break;
    case 55:
        printf("sender001");
        break;
    case 56:
        printf("sender002");
        break;
    case 57:
        printf("sender003");
        break;
    case 58:
        printf("sender004");
        break;
    case 59:
        printf("sender005");
        break;
    case 60:
        printf("sender006");
        break;
    case 61:
        printf("sender007");
        break;
    case 62:
        printf("sender008");
        break;
    case 63:
        printf("sender009");
        break;
    case 64:
        printf("sender010");
        break;
    case 65:
        printf("sender011");
        break;
    case 66:
        printf("testcyclic05");
        break;
    case 67:
        printf("testmodules");
        break;
    case 68:
        printf("testprotected");
        break;
    case 69:
        printf("testsdl08");
        break;
    case 70:
        printf("testsdl14");
        break;
    case 71:
        printf("testspcc");
        break;
    case 72:
        printf("testsendcomms09");
        break;
    case 73:
        printf("teststart00");
        break;
    case 74:
        printf("testunprot00");
        break;
    case 75:
        printf("testunprotin05");
        break;
    case 76:
        printf("testunprotout05");
        break;
    case 77:
        printf("testunprotected");
        break;
    case 78:
        printf("threads00e");
        break;
    case 79:
        printf("uartotherend");
        break;
    case 80:
        printf("partition-1-timer-manager");
        break;
    case 81:
        printf("rcvacn05");
        break;
    case 82:
        printf("env");
        break;
    default:
        printf("Invalid value in ENUMERATED ((*pData))");
    }
#endif
#ifdef __linux__
    pthread_mutex_unlock(&g_printing_mutex);
#endif
}

