#include <iostream>

using namespace std;

/*This algorithm emulates the Eratostenes sieve to calculate n prime numbers in c++:D
    Coding by Ing. Santiago Romero V-1.0
*/

void nPrimeNumbers(int nNumbersCalculate){
    int countNumbersCalculated = 0; int primeNumberToCalculate = 2;

    while(countNumbersCalculated < nNumbersCalculate){

        bool isPrime = true;

        for(int i = 0; i < primeNumberToCalculate && isPrime; i++){
            if(primeNumberToCalculate % i == 0){
                isPrime = false;
                break;
            }
        }

        if(isPrime){
            cout << "This number is prime: " << primeNumberToCalculate << endl;
            countNumbersCalculated++;
        }

        primeNumberToCalculate++;
    }
}