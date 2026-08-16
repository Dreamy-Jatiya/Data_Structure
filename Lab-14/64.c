//64. Vowel Anxiety Problem
/*Each time he encounters a vowel; he has to reverse the entire substring that 
came before the vowel. */

#include <stdio.h>
#include <string.h>
#define MAX 100000

int isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' ||
           c == 'o' || c == 'u';
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N;
        char S[MAX];
        char stack[MAX];
        int top = -1;

        scanf("%d", &N);
        scanf("%s", S);

        for (int i = 0; i < N; i++) {

            if (isVowel(S[i])) {

                // Reverse all characters before the vowel
                while (top >= 0) {
                    printf("%c", stack[top]);
                    top--;
                }

                // Print the vowel
                printf("%c", S[i]);
            }
            else {
                // Push consonants onto stack
                stack[++top] = S[i];
            }
        }

        // Print remaining characters
        while (top >= 0) {
            printf("%c", stack[top--]);
        }

        printf("\n");
    }

    return 0;
}
