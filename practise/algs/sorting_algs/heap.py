from .swap import swap_elements

def heapify(arr, N, i):
    largest = i
    left = i * 2 + 1
    right = i * 2 + 2

    if left < N and arr[left] > arr[largest] :
        largest = left
    if right < N and arr[right] > arr[largest]:
        largest = right

    if largest != i:
        swap_elements(arr, i, largest)
        heapify(arr, N, largest)

def heap_sort(arr):
    N = len(arr)

    for i in range(N // 2 - 1, -1, -1):
        heapify(arr, N, i)

    for i in range(N - 1, -1, -1):
        swap_elements(arr, 0, i)
        heapify(arr, i, 0)

    print("Heap sort: ", end = "")