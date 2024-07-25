

// code 2
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PROD 10
#define MAX_LEN 20

typedef struct {
    char lhs;
    char rhs[MAX_LEN];
} Production;

Production productions[MAX_PROD];
int num_productions;

void compute_first(char variable);
void compute_follow(char variable);

void add_production(char lhs, const char* rhs) {
    if (num_productions < MAX_PROD) {
        productions[num_productions].lhs = lhs;
        strcpy(productions[num_productions].rhs, rhs);
        num_productions++;
    }
    else {
        printf("Maximum number of productions exceeded.\n");
    }
}

void display_first(char variable) {
    printf("FIRST(%c): ", variable);
    compute_first(variable);
}

void display_follow(char variable) {
    printf("FOLLOW(%c): ", variable);
    compute_follow(variable);
}

int is_terminal(char symbol) {
    return islower(symbol) || symbol == '$';
}

int is_non_terminal(char symbol) {
    return isupper(symbol);
}

int contains_epsilon(char* str) {
    return (strcmp(str, "#") == 0);
}

void compute_first(char variable) {
    int i;
    for (i = 0; i < num_productions; i++) {
        if (productions[i].lhs == variable) {
            if (is_terminal(productions[i].rhs[0])) {
                printf("%c ", productions[i].rhs[0]);
            }
            else if (is_non_terminal(productions[i].rhs[0])) {
                compute_first(productions[i].rhs[0]);
            }
        }
    }
}

void compute_follow(char variable) {
    int i, j;
    char* temp;


    char follow_sets[26] = { 0 };


    if (variable == 'S') {
        follow_sets['S' - 'A'] = '$';
    }

    for (i = 0; i < num_productions; i++) {
        for (j = 0; productions[i].rhs[j] != '\0'; j++) {
            if (productions[i].rhs[j] == variable) {
                if (productions[i].rhs[j + 1] == '\0' || is_terminal(productions[i].rhs[j + 1])) {
                    temp = strchr(productions[i].rhs, variable);
                    if (temp - productions[i].rhs != j) {
                        int index = productions[i].lhs - 'A';
                        follow_sets[index] = productions[i].rhs[j + 1];
                    }
                }
                else {
                    int index = productions[i].rhs[j + 1] - 'A';
                    follow_sets[index] = productions[i].rhs[j + 1];
                }
            }
        }
    }

    for (i = 0; i < 26; i++) {
        if (follow_sets[i] != 0) {
            printf("%c ", follow_sets[i]);
        }
    }
    printf("\n");
}

int main() {
    char lhs;
    char rhs[MAX_LEN];

    num_productions = 0;

    printf("Enter the productions (Enter '0' to stop):\n");
    while (1) {
        printf("Enter lhs: ");
        scanf(" %c", &lhs);
        if (lhs == '0') break;
        printf("Enter rhs: ");
        scanf("%s", rhs);
        add_production(lhs, rhs);
    }

    // Display FIRST sets
    printf("\nFIRST sets:\n");
    for (char c = 'A'; c <= 'Z'; c++) {
        if (is_non_terminal(c)) {
            display_first(c);
            printf("\n");
        }
    }

    // Display FOLLOW sets
    printf("\nFOLLOW sets:\n");
    for (char c = 'A'; c <= 'Z'; c++) {
        if (is_non_terminal(c)) {
            display_follow(c);
            printf("\n");
        }
    }

    return 0;
}
