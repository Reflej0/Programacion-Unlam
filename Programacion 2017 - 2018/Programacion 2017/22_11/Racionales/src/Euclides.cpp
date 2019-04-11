#include "Euclides.h"

int euclides_mcd(int a,int b){

    if(a<0)a=-a;
    if(b<0)b=-b;

    while(a!=b && b!=0 && a!=0){

        if(a>b){
            a = a-b;
        }

        if(b>a){
            b = b-a;
        }
    }

    return a;
}
