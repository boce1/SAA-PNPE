from .swap import swap_elements

def buble_sort(arr):
    n = len(arr)
    for i in range(n - 1):
        for j in range(n - i - 1):
            if arr[j] > arr[j + 1]:
                swap_elements(arr, j, j + 1)
    
    print("buble sort: ", end = "")