class ListNode:
    def __init__(self, value = 0, next = None):
        self.value = value
        self.next = next

def print_list(head):
    print("[ ", end = "")
    while head:
        print(head.value, end = " ")
        head = head.next
    print("]")


def print_list2(head):
    if head:
        print(head.value, end = " ")
        print_list2(head.next)
    else:
        print()

def invert_list(head):
    prev = None

    while head and head.next:
        next_node = head.next
        head.next = prev
        prev = head
        head = next_node
    head.next = prev

    return head

def cancatonate_lists(head1, head2):
    dummy = ListNode()
    temp = dummy

    while head1 and head2:
        if head1.value < head2.value:
            temp.next = head1
            head1 = head1.next
        else:
            temp.next = head2
            head2 = head2.next

        temp = temp.next

    while head1:
        temp.next = head1
        temp = temp.next

    while head2:
        temp.next = head2
        temp = temp.next

    return dummy.next