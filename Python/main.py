import Binary_Search_Tree.bst, Dynamic_Array.DynamicArray, Hash_Table.HashTable, Linked_List.LinkedList, Priority_Queue.PriorityQueue, Queue.Queue, Sparse_Matrix.Sparse_Matrix, Stack.Stack


def binary_search_tree_test(test_arr):
    empty_bst = Binary_Search_Tree.bst.BinarySearchTree()
    bst = Binary_Search_Tree.bst.BinarySearchTree(test_arr)


def dynamic_array_test(test_arr):
    empty_da = Dynamic_Array.DynamicArray.DynamicArray()
    da = Dynamic_Array.DynamicArray.DynamicArray(test_arr)


def hash_table_test():
    div_ht = Hash_Table.HashTable.HashTable(0, 0)
    mid_sq_ht = Hash_Table.HashTable.HashTable(1, 0)
    dig_fold_ht = Hash_Table.HashTable.HashTable(2, 0)
    mult_ht = Hash_Table.HashTable.HashTable(3, 0)


def linked_list_test(test_arr):
    empty_ll = Linked_List.LinkedList.LinkedList()
    ll = Linked_List.LinkedList.LinkedList(test_arr)


def priority_queue_test(test_arr):
    empty_pq = Priority_Queue.PriorityQueue.PriorityQueue()
    pq = Priority_Queue.PriorityQueue.PriorityQueue(test_arr)


def queue_test(test_arr):
    empty_q = Queue.Queue.Queue()
    q = Queue.Queue.Queue(test_arr)


def sparse_matrix_test(test_matrix):
    empty_sm = Sparse_Matrix.Sparse_Matrix.SparseMatrix()
    sm = Sparse_Matrix.Sparse_Matrix.SparseMatrix(test_matrix)


def stack_test(test_arr):
    empty_s = Stack.Stack.Stack()
    s = Stack.Stack.Stack(test_arr)


def main():
    test_arr = [5, 3, 7, 2, 4, 6, 8]
    test_matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
    binary_search_tree_test(test_arr)
    dynamic_array_test(test_arr)
    hash_table_test()
    linked_list_test(test_arr)
    priority_queue_test(test_arr)
    queue_test(test_arr)
    sparse_matrix_test(test_matrix)
    stack_test(test_arr)
