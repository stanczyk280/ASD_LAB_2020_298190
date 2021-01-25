#ifndef LISTY_LIB
#define LISTY_LIB
typedef struct elem
{
	int x;
	struct elem* nast;
} el;

typedef el* wel;

// POMOCNICZE
int rand_int(unsigned int min, unsigned int max);

// ZADANIE 1
int usunP(wel*);
int usunO(wel*);
void druk(wel, wel*);
void dodajP(wel*, int);
void dodajO(wel*, int);
void dodajPrzed(wel*, int);
void dodajZa(wel*, int);
void usunWsk(wel*);
void usunListe(wel* l);
void wczytaj(wel* l);
void zapisz(wel l);
wel* znajdz(wel*, int);
wel recursiveReverse(wel l);

// ZADANIE 2
void usunWszystkie(wel* l, int y);
wel usunWszystkieRek(wel l, int y);

// ZADANIE 3
int wyznaczMode(wel l);
void usunMode(wel* l);

// ZADANIE 4
void usunWszystkieNP(wel* l, int y);

// ZADANIE 5
wel recursiveReverse(wel l);

// ZADANIE 6
void dodajSort(wel* l, int y);
int pierwszySort(wel l);
int ostatniSort(wel l);
void wczytajSort(wel* l);

void dodajSortWartownik(wel* l, int y);
int ostatniSortWartownik(wel l);
void wczytajSortWartownik(wel* l);

// ZADANIE 7
void polaczUp(wel* p, wel* q);

// ZADANIE 9

// lista dwukierunkowa
typedef struct _el2
{
	int x;
	struct _el2* popr;
	struct _el2* nast;
}el2d;
typedef el2d* wel2d;

int usunP2(wel2d*);
int usunO2(wel2d*);
void druk2(wel2d, wel2d*);
void dodajP2(wel2d*, int);
void dodajO2(wel2d*, int);
void dodajPrzed2(wel2d*, int);
void dodajZa2(wel2d*, int);
void usunWsk2(wel2d*);
void usunListe2(wel2d* l);
void wczytaj2(wel2d* l);
void zapisz2(wel2d l);
wel2d* znajdz2(wel2d*, int);
// lista dwukierunkowa posortowana rosnoca
void dodajSort2(wel2d* l, int y);
int pierwszySort2(wel2d l);
int ostatniSort2(wel2d l);
void wczytajSort2(wel2d* l);

void dodajSortWartownik2(wel2d* l, int y);
int ostatniSortWartownik2(wel2d l);
void wczytajSortWartownik2(wel2d* l);

// ZADANIE 10

// JEDNOKIERUNKOWA
typedef struct _elc
{
	int x;
	struct _elc* nast;
} elc;

typedef elc* welc;

void dodajCP(welc*, int);
void dodajCO(welc*, int);
int usunCO(welc* p);
int usunCP(welc* p);
void usunListeC(welc* l);
void drukC(welc l);
welc* znajdzC(welc* p, int y);
void dodajPrzedC(welc* p, int y);
void dodajZaC(welc* p, int y);
void usunWskC(welc* p);
void zapiszC(welc l);
void wczytajC(welc* l);

// DWUKIERUNKOWA
typedef struct _elc2
{
	int x;
	struct _elc2* nast;
	struct _elc2* popr;
} elc2;

typedef elc2* welc2;

void dodajCP2(welc2*, int);
void dodajCO2(welc2*, int);
int usunCO2(welc2* p);
int usunCP2(welc2* p);
void usunListeC2(welc2* l);
void drukC2(welc2 p);
welc2* znajdzC2(welc2* p, int y);
void dodajPrzedC2(welc2* p, int y);
void dodajZaC2(welc2* p, int y);
void usunWskC2(welc2* p);
void zapiszC2(welc2 l);
void wczytajC2(welc2* l);

// ZADANIE 12

void usunPowtorzeniaC(welc* p, welc q);
#endif // !LISTY_LIB