#include <stdio.h>
#include <string.h>
#include <time.h> // Include the time.h header

int longestCommonSubsequence(char *X, char *Y, int m, int n) {
    int LCS[m + 1][n + 1];

    // Build the LCS array in a bottom-up manner
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                LCS[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                LCS[i][j] = 1 + LCS[i - 1][j - 1];
            else
                LCS[i][j] = (LCS[i - 1][j] > LCS[i][j - 1]) ? LCS[i - 1][j] : LCS[i][j - 1];
        }
    }

    int index = LCS[m][n]; // Length of the LCS
    char lcs[index + 1];
    lcs[index] = '\0'; // Null-terminate the LCS string

    // Reconstruct the LCS string
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs[index - 1] = X[i - 1];
            i--;
            j--;
            index--;
        } else if (LCS[i - 1][j] > LCS[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    // Print the LCS
    printf("Longest Common Subsequence: %s\n", lcs);
    
    return LCS[m][n];
}

// Function to calculate runtime
double run_time(clock_t start, clock_t end) {
    double ms = (double)(end - start);
    ms = ms / (double)CLOCKS_PER_SEC; // Use CLOCKS_PER_SEC instead of CLK_TCK
    return ms;
}

int main() {
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";
    int m = strlen(X);
    int n = strlen(Y);

    clock_t start = clock(); // Start the timer
    int length = longestCommonSubsequence(X, Y, m, n);
    clock_t end = clock(); // End the timer

    printf("Length of LCS: %d\n", length);
    
    double time_taken = run_time(start, end); // Calculate the runtime
    printf("Time taken: %lf seconds\n", time_taken);

    return 0;
}
