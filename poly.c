#include <stdio.h>

struct poly
{
    int coeff;
    int expo;
};

int main()
{
    struct poly x1[20], x2[20], x3[40];
    int m, n;
    int i = 0, j = 0, k = 0;

    printf("enter the number of terms in first polynomial: ");
    scanf("%d", &m);
    printf("enter exponent and coefficient\n");
    for (i = 0; i < m; i++)
    {
        scanf("%d %d", &x1[i].coeff, &x1[i].expo);
    }

    printf("enter the number of terms in second polynomial: ");
    scanf("%d", &n);
    printf("enter exponent and coefficient\n");
    for (j = 0; j < n; j++)
    {
        scanf("%d %d", &x2[j].coeff, &x2[j].expo);
    }

    i = 0;
    j = 0;
    k = 0;

    while (i < m && j < n)
    {
        if (x1[i].expo == x2[j].expo)
        {
            x3[k].coeff = x1[i].coeff + x2[j].coeff;
            x3[k].expo = x1[i].expo;
            i = i + 1;
            j = j + 1;
            k = k + 1;
        }
        else if (x1[i].expo > x2[j].expo)
        {
            x3[k].coeff = x1[i].coeff;
            x3[k].expo = x1[i].expo;
            i = i + 1;
            k = k + 1;
        }
        else
        {
            x3[k].coeff = x2[j].coeff;
            x3[k].expo = x2[j].expo;
            j = j + 1;
            k = k + 1;
        }
    }

    while (i < m)
    {
        x3[k].coeff = x1[i].coeff;
        x3[k].expo = x1[i].expo;
        i = i + 1;
        k = k + 1;
    }

    while (j < n)
    {
        x3[k].coeff = x2[j].coeff;
        x3[k].expo = x2[j].expo;
        j = j + 1;
        k = k + 1;
    }

    printf("resultant polynomial is:\n");
    for (i = 0; i < k; i++)
    {
        printf("%d", x3[i].coeff);
        if (x3[i].expo != 0)
        {
            printf("x^%d", x3[i].expo);
        }
        if (i < k - 1)
        {
            printf("+");
        }
    }

    printf("\n");
    return 0;
}

