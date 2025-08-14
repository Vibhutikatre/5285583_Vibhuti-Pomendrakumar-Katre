#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    char s[10001], t[10001];
    scanf("%s", s);
    scanf("%s", t);
    
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == t[i]) {
            putchar('0');
        } else {
            putchar('1');
        }
    }
    putchar('\n');

    return 0;
}
