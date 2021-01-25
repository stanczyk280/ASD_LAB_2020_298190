#include <cstdio>
#include <cstdlib>
#include <ctime>
#include "listy_lib.h"

// POMOCNICZE
int rand_int(unsigned int min, unsigned int max)
{
	int tmp;
	time_t t;
	srand(static_cast<unsigned>(time(&t)));
	if (min > max)
	{
		tmp = min;
		min = max;
		max = tmp;
	}
	return rand() % max + min;
}

// ZADANIE 1
void druk(wel l, wel* aP)
{
	if (l)
	{
		while (l)
		{
			if (aP && l == *aP) printf("[");
			printf("%d", l->x);
			if (aP && l == *aP) printf("]");
			l = l->nast;
			if (l)
			{
				printf(" -> ");
			}
		}
		printf("|\n");
	}
	else
	{
		printf("Lista jest pusta.\n");
	}
}
void dodajP(wel* l, int y)
{
	wel q = static_cast<wel>(malloc(sizeof(el)));
	q->x = y;
	q->nast = *l;
	*l = q;
}
int usunP(wel* l)
{
	int y = 0;
	wel q = *l;
	if (*l)
	{
		y = (*l)->x;
		*l = (*l)->nast;
		free(q);
	}
	return y;
}
void dodajO(wel* l, int y)
{
	wel q = static_cast<wel>(malloc(sizeof(el)));
	q->x = y;
	q->nast = NULL;
	while (*l)
	{
		l = &((*l)->nast);
	}
	*l = q;
}
void usunListe(wel* l)
{
	wel p = *l, q;
	*l = 0;
	while (p)
	{
		q = p;
		p = p->nast;
		free(q);
	}
}
int usunO(wel* l)
{
	int y = 0;
	wel q;
	if (*l)
	{
		while ((*l)->nast)
		{
			l = &((*l)->nast);
		}
		q = *l;
		*l = NULL;
		y = q->x;
		free(q);
	}
	return y;
}
void wczytaj(wel* l)
{
	FILE* file = NULL;
	errno_t errno;
	int val = 0, count = 0;
	char* buffer;
	char* line;
	errno = fopen_s(&file, "dane.txt", "r");
	if (*l)
		usunListe(l);
	if (errno)
	{
		printf("AN ERROR OCCURED: %d", errno);
		return;
	}
	//policz wszystkie znaki
	while ((fgetc(file)) != EOF)
	{
		count++;
	}
	//powrot na poczatek pliku
	rewind(file);
	buffer = static_cast<char*>(malloc(sizeof(char) * count + 1));
	line = fgets(buffer, count, file);
	while (*line)
	{
		val = strtol(line, &line, 10);
		dodajO(l, val);
	}
	free(buffer);
	fclose(file);
}
void zapisz(wel l)
{
	FILE* file = NULL;
	errno_t errno;
	errno = fopen_s(&file, "dane.txt", "w");
	if (errno)
	{
		printf("AN ERROR OCCURED: %d", errno);
		return;
	}
	while (l)
	{
		//fwrite(&l->x, sizeof(l->x), 1, file);
		fprintf_s(file, "%d ", l->x);
		l = (l)->nast;
	}
	fclose(file);
}
wel* znajdz(wel* l, int y)
{
	while (*l && (*l)->x != y) l = &(*l)->nast;
	if (*l)
		return l;
	return NULL;
}
void usunWsk(wel* l)
{
	if (*l)
	{
		wel q = (*l)->nast;
		free(*l);
		*l = q;
	}
}
void dodajPrzed(wel* al, int y)
{
	wel q = static_cast<wel>(malloc(sizeof(el)));
	q->x = y;
	q->nast = *al;
	*al = q;
}
void dodajZa(wel* al, int y)
{
	wel q = static_cast<wel>(malloc(sizeof(el)));
	q->x = y;
	q->nast = (*al)->nast;
	(*al)->nast = q;
}

// ZADANIE 2
void usunWszystkie(wel* p, int y)
{
	if (!p) return;
	while (*p)
	{
		if ((*p)->x == y)
		{
			usunWsk(p);
		}
		else
		{
			p = &(*p)->nast;
		}
	}
}
wel usunWszystkieRek(wel p, int y)
{
	wel q = NULL;
	if (p)
	{
		if (p->x == y)
		{
			q = usunWszystkieRek(p->nast, y);
			free(p);
			p = q;
		}
		else
		{
			p->nast = usunWszystkieRek(p->nast, y);
		}
	}
	return p;
}

