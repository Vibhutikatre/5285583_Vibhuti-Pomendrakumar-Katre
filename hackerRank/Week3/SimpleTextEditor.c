#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


#define MAXIMUM_LEN 1000000

typedef struct Node {
    char *state;
    struct Node *post;
} Node;

Node *stack = NULL;
void push(char *s) {
    Node *node2 = (Node *)malloc(sizeof(Node));
    node2->state = strdup(s);  
    node2->post = stack;
    stack = node2;
}

char* pop() {
    if (!stack) return "";
    Node *store = stack;
    char *topState = stack->state;
    stack = stack->post;
    free(store);
    return topState;
}

int main() {
    int Q;
    scanf("%d", &Q);

    char S[MAXIMUM_LEN+1] = "";  

    for (int i = 0; i < Q; i++) {
        int type;
        scanf("%d", &type);

        if (type == 1) {   
            char W[MAXIMUM_LEN+1];
            scanf("%s", W);
            push(S);  
            strcat(S, W);
        } 
        else if (type == 2) {  
            int k;
            scanf("%d", &k);
            push(S);  
            int len = strlen(S);
            S[len - k] = '\0';
        } 
        else if (type == 3) {  
            int k;
            scanf("%d", &k);
            printf("%c\n", S[k-1]);
        } 
        else if (type == 4) {  
            char *prior = pop();
            strcpy(S, prior);
            free(prior);
        }
    }

    return 0;
}