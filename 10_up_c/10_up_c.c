// ���������
// ���� ��������� ����, ���������� ����� � ���� ����� a1, a2, a3,..., an. �������� ����,
// ���������� ����� ������ ������� �������� ����� ��������.������� ��������
// ��������� �� �������� ai=[a(i-1)+a(i)+a(i+1)/3], �� i = 2, 3, ..., n - 1.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "windows.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	FILE* file = fopen("file.txt", "w");
	char s[100], ss[100], newfilename[100];
	double a, b;
	if (!file)
	{
		printf("��������� ������� ����1\n");
		return 1;
	}
	fprintf(file, "6 13 34 76 34 86 45 90 87");
	fclose(file);

	FILE* ifile = fopen("file.txt", "r");
	if (!ifile)
	{
		printf("��������� ������� ����2\n");
		return 1;
	}


	while (!feof(ifile))
	{
		getline(ifile, ss);
		printf("%s\n", ss);
	}

	fclose(ifile);

	printf("������ ��� ������ �����\n");
	scanf("%s", newfilename);
	FILE* newout = fopen(newfilename, "w");
	if (!newout)
	{
		printf("��������� ������� ����3\n");
		return 1;
	}

	FILE* ifile2 = fopen("file", "r");
	if (!ifile2)
	{
		printf("��������� ������� ����4\n");
		return 1;
	}
	int arr = 0;
	while (!feof(ifile2))  // �������
	{
		double a, b;
		fseek(ifile2, arr, SEEK_SET);
		a = 0;
		for (int i = 0; i < 3; i++)
		{
			fscanf(ifile2, "%fL", &b);
			a = a + b;
			if (i == 0)
			{
				arr = ftell(ifile2);
			}
		}
		fprintf(newout, "%fL ", a / 3);
	}
	fclose(newout);
	fclose(ifile);

	return 0;
}