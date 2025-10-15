#include <iostream>
#include <iomanip>
using namespace std;
double E_promedio(int *energias)
{
    double suma = 0;
    while (*energias != '\0')
    {
        suma = suma + *energias;
        energias++;
    }
    return suma;
}
void e_diferencias(double *diferencias, int *energias, int *n)
{
    int k = 1;
    for (int i = 0; i < *n; i++)
    {
        if (i == 0 || i == *n - 1)
        {
        }
        else
        {
            *(diferencias + k) = (*(energias + (i + 1)) - *(energias + (i - 1))) / 2.0;
            k++;
        }
    }
}
void imprimir(int *energias, int *n, double *diferencias)
{
    {
        cout << left << setw(8) << "Indice" << setw(12) << "E_original" << setw(12) << "D_centrada" << endl;
        e_diferencias(diferencias, energias, n);
        for (int i = 0; i < *n; i++)
        {
            if (i == 0 || i == *n - 1)
            {
                cout << left << setw(8) << i;
                cout << fixed << setw(12) << *(energias + i) << setprecision(3);
                cout << setw(12) << "--" << setprecision(3) << endl;
            }
            else
            {
                cout << left << setw(8) << i;
                cout << fixed << setw(12) << *(energias + i) << setprecision(3);
                cout << setw(12) << *(diferencias + (i)) << setprecision(3) << endl;
            }
        }
    }
}
int main()
{
    int const maximo = 10;
    int cantidad = 5;
    int energias[maximo] = {2, 5, 3, 7, 6};
    double diferencias[maximo] = {};
    e_diferencias(diferencias, energias, &cantidad);
    imprimir(energias, &cantidad, diferencias);
    cout << "Promedio de energía= " << E_promedio(energias);
    return 0;
}