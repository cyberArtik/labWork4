#include <stdio.h>
#include <string.h>



void baseTask() {
    char input[100];
    int is_space(char c) {
    return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}
    printf("Enter a string to select first and last letter of every word: ");
    fgets(input, sizeof(input), stdin);

    int word_start = 0;
    int i = 0;

    while (input[i] != '\0') {
        if (is_space(input[i])) {
            if (i > word_start) {
                printf("First letter is %c and last letter is %c\n", input[word_start], input[i - 1]);
            }
            word_start = i + 1;
        }
        i++;
    }
}

int isRotation(const char *str1, const char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if (len1 != len2 || len1 == 0) {
        return 0;
    }

    char combined[2 * len1 + 1];
    strcpy(combined, str1);
    strcat(combined, str1);

    if (strstr(combined, str2) != NULL) {
        return 1;
    }

    return 0;
}

void rotation() {
    char str1[100];
    char str2[100];

    printf("The string #1: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0';

    printf("The rotation of string #2: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0';

    if (isRotation(str1, str2)) {
        printf("'%s' is a rotation of '%s'\n", str2, str1);
    } else {
        printf("'%s' is not a rotation of '%s'\n", str2, str1);
    }
}

void oppositeCase(char* str) {
    int ln = strlen(str);

    for (int i = 0; i < ln; i++) {
        if (str[i] >= 'a' && str[i] <= 'z'){
            str[i] = str[i] - 32;
        }
    }
}

void upperCase() {
    char input[1000];

    printf("Enter a sentence to be uppercased: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    oppositeCase(input);

    printf("Sentence with characters in opposite case: %s\n", input);
}

int countPunctuation(const char *sentence) {
    int punctuationCount = 0;
    const char *punctuationMarks = "!\"#$%&'()*+,-./:;?@[\\]^_`{|}~";

    for (int i = 0; sentence[i] != '\0'; i++) {
        if (strchr(punctuationMarks, sentence[i])) {
            punctuationCount++;
        }
    }

    return punctuationCount;
}

void punctuationCounter() {
    char sentence[1000];

    printf("Counter of punctuation marks in the sentence: ");
    fgets(sentence, sizeof(sentence), stdin);
    sentence[strcspn(sentence, "\n")] = '\0';

    int punctuationCount = countPunctuation(sentence);

	printf("Number of punctuation marks in the sentence is %d\n", punctuationCount);
}

int main() {

	baseTask();
	printf("-----------------------------------------\n");
	rotation();
	printf("-----------------------------------------\n");
	upperCase();
	printf("-----------------------------------------\n");
	punctuationCounter();
    printf("-----------------------------------------\n");
	return 0;
}
