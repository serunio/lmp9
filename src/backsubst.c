 #include "backsubst.h"
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int  backsubst(Matrix *x, Matrix *mat, Matrix *b)
{
    if (!(mat->r == mat->c && mat->r == x->r && mat->r == b->r))
        return 2;

    for (int j = mat->r - 1; j >= 0; j--) {
        if (mat->data[j][j] == 0) return 1;
        x->data[j][0] = b->data[j][0];
        for (int i = j + 1; i <= mat->r - 1; i++) {
            x->data[j][0] -= mat->data[j][i] * x->data[i][0];
        }
        x->data[j][0] /= mat->data[j][j];
    }
    return 0;
}


