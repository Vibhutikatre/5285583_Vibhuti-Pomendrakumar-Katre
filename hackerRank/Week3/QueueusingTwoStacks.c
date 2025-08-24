#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


/* Enter your code here. Read input from STDIN. Print output to STDOUT */ 

#define HIGH 100000

long first_Stack[HIGH], sec_Stack[HIGH];
int top_1 = -1, top_2 = -1;

void push_1(long x) { first_Stack[++top_1] = x; }
long pop1() { return first_Stack[top_1--]; }
int empty1() { return top_1 == -1; }

void push2(long x) { sec_Stack[++top_2] = x; }
long pop2() { return sec_Stack[top_2--]; }
int empty2() { return top_2 == -1; }

int main() {
    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 1) {
            long val; scanf("%ld", &val);
            push_1(val);
        } 
        else if (type == 2) {
            if (empty2()) {
                while (!empty1()) push2(pop1());
            }
            if (!empty2()) pop2();
        } 
        else {
            if (empty2()) {
                while (!empty1()) push2(pop1());
            }
            if (!empty2()) printf("%ld\n", sec_Stack[top_2]);
        }
    }
    return 0;
}