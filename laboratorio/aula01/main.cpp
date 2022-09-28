#include <iostream>
#include "fibonacci.h"

using namespace std;

int main() {
    int num;
    Fibonacci fib;

    cout << "Digite um numero: "; cin >> num;
    fib.setFibonacci(num);

    cout << "Fibonacci de " << num << " = " << fib.getFibonacci() << endl;
    return 0;
}
