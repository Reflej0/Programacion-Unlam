#include <stdio.h>
#include <stdlib.h>

int main()
{
    ///---------------TEXTO------------------------
    //FILE* arch_txt_w = fopen("arch.txt", "wt");
    //FILE* arch_txt_a = fopen("arch.txt", "rt");
    //LECTURA VARIABLE.
    FILE* arch_txt_r = fopen("arch.txt", "rt");
    char line[100];
    while(fgets(line, 100, arch_txt_r))
    {
        printf("%s\n", line);
    }
    fclose(arch_txt_r);
    ///-------------------------------------------
}