// ZADANIE 3
int wyznaczMode(wel l)
{
	wel q = l;
	int moda;
	int moda_l = 0;
	int temp;
	int licznik = 0;
	if (!l) return INT_MAX;
	moda = q->x;
	temp = moda;
	licznik++;
	while (l)
	{
		temp = q->x;
		while (q)
		{
			if (q->x == temp) licznik++;
			q = q->nast;
		}
		if (licznik > moda_l)
		{
			moda = temp;
			licznik = 0;
			temp = 0;
		}
		l = l->nast;
		q = l;
	}
	return moda;
}
void usunMode(wel* l)
{
	int moda = wyznaczMode(*l);
	usunWszystkie(l, moda);
}

// ZADANIE 4
void usunWszystkieNP(wel* p, int y)
{
	if (!p) return;
	while (*p)
	{
		if ((*p)->x % y != 0)
		{
			usunWszystkie(p, (*p)->x);
		}
		else
		{
			p = &(*p)->nast;
		}
	}
}

// ZADANIE 5
wel recursiveReverse(wel l)
{

	if (l == NULL) return NULL;
	if (l->nast == NULL) return l;
	wel reszta = recursiveReverse(l->nast);
	l->nast->nast = l;
	l->nast = NULL;
	return reszta;
}

// ZADANIE 6
void dodajSort(wel* l, int y)
{
	wel q = static_cast<wel>(malloc(sizeof(el)));
	q->x = y;
	while (*l && (*l)->x < y) l = &(*l)->nast;
	q->nast = *l;
	*l = q;
}
int pierwszySort(wel l)
{
	if (l) return l->x;
	return INT_MAX;
}
int ostatniSort(wel l)
{
	while (l && l->nast) l = l->nast;
	return l->x;
}
void wczytajSort(wel* l)
{
	FILE* file = NULL;
	errno_t errno;
	int val = 0, count = 0;
	char* buffer;
	char* line;
	errno = fopen_s(&file, "dane.txt", "r");
	if (*l)
		usunListe(l);
	if (errno)
	{
		printf("AN ERROR OCCURED: %d", errno);
		return;
	}
	//policz wszystkie znaki
	while ((fgetc(file)) != EOF)
	{
		count++;
	}
	//powrot na poczatek pliku
	rewind(file);
	buffer = static_cast<char*>(malloc(sizeof(char) * count + 1));
	line = fgets(buffer, count, file);
	while (*line)
	{
		val = strtol(line, &line, 10);
		dodajSort(l, val);
	}
	free(buffer);
	fclose(file);
}

void druk_wartownik(wel l, wel* aP)
{
	if (l)
	{
		while (l && l->x < INT_MAX)
		{
			if (aP && l == *aP) printf("[");
			printf("%d", l->x);
			if (aP && l == *aP) printf("]");
			l = l->nast;
			if (l)
			{
				printf(" -> ");
			}
		}
		printf("|\n");
	}
	else
	{
		printf("Lista jest pusta.\n");
	}
}
void dodajSortWartownik(wel* l, int y)
{
	wel q = static_cast<wel>(malloc(sizeof(el)));
	q->x = y;
	while ((*l)->x < y) l = &(*l)->nast;
	q->nast = *l;
	*l = q;
}
int ostatniSortWartownik(wel l)
{
	while (l->x < INT_MAX) l = l->nast;
	return l->x;
}
void wczytajSortWartownik(wel* l)
{
	FILE* file = NULL;
	errno_t errno;
	int val = 0, count = 0;
	char* buffer;
	char* line;
	errno = fopen_s(&file, "dane.txt", "r");
	if (*l)
		usunListe(l);
	if (errno)
	{
		printf("AN ERROR OCCURED: %d", errno);
		return;
	}
	//policz wszystkie znaki
	while ((fgetc(file)) != EOF)
	{
		count++;
	}
	//powrot na poczatek pliku
	rewind(file);
	buffer = static_cast<char*>(malloc(sizeof(char) * count + 1));
	line = fgets(buffer, count, file);
	while (*line)
	{
		val = strtol(line, &line, 10);
		dodajSortWartownik(l, val);
	}
	free(buffer);
	fclose(file);
}

