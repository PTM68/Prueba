#include <iostream>
#include <stdio.h>
#include <vector>
#include "VarDataRef.h"
using namespace std;
VarDataRef * myVDRef[MAXNUMVARDATAREFS];//={NULL};
vector<VarDataRef > v;
vector<VarDataRef *> vp;
int iteraciones = 3;

int main () {
    printf("Cambio tonto para ver que pasa\n");
    VarDataRef myVDRef_aux2 ;
    int xx;
    for (xx=0;xx<iteraciones;xx++) {
          
          
        myVDRef[xx] = new VarDataRef(xx);


        printf("xx: %i Direccion del puntero: %p de la instancia: %p \n",xx,&myVDRef[xx], myVDRef[xx]);
        // Cuando se usa un puntero a la instancia de clase se usa -> para acceder al interior
        myVDRef[xx]->set_value (100+xx);
        myVDRef[xx]->print_values();
 //       myVDRef_aux2 = *myVDRef[xx];
 //       myVDRef_aux2.print_values();
 //       v.push_back(myVDRef_aux2) ;     
          v.push_back(*myVDRef[xx]) ;   
          vp.push_back(myVDRef[xx]);
    printf("Explicitamente la posicion 0\n");
          printf("Direccion del puntero: %p de la instancia: %p \n",&myVDRef[0], myVDRef[0]);
        myVDRef[0]->print_values();
      printf("Via vector...................\n");
        v[xx].print_values();
      printf("Via vector de punteros.......\n");
        vp[xx]->print_values();
    }

  
    printf(".......A ver si hemos hecho algo................\n");

  
    for (xx=0;xx<iteraciones;xx++) {
         
        printf("Direccion del puntero: %p de la instancia: %p \n",&myVDRef[xx], myVDRef[xx]);
        myVDRef[xx]->print_values();
    }
    
    
  
    printf(".......Jugando con los punteros................\n");
    int pointer_len = sizeof(VarDataRef *);
    int object_len = sizeof(VarDataRef);
    printf("pointer size: %i,  object size: %i\n", pointer_len, object_len);
    
    VarDataRef **puntero_aux;   // Un puntero a punteros VarDataRef es "de facto" 
    //un alias del array de punteros si lo inicializamos al objeto apuntado por la fila 0 del array

    VarDataRef myVDRef_aux ;
    puntero_aux =  &myVDRef[0];
    

    
    
    for (xx=0;xx<iteraciones;xx++) {
      printf("Direccion del puntero: %p de la instancia myVDRef[%i]: %p \n",puntero_aux, xx, *puntero_aux);
      myVDRef_aux = **puntero_aux;
      printf("Size of object instance: %i\n",sizeof(myVDRef_aux));
        
      // La diferencia es que no podemos acceder "al interior" 
      // del objeto via doble indireccion,
      // necesitamos una variable auxiliar para representar al objeto direccionado
      myVDRef_aux.print_values();  // Cuando se usa una variable para la instancia de 
                                   // clase se usa punto para acceder al interior
      puntero_aux++;  // incrementar el puntero a punteros es como incrementar el
                      // indice del array 
    }   
    
    
// vVDRefInt[]
        
    printf(".......Con el array global externo................\n");
    for (xx=0;xx<iteraciones;xx++) {
         printf("en Main.cpp: xx: %i",xx);
    printf(" address stored: %p \n",vVDRefInt[xx]);
       myVDRef_aux = *vVDRefInt[xx];
       myVDRef_aux.print_values();
      printf("Via vector...................\n");
        v[xx].print_values();
      printf("Via vector de punteros.......\n");
        vp[xx]->print_values();     
    } 




  

  return 0;
}
