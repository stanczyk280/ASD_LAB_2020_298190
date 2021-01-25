#include <cstdio>
#include <cstdlib>
#include "listy_lib.h"
#include "drzewa_lib.h"
#include "sortowania.h"
#include <queue>
#include <iostream>
#include "heapSort.h"
#include "dijkstra.h"
#define N 1000
#define M 10

// Jednokierunkowe
int Jednokierunkowe()
{
	int j = 0, k = 0;
	wel* aP = NULL;
	wel p = NULL, q = NULL, r = NULL;
	wel do_polaczenia = NULL;
	puts("1. Lista nieuporzadkowana");
	puts("2. Lista uporzadkowana (bez wartownika)");
	puts("2. Lista uporzadkowana (z wartownikiem)");
	scanf_s("%d", &k);
	switch (k)
	{
	case 1:
		do
		{
			system("cls");
			druk(p, aP);
			puts("Jaka operacje wykonac?\n");
			puts("1.Dodaj element na poczatku listy");
			puts("2.Dodaj element na koncu listy.");
			puts("3.Usun pierszy element listy.");
			puts("4.Usun ostatni element listy.");
			puts("5.Odszukaj zadany element.");
			puts("6.Dodaj nowy element przed wskazanym.");
			puts("7.Dodaj nowy element za wskazanym.");
			puts("8.Usun wskazany element.");
			puts("9.Wczytaj zawartosc listy z pliku.");
			puts("10.Zapisz zawartosc listy do pliku.");
			puts("11. Usun wszystkie elementy o podanej wartosci.");
			puts("12. Odwroc liste.");
			puts("13. Usun wszystkie niepodzielne przez podana liczbe.");
			puts("14. Wyznacz dominante.");
			puts("15. Usun dominante.");
			puts("0. Zakoncz dzialanie programu.");
			scanf_s("%d", &k);
			switch (k)
			{
			case 1:
				printf("Podaj element:");
				scanf_s("%d", &j);
				dodajP(&p, j);
				break;
			case 2:
				printf("Podaj element:");
				scanf_s("%d", &j);
				dodajO(&p, j);
				break;
			case 3:
				j = usunP(&p);
				printf("Usuniety element j=%d\n", j);
				break;
			case 4:
				j = usunO(&p);
				printf("Usuniety element j=%d\n", j);
				break;
			case 5:
				printf("Podaj szukana wartosc: ");
				scanf_s("%d", &j);
				aP = znajdz(&p, j);
				if (aP) printf("Znaleziono element %d na liscie.\n", j);
				break;
			case 6:
				printf("Podaj element:");
				scanf_s("%d", &j);
				dodajPrzed(aP, j);
				aP = &(*aP)->nast;
				break;
			case 7:
				printf("Podaj element:");
				scanf_s("%d", &j);
				dodajZa(aP, j);
				break;
			case 8:
				usunWsk(aP);
				aP = NULL;
				break;
			case 9:
				wczytaj(&p);
				break;
			case 10:
				zapisz(p);
				break;
			case 11:
				puts("Podaj element:");
				scanf_s("%d", &j);
				usunWszystkie(&p, j);
				break;
			case 12:
				p = recursiveReverse(p);
				break;
			case 13:
				puts("podaj element:");
				scanf_s("%d", &j);
				usunWszystkieNP(&p, j);
				break;
			case 14:
				j = wyznaczMode(p);
				printf("dominanta = %d", j);
				break;
			case 15:
				usunMode(&p);
				break;
			default:
				k = 0;
				break;
			}
			j = 0;
		} while (k);
		break;
	case 2:
		do
		{
			druk(p, aP);
			puts("1. Dodaj wartosc do listy");
			puts("2. Pobierz pierwszy element.");
			puts("3. Pobierz ostatni element");
			puts("4. Wyszukaj element");
			puts("5. Usun podany element");
			puts("6. Wczytaj z pliku");
			puts("7. Zapisz do pliku");
			puts("8. Polacz dwie listy");
			puts("0. Wyjdz");
			scanf_s("%d", &k);
			switch (k)
			{
			case 1:
				puts("podaj wartosc do dodania");
				scanf_s("%d", &j);
				dodajSort(&p, j);
				break;
			case 2:
				printf("Pierwszy element = %d\n", pierwszySort(p));
				break;
			case 3:
				printf("Ostatni element = %d\n", ostatniSort(p));
				break;
			case 4:
				printf("Podaj szukana wartosc: ");
				scanf_s("%d", &j);
				aP = znajdz(&p, j);
				if (aP) printf("Znaleziono element %d na liscie.\n", j);
				break;
			case 5:
				usunWsk(aP);
				aP = NULL;
				break;
			case 6:
				wczytajSort(&p);
				break;
			case 7:
				zapisz(p);
				break;
			case 8:
				// Dla testow druga lista wczytana z pliku
				wczytajSort(&do_polaczenia);
				polaczUp(&p, &do_polaczenia);
				break;
			default:
				exit(0);
			}
		} while (k);
		break;
	case 3:
		dodajP(&p, INT_MAX);
		do
		{
			druk(p, aP);
			puts("1. Dodaj wartosc do listy");
			puts("2. Pobierz pierwszy element.");
			puts("3. Pobierz ostatni element");
			puts("4. Wyszukaj element");
			puts("5. Usun podany element");
			puts("6. Wczytaj z pliku");
			puts("7. Zapisz do pliku");
			puts("0. Wyjdz");
			scanf_s("%d", &k);
			switch (k)
			{
			case 1:
				puts("podaj wartosc do dodania");
				scanf_s("%d", &j);
				dodajSortWartownik(&p, j);
				break;
			case 2:
				printf("Pierwszy element = %d\n", pierwszySort(p));
				break;
			case 3:
				printf("Ostatni element = %d\n", ostatniSortWartownik(p));
				break;
			case 4:
				printf("Podaj szukana wartosc: ");
				scanf_s("%d", &j);
				aP = znajdz(&p, j);
				if (aP) printf("Znaleziono element %d na liscie.\n", j);
				break;
			case 5:
				usunWsk(aP);
				aP = NULL;
				break;
			case 6:
				wczytajSort(&p);
				break;
			case 7:
				zapisz(p);
				break;
			default:
				exit(0);
			}
		} while (k);
		break;
	default:
		exit(0);
	}
	return 0;
}

