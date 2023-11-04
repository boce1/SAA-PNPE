from .swap import swap_elements

def shell_sort(arr):
    n = len(arr)
    gap = n // 2

    while gap > 0:
        for i in range(gap, n):
            j = i
            while j >= gap and arr[j] < arr[j - gap]:
                swap_elements(arr, j, j - gap)
                j -= gap
        gap //= 2

    print("shell sort: ", end = "")
        
