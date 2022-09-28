#include "fibonacci.h"

void Fibonacci::setFibonacci(int idx) {
    resultado = computeFibonacci(idx);
}

int Fibonacci::getFibonacci() { return resultado; }

int Fibonacci::computeFibonacci(int idx) {
    if (idx == 0)
        return 0;
    else if (idx == 1)
        return 1;
    else
        return computeFibonacci(idx - 1) + computeFibonacci(idx - 2);
}