// Dwukierunkowe
int Dwukierunkowe()
{
	int j = 0, k = 0;
	wel2d* aP = NULL;
	wel2d p = NULL, q = NULL, r = NULL;
	puts("1. Lista dwukierunkowa nieuporzadkowana");
	puts("2. Lista dwukierunkowa uporzadkowana (bez wartownika)");
	puts("2. Lista dwukierunkowa uporzadkowana (z wartownikiem)");
	scanf_s("%d", &k);
	switch (k)
	{
	case 1:
		do
		{
			system("cls");
			druk2(p, aP);
			puts("Jaka operacje wykonac?\n");
			puts("1.Dodaj element na poczatku listy");
			puts("2.Dodaj element na koncu listy.");
			puts("3.Usun pierszy element listy.");
			puts("4.Usun ostatni element listy.");
			puts("5.Odszukaj zadany element.");
			puts("6.Dodaj nowy element przed wskazanym.");
			puts("7.Dodaj nowy element za wskazanym.");
			puts("8.Usun wskazany element.");
			puts("9.Wczytaj zawartosc listy z pliku.");
			puts("10.Zapisz zawartosc listy do pliku.");
			puts("0. Zakoncz dzialanie programu.");
			scanf_s("%d", &k);
			switch (k)
			{
			case 1:
				printf("Podaj element:");
				scanf_s("%d", &j);
				dodajP2(&p, j);
				break;
			case 2:
				printf("Podaj element:");
				scanf_s("%d", &j);
				dodajO2(&p, j);
				break;
			case 3:
				j = usunP2(&p);
				printf("Usuniety element j=%d\n", j);
				break;
			case 4:
				j = usunO2(&p);
				printf("Usuniety element j=%d\n", j);
				break;
			case 5:
				printf("Podaj szukana wartosc: ");
				scanf_s("%d", &j);
				aP = znajdz2(&p, j);
				if (aP) printf("Znaleziono element %d na liscie.\n", j);
				break;
			case 6:
				printf("Podaj element:");
				scanf_s("%d", &j);
				dodajPrzed2(aP, j);
				aP = &(*aP)->nast;
				break;
			case 7:
				printf("Podaj element:");
				scanf_s("%d", &j);
				dodajZa2(aP, j);
				break;
			case 8:
				usunWsk2(aP);
				aP = NULL;
				break;
			case 9:
				wczytaj2(&p);
				break;
			case 10:
				zapisz2(p);
				break;
			default:
				k = 0;
				break;
			}
			j = 0;
		} while (k);
		break;
	case 2:
		do
		{
			druk2(p, aP);
			puts("1. Dodaj wartosc do listy");
			puts("2. Pobierz pierwszy element.");
			puts("3. Pobierz ostatni element");
			puts("4. Wyszukaj element");
			puts("5. Usun podany element");
			puts("6. Wczytaj z pliku");
			puts("7. Zapisz do pliku");
			puts("0. Wyjdz");
			scanf_s("%d", &k);
			switch (k)
			{
			case 1:
				puts("podaj wartosc do dodania");
				scanf_s("%d", &j);
				dodajSort2(&p, j);
				break;
			case 2:
				printf("Pierwszy element = %d\n", pierwszySort2(p));
				break;
			case 3:
				printf("Ostatni element = %d\n", ostatniSort2(p));
				break;
			case 4:
				printf("Podaj szukana wartosc: ");
				scanf_s("%d", &j);
				aP = znajdz2(&p, j);
				if (aP) printf("Znaleziono element %d na liscie.\n", j);
				break;
			case 5:
				usunWsk2(aP);
				aP = NULL;
				break;
			case 6:
				wczytajSort2(&p);
				break;
			case 7:
				zapisz2(p);
				break;
			default:
				exit(0);
			}
		} while (k);
		break;
	case 3:
		dodajP2(&p, INT_MAX);
		do
		{
			druk2(p, aP);
			puts("1. Dodaj wartosc do listy");
			puts("2. Pobierz pierwszy element.");
			puts("3. Pobierz ostatni element");
			puts("4. Wyszukaj element");
			puts("5. Usun podany element");
			puts("6. Wczytaj z pliku");
			puts("7. Zapisz do pliku");
			puts("0. Wyjdz");
			scanf_s("%d", &k);
			switch (k)
			{
			case 1:
				puts("podaj wartosc do dodania");
				scanf_s("%d", &j);
				dodajSortWartownik2(&p, j);
				break;
			case 2:
				printf("Pierwszy element = %d\n", pierwszySort2(p));
				break;
			case 3:
				printf("Ostatni element = %d\n", ostatniSortWartownik2(p));
				break;
			case 4:
				printf("Podaj szukana wartosc: ");
				scanf_s("%d", &j);
				aP = znajdz2(&p, j);
				if (aP) printf("Znaleziono element %d na liscie.\n", j);
				break;
			case 5:
				usunWsk2(aP);
				aP = NULL;
				break;
			case 6:
				wczytajSort2(&p);
				break;
			case 7:
				zapisz2(p);
				break;
			default:
				exit(0);
			}
		} while (k);
		break;
	default:
		exit(0);
	}
	return 0;
}