// ZADANIE 7
void polaczUp(wel* p, wel* q)
{
	wel* r = p, * s = q;
	wel t;
	if (*q)
	{
		if (!(*p))
		{
			*p = *q;
			*q = NULL;
		}
		else
		{
			if ((*p)->x > (*q)->x)
			{
				t = *p;
				*p = *q;
				*q = t;
			}
			do
			{
				r = &(*r)->nast;
			} while (*r && (*r)->x <= (*q)->x);
			if (!(*r))
			{
				*r = *q;
				*q = NULL;
			}
			else
			{
				do
				{
					do
					{
						s = &((*s)->nast);
					} while (*s && (*s)->x <= (*r)->x);
					t = *s;
					*s = *r;
					*r = *q;
					*q = t;
					r = s;
					s = q;
				} while (*q);
			}
		}
	}
}

// ZADANIE 9

// lista dwukierunkowa
void druk2(wel2d l, wel2d* aP)
{
	if (l)
	{
		while (l)
		{
			printf(" <- ");
			if (aP && l == *aP) printf("[");
			printf("%d", l->x);
			if (aP && l == *aP) printf("]");
			l = l->nast;
			if (l)
			{
				printf(" -> ");
			}
		}
		printf("|\n");
	}
	else
	{
		printf("Lista jest pusta.\n");
	}
}
void dodajP2(wel2d* l, int y)
{
	wel2d q = static_cast<wel2d>(malloc(sizeof(el2d)));
	q->x = y;
	q->nast = *l;
	q->popr = NULL;
	if (q->nast)
		q->nast->popr = q;
	*l = q;
}
int usunP2(wel2d* l)
{
	int y = 0;
	wel2d q = *l;
	if (*l)
	{
		y = (*l)->x;
		*l = (*l)->nast;
		//(*l)->popr = NULL;
		free(q);
	}
	return y;
}
void dodajO2(wel2d* l, int y)
{
	wel2d q = static_cast<wel2d>(malloc(sizeof(el2d)));
	q->x = y;
	q->nast = NULL;
	while (*l)
	{
		q->popr = *l;
		l = &((*l)->nast);
	}
	*l = q;
}
void usunListe2(wel2d* l)
{
	wel2d p = *l, q;
	*l = 0;
	while (p)
	{
		q = p;
		p = p->nast;
		free(q);
	}
}
int usunO2(wel2d* l)
{
	int y = 0;
	wel2d q;
	if (*l)
	{
		while ((*l)->nast)
		{
			l = &((*l)->nast);
		}
		q = *l;
		*l = NULL;
		y = q->x;
		free(q);
	}
	return y;
}
void wczytaj2(wel2d* l)
{
	FILE* file = NULL;
	errno_t errno;
	int val = 0, count = 0;
	char* buffer;
	char* line;
	errno = fopen_s(&file, "dane.txt", "r");
	if (*l)
		usunListe2(l);
	if (errno)
	{
		printf("AN ERROR OCCURED: %d", errno);
		return;
	}
	//policz wszystkie znaki
	while ((fgetc(file)) != EOF)
	{
		count++;
	}
	//powrot na poczatek pliku
	rewind(file);
	buffer = static_cast<char*>(malloc(sizeof(char) * count + 1));
	line = fgets(buffer, count, file);
	while (*line)
	{
		val = strtol(line, &line, 10);
		dodajO2(l, val);
	}
	free(buffer);
	fclose(file);
}
void zapisz2(wel2d l)
{
	FILE* file = NULL;
	errno_t errno;
	errno = fopen_s(&file, "dane.txt", "w");
	if (errno)
	{
		printf("AN ERROR OCCURED: %d", errno);
		return;
	}
	while (l)
	{
		//fwrite(&l->x, sizeof(l->x), 1, file);
		fprintf_s(file, "%d ", l->x);
		l = (l)->nast;
	}
	fclose(file);
}
wel2d* znajdz2(wel2d* l, int y)
{
	while (*l && (*l)->x != y) l = &(*l)->nast;
	if (*l)
		return l;
	return NULL;
}
void usunWsk2(wel2d* l)
{
	if (*l)
	{
		wel2d q = (*l)->nast;
		q->popr = (*l)->popr;
		free(*l);
		*l = q;
	}
}
void dodajPrzed2(wel2d* al, int y)
{
	wel2d q = static_cast<wel2d>(malloc(sizeof(el2d)));
	q->x = y;
	q->nast = *al;
	(*al)->popr = q;
	*al = q;
}
void dodajZa2(wel2d* al, int y)
{
	wel2d q = static_cast<wel2d>(malloc(sizeof(el2d)));
	q->x = y;
	q->nast = (*al)->nast;
	if ((*al)->nast)
		(*al)->nast->popr = q;
	q->popr = (*al);
	(*al)->nast = q;
}

