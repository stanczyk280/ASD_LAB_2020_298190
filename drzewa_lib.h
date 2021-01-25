#ifndef DRZEWA_LIB
#define DRZEWA_LIB
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define LEN 8
typedef struct el_drzewa_bin
{
	char klucz[LEN];
	struct el_drzewa_bin* lewy;
	struct el_drzewa_bin* prawy;
	struct el_drzewa_bin* rodzic;
}el_drzewa_bin;

typedef el_drzewa_bin* drzewo_bin;

// ZADANIE 14
void _dBinDrukuj2D(drzewo_bin d, int dist);
void dBinDrukuj2D(drzewo_bin d);
void _dBinDrukuj(drzewo_bin d, int level);
void dBinUsunCale(drzewo_bin* d);
void dBinDrukuj(drzewo_bin d);
void dBinDodaj(drzewo_bin* d, drzewo_bin rodzic, const char* klucz);
void dBinUsun(drzewo_bin* d, char* klucz);
drzewo_bin* dBinSzukaj(drzewo_bin* d, char* klucz);
drzewo_bin* dBinMin(drzewo_bin* d);
drzewo_bin* dBinMax(drzewo_bin* d);
drzewo_bin* dBinPoprzednik(drzewo_bin* d);
drzewo_bin* dBinNastepnik(drzewo_bin* d);

// ZADANIE 15
drzewo_bin dBinWczytaj(FILE* file);
void dBinZapisz(FILE* file, drzewo_bin d);
// ZADANIE 16
/*
najpierw minimum, potem po nastepnikach porownywac
*/
int d_bin_te_same_wartosci(drzewo_bin* D, drzewo_bin* T);
#endif // !DRZEWA_LIB