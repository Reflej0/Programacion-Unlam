#include<utilitarias.h>
#include<string.h>
#include<varias.h>

int cmp_dni(const t_info*i1,const t_info *i2)
{
    return i1->dni-i2->dni;
}

int agregar_materia(FILE * pf, t_arbol * a)
{
    t_info infoDni;
    int encontro;
    printf("Ingrese dni:");
    scanf("%d",&infoDni.dni);
    encontro=buscar_en_arbol_bin_busq(a,&infoDni,cmp_dni);
    if(!encontro)
        return NO_EXISTE;
    mostrarAlumno(&infoDni,pf);
    agregarMateria(&infoDni,pf);
    mostrarAlumno(&infoDni,pf);
    return TODO_OK;
}


void mostrarAlumno(t_info *i,FILE *pf)
{
    t_alumno alu;
    fseek(pf,i->nro_reg*sizeof(t_alumno),SEEK_SET);
    fread(&alu,sizeof(t_alumno),1,pf);
    printf("DNI:%d\nApellido y Nombre:%s\nMaterias:%d\tPromedio:%f\n\n",alu.dni,alu.apyn,alu.cant_materias,alu.promedio);
}

void agregarMateria(t_info*i,FILE *pf)
{
    float nota;
    t_alumno alu;
    printf("Ingrese la nueva nota:");
    scanf("%f",&nota);
    printf("\n");
    fseek(pf,i->nro_reg*sizeof(t_alumno),SEEK_SET);
    fread(&alu,sizeof(t_alumno),1,pf);
    alu.promedio=(alu.promedio*alu.cant_materias+nota)/(alu.cant_materias+1);
    alu.cant_materias++;
    fseek(pf,i->nro_reg*sizeof(t_alumno),SEEK_SET);
    fwrite(&alu,sizeof(t_alumno),1,pf);
}

