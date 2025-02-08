#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int* elements;
  int size;
  int capacity;
} Heap;

typedef struct {
  Heap heap;
} SeatManager;

void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void minHeapify(Heap* heap, int index) {
  int smallest = index;
  int left = 2 * index + 1;
  int right = 2 * index + 2;

  if (left < heap->size && heap->elements[left] < heap->elements[smallest]) {
    smallest = left;
  }
  if (right < heap->size && heap->elements[right] < heap->elements[smallest]) {
    smallest = right;
  }

  if (smallest != index) {
    swap(&heap->elements[smallest], &heap->elements[index]);
    minHeapify(heap, smallest);
  }
}

int full(Heap* heap) { return heap->size == heap->capacity; }

int empty(Heap* heap) { return heap->size == 0; }

void push(Heap* heap, int value) {
  heap->size++;
  if (full(heap)) {
    printf("\nHeap Cheia!\n");
    heap->size--;
    return;
  }

  int position = heap->size - 1;
  heap->elements[position] = value;

  while (position > 0 && heap->elements[(position - 1) / 2] > heap->elements[position]) {
    swap(&heap->elements[position], &heap->elements[(position - 1) / 2]);
    position = (position - 1) / 2;
  }
}

int pop(Heap* heap) {
  if (empty(heap)) {
    return -1;
  }

  int root = heap->elements[0];
  heap->size--;
  heap->elements[0] = heap->elements[heap->size];

  minHeapify(heap, 0);

  return root;
}

SeatManager* seatManagerCreate(int n) {
  SeatManager* seatManager = (SeatManager*)malloc(sizeof(SeatManager));
  if (seatManager == NULL) {
    printf("\nErro ao alocar memória!\n");
    return NULL;
  }

  seatManager->heap.capacity = n;
  seatManager->heap.size = 0;
  seatManager->heap.elements = (int*)malloc(n * sizeof(int));

  for (int counter = 1; counter <= n; counter++) {
    push(&seatManager->heap, counter);
  }

  return seatManager;
}

int seatManagerReserve(SeatManager* obj) { return pop(&obj->heap); }

void seatManagerUnreserve(SeatManager* obj, int seatNumber) { push(&obj->heap, seatNumber); }

void seatManagerFree(SeatManager* obj) {
  free(obj->heap.elements);
  free(obj);
}

int main() {
  SeatManager* manager = seatManagerCreate(5);
  printf("Reserve: %d\n", seatManagerReserve(manager));
  printf("Reserve: %d\n", seatManagerReserve(manager));
  seatManagerUnreserve(manager, 1);
  printf("Reserve: %d\n", seatManagerReserve(manager));
  seatManagerFree(manager);
  return 0;
}