// Cykliczne
int Cykliczne()
{
	int j = 0, k = 0;
	welc* aP = NULL;
	welc p = NULL, q = NULL, r = NULL;
	welc testowa = NULL;
	puts("1. Lista cykliczna nieuporzadkowana");
	puts("2. Lista cykliczna dwukierunkowa");
	scanf_s("%d", &k);
	switch (k)
	{
	case 1:
		do
		{
			system("cls");
			drukC(p);
			puts("Jaka operacje wykonac?\n");
			puts("1.Dodaj element na poczatku listy");
			puts("2.Dodaj element na koncu listy");
			puts("3.Usun pierszy element listy.");
			puts("4.Usun ostatni element listy.");
			puts("5.Odszukaj zadany element.");
			puts("6.Dodaj nowy element przed wskazanym.");
			puts("7.Dodaj nowy element za wskazanym.");
			puts("8.Usun wskazany element.");
			puts("9.Wczytaj zawartosc listy z pliku.");
			puts("10.Zapisz zawartosc listy do pliku.");
			puts("12. Usun wartrosci zawierajace sie w drugiej liscie (testowa [1, 2, 3])");
			puts("0. Zakoncz dzialanie programu.");
			scanf_s("%d", &k);
			switch (k)
			{
			case 1:
				printf("Podaj element:");
				scanf_s("%d", &j);
				dodajCP(&p, j);
				break;
			case 2:
				printf("Podaj element:");
				scanf_s("%d", &j);
				dodajCO(&p, j);
				break;
			case 3:
				j = usunCP(&p);
				printf("Usuniety element j=%d\n", j);
				break;
			case 4:
				j = usunCO(&p);
				printf("Usuniety element j=%d\n", j);
				break;
			case 5:
				printf("Podaj szukana wartosc: ");
				scanf_s("%d", &j);
				aP = znajdzC(&p, j);
				if (aP) printf("Znaleziono element %d na liscie.\n", j);
				break;
			case 6:
				printf("Podaj element:");
				scanf_s("%d", &j);
				dodajPrzedC(aP, j);
				aP = &(*aP)->nast;
				break;
			case 7:
				printf("Podaj element:");
				scanf_s("%d", &j);
				dodajZaC(aP, j);
				break;
			case 8:
				usunWskC(aP);
				aP = NULL;
				break;
			case 9:
				wczytajC(&p);
				break;
			case 10:
				zapiszC(p);
			case 12:
				dodajCO(&testowa, 1);
				dodajCO(&testowa, 2);
				dodajCO(&testowa, 3);
				usunPowtorzeniaC(&p, testowa);
				break;
			default:
				k = 0;
				break;
			}
			j = 0;
		} while (k);
		break;
		/*case 2:
			do
			{
				druk2(p, aP);
				puts("1. Dodaj wartosc do listy");
				puts("2. Pobierz pierwszy element.");
				puts("3. Pobierz ostatni element");
				puts("4. Wyszukaj element");
				puts("5. Usun podany element");
				puts("6. Wczytaj z pliku");
				puts("7. Zapisz do pliku");
				puts("0. Wyjdz");
				scanf_s("%d", &k);
				switch (k)
				{
				case 1:
					puts("podaj wartosc do dodania");
					scanf_s("%d", &j);
					dodajSort2(&p, j);
					break;
				case 2:
					printf("Pierwszy element = %d\n", pierwszySort2(p));
					break;
				case 3:
					printf("Ostatni element = %d\n", ostatniSort2(p));
					break;
				case 4:
					printf("Podaj szukana wartosc: ");
					scanf_s("%d", &j);
					aP = znajdz2(&p, j);
					if (aP) printf("Znaleziono element %d na liscie.\n", j);
					break;
				case 5:
					usunWsk2(aP);
					aP = NULL;
					break;
				case 6:
					wczytajSort2(&p);
					break;
				case 7:
					zapisz2(p);
					break;
				default:
					exit(0);
				}
			} while (k);
			break;*/
	default:
		exit(0);
	}
	return 0;
}

