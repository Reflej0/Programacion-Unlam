using namespace std;
class Cadena
{
private:
    char* cad;
    Cadena(size_t l);
    static size_t _strlen(const char* cad);
    static char* _strcpy(char* dest, const char* src);
    static char* _strcat(char* dest, const char* src);
public:
    Cadena(const char* cad=""); ///REVISAR NULL.
    Cadena(const Cadena& otra);
    ~Cadena();
    Cadena& operator=(const char* cad);
    Cadena& operator=(const Cadena& otra);
    Cadena& operator+=(const char c);
    Cadena& operator+=(const char* cad);
    Cadena& operator+=(const Cadena& otra);
    Cadena operator+(const char c)const;
    Cadena operator+(const char* cad)const;
    Cadena operator+(Cadena& otra)const;
    friend ostream& operator<<(ostream&, const Cadena&);
    char* getCad()const;
};

char* operator+(char* primitivo, Cadena& obj);
