//Дано файл f натуральних чисел. Записати у файл g усі прості числа з файлу f у порядку спадання.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    FILE* fout = fopen("f.txt", "wb");
    if (fout == NULL) {
        printf("Файл не відкрився");
        return 0;
    }

    printf("Введіть декілька натуральних чисел (останнє число 999): \n");
    double num = 0;
    scanf("%lf", &num);
    while (num != 999) {
        fwrite(&num, sizeof(double), 1, fout);
        scanf("%lf", &num);
    }
    fclose(fout);

    FILE* fin = fopen("f.txt", "rb");
    if (fin == NULL) {
        printf("Файл не відкрився");
        return 0;
    }

    int arr[64] = { 0, };
    double element = 0;
    int last = 0;
    while (!feof(fin)) {
        element = 0;
        fread(&element, sizeof(double), 1, fin);
        short t = 1;
        for (int i = 2; i <= element / 2; i++) {
            double element_d = element / i;
            if (element_d - (int)element / i == 0) {
                t = 0;
                break;
            }
        }
        if (t == 1 && element != 0) {
            arr[last] = element;
            last++;
        }
    }
    fclose(fin);
    last--;
    for (int i = 0; i < last; i++) {
        for (int j = 0; j < last - i; j++)
            if (arr[j] < arr[j + 1]) {
                int help = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = help;
            }
    }

    fout = fopen("g.txt", "wb+");
    if (fout == NULL) {
        printf("Файл не відкрився");
        return 0;
    }
    fwrite(arr, sizeof(arr[0]), last + 1, fout);
    printf("Числа з другого файлу: ");
    int print = 0;
    fseek(fout, 0, 0);
    for (int i = 0; i < last + 1; i++) {
        fread(&print, sizeof(arr[0]), 1, fout);
        printf("%d ", print);
    }
    fclose(fout);
    return 0;
}