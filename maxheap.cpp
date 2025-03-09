#include <iostream>
using namespace std;

void max_heapify(int a[], int heap_size, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heap_size && a[left] > a[largest])
        largest = left;

    if (right < heap_size && a[right] > a[largest])
        largest = right;

    if (largest != i) {
        swap(a[i], a[largest]);
        max_heapify(a, heap_size, largest);
    }
}

void build_max_heap(int a[], int heap_size) {
    for (int i = heap_size / 2 - 1; i >= 0; i--) {
        max_heapify(a, heap_size, i);
    }
}

void printArray(int a[], int heap_size) {
    for (int i = 0; i < heap_size; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    //hardcode the input here
    int a[] = {16,4,10,14,7,9,3,2,8,1};
    int heap_size = sizeof(a) / sizeof(a[0]);

    cout << "Original array: ";
    printArray(a, heap_size);

    build_max_heap(a, heap_size);

    cout << "Max-heapified array: ";
    printArray(a, heap_size);

    return 0;
}