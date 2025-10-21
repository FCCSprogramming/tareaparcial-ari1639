#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
// Ari-20250108H
void imprimir(double **m, int *n)
{
    for (int i = 0; i < *n; i++)
    {
        for (int j = 0; j < *n; j++)
        {
            cout << right << fixed << setprecision(2) << setw(8) << *(*(m + i) + j);
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
void traza_m(double **m, int *dimension, double *traza)
{
    for (int i = 0; i < *dimension; i++)
    {
        (*traza) += (*(*(m + i) + i));
    }
}
void multiplicar_matrices(double **m1, double **m2, double **m3, int *dimension)
{

    for (int j = 0; j < *dimension; j++)
    {
        for (int i = 0; i < *dimension; i++)
        {
            for (int k = 0; k < *dimension; k++)
            {
                *(*(m3 + i) + j) += (*(*(m1 + i) + k)) * (*(*(m2 + k) + j)) * 1.0;
            }
        }
    }
}
void E_normalizada(double **m, int *dimension, double *Energia)
{
    for (int i = 0; i < *dimension; i++)
    {
        for (int j = 0; j < *dimension; j++)
        {
            *Energia += pow(*(*(m + i) + j), 2);
        }
    }
    *Energia = *Energia / pow(*dimension, 2);
}
int main()
{
    // Matriz original
    double fila1[3] = {1, 2, 3};
    double fila2[3] = {0, 1, 4};
    double fila3[3] = {2, 0, 1};
    double *matriz[3] = {fila1, fila2, fila3};
    double **p1 = matriz;
    // Matriz transpuesta
    double fila1_t[3] = {0};
    double fila2_t[3] = {0};
    double fila3_t[3] = {0};
    double *matriz_t[3] = {fila1_t, fila2_t, fila3_t};
    double **p2 = matriz_t;
    // Matriz del producto
    double fila1p[3] = {0};
    double fila2p[3] = {0};
    double fila3p[3] = {0};
    double *matrizp[3] = {fila1p, fila2p, fila3p};
    double **p3 = matrizp;
    // Valores iniciales:
    int n = 3;
    double traza = 0;
    double energia = 0;
    int *N = &n;
    double *t = &traza;
    double *e = &energia;
    cout << "N: " << n << endl;
    cout << "Matriz A: " << endl;
    imprimir(p1, N);
    cout << "Transpuesta A^T: " << endl;
    transpuesta(p1, N, p2);
    imprimir(p2, N);
    multiplicar_matrices(p1, p2, p3, N);
    E_normalizada(p1, N, e);
    traza_m(p3, N, t);
    cout << "Matriz de Inercia I=A*A^T: " << endl;
    imprimir(p3, N);
    cout << "Traza (I)= " << *t << endl;
    cout << "Energia normalizada: " << *e;
    return 0;
}