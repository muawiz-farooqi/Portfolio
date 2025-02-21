#include <string.h>

int longestCommonSubsequence(char * text1, char * text2)
{
    int i, j;
    int x = strlen(text1) + 1;
    int y = strlen(text2) + 1;
    int** matrix = malloc(y * sizeof(int*));
    for (i = 0; i < y; i++)
    {
        matrix[i] = malloc(x * sizeof(int));
        matrix[i][0] = 0;
    }
    for (i = 0; i < x; i++)
    {
        matrix[0][i] = 0;
    }
    for (i = 1; i < y; i++)
    {
        for (j = 1; j < x; j++)
        {
            if (text1[j - 1] == text2[i - 1])
            {
                matrix[i][j] = matrix[i - 1][j - 1] + 1;
            } else if (matrix[i - 1][j] >= matrix[i][j - 1])
            {
                matrix[i][j] = matrix[i - 1][j];
            } else
            {
                matrix[i][j] = matrix[i][j - 1];
            }
        }
    }
    return matrix[y - 1][x - 1];
}