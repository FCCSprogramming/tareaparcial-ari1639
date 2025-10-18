#include <iostream>
#include <iomanip>
using namespace std;
void imprimir(double **m, int *n)
{
    for (int i = 0; i < *n; i++)
    {
        for (int j = 0; j < *n; j++)
        {
            cout << right << setw(5) << *(*(m + i) + j);
        }
        cout << endl;
    }
}
void transpuesta(double **m, int *n, double **mt)
{
    for (int i = 0; i < *n; i++)
    {
        for (int j = 0; j < *n; j++)
        {
            *(*(mt + i) + j) = *(*(m + j) + i);
        }
    }
}
int main()
{
    double fila1[3] = {1, 2, 3};
    double fila2[3] = {0, 1, 4};
    double fila3[3] = {2, 0, 1};
    double *matriz[3] = {fila1, fila2, fila3};
    double **p1 = matriz;
    double fila1_t[3] = {0};
    double fila2_t[3] = {0};
    double fila3_t[3] = {0};
    double *matriz_t[3] = {fila1_t, fila2_t, fila3_t};
    double **p2 = matriz_t;
    int n = 3;
    imprimir(p1, &n);
    cout << "Transpuesta: " << endl;
    transpuesta(p1, &n, p2);
    imprimir(p2, &n);
    return 0;
}