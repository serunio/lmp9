#include "gauss.h"
#include <stdlib.h>
#include <stdio.h>
#include "zamiana.h"

#include "zamiana.h"
/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b) {
    /**
  	 * Tutaj należy umieścić właściwą implemntację.
		 */

    int i = 0;
    int j = 0;
    int l = 0;
    double *wspolczynnik;
    //
    for (i = 0; i < mat->c - 1; i++) {
        zamiana(mat, b, i);
        int x = 0;
        wspolczynnik = malloc(sizeof(double) * (mat->r - 1 - i));
        for (j = i + 1; j < mat->r; j++) {

            wspolczynnik[x] = (mat->data[j][i]) / (mat->data[i][i]);
            if (wspolczynnik[x] == 0)
                return 1;

            for (l = i; l < mat->c; l++) {
                mat->data[j][l] = (mat->data[j][l]) - (mat->data[i][l] * wspolczynnik[x]);
            }
            b->data[j][0] = (b->data[j][0]) - (b->data[0][0] * wspolczynnik[x]);
            x++;
        }
        free(wspolczynnik);
    }
    return 0;
}

