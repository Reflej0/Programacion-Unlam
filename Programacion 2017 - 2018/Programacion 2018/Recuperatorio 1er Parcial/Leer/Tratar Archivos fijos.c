int leerArchivoYCargarLista(FILE *fp, t_lista *lista)
{
    int cantidad = 1;
    t_noved dato;
    fscanf(fp, "%6c%13f%10f%1d\n", dato.clave, &dato.canti, &dato.precio, &dato.nroReg);
    dato.clave[6] = '\0';
    while(!feof(fp))
    {
        if(dato.precio==0)
            dato.canti*=-1;
        /*printf("%s\n%f\n%f\n%d\n", dato.clave, dato.canti, dato.precio, dato.nroReg);
        system("PAUSE");*/
        insertarAlFinal(lista, &dato);
        fscanf(fp, "%6c%13f%10f%1d\n", dato.clave, &dato.canti, &dato.precio, &dato.nroReg);
        dato.clave[6] = '\0';
        cantidad++;
    }
    if(dato.precio==0)
            dato.canti*=-1;
    insertarAlFinal(lista, &dato);
    fscanf(fp, "%6c%9f%9f%d\n", dato.clave, &dato.canti, &dato.precio, &dato.nroReg);
    dato.clave[6] = '\0';
    return cantidad;
}

int leerArchivoYCargarLista(FILE *fp, t_lista *p)
{
    char linea[TAM+1], *aux;
    t_info nov;
    int cont=0;

    while (fgets(linea,TAM+1,fp)) //agarro una linea del archivo
    {
        cont++;
        aux=strrchr(linea,'\n'); //Manda direccion de memoria a ultima ocurrencia de \n
            if (aux == NULL)
            {
                fclose(fp);
                fprintf(stderr,"ERROR: No se encontro nada, che\n" ); //Esta recibiendo el NULL del fallo de fgets
                exit (1);
            }
        //char *aux=strrchr(linea,'\n');
        //char *aux=linea+TAMTOT;
        *aux='\0';
        //Reg
        aux-=1;
        sscanf(aux,"%d",&nov.nroReg);
        *aux='\0';
        //Prec
        aux-=10;
        sscanf(aux,"%f",&nov.precio);
        *aux='\0';
        //Cantidad
        aux-=13;
        sscanf(aux,"%f",&nov.canti);
        *aux='\0';
        //Clave                //Este es especial por ser chars
        aux-=6;
        strcpy(nov.clave,aux);
        *aux='\0';
        if(nov.precio==0)   //Si el precio es 0, es un pedido y debo almacenar como negativo
            nov.canti=0-nov.canti;
        /*printf("CLAVE:%s\n",nov.clave);
        printf("CANTIDAD:%f\n",-nov.canti);
        printf("PRECIO:%f\n",nov.precio);           //Para ver si anda esta garcha
        printf("NUM DE REGISTRO:%d\n",nov.nroReg);
        printf("\n");*/
        insertarAlFinal(p,&nov);    //agrega al final de la lista un nodo con info que acabo de parsear de archivo
        if(listaLlena(p))   //Si la lista esta llena (o sea, sin memoria) chau.
            exit(1);
    }

    return cont;
}