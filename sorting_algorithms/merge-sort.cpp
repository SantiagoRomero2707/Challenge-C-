#include <iostream>
using namespace std;


void sorted(int tamanio, int arreglo[]){
    for(int i = 0 ; i<tamanio;i++){
        if(arreglo[i] > arreglo[i+1]){
            int aux = arreglo[i];
            arreglo[i] = arreglo[i+1];
            arreglo[i+1] = aux;
        }
    }
}

void merge(int tamanio, int arreglo[], int tamanioMerge, int arregloMerge[]){

    int arregloNuevo[tamanio];

    for(int i = 0; i <tamanio;i++){
        if(arreglo[i] == arregloMerge[i]){
            arregloNuevo[i] = arregloMerge[i];
        }else{
            arregloNuevo[i] = arreglo[i];
        }
    }

    for(int k = 0; k < tamanio; k++){
        cout << arreglo[k] << " ";
    }

}

void recursividad(int tamanioOriginal, int arregloOriginal []){
    
    int mitad = tamanioOriginal/2;

    int arrayLeft[mitad], arrayRight[mitad];
    int auxMitad = mitad;
    while(auxMitad >2){
        int arregloAuxLeft [auxMitad];
        int arregloAuxRight [auxMitad];
        recursividad(auxMitad, arregloAuxLeft);
        recursividad(auxMitad, arregloAuxRight);

        if(auxMitad == 2){
            merge(mitad, arrayLeft, auxMitad, arregloAuxLeft);
            merge(mitad, arrayRight, auxMitad, arregloAuxRight);
        }        
    }

}

int main(){
    int tamanioOriginal = 10; 
    int arraySorted [tamanioOriginal] = {64,33,21,21,10,54,12,6,90,1};

    return 0;
}

