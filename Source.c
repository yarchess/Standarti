#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>


void main() {
	system("cls");
	srand(time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int g, k, m, e = 0, counter_g = 0, counter_m = 0;
	float b;
	int ax[50], ex[50], bx[50], residue[50], gx[50];

	printf("������� ����������� ���������: ");
	scanf_s("%d", &g);
	printf("������� ���������� �������������� ����� ");
	scanf_s("%d", &k);
	printf("\n������� ��������� � ������� �� 0 �� %d: ", ((2 << (k - 1)) - 1));
	scanf_s("%d", &m);
	while (m > (2 << (k - 1)) - 1) {
		printf("�� ����� ������� ������� ����� ��� ��������� - %d, ������� ������: ", m);
		scanf_s("%d", &m);
	}
	printf("\n������� ����������� ������ �� ���: ");
	scanf_s("%f", &b);


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
	printf("��������� m(x) � �������� ����: ");
	for (int i = counter_m - 1; i >= 0; i--) { //�������� � counter_m - 1, ��� ��� ������ � ������� �� 0
		printf("%d ", ax[i]);
	}
	printf("\n����������� ��������� g(x) � �������� ����: ");
	for (int i = counter_g - 1; i >= 0; i--) {
		printf("%d ", gx[i]);
	}
	printf("\n");

	for (i = counter_m - 1; i >= 0; i--) {
		residue[i] = ax[i];
	}

	for (i = counter_m - 1; i >= 0; i--) {
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

	printf("������� �� ������� m(x) �� g(x):  ");
	for (int i = counter_g - 1; i >= 0; i--) {
		printf("%d ", residue[i]);
	}

	for (int i = counter_m - 1; i >= 0; i--) {
		ax[i + counter_g - 1] = ax[i];
		ax[i] = 0;
	}

	printf("\na(x): ");

	for (int i = counter_g - 2; i >= 0; i--) { //�������� � -2 ��� ��� � ������� ������� ��� g(x) ������ ����� 0
		ax[i] = residue[i];
	}

	for (int i = counter_m + counter_g - 2; i >= 0; i--) { //�������� a(x)
		printf("%d ", ax[i]);
	}
	
	//printf("\n\n%d\n\n", (counter_g + counter_m));
	for (int i = 0; i <= (counter_g + counter_g - 1); i++) {
		int a = (rand() % 10001);
		float y = b * 10000;
		if (y > (float)a) {
			e = e + (1 << i);
		}
	}
	i = 0;
	int counter_e = 0;
	if (e == 0) {
		for (int i = 0; i <= (counter_g + counter_g - 1); i++) {
			ex[i] = 0;
			counter_e++;
		}
	}
	else {
		
		for (int i = 0; i <= (counter_g + counter_g - 1); i++) {
			ex[i] = e % 2;
			e >>= 1;
			counter_e++;
		}
	}

	printf("\n������ ������ � �������� ���� e(x): ");
	for (int i = counter_e - 1; i >= 0; i--) { //������ ������
		printf("%d ", ex[i]);
	}

	for (i = 0; i <= counter_e - 1; i++) {
		bx[i] = ex[i] ^ ax[i];
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

	printf("\n������� �� ������� b(x) �� g(x):  ");
	for (int i = counter_g - 1; i >= 0; i--) {
		printf("%d ", residue[i]);
	}

	if (check == 1) {
		printf("\n\n��������� ������ ��������\n");
	}
	else {
		printf("\n\n������������� ��������� ������� � ���� ���� ������ ��� ��������, ��� ����������\n");
	}
}