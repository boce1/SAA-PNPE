class TreeNode():
    def __init__(self, value = 0, left = None, right = None):
        self.value = value
        self.left = left
        self.right = right


def preorder_traversal(root):
    if root:
        print(root.value, end = " ")
        preorder_traversal(root.left)
        preorder_traversal(root.right)

def inorder_traversal(root):
    if root:
        inorder_traversal(root.left)
        print(root.value, end = " ")
        inorder_traversal(root.right)

def postorder_traversal(root):
    if root:
        postorder_traversal(root.left)
        postorder_traversal(root.right)
        print(root.value, end = " ")

def invert_tree(root):
    if root:
        if root.left and root.right:
            temp = root.left
            root.left = root.right
            root.right = temp
           
        invert_tree(root.left)
        invert_tree(root.right)