// lista sortujaca dwukierunkowa
void dodajSort2(wel2d* l, int y)
{
	wel2d q = static_cast<wel2d>(malloc(sizeof(el2d)));
	q->x = y;
	while (*l && (*l)->x < y)
	{
		q->popr = *l;
		l = &(*l)->nast;
	}
	q->nast = *l;
	*l = q;
}
int pierwszySort2(wel2d l)
{
	if (l) return l->x;
	return INT_MAX;
}
int ostatniSort2(wel2d l)
{
	while (l && l->nast) l = l->nast;
	return l->x;
}
void wczytajSort2(wel2d* l)
{
	FILE* file = NULL;
	errno_t errno;
	int val = 0, count = 0;
	char* buffer;
	char* line;
	errno = fopen_s(&file, "dane.txt", "r");
	if (*l)
		usunListe2(l);
	if (errno)
	{
		printf("AN ERROR OCCURED: %d", errno);
		return;
	}
	//policz wszystkie znaki
	while ((fgetc(file)) != EOF)
	{
		count++;
	}
	//powrot na poczatek pliku
	rewind(file);
	buffer = static_cast<char*>(malloc(sizeof(char) * count + 1));
	line = fgets(buffer, count, file);
	while (*line)
	{
		val = strtol(line, &line, 10);
		dodajSort2(l, val);
	}
	free(buffer);
	fclose(file);
}

void druk_wartownik2(wel2d l, wel2d* aP)
{
	if (l)
	{
		while (l && l->x < INT_MAX)
		{
			if (aP && l == *aP) printf("[");
			printf("%d", l->x);
			if (aP && l == *aP) printf("]");
			l = l->nast;
			if (l)
			{
				printf(" -> ");
			}
		}
		printf("|\n");
	}
	else
	{
		printf("Lista jest pusta.\n");
	}
}
void dodajSortWartownik2(wel2d* l, int y)
{
	wel2d q = static_cast<wel2d>(malloc(sizeof(el2d)));
	q->x = y;
	while ((*l)->x < y)
	{
		q->popr = *l;
		l = &(*l)->nast;
	}
	q->nast = *l;
	*l = q;
}
int ostatniSortWartownik2(wel2d l)
{
	while (l->x < INT_MAX) l = l->nast;
	return l->x;
}
void wczytajSortWartownik2(wel2d* l)
{
	FILE* file = NULL;
	errno_t errno;
	int val = 0, count = 0;
	char* buffer;
	char* line;
	errno = fopen_s(&file, "dane.txt", "r");
	if (*l)
		usunListe2(l);
	if (errno)
	{
		printf("AN ERROR OCCURED: %d", errno);
		return;
	}
	//policz wszystkie znaki
	while ((fgetc(file)) != EOF)
	{
		count++;
	}
	//powrot na poczatek pliku
	rewind(file);
	buffer = static_cast<char*>(malloc(sizeof(char) * count + 1));
	line = fgets(buffer, count, file);
	while (*line)
	{
		val = strtol(line, &line, 10);
		dodajSortWartownik2(l, val);
	}
	free(buffer);
	fclose(file);
}

// ZADANIE 10

