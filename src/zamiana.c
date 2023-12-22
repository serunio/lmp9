#include "zamiana.h"
#include "mat_io.h"
#include <math.h>
#include <stdlib.h>

int zamiana(Matrix* A, Matrix* b, int column)
{
    double* tempA = malloc(A->c * sizeof(double));
    int i=column;
    int j;
    double max = fabs(A->data[column][column]);
    double tempb;
    for(j = column; j < A->r; j++)
    {
        if(fabs(A->data[j][column]) >= max)
        {
            max = fabs(A->data[j][column]);
            tempA = A->data[j];
            tempb = b->data[j][0];
            i = j;
        }
    }
    A->data[i] = A->data[0];
    b->data[i][0] = b->data[0][0];
    A->data[0] = tempA;
    b->data[0][0] = tempb;

    return 0;
}
