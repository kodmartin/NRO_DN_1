#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

using namespace std;

double izracunAtan(double* vrednost, int* steviloKorakov)
{
    double vsota = 0.0;

    for (int indeks = 0; indeks < *steviloKorakov; indeks++)
    {
        double clen = pow(-1, indeks) * pow(*vrednost, 2 * indeks + 1) / (2 * indeks + 1);
        vsota += clen;
    }

    return vsota;
}

double funkcija(double argument, int korakiAtan)
{
    double vhodAtan = argument / 2.0;
    return exp(3 * argument) * izracunAtan(&vhodAtan, &korakiAtan);
}

int main()
{
    double spodnjaMeja = 0.0;
    double zgornjaMeja = M_PI / 4.0;

    int steviloPodintervalov = 1000;
    int steviloClenov = 50;

    double korak = (zgornjaMeja - spodnjaMeja) / steviloPodintervalov;

    double akumulator = funkcija(spodnjaMeja, steviloClenov)
        + funkcija(zgornjaMeja, steviloClenov);

    for (int zaporedni = 1; zaporedni < steviloPodintervalov; zaporedni++)
    {
        double trenutnaTocka = spodnjaMeja + zaporedni * korak;
        akumulator += 2.0 * funkcija(trenutnaTocka, steviloClenov);
    }

    double priblizekIntegrala = (korak / 2.0) * akumulator;

    cout << "Priblizen rezultat: " << priblizekIntegrala << endl;

    return 0;
}