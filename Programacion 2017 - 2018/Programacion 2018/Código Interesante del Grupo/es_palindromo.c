#define TAM 30
#define MI_TOLOWER(C) (((C)>='A'&&(C)<='Z')?(C)+('a'-'A'):(C))
int  es_palindromo (const char * s1)
{
    char *pIni=(char*)s1,*pFin=pIni; 

    while (*pFin)
        pFin++;
    pFin--;
    while(pIni<pFin&&MI_TOLOWER(*pIni)==MI_TOLOWER(*pFin))
    {
        pIni++;
        pFin--;
        if(*pIni==' ')
            pIni++;
        if(*pFin==' ')
            pFin--;
    }
    return(pIni<pFin)?0:1;
}