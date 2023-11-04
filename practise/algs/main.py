import test
import sorting_algs
import binary_tree
import linked_list

def test_sorting_algs():
    size = 10

    arr_t = test.generate_arr(size)
    test.test_sort(lambda : sorting_algs.buble_sort(arr_t), arr_t)

    arr_t = test.generate_arr(size)
    test.test_sort(lambda : sorting_algs.selection_sort(arr_t), arr_t)

    arr_t = test.generate_arr(size)
    test.test_sort(lambda : sorting_algs.merge_sort(arr_t), arr_t)

    arr_t = test.generate_arr(size)
    test.test_sort(lambda : sorting_algs.insertion_sort(arr_t), arr_t)

    arr_t = test.generate_arr(size)
    test.test_sort(lambda : sorting_algs.shaker_sort(arr_t), arr_t)

    arr_t = test.generate_arr(size)
    test.test_sort(lambda : sorting_algs.shell_sort(arr_t), arr_t)

    arr_t = test.generate_arr(size)
    test.test_sort(lambda : sorting_algs.quick_sort(arr_t, 0, len(arr_t) - 1), arr_t)

    arr_t = test.generate_arr(size)
    test.test_sort(lambda : sorting_algs.quick_sort2(arr_t, 0, len(arr_t) - 1), arr_t)

    arr_t = test.generate_arr(size)
    test.test_sort(lambda : sorting_algs.heap_sort(arr_t), arr_t)

    arr_t = test.generate_arr(size)
    test.test_sort(lambda : sorting_algs.count_sort(arr_t), arr_t)

    arr_t = test.generate_arr(size)
    test.test_sort(lambda : sorting_algs.radix_sort(arr_t), arr_t)

def test_binary_tree():
    n1 = binary_tree.TreeNode(value = 1)
    n1_2 = binary_tree.TreeNode(value = 2)
    n1_3 = binary_tree.TreeNode(value = 3)
    n2_4 = binary_tree.TreeNode(value = 4)
    n2_5 = binary_tree.TreeNode(value = 5)
    n3_6 = binary_tree.TreeNode(value = 6)
    n3_7 = binary_tree.TreeNode(value = 7)
    
    n1.left = n1_2
    n1.right = n1_3

    n1_2.left = n2_4
    n1_2.right = n2_5

    n1_3.left = n3_6
    n1_3.right = n3_7

    print("Preoder traversal")
    binary_tree.preorder_traversal(n1)
    print("\nInorder traversal")
    binary_tree.inorder_traversal(n1)
    print("\nPostorder traversal")
    binary_tree.postorder_traversal(n1)
    print()

    print("inverting")
    binary_tree.invert_tree(n1)
    print("Preorder tranversal")
    binary_tree.preorder_traversal(n1)

def test_linked_list():
    n1 = linked_list.ListNode(value = 1)
    n2 = linked_list.ListNode(value = 2)
    n3 = linked_list.ListNode(value = 3)
    n4 = linked_list.ListNode(value = 4)
    n5 = linked_list.ListNode(value = 5)

    n1.next = n2
    n2.next = n3
    n3.next = n4
    n4.next = n5

    linked_list.print_list(n1)
    head = linked_list.invert_list(n1)
    linked_list.print_list(head)

    head2 = linked_list.cancatonate_lists(n1, n1)

#test_binary_tree()
test_sorting_algs()
#test_linked_list()