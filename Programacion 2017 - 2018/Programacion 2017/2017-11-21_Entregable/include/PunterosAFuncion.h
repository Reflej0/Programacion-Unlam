#ifndef PUNTEROSAFUNCION_H
#define PUNTEROSAFUNCION_H


typedef int (*t_cmp)(const void*, const void*);
typedef void (*t_accion)(void* info, void* datos_accion);
typedef int (*t_condicion)(void* info);
typedef void (*t_actualizar)(void* actualizado, const void* actualizador);


#endif // PUNTEROSAFUNCION_H
