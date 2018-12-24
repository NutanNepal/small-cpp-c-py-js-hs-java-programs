class Node:
    def __init__(self, L, R, n):
        self.left = L
        self.right = R
        self.value = n

def tree_by_levels(node):
    if not node: return []
    node_list = [node]
    i = 0
    while( i < len(node_list)):
        if node_list[i].left: node_list.append(node_list[i].left)
        if node_list[i].right: node_list.append(node_list[i].right)
        i += 1
    return [x.value for x in node_list]

print(tree_by_levels(None))
print(tree_by_levels(Node(Node(None, Node(None, None, 4), 2), Node(Node(None, None, 5), Node(None, None, 6), 3), 1)))