#include <stdio.h>
#include <stdlib.h>

#define ROW 2
#define COL 4

void method_a(int m, int n, int (*ptr_arr)[n]);
void method_b(int m, int n, int *ptr_arr);
void method_c(int m, int n, int arr[][n]);

int main(int argc, char *argv[]) {

    int arr[ROW][COL];

    int i;
    int j;
    for(i = 0; i < ROW; i++) {
        for(j = 0; j < COL; j++) {
            arr[i][j] = j;
        }
    }

    printf("Original array:\n");
    for (i = 0; i < ROW; i++) {
        for(j = 0; j < COL; j++) {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }

    printf("\n\n");

    method_a(ROW, COL, (int *)arr[0]);

    printf("method_a() array:\n");
    for (i = 0; i < ROW; i++) {
        for(j = 0; j < COL; j++) {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }

    printf("\n\n");

    printf("method_b() array:\n");
    method_b(ROW, COL, (int *)arr);

    for (i = 0; i < ROW; i++) {
        for(j = 0; j < COL; j++) {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }

    printf("\n\n");

    method_c(ROW, COL, (int *)arr);

    printf("method_c() array:\n");
    for (i = 0; i < ROW; i++) {
        for(j = 0; j < COL; j++) {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }

    printf("\n\n");

    return EXIT_SUCCESS;
}

void method_a(int m, int n, int (*ptr_arr)[n])
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            ptr_arr[i][j] = j + 1;
        }
    }
}

void method_b(int m, int n, int *ptr_arr)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            /* We need to use pointer arithmetic when indexing. */
            *((ptr_arr + i * n) + j) = j + 2;
        }
    }
    /* The whole function could have also been defined a bit different by taking
     * the i index out of the pointer arithmetic. n alone will then provide our
     * correct offset to the right. This may be a bit easier to understand. Our
     * for-loop would then look like this:
     * for (i = 0; i < m; i++)
     * {
     *     for (j = 0; j < n; j++)
     *     {
     *         *((ptr_arr + n) + j) = j + 2;
     *     }
     *     ptr_arr++;
     * }*/
}

void method_c(int m, int n, int arr[][n])
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            arr[i][j] = j + 3;
        }
    }
}
