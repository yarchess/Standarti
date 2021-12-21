#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <cstdlib>
#include <iostream>
using namespace std;

void main() {
	int g, k, m, e = 0;
	int counter_g = 0, counter_m = 0, counter_e = 0;
	int ax[50], ex[50], bx[50], residue[50], gx[50];

	cout<<"Vvedite g: ";
	cin>>g;
	cout<<"Vvedite k: ";
	cin>>k;
	printf("\nVvedite m ot 0 do %d: ", ((2 << (k - 1)) - 1));
	scanf_s("%d", &m);
	while (m > (2 << (k - 1)) - 1) {
		cout<<"Sliwkom bol'shoe chislo - "<<m<< ", vvedite men'we: ";
		cin>>m;
	}
	int tmp_g = g;
	int i = 0;
	while (tmp_g != 0) {
		gx[i] = tmp_g % 2;
		i++;
		tmp_g >>= 1;
		counter_g++;
	}

	int tmp_m = m;
	i = 0;
	while (tmp_m != 0) {
		ax[i] = tmp_m % 2;
		i++;
		tmp_m >>= 1;
		counter_m++;
	}

	for (int i = counter_m-1; i >= 0; i--) {
		ax[i + counter_g - 1] = ax[i];
		ax[i] = 0;
	}
	cout<<"Message v dvoichnom vide: ";
	for (int i = counter_m + counter_g - 2; i >= counter_g-1; i--) {
		cout<<ax[i];
	}
	cout<<"\ng v dvoichnom vide: ";
	for (int i = counter_g - 1; i >= 0; i--) {
		cout<<gx[i];
	}
	cout<<"\n";

	for (i = counter_m + counter_g - 2; i >= 0; i--) {
		residue[i] = ax[i];
	}

	for (i = counter_m + counter_g - 2; i >= 0; i--) {
		if (residue[i] == 0) {
			continue;
		}
		if (i < counter_g - 1) {
			break;
		}
		int i_tmp = i;
		for (int j = counter_g - 1; j >= 0; j--) {

			if (residue[i_tmp] == gx[j]) {
				residue[i_tmp] = 0;
			}
			else { residue[i_tmp] = 1; }
			i_tmp--;
		}
	}

	cout<<"Ostatok ot deleni9 m(x) na g(x):  ";
	for (int i = counter_g - 1; i >= 0; i--) {
		cout<<residue[i];
	}

	cout<<"\na(x): ";

	for (int i = counter_g - 2; i >= 0; i--) { //Начинаем с -2 так как в старшем разряде для g(x) всегда будет 0
		ax[i] = residue[i];
	}

	for (int i = counter_m + counter_g - 2; i >= 0; i--) {
		cout<<ax[i];
	}

	cout<<"\nVvedite e\n ";// e(x)
	int a = 1;
	for (i = counter_m + counter_g - 2; i >= 0; i--) {
		cout << "e["<<a<<"]=";
		cin >> ex[i];
		if (ex[i] > 1) {
			while (ex[i] > 1) {
				cout << "Vvedite 1 libo 0: ";
				cin >> ex[i];
			}
		}
		counter_e++;
		a++;
	}

	cout<<"\nb(x): ";
	for (i = counter_e - 1; i >= 0; i--) {// b(x)
		bx[i] = ex[i] ^ ax[i];
		cout << bx[i];
	}

	for (int i = counter_e - 1; i >= 0; i--) {
		residue[i] = bx[i];
	}

	int check = 1;
	for (int i = counter_e - 1; i >= 0; i--) {
		if (residue[i] == 0) {
			continue;
		}
		if (i < counter_g - 1) {
			break;
		}
		int i_tmp = i;
		for (int j = counter_g - 1; j >= 0; j--) {

			if (residue[i_tmp] == gx[j]) {
				residue[i_tmp] = 0;
			}
			else { residue[i_tmp] = 1; }
			i_tmp--;
		}
	}

	for (int i = 0; i <= counter_g - 1; i++) {
		if (residue[i] == 1) {
			check = 0;
			break;
		}
	}

	int check_e = 0;
	for (int i = counter_e - 1; i >= 0; i--) {
		if (ex[i] == 1) {
			check_e = 1;
			break;
		}
	}
	cout<<"\nOstatok ot deleni9 b(x) na g(x):  ";
	for (int i = counter_g - 1; i >= 0; i--) {
		cout<<residue[i];
	}

	if (check == 1 && check_e == 1) {
		cout<<"\n\nOwibok net\n";
	}
	else {
		cout<<"\n\nOwibka obnarujena\n";
	}
}