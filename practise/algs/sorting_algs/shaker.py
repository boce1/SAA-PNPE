from .swap import swap_elements

def shaker_sort(arr):
    left = 0
    right = len(arr) - 1
    k = left
    last_swap = left

    while left < right:
        while k < right:
            if arr[k] > arr[k + 1]:
                swap_elements(arr, k, k + 1)
                last_swap = k
            k += 1
        right = last_swap
        k = right

        while k > left:
            if arr[k] < arr[k - 1]:
                swap_elements(arr, k, k - 1)
                last_swap = k
            k -= 1
        left = last_swap
        k = left

    print("shaker sort: ", end = "")
