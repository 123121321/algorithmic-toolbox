/* find the maximum product of 2 distinct numbers in a sequence of
   non-negative integers, input is formatted such that the first
   line contains an integer n, and the second line contains n
   non negative integers a_1, . . ., a_n, separated by spaces */

#include <stdio.h>
#include <stdlib.h>

int maxPairwiseProd(int *sequence, int numOfInts);
int *takeNInts(int N);

int main(){
    int *sequence = NULL;
    int nums = 0;
    int max = 0;
    scanf("%i", &nums);
    sequence = takeNInts(nums);
    max = maxPairwiseProd(sequence, nums);
    printf("maxPairwiseProd for the sequence input: %i\n", max);
    return 0;
}

// use the naive approach for first attempt.
// run through each product and compare to previous products
// to find maximum.
/* sequence: 1 5 9 2 1
 * 1 * 5 = 5, 1 * 9 > 5, 1 * 9 > 1 * 2, 1 * 9 > 1 * 1
 * then, having done all products involving the first number,
 * start with the second,
 * 5 * 9 = 45, 5 * 2 < 45, 5 * . . .,
 * and so on until you reach the (n - 1)th term in the sequence
 * and multiply it with the nth term, comparing to your previous max */
int maxPairwiseProd(int *sequence, int numOfInts){
    int hold=0;
    for (int i = 0; i<numOfInts-1; i++){
        for (int j = i+1; j<numOfInts; j++){
            if (sequence[i] * sequence[j] >= hold){
                hold = sequence[i] * sequence[j];
            }
        }
    }
    return hold;
}

int *takeNInts(int N){
    int *sequence = malloc(sizeof(int)*N);
    for (int i=0; i<N; i++){
        scanf("%i", &sequence[i]);
    }
    return sequence;
}
