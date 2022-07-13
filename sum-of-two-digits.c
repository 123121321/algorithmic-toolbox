#include <stdio.h>

// assignment 1 of this course is to take 2 digits from stdin
// and output their sum to stdout as an exercise in problem
// solving

int sumTwoDigits(int a, int b);

int main(){
    int a, b;

    scanf("%i", &a);
    scanf("%i", &b);
    printf("%i\n", sumTwoDigits(a, b));
}

int sumTwoDigits(int a, int b){
    return (a + b);
}