// JEDNOKIERUNKOWA
void dodajCP(welc* p, int y)
{
	welc tmp = static_cast<welc>(malloc(sizeof(elc)));
	welc curr = NULL;
	tmp->x = y;

	if (*p == NULL)
	{
		tmp->nast = tmp;
		*p = tmp;
	}
	else
	{
		tmp->nast = *p;
		curr = *p;
		while (curr->nast != *p)
		{
			curr = curr->nast;
		}
		curr->nast = tmp;
		*p = tmp;
	}
}
void dodajCO(welc* p, int y)
{
	welc tmp = static_cast<welc>(malloc(sizeof(elc)));
	tmp->x = y;
	welc start = NULL;
	if (*p == NULL)
	{
		tmp->nast = tmp;
		*p = tmp;
	}
	else
	{
		start = *p;
		while ((*p)->nast != start)
			p = &((*p)->nast);

		tmp->nast = (*p)->nast;
		(*p)->nast = tmp;
	}
}
int usunCP(welc* p)
{
	welc start = NULL, kon = NULL;
	int res = NULL;
	if (*p == NULL)
	{
		return res;
	}
	if ((*p)->nast == *p)
	{
		res = (*p)->x;
		free(*p);
		*p = NULL;
	}
	else
	{
		start = *p;
		kon = *p;
		while (kon->nast != start)
		{
			kon = kon->nast;
		}
		kon->nast = start->nast;
		*p = start->nast;
		free(start);
	}
	return res;
}
int usunCO(welc* p)
{
	welc start = NULL, curr = NULL;
	int res = NULL;
	if (*p == NULL || (*p)->nast == *p)
	{
		res = (*p)->x;
		free(*p);
		*p = NULL;
		return res;
	}
	curr = *p;
	start = *p;

	while (curr->nast->nast != start)
		curr = curr->nast;
	res = curr->x;
	start = curr->nast;
	curr->nast = *p;
	free(start);
	return res;
}
void drukC(welc p)
{
	welc start = p;
	if (p)
	{
		do
		{
			printf("%d -> ", p->x);
			p = p->nast;
		} while (p != start);
		printf("|\n");
	}
}
void usunListeC(welc* p)
{
	welc* tmp;
	while (*p)
	{
		tmp = &(*p)->nast;
		free(*p);
		p = tmp;
	}

}
welc* znajdzC(welc* p, int y)
{
	welc start = *p;
	if (!*p)
		return NULL;
	do
	{
		if ((*p)->x == y)
			return p;
		p = &(*p)->nast;
	} while (*p != start);
	return NULL;
}
void usunWskC(welc* p)
{
	if (*p)
	{
		welc q = (*p)->nast;
		free(*p);
		*p = q;
	}
}
void dodajPrzedC(welc* p, int y)
{
	welc q = static_cast<welc>(malloc(sizeof(elc)));
	q->x = y;
	q->nast = *p;
	*p = q;
}
void dodajZaC(welc* p, int y)
{
	welc q = static_cast<welc>(malloc(sizeof(elc)));
	q->x = y;
	q->nast = (*p)->nast;
	(*p)->nast = q;
}
void wczytajC(welc* l)
{
	FILE* file = NULL;
	errno_t errno;
	int val = 0, count = 0;
	char* buffer;
	char* line;
	errno = fopen_s(&file, "dane.txt", "r");
	if (*l)
		usunListeC(l);
	if (errno)
	{
		printf("AN ERROR OCCURED: %d", errno);
		return;
	}
	//policz wszystkie znaki
	while ((fgetc(file)) != EOF)
	{
		count++;
	}
	//powrot na poczatek pliku
	rewind(file);
	buffer = static_cast<char*>(malloc(sizeof(char) * count + 1));
	line = fgets(buffer, count, file);
	while (*line)
	{
		val = strtol(line, &line, 10);
		dodajCO(l, val);
	}
	free(buffer);
	fclose(file);
}
void zapiszC(welc l)
{
	welc start = l;
	FILE* file = NULL;
	errno_t errno;
	errno = fopen_s(&file, "dane.txt", "w");
	if (errno)
	{
		printf("AN ERROR OCCURED: %d", errno);
		return;
	}
	if (l)
	{
		do
		{
			fprintf_s(file, "%d ", l->x);
			l = (l)->nast;
		} while (l != start);
	}

	fclose(file);
}