void drukujOpcjeDrzewa()
{
	puts("1. Dodaj element.");
	puts("2. Usun element.");
	puts("3. Szukaj elementu.");
	puts("4. Zwroc minimalny element.");
	puts("5. Zwroc maksymalny element.");
	puts("6. Zwroc poprzednik elementu.");
	puts("7. Zwroc nastepnik elementu");
	puts("8. Usun drzewo.");
	puts("9. Zapisz drzewo do pliku.");
	puts("10. Wczytaj drzewo z pliku.");
	puts("11. sprawdz czy 2 drzewa maja dokladnie te same wartosci.");
	puts("0. Wyjdz");
}
int Drzewa()
{
	FILE* file = NULL;
	errno_t errno;
	drzewo_bin D = NULL, test1 = NULL, test2 = NULL;
	drzewo_bin* found = NULL;
	int choice = 0, tmp = 0;;
	char val[LEN];
	do
	{
		putchar('\n');
		dBinDrukuj2D(D);
		//dBinDrukuj(D);
		drukujOpcjeDrzewa();
		scanf_s(" %d", &choice);
		switch (choice)
		{
		case 1:
			puts("Podaj wartosc nowego elementu.");
			scanf_s(" %7s", &val, LEN);
			dBinDodaj(&D, NULL, val);
			break;
		case 2:
			puts("Podaj wartosc elementu do usuniecia.");
			scanf_s(" %7s", &val, LEN);
			dBinUsun(&D, val);
			break;
		case 3:
			puts("Podaj wartosc szukanego elementu.");
			scanf_s(" %7s", &val, LEN);
			found = dBinSzukaj(&D, val);
			if (found)
				puts("Znaleziono element.");
			else
				puts("Nie znaleziono elementu.");
			break;
		case 4:
			found = dBinMin(&D);
			if (found)
				printf("Najmniejszy element drzewa to (%7s)\n", (*found)->klucz);
			else
				puts("Nie znaleziono elementu.");
			break;
		case 5:
			found = dBinMax(&D);
			if (found)
				printf("Najwiekszy element drzewa to (%7s)\n", (*found)->klucz);
			else
				puts("Nie znaleziono elementu.");
			break;
		case 6:
			found = dBinPoprzednik(&D);
			if (found)
				printf("Poprzednik znaleziony. Jego wartosc wynosi %7s", (*found)->klucz);
			else
				puts("Nie znaleziono poprzednika.");
			break;
		case 7:
			found = dBinNastepnik(&D);
			if (found)
				printf("Nastepnik znaleziony. Jego wartosc wynosi %7s", (*found)->klucz);
			else
				puts("Nie znaleziono nastepnika.");
			break;
		case 8:
			dBinUsunCale(&D);
			break;
		case 9:
			errno = fopen_s(&file, "dBinZapis.txt", "w");
			if (errno)
			{
				printf("AN ERROR OCCURED: %d", errno);
				break;
			}
			dBinZapisz(file, D);
			fclose(file);
			break;
		case 10:
			errno = fopen_s(&file, "dBinZapis.txt", "r");
			if (errno)
			{
				printf("AN ERROR OCCURED: %d", errno);
				break;
			}
			dBinUsunCale(&D);
			D = dBinWczytaj(file);
			fclose(file);
			break;
		case 11:
			/*testuj czy maja takie same wartosci*/
			dBinDodaj(&test1, NULL, "a");
			dBinDodaj(&test1, NULL, "b");
			dBinDodaj(&test1, NULL, "c");
			dBinDodaj(&test1, NULL, "d");
			dBinDodaj(&test1, NULL, "e");
			dBinDodaj(&test2, NULL, "e");
			dBinDodaj(&test2, NULL, "a");
			dBinDodaj(&test2, NULL, "c");
			dBinDodaj(&test2, NULL, "b");
			dBinDodaj(&test2, NULL, "d");
			//dBinDodaj(&test2, NULL, "g");
			printf("%d\n", d_bin_te_same_wartosci(&test1, &test2));
			system("pause");
			break;
			//case 12:
			//	dBinDodaj(&test1, NULL, "a");
			//	dBinDodaj(&test1, NULL, "e");
			//	dBinDodaj(&test1, NULL, "c");
			//	dBinDodaj(&test1, NULL, "b");
			//	dBinDodaj(&test1, NULL, "d");
			//	dBinDrukuj2D(test1);
			//	cout << endl << endl;
			//	printLevelOrder(test1);
			//	break;
		default:
			break;
		}
	} while (choice);
	return 0;
}

