from .swap import swap_elements

def selection_sort(arr):
    n = len(arr)

    for i in range(n - 1):
        min_index = i
        for j in range(i + 1, n):
            if arr[j] < arr[min_index]:
                min_index = j
        swap_elements(arr, min_index, i) 

    print("selection sort: ", end = "")
