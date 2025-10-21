#include <iostream>
using namespace std;
const int maximo = 100;
int aux_id[maximo];
double aux_o2[maximo];
void merge(int *id, double *o2, int *inicio, int *medio, int *final)
{
    int izq = *inicio;
    int *pizq = &izq;
    int der = *medio;
    int *pder = &der;
    int k = *inicio;
    while (*pizq <= *medio && *pder <= *final)
    {
        if (*(id + *pizq) < *(id + *pder))
        {
            aux_id[k] = *(id + *pizq);
            aux_o2[k] = *(o2 + *pizq);
            (*pizq)++;
        }
        else
        {
            aux_id[k] = *(id + *pder);
            aux_o2[k] = *(o2 + *pder);
            (*pder)++;
        }
        k++;
    }
    while (*pizq <= *medio)
    {
        aux_id[k] = *(id + *pizq);
        aux_o2[k] = *(o2 + *pizq);
        (*pizq)++;
        k++;
    }
    while (*pder <= *final)
    {
        aux_id[k] = *(id + *pder);
        aux_o2[k] = *(o2 + *pder);
        (*pder)++;
        k++;
    }
}
void mergesort(int *id, double *o2, int *inicio, int *final)
{
    if (*inicio < *final)
    {
        int medio = (*inicio + *final) / 2;
        int *p1 = &medio;
        int medio2 = (*inicio + *final) / 2 + 1;
        int *p2 = &medio2;
        mergesort(id, o2, inicio, p1);
        mergesort(id, o2, p2, final);
        merge(id, o2, inicio, p1, final);
    }
}
int main()
{
    int id[maximo];
    double o2[maximo];
    return 0;
}