// Sortowania
int Sortowania()
{
	int i, j, k;

	unsigned long long* bubble_assignment_counter = static_cast<unsigned long long*>(malloc(M * sizeof(unsigned long long)));
	unsigned long long* bubble_comparison_counter = static_cast<unsigned long long*>(malloc(M * sizeof(unsigned long long)));
	zero_array(bubble_assignment_counter, M);
	zero_array(bubble_comparison_counter, M);

	unsigned long long* shellsort_assignment_counter = static_cast<unsigned long long*>(malloc(M * sizeof(unsigned long long)));
	unsigned long long* shellsort_comparison_counter = static_cast<unsigned long long*>(malloc(M * sizeof(unsigned long long)));
	zero_array(shellsort_assignment_counter, M);
	zero_array(shellsort_comparison_counter, M);

	unsigned long long* insertsort_assignment_counter = static_cast<unsigned long long*>(malloc(M * sizeof(unsigned long long)));
	unsigned long long* insertsort_comparison_counter = static_cast<unsigned long long*>(malloc(M * sizeof(unsigned long long)));
	zero_array(insertsort_assignment_counter, M);
	zero_array(insertsort_comparison_counter, M);

	unsigned long long* quicksort_assignment_counter = static_cast<unsigned long long*>(malloc(M * sizeof(unsigned long long)));
	unsigned long long* quicksort_comparison_counter = static_cast<unsigned long long*>(malloc(M * sizeof(unsigned long long)));
	zero_array(quicksort_assignment_counter, M);
	zero_array(quicksort_comparison_counter, M);

	int* bubble_arr = static_cast<int*>(malloc(N * sizeof(int)));
	int* shell_arr = static_cast<int*>(malloc(N * sizeof(int)));
	int* quicksort_arr = static_cast<int*>(malloc(N * sizeof(int)));
	int* insertsort_arr = static_cast<int*>(malloc(N * sizeof(int)));
	int* base_numbers = static_cast<int*>(malloc(N * sizeof(int)));

	for (i = 0; i < M; i++)
	{
		//Generowanie liczb
		randomfill_array(base_numbers, N, 100);

		//Kopiowanie do tablic
		copy_array(base_numbers, bubble_arr, N);
		copy_array(base_numbers, shell_arr, N);
		copy_array(base_numbers, quicksort_arr, N);
		copy_array(base_numbers, insertsort_arr, N);
		bubblesort(bubble_arr, N, &bubble_assignment_counter[i], &bubble_comparison_counter[i]);
		shellSort(shell_arr, N, &shellsort_assignment_counter[i], &shellsort_comparison_counter[i]);
		quicksort(quicksort_arr, 0, N - 1, &quicksort_assignment_counter[i], &quicksort_comparison_counter[i]);
		insertsort(insertsort_arr, N, &insertsort_assignment_counter[i], &insertsort_comparison_counter[i]);
	}
	//printf("Bubblesort:\n\tmin przypisan: %ld\n\tmax przypisan: %ld\n\tmin porownan: %ld\n\tmax porownan: %ld\n\tavr przypisan: %ld\n\tavr porownan: %ld\n", min_arr(bubble_assignment_counter, N), max_arr(bubble_assignment_counter, N), min_arr(bubble_comparison_counter, N), max_arr(bubble_comparison_counter, N), average_arr(bubble_assignment_counter, N), average_arr(bubble_comparison_counter, N));
	sort_stats("bubbleSort", bubble_assignment_counter, bubble_comparison_counter, M);
	sort_stats("shellSortt", shellsort_assignment_counter, shellsort_comparison_counter, M);
	sort_stats("quicksort", quicksort_assignment_counter, quicksort_comparison_counter, M);
	sort_stats("insertsort", insertsort_assignment_counter, insertsort_comparison_counter, M);
	free(bubble_arr);
	free(shell_arr);
	free(quicksort_arr);
	free(insertsort_arr);
	return 0;
}

