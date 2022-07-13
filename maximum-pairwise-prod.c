/* find the maximum product of 2 distinct numbers in a sequence of
   non-negative integers, input is formatted such that the first
   line contains an integer n, and the second line contains n
   non negative integers a_1, . . ., a_n, separated by spaces */

// TO DO
// implement stress testing through random test generator,
// result comparison, loop that tests whether results differ,
// optimize mPwPrB further down from ~o(2n),
// find a way to see roughly how much memory and time is needed
// for each algorithm

#include <stdio.h>
#include <stdlib.h>

int maxPairwiseProd(int *sequence, int numOfInts);
int maxPairwiseProdBetter(int *sequence, int numOfInts);

int *takeNInts(int N);

int main(){
    int *sequence = NULL;
    int nums = 0;
    int max = 0;
    scanf("%i", &nums);
    sequence = takeNInts(nums);
    max = maxPairwiseProdBetter(sequence, nums);
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
 * and multiply it with the nth term, comparing to your previous max
 * runs roughly O(n^2) */
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

// we note that we can skip doing trial multiplication if we instead
// find the 2 biggest distinct integers within (sequence) and multiply
// them together. (thank you for pointing this obvious insight i
// missed, UCSD) runs roughly O(n)
int maxPairwiseProdBetter(int *sequence, int numOfInts){
    int maxInd1=0;
    int maxInd2=0;
    int hold = 0;
    // using a placeholder value to avoid the headache of edge sequences
    // like 2 1, 1 3 2, returning incorrect values
    // likely a way to avoid this temp variable but i think the
    // additional memory used is negligible
    for (int i=0; i<numOfInts; i++){
        if (hold < sequence[i]){
            hold = sequence[i];
            maxInd1 = i;
        }
    }
    hold = 0;
    for (int i=0; i<numOfInts; i++){
        if (hold < sequence[i] && hold <= sequence[maxInd1] 
                && i != maxInd1){
            hold = sequence[i];
            maxInd2 = i;
        }
    }
    printf("ind1, ind2: %i %i\n", maxInd1, maxInd2);
    return sequence[maxInd1] * sequence[maxInd2];
}
int *takeNInts(int N){
    int *sequence = malloc(sizeof(int)*N);
    for (int i=0; i<N; i++){
        scanf("%i", &sequence[i]);
    }
    return sequence;
}
