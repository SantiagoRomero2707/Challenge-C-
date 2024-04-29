#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

string randomSymbol(){

    int randomIndices = rand() % 2 ;

    string arraySimbols[2] = {"O","X"};

    string symbolChoice = arraySimbols[randomIndices];

    return symbolChoice;
}

int randomNumber(int low, int high){
     return (low + rand() % (high - low + 1));
}

void replaceLines(string majorArrangement[], int lengthGreater, string minorArrangement[], int shortestLength){

    int aux = 0;

    for(int i = 0; i<lengthGreater;i++){

        if(minorArrangement[aux] == "O"){
            aux++;
        }
        else{
            majorArrangement[i] = minorArrangement[aux];
            aux++;
        }

        if(aux == shortestLength){
            aux = 0;
        }
    }
}

int countPattern(string majorArrangement[], int lengthGreater, string minorArrangement[], int shortestLength){

    int aux = 0, countPattern=0;

    for(int i =0; i < lengthGreater;i++){
        if(aux == shortestLength-1){
            if(majorArrangement[i]==minorArrangement[aux]){
                countPattern++;
            }
            aux = 0;
        }else{
            aux++;
        }
    }

    return countPattern;
}

void reflectionImage(int rowsArrayBidimensionalBigger, int columnsArrayBidimensionalBigger, int rowsArrayBidimensionalSmall, int columnsArrayBidimensionalSmall){

    string arrayImageSmall[rowsArrayBidimensionalSmall][columnsArrayBidimensionalSmall];

    for(int i = 0; i < rowsArrayBidimensionalSmall; i++){
        for (int j =0; j<columnsArrayBidimensionalSmall; j++){
            string symbol = randomSymbol();
            arrayImageSmall[i][j] = symbol;
        }
    }

    string arrayReflectionLarge[rowsArrayBidimensionalBigger][columnsArrayBidimensionalBigger];

    cout << "Matriz para poder evaluar cuantas veces se puede ser replicada el patron: " <<endl;

    for(int i = 0; i < rowsArrayBidimensionalBigger; i++){
        for(int j = 0; j < columnsArrayBidimensionalBigger; j++){
            arrayReflectionLarge[i][j] = "O";
            cout << setw(2) << arrayReflectionLarge[i][j];
        }
        cout << endl;
    }

    int aux = 0, totalTimes = 0;
    for(int i = 0; i < rowsArrayBidimensionalBigger; i++){
        replaceLines(arrayReflectionLarge[i], columnsArrayBidimensionalBigger, arrayImageSmall[aux], columnsArrayBidimensionalSmall);
        aux++;

        if(aux == rowsArrayBidimensionalSmall){
            totalTimes = totalTimes + countPattern(arrayReflectionLarge[i], columnsArrayBidimensionalBigger, arrayImageSmall[aux-1], columnsArrayBidimensionalSmall);
            aux = 0;
        }
    }

    cout << endl << "Patron a replicar: " << endl;

    for(int i = 0; i<rowsArrayBidimensionalSmall;i++){
        for(int j = 0; j<columnsArrayBidimensionalSmall;j++){
            cout << setw(2) << arrayImageSmall[i][j];
        }
        cout << endl;
    }

    cout << endl << "Result: " << endl;

    for(int i =0; i< rowsArrayBidimensionalBigger;i++){

        cout << setw(2) << left << (i+1) <<":";

        for(int j = 0; j<columnsArrayBidimensionalBigger; j++){
            cout << setw(2) << arrayReflectionLarge[i][j];
        }
        cout << endl;
    }

    cout << endl << "Se puede replicar " << totalTimes << " veces" <<endl;
}

int main()
{
    srand(time(NULL));
    reflectionImage(randomNumber(20,30),randomNumber(10,30),randomNumber(3,4),randomNumber(3,4));
    return 0;
}