int heaps()
{
	using namespace std;
	string arr[] = { "pizza", "spaghetti", "calzone", "chleb", "ryba", "banany", "arbuz" };

	int n = sizeof(arr) / sizeof(arr[0]);

	Heapsort(arr, n);
	return 0;
}
int dijkstra()
{
	adjacency_list_t adjacency_list(10);
	// 0 = a
	adjacency_list[0].emplace_back(1, 7);
	adjacency_list[0].emplace_back(2, 9);
	adjacency_list[0].emplace_back(6, 13);
	adjacency_list[0].emplace_back(5, 14);
	// 1 = b
	adjacency_list[1].emplace_back(0, 7);
	adjacency_list[1].emplace_back(2, 10);
	adjacency_list[1].emplace_back(3, 15);
	adjacency_list[1].emplace_back(9, 16);
	// 2 = c
	adjacency_list[2].emplace_back(0, 9);
	adjacency_list[2].emplace_back(1, 10);
	adjacency_list[2].emplace_back(3, 11);
	adjacency_list[2].emplace_back(7, 13);
	adjacency_list[2].emplace_back(5, 2);
	// 3 = d
	adjacency_list[3].emplace_back(1, 15);
	adjacency_list[3].emplace_back(2, 11);
	adjacency_list[3].emplace_back(4, 6);
	adjacency_list[3].emplace_back(6, 8);
	// 4 = e
	adjacency_list[4].emplace_back(3, 6);
	adjacency_list[4].emplace_back(5, 9);
	// 5 = f
	adjacency_list[5].emplace_back(0, 14);
	adjacency_list[5].emplace_back(2, 2);
	adjacency_list[5].emplace_back(4, 9);
	// 6 = g
	adjacency_list[6].emplace_back(4, 6);
	adjacency_list[6].emplace_back(1, 2);
	adjacency_list[6].emplace_back(5, 7);
	// 7 = h
	adjacency_list[7].emplace_back(2, 10);
	adjacency_list[7].emplace_back(3, 4);
	adjacency_list[7].emplace_back(6, 9);
	adjacency_list[7].emplace_back(1, 11);
	// 8 = i
	adjacency_list[8].emplace_back(7, 7);
	adjacency_list[8].emplace_back(9, 3);
	adjacency_list[8].emplace_back(0, 10);
	adjacency_list[8].emplace_back(3, 7);
	adjacency_list[8].emplace_back(4, 3);
	// 9 = j
	adjacency_list[9].emplace_back(5, 3);
	adjacency_list[9].emplace_back(7, 10);
	adjacency_list[9].emplace_back(3, 9);
	adjacency_list[9].emplace_back(2, 6);

	std::vector<weight_t> min_distance;
	std::vector<vertex_t> previous;
	dijkstra_compute_paths(0, adjacency_list, min_distance, previous);
	std::cout << "Distance from 0 to 4: " << min_distance[4] << std::endl;
	std::list<vertex_t> path = dijkstra_get_shortest_path_to(4, previous);
	std::cout << "Path : ";
	std::copy(path.begin(), path.end(), std::ostream_iterator<vertex_t>(std::cout, " "));
	std::cout << std::endl;

	return 0;
}
int main()
{
	int choice;
	puts("1. Listy jednokierunkowe.");
	puts("2. Listy dwukierunkowe.");
	puts("3. Listy cykliczne.");
	puts("4. Drzewa.");
	puts("5. Sortowania.");
	puts("6. HeapSort.");
	puts("7. Dijkstra");
	scanf_s("%d", &choice);
	system("cls");
	switch (choice)
	{
	case 1:
		Jednokierunkowe();
		break;
	case 2:
		Dwukierunkowe();
		break;
	case 3:
		Cykliczne();
		break;
	case 4:
		Drzewa();
		break;
	case 5:
		Sortowania();
		break;
	case 6:
		heaps();
		break;
	case 7:
		dijkstra();
		break;
	default:
		break;
	}
	return 0;
}