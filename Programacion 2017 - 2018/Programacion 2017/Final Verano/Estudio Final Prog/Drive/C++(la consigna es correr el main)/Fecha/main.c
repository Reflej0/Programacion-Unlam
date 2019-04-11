#include"fecha.h"

int main()
{
    t_fecha f1, fn;
    puts("Ingrese la fecha de formato DD/MM/AAAA");
    scanf("%d/%d/%d", &f1.d, &f1.m, &f1.a);
    if(esfechavalida(f1))
        puts("FECHA VALIDA");
    else
        puts("NO ES FECHA VALIDA");

    fn=incrementarundia(f1);
    printf("%d/%d/%d",fn.d,fn.m,fn.a);
    return 0;
}
