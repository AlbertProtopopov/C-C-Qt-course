#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100000
#define SHOW 10

void bubbleSort(int *num, int size);  // пузырьковая сортировка

void quickSort(int *numbers, int left, int right); // быстрая сортировка

void quickSortCall(int *numbers, int left, int right); // быструю сортировку вызываю другим методом, т.к. 
                                                       // в ней рекурсия, чтобы корректно измерить время выполнения
void selectionSort(int *num, int size); // сортировка прямыми включениями

void show(int *num, int size); // показать первые 10 элементов массива

void init(int * array1, int * array2, int * array3);

int main(){

    srand(time(0));

    int array1[SIZE];
    int array2[SIZE];
    int array3[SIZE];
    
    init (array1, array2, array3);
    
    quickSortCall(array1, 0, SIZE - 1);
    show(array1, SHOW);
    
    selectionSort(array2, SIZE);
    show(array2, SHOW);
    
    bubbleSort(array3, SIZE);
    show(array3, SHOW);
    
    return 0;
}

void init(int * array1, int * array2, int * array3){

    for (int i = 0; i < SIZE; i++){
    
        array1[i] = rand();
        array2[i] = array1[i];
        array3[i] = array1[i];
    }    
};

void show(int *array, int size){

    for (int i = 0; i < size; i++)
        if (i < 10)
            printf("array[%d] = %d\n", i, array[i]);
    printf("\n");
};

void bubbleSort(int *num, int size){

    double sortTime = 0.0;
  
    clock_t start = clock();

    for (int i = 0; i < size - 1; i++){
    
        for (int j = (size - 1); j > i; j--){
            if (num[j - 1] > num[j]){
                int temp = num[j - 1];
                num[j - 1] = num[j];
                num[j] = temp;
            }
        }
    }
  
    clock_t end = clock();
    sortTime = (double) (end - start) / (CLOCKS_PER_SEC);
    printf("Bubble sort time %f seconds\n", sortTime);
    printf("First 10 elements:\n");  
}

void quickSort(int *numbers, int left, int right){
  
    int pivot; // разрешающий элемент
    int l_hold = left; //левая граница
    int r_hold = right; // правая граница
    pivot = numbers[left];
    while (left < right){ // пока границы не сомкнутся

        while ((numbers[right] >= pivot) && (left < right))
            right--; // сдвигаем правую границу пока элемент [right] больше [pivot]
        if (left != right){ // если границы не сомкнулись
            numbers[left] = numbers[right]; // перемещаем элемент [right] на место разрешающего
            left++; // сдвигаем левую границу вправо
        }
        while ((numbers[left] <= pivot) && (left < right))
            left++; // сдвигаем левую границу пока элемент [left] меньше [pivot]
        if (left != right){ // если границы не сомкнулись
            numbers[right] = numbers[left]; // перемещаем элемент [left] на место [right]
            right--; // сдвигаем правую границу вправо
        }
    }
    numbers[left] = pivot; // ставим разрешающий элемент на место
    pivot = left;
    left = l_hold;
    right = r_hold;
    
    if (left < pivot) // Рекурсивно вызываем сортировку для левой и правой части массива
        quickSort(numbers, left, pivot - 1);
    if (right > pivot)
        quickSort(numbers, pivot + 1, right);
}

void quickSortCall(int *numbers, int left, int right){
    
    double sortTime = 0.0;
       
    clock_t start = clock();
    
    quickSort(numbers, left, right);
    
    clock_t end = clock();
    sortTime = (double) (end - start) / (CLOCKS_PER_SEC);
    printf("Quick sort time %f seconds\n", sortTime);
    printf("First 10 elements:\n");  
};

void selectionSort(int *num, int size){

    double sortTime = 0.0;
  
    clock_t start = clock();

    int min, temp; // для поиска минимального элемента и для обмена
    for (int i = 0; i < size - 1; i++){
        min = i; // запоминаем индекс текущего элемента
    // ищем минимальный элемент чтобы поместить на место i-ого
        for (int j = i + 1; j < size; j++){  // для остальных элементов после i-ого
            if (num[j] < num[min]) // если элемент меньше минимального,
            min = j;       // запоминаем его индекс в min
        }
        temp = num[i];      // меняем местами i-ый и минимальный элементы
        num[i] = num[min];
        num[min] = temp;
    }
  
    clock_t end = clock();
    sortTime = (double) (end - start) / (CLOCKS_PER_SEC);
    printf("Selection sort time %f seconds\n", sortTime);
    printf("First 10 elements:\n");  
}
