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
        printf("function-10");
        break;
    case 1:
        printf("function-100");
        break;
    case 2:
        printf("function-101");
        break;
    case 3:
        printf("function-102");
        break;
    case 4:
        printf("function-103");
        break;
    case 5:
        printf("function-104");
        break;
    case 6:
        printf("function-106");
        break;
    case 7:
        printf("function-107");
        break;
    case 8:
        printf("function-108");
        break;
    case 9:
        printf("function-109");
        break;
    case 10:
        printf("function-11");
        break;
    case 11:
        printf("function-110");
        break;
    case 12:
        printf("function-111");
        break;
    case 13:
        printf("function-112");
        break;
    case 14:
        printf("function-113");
        break;
    case 15:
        printf("function-115");
        break;
    case 16:
        printf("function-116");
        break;
    case 17:
        printf("function-117");
        break;
    case 18:
        printf("function-118");
        break;
    case 19:
        printf("function-119");
        break;
    case 20:
        printf("function-12");
        break;
    case 21:
        printf("function-120");
        break;
    case 22:
        printf("function-121");
        break;
    case 23:
        printf("function-122");
        break;
    case 24:
        printf("function-124");
        break;
    case 25:
        printf("function-125");
        break;
    case 26:
        printf("function-126");
        break;
    case 27:
        printf("function-127");
        break;
    case 28:
        printf("function-128");
        break;
    case 29:
        printf("function-129");
        break;
    case 30:
        printf("function-13");
        break;
    case 31:
        printf("function-130");
        break;
    case 32:
        printf("function-131");
        break;
    case 33:
        printf("function-132");
        break;
    case 34:
        printf("function-14");
        break;
    case 35:
        printf("function-15");
        break;
    case 36:
        printf("function-16");
        break;
    case 37:
        printf("function-17");
        break;
    case 38:
        printf("function-18");
        break;
    case 39:
        printf("function-19");
        break;
    case 40:
        printf("function-2");
        break;
    case 41:
        printf("function-20");
        break;
    case 42:
        printf("function-21");
        break;
    case 43:
        printf("function-22");
        break;
    case 44:
        printf("function-23");
        break;
    case 45:
        printf("function-24");
        break;
    case 46:
        printf("function-25");
        break;
    case 47:
        printf("function-26");
        break;
    case 48:
        printf("function-27");
        break;
    case 49:
        printf("function-28");
        break;
    case 50:
        printf("function-29");
        break;
    case 51:
        printf("function-3");
        break;
    case 52:
        printf("function-30");
        break;
    case 53:
        printf("function-31");
        break;
    case 54:
        printf("function-32");
        break;
    case 55:
        printf("function-33");
        break;
    case 56:
        printf("function-34");
        break;
    case 57:
        printf("function-35");
        break;
    case 58:
        printf("function-36");
        break;
    case 59:
        printf("function-37");
        break;
    case 60:
        printf("function-38");
        break;
    case 61:
        printf("function-39");
        break;
    case 62:
        printf("function-4");
        break;
    case 63:
        printf("function-40");
        break;
    case 64:
        printf("function-41");
        break;
    case 65:
        printf("function-42");
        break;
    case 66:
        printf("function-43");
        break;
    case 67:
        printf("function-44");
        break;
    case 68:
        printf("function-45");
        break;
    case 69:
        printf("function-46");
        break;
    case 70:
        printf("function-47");
        break;
    case 71:
        printf("function-48");
        break;
    case 72:
        printf("function-49");
        break;
    case 73:
        printf("function-5");
        break;
    case 74:
        printf("function-50");
        break;
    case 75:
        printf("function-51");
        break;
    case 76:
        printf("function-52");
        break;
    case 77:
        printf("function-53");
        break;
    case 78:
        printf("function-54");
        break;
    case 79:
        printf("function-55");
        break;
    case 80:
        printf("function-56");
        break;
    case 81:
        printf("function-57");
        break;
    case 82:
        printf("function-58");
        break;
    case 83:
        printf("function-59");
        break;
    case 84:
        printf("function-6");
        break;
    case 85:
        printf("function-60");
        break;
    case 86:
        printf("function-61");
        break;
    case 87:
        printf("function-62");
        break;
    case 88:
        printf("function-63");
        break;
    case 89:
        printf("function-64");
        break;
    case 90:
        printf("function-65");
        break;
    case 91:
        printf("function-66");
        break;
    case 92:
        printf("function-67");
        break;
    case 93:
        printf("function-68");
        break;
    case 94:
        printf("function-69");
        break;
    case 95:
        printf("function-7");
        break;
    case 96:
        printf("function-70");
        break;
    case 97:
        printf("function-71");
        break;
    case 98:
        printf("function-72");
        break;
    case 99:
        printf("function-73");
        break;
    case 100:
        printf("function-74");
        break;
    case 101:
        printf("function-75");
        break;
    case 102:
        printf("function-76");
        break;
    case 103:
        printf("function-77");
        break;
    case 104:
        printf("function-78");
        break;
    case 105:
        printf("function-79");
        break;
    case 106:
        printf("function-8");
        break;
    case 107:
        printf("function-80");
        break;
    case 108:
        printf("function-81");
        break;
    case 109:
        printf("function-82");
        break;
    case 110:
        printf("function-83");
        break;
    case 111:
        printf("function-84");
        break;
    case 112:
        printf("function-85");
        break;
    case 113:
        printf("function-86");
        break;
    case 114:
        printf("function-87");
        break;
    case 115:
        printf("function-88");
        break;
    case 116:
        printf("function-89");
        break;
    case 117:
        printf("function-9");
        break;
    case 118:
        printf("function-90");
        break;
    case 119:
        printf("function-91");
        break;
    case 120:
        printf("function-92");
        break;
    case 121:
        printf("function-93");
        break;
    case 122:
        printf("function-94");
        break;
    case 123:
        printf("function-95");
        break;
    case 124:
        printf("function-96");
        break;
    case 125:
        printf("function-97");
        break;
    case 126:
        printf("function-98");
        break;
    case 127:
        printf("function-99");
        break;
    case 128:
        printf("tf-reporter");
        break;
    case 129:
        printf("uartotherend");
        break;
    case 130:
        printf("testfunction");
        break;
    case 131:
        printf("triggerfunction");
        break;
    case 132:
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

