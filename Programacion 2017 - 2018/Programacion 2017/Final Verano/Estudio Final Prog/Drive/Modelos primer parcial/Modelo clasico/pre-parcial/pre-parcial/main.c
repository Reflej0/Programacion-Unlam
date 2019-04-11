#include ".h"

int main()
{
    /*char s1[40]="la vida es bella es esto caos total es",
         s2[10]="es";

    s2Ens1("un castillo de arena", "astill");
    validarCuenta("33-7");
    fflush(stdin);
    sacarS2deS1(s1,s2);
    printf("%s\n",s1);*/

    FILE* arch,
        * mas1000,
        * menos1000,
        *errores;
    t_dato infoarch[7]={{"1122-7",'d',1000},
                        {"1111-4",'d',1000},
                        {"1111-4",'e',1000},
                        {"1111-4",'d',200},
                        {"9999-9",'d',1000},
                        {"9999-9",'d',1000},
                        {"1111-7",'d',1000}},
           reg,
           aux;
    float saldo;
    t_lista lista;

    arch=fopen("ArchivoMaestro.bin","wb");
    if(!arch)
        return 1;
    fwrite(infoarch,sizeof(t_dato),7,arch);
    fclose(arch);

    /// /// /// /// /// /// /// /// /// /// ///

    arch=fopen("ArchivoMaestro.bin","rb");

    if(!arch)
        return 1;

    errores=fopen("errores.txt","wt");
    if(!errores)
    {
        fclose(arch);
        return 1;
    }

    mas1000=fopen("MasDeMil.txt","wt");
    if(!mas1000)
    {
        fclose(arch);
        fclose(errores);
        return 1;
    }

    menos1000=fopen("MenosDeMil.txt","wt");
    if(!menos1000)
    {
        fclose(mas1000);
        fclose(arch);
        fclose(errores);
        return 1;
    }

    crearLista(&lista);
    fread(&reg,sizeof(t_dato),1,arch);

    while(!feof(arch))
    {
        aux=reg;
        if(!CuentaValida(reg.ncuenta))
        {
            while(!feof(arch) && cmpNom(&aux,&reg)==0)
            {
                fprintf(errores,"%s|%c|%4.2f\n",reg.ncuenta,reg.mov,reg.importe);
                fread(&reg,sizeof(t_dato),1,arch);
            }
        }
        else
        {
            saldo=0;
            while(!feof(arch) && cmpNom(&aux,&reg)==0)
            {
                if(reg.mov=='d')
                    saldo+=reg.importe;
                else
                    saldo-=reg.importe;

                if(!listaLLena(&lista))
                    insertarEnListaOrdenado(&lista,&reg,cmp);
                fread(&reg,sizeof(t_dato),1,arch);
            }

            while(!listaVacia(&lista))
            {
                EliminarPrimerElemento(&lista,&aux);
                if(saldo<1000)
                    fprintf(menos1000,"%s|%c|%4.2f\n",aux.ncuenta,aux.mov,aux.importe);
                else
                    fprintf(mas1000,"%s|%c|%4.2f\n",aux.ncuenta,aux.mov,aux.importe);
            }
        }
    }

    fclose(mas1000);
    fclose(arch);
    fclose(menos1000);
    fclose(errores);
    return 0;

}
