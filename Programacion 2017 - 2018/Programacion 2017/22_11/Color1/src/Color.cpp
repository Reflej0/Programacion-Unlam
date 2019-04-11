#include "Color.h"

Color::Color(){

    this->r = 0;
    this->g=0;
    this->b=0;
    strcpy(this->nombre,"");
}
Color::Color(int a,int b,int c,char*nom){

    this->r = a;
    this->g=b;
    this->b=c;
    strcpy(this->nombre,nom);
}

Color& Color::operator=(const Color&obj){

    this->r = obj.r;
    this->g=obj.g;
    this->b=obj.b;
    strcpy(this->nombre,obj.nombre);

    return *this;

}
Color Color::operator--(int){

    Color aux(*this);

    if(this->r == 0){
        this->r = 255;
    }else{
        this->r--;
    }

    if(this->g == 0){
        this->g = 255;
    }else{
        this->g--;
    }

    if(this->b == 0){
        this->b = 255;
    }else{
        this->b--;
    }

    return aux;


} //x--
Color Color::operator++(int){

    Color aux(*this);

    if(this->r == 255){
        this->r = 0;
    }else{
        this->r++;
    }

    if(this->g == 255){
        this->g = 0;
    }else{
        this->g++;
    }

    if(this->b == 255){
        this->b = 0;
    }else{
        this->b++;
    }

    return aux;

}//x++
Color& Color::operator++(){

    if(this->r == 255){
        this->r = 0;
    }else{
        this->r++;
    }

    if(this->g == 255){
        this->g = 0;
    }else{
        this->g++;
    }

    if(this->b == 255){
        this->b = 0;
    }else{
        this->b++;
    }

    return *this;

}//++x
void Color::CambiarColorNomb(char*nom){

    strcpy(this->nombre,nom);
}

ostream& operator<<(ostream&sal,Color&obj){

    sal<<"r: "<<obj.r<<" g: "<<obj.g<<" b: "<<obj.b<<" nombre: "<<obj.nombre<<endl;
}