// DWUKIERUNKOWA
void dodajCP2(welc2* p, int y)
{
	welc2 nowy = static_cast<welc2>(malloc(sizeof(elc2)));
	nowy->x = y;

	if (!*p)
	{
		nowy->nast = nowy;
		nowy->popr = nowy;
	}
	else
	{
		nowy->nast = *p;
		nowy->popr = (*p)->popr;
		(*p)->popr->nast = nowy;
		(*p)->popr = nowy;
	}
	*p = nowy;
}
void dodajCO2(welc2* p, int y)
{
	welc2 start = *p;
	welc2 nowy = static_cast<welc2>(malloc(sizeof(elc2)));
	if (!*p)
	{
		dodajCP2(p, y);
		return;
	}

	p = &start->popr;
	if (nowy)
	{
		nowy->x = y;
		nowy->nast = start;
		nowy->popr = (*p);
		(*p)->nast = nowy;
		start->popr = nowy;
	}
}
int usunCP2(welc2* p)
{
	welc2 start = NULL;
	int res = NULL;
	if (*p)
	{
		res = (*p)->x;
		if ((*p)->nast == *p)
		{
			free(*p);
			*p = 0;
			return res;
		}
		start = *p;
		*p = (*p)->nast;
		if (*p)
		{
			(*p)->popr = start->popr;
			start->popr->nast = *p;
		}
		free(start);
	}
	return res;
}
int usunCO2(welc2* p)
{
	welc2 kon = NULL;
	int res = NULL;
	if (*p)
	{
		if (*p == (*p)->nast)
		{
			free(*p);
			*p = 0;
			return res;
		}
		kon = (*p)->popr;
		kon->popr->nast = *p;
		(*p)->popr = kon->popr;
		free(kon);
	}
	return res;
}
void usunListeC2(welc2* p)
{
	welc2* tmp;
	while (*p)
	{
		tmp = &(*p)->nast;
		free(*p);
		p = tmp;
	}
}
void drukC2(welc2 p)
{
	welc2 start = p;
	if (p)
	{
		do
		{
			printf("%d -> ", p->x);
			p = p->nast;
		} while (p != start);
		printf("|\n");
	}
}
welc2* znajdzC2(welc2* p, int y)
{
	welc2 start = *p;
	if (!*p)
		return NULL;
	do
	{
		if ((*p)->x == y)
			return p;
		p = &(*p)->nast;
	} while (*p != start);
	return NULL;
}
void dodajPrzedC2(welc2* p, int y)
{
	welc2 q = static_cast<welc2>(malloc(sizeof(elc2)));
	q->x = y;
	q->nast = *p;
	q->popr = (*p)->popr;
	(*p)->popr = q;
	*p = q;
}
void dodajZaC2(welc2* p, int y)
{
	welc2 q = static_cast<welc2>(malloc(sizeof(elc2)));
	q->x = y;
	q->nast = (*p)->nast;
	(*p)->nast = q;
	q->popr = *p;
}
void usunWskC2(welc2* p)
{
	if (*p)
	{
		welc2 q = (*p)->nast;
		usunCP2(p);
		*p = q;
	}
}
void zapiszC2(welc2 l)
{
	welc2 start = l;
	FILE* file = NULL;
	errno_t errno;
	errno = fopen_s(&file, "dane.txt", "w");
	if (errno)
	{
		printf("AN ERROR OCCURED: %d", errno);
		return;
	}
	if (l)
	{
		do
		{
			fprintf_s(file, "%d ", l->x);
			l = (l)->nast;
		} while (l != start);
	}

	fclose(file);
}
void wczytajC2(welc2* p)
{
	FILE* file = NULL;
	errno_t errno;
	int val = 0, count = 0;
	char* buffer;
	char* line;
	errno = fopen_s(&file, "dane.txt", "r");
	if (*p)
		usunListeC2(p);
	if (errno)
	{
		printf("AN ERROR OCCURED: %d", errno);
		return;
	}
	//policz wszystkie znaki
	while ((fgetc(file)) != EOF)
	{
		count++;
	}
	//powrot na poczatek pliku
	rewind(file);
	buffer = static_cast<char*>(malloc(sizeof(char) * count + 1));
	line = fgets(buffer, count, file);
	while (*line)
	{
		val = strtol(line, &line, 10);
		dodajCO2(p, val);
	}
	free(buffer);
	fclose(file);
}

// ZADANIE 12
void usunPowtorzeniaC(welc* p, welc q)
{
	if (!*p || !q)
		return;
	welc startQ = q;
	welc startP = *p;
	welc curr = *p;
	int zmiana = 0;
	do
	{
		zmiana = 0;
		do
		{
			if (curr == 0)
				return;
			if (q->x == curr->x)
			{
				if (startP == startP->nast)
					startP = 0;
				if (startP == curr)
				{
					startP = startP->nast;
					zmiana = 1;
				}
				usunCP(&curr);
			}
			else
			{
				curr = curr->nast;
			}
		} while (curr != startP);
		if (!zmiana)
			q = q->nast;
	} while (q != startQ);
	*p = curr;
}
