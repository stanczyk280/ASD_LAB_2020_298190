#include "drzewa_lib.h"

/*
	strcmp(string1, string2) =>{
		< 0 -> string1 less than string2
		0   -> string1 equals string2
		> 0 -> string1 greater than string2
	}
*/
void _dBinDrukuj2D(drzewo_bin d, int dist)
{
	if (!d)
		return;

	dist += LEN;

	_dBinDrukuj2D(d->prawy, dist);

	putchar('\n');
	for (int i = LEN; i < dist; i++)
		putchar(' ');
	printf("%-7s\n", d->klucz);

	_dBinDrukuj2D(d->lewy, dist);
}

void dBinDrukuj2D(drzewo_bin d)
{
	_dBinDrukuj2D(d, 0);
}
void _dBinDrukuj(drzewo_bin d, int level)
{
	if (!d)
		return;
	_dBinDrukuj(d->prawy, level + 1);
	for (int i = 0; i < level; i++)
		putchar(' ');
	printf("%s\n", d->klucz);
	_dBinDrukuj(d->lewy, level + 1);
}
void dBinDrukuj(drzewo_bin d)
{
	_dBinDrukuj(d, 0);
	putchar('\n');
}
void dBinDodaj(drzewo_bin* d, drzewo_bin r, const char* val)
{
	if (!*d)
	{
		*d = static_cast<drzewo_bin>(malloc(sizeof(el_drzewa_bin)));
		strcpy_s((*d)->klucz, LEN, val);
		(*d)->lewy = NULL;
		(*d)->prawy = NULL;
		(*d)->rodzic = r;
	}
	else
		if (strcmp(val, (*d)->klucz) <= 0)
			dBinDodaj(&(*d)->lewy, *d, val);
		else
			dBinDodaj(&(*d)->prawy, *d, val);
}
void dBinUsun(drzewo_bin* d, char* val)
{
	drzewo_bin* s;
	drzewo_bin q;
	if (!*d) return;
	d = dBinSzukaj(d, val);
	if ((*d)->lewy && (*d)->prawy)
	{
		s = dBinMax(&(*d)->lewy);
		q = *s;
		strcpy_s((*d)->klucz, LEN, (*s)->klucz);
		*s = (*s)->lewy;
		if (*s)
		{
			(*s)->rodzic = q->rodzic;
		}
		free(q);
	}
	else
	{
		q = *d;
		*d = q->lewy ? q->lewy : q->prawy;
	}
	if (*d)
		(*d)->rodzic = q->rodzic;
	else
		free(q);
}
void dBinUsunCale(drzewo_bin* d)
{
	if (!*d) return;
	dBinUsunCale(&(*d)->lewy);
	dBinUsunCale(&(*d)->prawy);
	free(*d);
	*d = NULL;
}
drzewo_bin* dBinSzukaj(drzewo_bin* d, char* val)
{
	if (!*d) return NULL;
	if (strcmp(val, (*d)->klucz) < 0)
		return dBinSzukaj(&(*d)->lewy, val);
	else if (strcmp(val, (*d)->klucz) > 0)
		return dBinSzukaj(&(*d)->prawy, val);
	else return d;
}
drzewo_bin* dBinMin(drzewo_bin* d)
{
	if (!*d) return NULL;
	while ((*d)->lewy)
		d = &(*d)->lewy;
	return d;
}
drzewo_bin* dBinMax(drzewo_bin* d)
{
	if (!*d) return NULL;
	while ((*d)->prawy)
		d = &(*d)->prawy;
	return d;
}
drzewo_bin* dBinPoprzednik(drzewo_bin* d)
{
	drzewo_bin* tmp = NULL;
	if (!d) return NULL;
	if ((*d)->lewy)
		return dBinMax(&(*d)->lewy);
	tmp = &(*d)->rodzic;
	while (tmp && (*tmp)->prawy != *d)
	{
		d = tmp;
		tmp = &(*tmp)->rodzic;
	}
	return tmp;
}
drzewo_bin* dBinNastepnik(drzewo_bin* d)
{
	/*
	if ((*d)->prawy != NULL)
		return dBinMin(&(*d)->prawy)
	Node_tmp = Node->parent
	while (Node_tmp != NULL and Node_tmp->left != Node)
		Node = Node_tmp
		Node_tmp = Node_tmp->parent
	return Node_tmp
	*/
	drzewo_bin* tmp = NULL;
	if (!d) return NULL;
	if ((*d)->prawy)
		return dBinMin(&(*d)->prawy);
	tmp = &(*d)->rodzic;
	while (*tmp && (*tmp)->lewy != *d)
	{
		d = tmp;
		tmp = &(*tmp)->rodzic;
	}
	return tmp;
}
void dBinZapisz(FILE* file, drzewo_bin d)
{
	if (d == NULL) fprintf(file, "%s ", "0");
	else
	{
		fprintf(file, "%s ", d->klucz);
		dBinZapisz(file, d->lewy);
		dBinZapisz(file, d->prawy);
	}

}
drzewo_bin dBinWczytaj(FILE* file)
{
	drzewo_bin T;
	char napis[LEN];
	fscanf_s(file, "%s", napis, LEN);
	if (strcmp(napis, "0") == 0) return NULL;
	T = static_cast<drzewo_bin>(malloc(sizeof(el_drzewa_bin)));
	strcpy_s(T->klucz, LEN, napis);
	T->lewy = dBinWczytaj(file);
	T->prawy = dBinWczytaj(file);
	return T;
}

// ZADANIE 16
int d_bin_te_same_wartosci(drzewo_bin* D, drzewo_bin* T)
{
	if (*D && *T)
	{
		drzewo_bin* tmp1, * tmp2;
		tmp1 = dBinMin(D);
		tmp2 = dBinMin(T);
		if (strcmp((*tmp1)->klucz, (*tmp2)->klucz) == 0)
		{
			while (*tmp1 && *tmp2)
			{
				tmp1 = dBinNastepnik(tmp1);
				tmp2 = dBinNastepnik(tmp2);
				if (*tmp1 && *tmp2)
					if (strcmp((*tmp1)->klucz, (*tmp2)->klucz) != 0)
						return 0;
			}
			if (!*tmp1 && !*tmp2) return 1;
		}
	}
	return 0;
}

