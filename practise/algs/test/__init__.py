from random import shuffle

def generate_arr(size):
    arr = [x for x in range(1, size + 1)]
    shuffle(arr)
    return arr

def test_sort(sort_alg, arr):
    print(arr)
    sort_alg()
    print(arr, end = " ")
    if arr == sorted(arr):
        print("Test passed")
    print()


#test_n = 5
#for i in range(test_n):
#    arr = generate_arr(10)
#    test_sort(arr, )

