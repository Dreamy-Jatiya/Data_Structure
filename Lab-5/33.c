/* 33. Design anagram game using array.  
    -> Allow a user to enter N words and store it in an array.  
    -> Generate a random number between 0 to N-1.  
    -> Based on the random number generated display the word stored at that 
       index of an array and allow user to enter its anagram.  
    -> Check whether the word entered by the user is an anagram of displayed 
       number or not and display an appropriate message.  
    -> Given a word A and word B. B is said to be an anagram of A if and only if the 
       characters present in B is same as characters present in A, irrespective of 
       their sequence. For ex: “LISTEN” == “SILENT”
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int isPresent(char ch, char *str) {
    for (int i = 0; i < strlen(str); i++) {
        if (ch == str[i]) {
            return 1;
        }
    }
    return 0;
}

void main() {
    int total_words;

    printf("Enter the number of words you want to play with: ");
    scanf("%d", &total_words);

    char words[total_words][20];

    for (int i = 0; i < total_words; i++) {
        printf("Enter word %d: ", i + 1);
        scanf("%s", words[i]);
    }

    int random_index = rand() % total_words;

    
    char user_word[20];
    printf("Enter its anagram: ");
    scanf("%s", user_word);
    
    int flag = 0;
    
    // Bug Fix 1: Check lengths are equal
    if (strlen(words[random_index]) != strlen(user_word)) {
        flag = 1;
    } else {
        // Bug Fix 2: Removed unnecessary inner j-loop
        for (int i = 0; i < strlen(words[random_index]); i++) {
            if (!isPresent(words[random_index][i], user_word)) {
                flag = 1;
                break;
            }
        }
    }
    
    printf("\nThe word to guess anagram for: %s\n", words[random_index]);  // show the word
    
    if (flag == 0) {
        printf("Congratulations! You entered an anagram of %s\n", words[random_index]);
    } else {
        printf("Sorry! You did not enter an anagram of %s\n", words[random_index]);
    }
}
