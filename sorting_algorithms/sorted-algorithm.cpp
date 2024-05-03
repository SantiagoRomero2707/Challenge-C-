#include <iostream>

/*  This code contains three (3) kids of algorithms for sorted arrays (NO vector list with lenght dynamic)
    the algorithms are: Burble Sort, Selection Sort and Insertion Sort.
    This is a first version so maybe in a few month update this code 

    NOTE: The functions are return void because C++ accept change in parameters of functions like reference so
    i change de value original of array and not a copy or value in the scope of the block of function 
    Regards :D Ing. Santiago Romero 
*/


void bubbleSort (int lenghtArray, int arraySorted[]){

    for(int i = 0; i < lenghtArray; i++){
        for(int j = 0; j < lenghtArray-1; j++){
            if(arraySorted[j] > arraySorted[j+1]){
                int aux = arraySorted[j];
                arraySorted[j] = arraySorted[j+1];
                arraySorted[j+1] = aux;
            }
        }
    }
    
}


void selectionSort( int lenghtArray, int arraySorted[]){

    for(int i = 0; i < lenghtArray; i++){
        int minNumber = arraySorted[i], int indexPosition = 0;
        for(int j = 0; j<lenghtArray;j++){
            if(arraySorted[j] < minNumber){
                minNumber = arraySorted[j]; 
                indexPosition = j;
            }
        }

        if(minNumber != arraySorted[i]){
            int aux = arraySorted[i];
            arraySorted[i] = minNumber;
            arraySorted[indexPosition] = arraySorted[i];
        }

    }

}

void insertionSort(int lenghtArray, int arraySorted[]){

    for(int i = 0; i < lenghtArray; i++){

        int nextPosition = i+1, beforePosition = 0;
        while(nextPosition>0){

            if(arraySorted[nextPosition]<arraySorted[i-beforePosition]){
	            int aux = arraySorted[i-beforePosition];
		        arraySorted[i-beforePosition] = arraySorted[nextPosition]; // 3
		        arraySorted[nextPosition] = aux;
            }

            nextPosition--;
            beforePosition++;
            
        }
    }

}

