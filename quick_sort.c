#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <stdint.h>

// Создание собственного типа MyType на основе uint32_t
typedef uint32_t MyType;

// Заполение массива рандомными числами
void filling_array(MyType *array, int N)
{
	int i;
	for (i=0; i<N; i++)
		array[i] = rand();
}

// Быстрая сортировка
void quick_sort(MyType *array, int low, int high)
{
	int pivot, i, j, temp;
	if(low < high){
		pivot = low;
		i = low;
		j = high;

		while(i < j){
			while ((array[i] <= array[pivot]) && (i <= high))
				i++;

			while((array[j] > array[pivot]) && (j >= low))
				j--;

			if(i < j){
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}

		temp = array[j];
		array[j] = array[pivot];
		array[pivot] = temp;
		quick_sort(array, low, j-1);
		quick_sort(array, j+1, high);
	}
}

void main()
{
	MyType *array;
	int i, N;

	setlocale(LC_ALL, "Russian");

	printf("Введите размер массива: ");
	scanf("%d", &N);

	array = (MyType *) malloc(N * sizeof(MyType));

	filling_array(array, N);

	printf("Исходный массив: ");
	for (i=0; i<N; i++)
		printf("%d ", array[i]);

	quick_sort(array, 0, N);

	printf("\n\n");
	printf("Отсортированный массив: ");
	for (i=0; i<N; i++)
		printf("%d ", array[i]);

	free(array);
	array = NULL;

	_getch();
}

