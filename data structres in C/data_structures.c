#include <stdio.h>
#include <stdlib.h>

// array
int oper;
int i;
int no_of_ele_arr, arr[100], oper_on_arr;
int arr_ins_at_end()
{
    int ins_val;
    printf("you are inserting the element at end\n");
    printf("enter the value that you want to insert at last\n");
    scanf("%d", &ins_val);
    arr[no_of_ele_arr] = ins_val;
    no_of_ele_arr++;
    printf("Array after insertion:\n");
    printf("\t|");
    for (i = 0; i < no_of_ele_arr; i++)
    {
        printf("\t%d ", arr[i]);
    }
    printf("\t|");
    printf("\n");
}
int arr_ins_at_any_pos()
{
    int ins_pos, ins_val;
    printf("enter the position you want to insert\n");
    scanf("%d", &ins_pos);
    printf("enter the value you want to see on that position\n");
    scanf("%d", &ins_val);
    // here logic is that i will go end to starting and insert element
    for (i = no_of_ele_arr; i >= ins_pos; i--)
    {
        // to move the right sided elements of inserted element oon right side
        arr[i] = arr[i - 1];
    }
    // to put the vslue
    arr[ins_pos - 1] = ins_val;
    no_of_ele_arr++;
    printf("Array after insertion:\n");
    printf("\t|");
    for (i = 0; i < no_of_ele_arr; i++)
    {
        printf("\t%d ", arr[i]);
    }
    printf("\t|");
    printf("\n");
}
int arr_del_at_end()
{
    printf("you are deleting the element at end\n");
    no_of_ele_arr--;
    printf("Array after delete last element:\n");
    printf("\t|");
    for (i = 0; i < no_of_ele_arr; i++)
    {
        printf("\t%d ", arr[i]);
    }
    printf("\t|");
    printf("\n");
}
int arr_del_at_pos()
{
    int del_pos, del_val;
    printf("you are deleting the element by position\n");
    printf("enter the position that you want to delete\n");
    scanf("%d", &del_pos);
    for (i = del_pos; i < no_of_ele_arr - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    no_of_ele_arr--;

    printf("after deleting the element at position %d\n", i);
    printf("\t|");
    for (i = 0; i < no_of_ele_arr; i++)
    {
        printf("\t%d ", arr[i]);
    }
    printf("\t|");
    printf("\n");
}
int arr_rev()
{
    for (i = 0; i < no_of_ele_arr / 2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[no_of_ele_arr - i - 1];
        arr[no_of_ele_arr - i - 1] = temp;
    }
    printf("after reversing the array\n", i);
    printf("\t|");
    for (i = 0; i < no_of_ele_arr; i++)
    {
        printf("\t%d ", arr[i]);
    }
    printf("\t|");
    printf("\n");
}
int min_ele_arr()
{
    int min = arr[0];
    for (i = 0; i < no_of_ele_arr; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    printf("the minimum element is %d\n", min);
}
int max_ele_arr()
{
    int max = arr[0];
    for (i = 0; i < no_of_ele_arr; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    printf("the maximum element is %d\n", max);
}
int arr_lin_ser()
{
    int sear_val, found;
    printf("entr the value that yu want to search\n");
    scanf("%d", &sear_val);
    for (i = 0; i < no_of_ele_arr; i++)
    {
        if (sear_val == arr[i])
        {
            found = 1;
            break;
        }
    }
    if (found == 1)
    {
        printf("element is present in the array at position %d", i);
    }
}
void selectionSort()
{
    int j, min_idx, temp;
    for (i = 0; i < no_of_ele_arr - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < no_of_ele_arr; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
    printf("\t\t |");
    for (i = 0; i < no_of_ele_arr; i++)
    {
        printf("\t%d", arr[i]);
    }
    printf("|");
}
int BubbleSort()
{
    int j, temp;
    for (i = 0; i < no_of_ele_arr - 1; i++)
    {
        for (j = 0; j < no_of_ele_arr - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("\t\t |");
    for (i = 0; i < no_of_ele_arr; i++)
    {
        printf("\t%d", arr[i]);
    }
    printf("|");
}
int swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}
int QuickSort()
{
    quicksort(arr, 0, no_of_ele_arr - 1);
    printf("Sorted array: \n");
    printf("\t\t |");
    for (i = 0; i < no_of_ele_arr; i++)
    {
        printf("\t%d", arr[i]);
    }
    printf("|");
}
int insertionsort()
{
    for (i = 0; i < no_of_ele_arr; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j > 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    printf("\t\t |");
    for (i = 0; i < no_of_ele_arr; i++)
    {
        printf("\t%d", arr[i]);
    }
    printf("|");
}
void merge(int A[], int mid, int low, int high)
{
    int i, j, k, B[100];
    i = low;
    j = mid + 1;
    k = low;
    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        B[k] = A[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        B[k] = A[j];
        k++;
        j++;
    }
    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
}
void mergeSort(int A[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergeSort(A, low, mid);
        mergeSort(A, mid + 1, high);
        merge(A, mid, low, high);
    }
}
int sorting_array()
{
    int arr_sort_op;
    printf("you are sorting array\n");
    printf("enter 1 for selection sort\n");
    printf("enter 2 for bubble sort\n");
    printf("enter 3 for quick sort \n");
    printf("enter 4 for insertion sort \n");
    printf("enter 5 for merge sort \n");
    scanf("%d", &arr_sort_op);
    switch (arr_sort_op)
    {
    case 1:
        selectionSort();
        break;
    case 2:
        BubbleSort();
        break;
    case 3:
        QuickSort();
        break;
    case 4:
        insertionsort();
        break;
    case 5:
        mergeSort(arr, 0, 6);
        break;
    default:
        break;
    }
}
int binarySearch(int arr[], int low, int high, int ex_val)
{
    if (high < low)
    {
        return -1;
    }
    int mid = (low + high) / 2;
    if (ex_val == arr[mid])
    {
        return mid;
    }
    if (ex_val < arr[mid])
    {
        return binarySearch(arr, low, mid - 1, ex_val);
    }
    else
    {
        return binarySearch(arr, mid + 1, high, ex_val);
    }
}
int finalbinsearch()
{
    int ex_val;
    printf("Array before sorting: ");
    for (int i = 0; i < no_of_ele_arr; i++)
    {
        printf("%d ", arr[i]);
    }
    selectionSort();
    printf("\nArray after sorting: ");
    for (int i = 0; i < no_of_ele_arr; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("enter the expected value\n");
    scanf("%d", &ex_val);
    int index = binarySearch(arr, 0, no_of_ele_arr - 1, ex_val);
    if (index != -1)
    {
        printf("\n%d found at index %d\n", ex_val, index);
    }
    else
    {
        printf("\n%d not found\n", ex_val);
    }
}
int arr_search()
{
    int search_op;
    printf("you are sarchng th elment \n");
    printf("enter\t1\t for linear search\n");
    printf("enter\t2\t for binary search\n");
    scanf("%d", &search_op);
    if (search_op == 1)
    {
        printf("you ae searching linearly\n");
        arr_lin_ser();
    }
    else if (search_op == 2)
    {
        printf("you ae searching bnarily\n");
        finalbinsearch();
    }
}
int arr_op_menu()
{
    printf("\t=========================================\n");
    printf("\timplimentation of various functions on arrays\n");
    printf("\t=========================================\n");
    printf("\t\t\tenter   1   for   insertion at end \n");
    printf("\t\t\tenter   2   for   insertion at any point \n");
    printf("\t\t\tenter   3   for   deletion at end \n");
    printf("\t\t\tenter   4   for   deletion at any point \n");
    printf("\t\t\tenter   5   for   reverse array \n");
    printf("\t\t\tenter   6   for   minimum element \n");
    printf("\t\t\tenter   7   for   maximum element \n");
    printf("\t\t\tenter   8   for   searching the element \n");
    printf("\t\t\tenter   9   for   sorting the array \n");
    printf("enter your operation that you want \n");
    scanf("%d", &oper_on_arr);
    switch (oper_on_arr)
    {
    case 1:
        printf("inserting at the end\n");
        arr_ins_at_end();
        break;
    case 2:
        printf("inserting at any position");
        arr_ins_at_any_pos();
        break;
    case 3:
        printf(" array element delete at end ");
        arr_del_at_end();
        break;
    case 4:
        printf(" array element delete at any position ");
        arr_del_at_pos();
        break;
    case 5:
        printf(" reversing array \n ");
        arr_rev();
        break;
    case 6:
        printf(" minimum in array \n ");
        min_ele_arr();
        break;
    case 7:
        printf(" maximum in array \n ");
        max_ele_arr();
        break;
    case 8:
        printf(" search an elemnt in array \n ");
        arr_search();
        break;
    case 9:
        printf("sorting the element\n");
        sorting_array();

    default:
        break;
    }
}
int array_op()
{
    printf("operating on array\n");
    printf("enter the number of elements in your array\n");
    scanf("%d", &no_of_ele_arr);
    for (i = 0; i < no_of_ele_arr; i++)
    {
        printf("enter the element %d for array\n", i);
        scanf("%d", &arr[i]);
    }
    printf("your given elements are\n");
    printf("\t|");

    for (i = 0; i < no_of_ele_arr; i++)
    {
        printf("\t%d", arr[i]);
    }
    printf("\t|");
    printf("\n");
    arr_op_menu();
}

// linked list
struct nodes *head;
struct noded *headd;
int link_list_oprs;
struct nodes
{
    int data;
    struct nodes *next;
};
struct noded
{
    struct noded *prev;
    int data;
    struct noded *next;
};
int LL_trav(struct nodes *ptr)
{
    int no_of_ele_LL = 0;
    while (ptr != NULL)
    {
        printf(" element : %d   value :  %d  \n", no_of_ele_LL, ptr->data);
        ptr = ptr->next;
        no_of_ele_LL++;
    }
    return no_of_ele_LL;
}
int LL_trav_d(struct noded *ptrd)
{
    int no_of_ele_LL_d = 0;
    while (ptrd != NULL)
    {
        printf(" element : %d   value :  %d  \n", no_of_ele_LL_d, ptrd->data);
        ptrd = ptrd->next;
        no_of_ele_LL_d++;
    }
    return no_of_ele_LL_d;
}
int LL_trav_c(struct nodes *head)
{
    int no_of_ele_LL = 0;
    struct nodes *ptr = head;
    do
    {
        printf(" element : %d   value :  %d  \n", no_of_ele_LL, ptr->data);
        ptr = ptr->next;
        no_of_ele_LL++;
    } while (ptr != head);
    return no_of_ele_LL;
}
int LL_trav_d_c(struct noded *ptrd)
{
    int no_of_ele_LL_d = 0;
    do
    {
        printf(" element : %d   value :  %d  \n", no_of_ele_LL_d, ptrd->data);
        ptrd = ptrd->next;
        no_of_ele_LL_d++;
    } while (ptrd != headd);
    return no_of_ele_LL_d;
}
int create_node_sin_LL()
{
    struct nodes *second;
    struct nodes *third;
    struct nodes *fourth;
    // allocate memory for nodes in linked list in heap
    head = (struct nodes *)malloc(sizeof(struct nodes));
    second = (struct nodes *)malloc(sizeof(struct nodes));
    third = (struct nodes *)malloc(sizeof(struct nodes));
    fourth = (struct nodes *)malloc(sizeof(struct nodes));
    // link 1 st and 2 nd
    head->data = 10;
    head->next = second;
    // link 2 nd and 3 rd
    second->data = 20;
    second->next = third;
    // link 3 rd and 4 th
    third->data = 30;
    third->next = fourth;
    // terminating
    fourth->data = 40;
    fourth->next = NULL;
    LL_trav(head);
}
int create_node_dub_LL()
{
    struct noded *second;
    struct noded *third;
    struct noded *fourth;
    // allocate memory for nodes in linked list in heap
    headd = (struct noded *)malloc(sizeof(struct noded));
    second = (struct noded *)malloc(sizeof(struct noded));
    third = (struct noded *)malloc(sizeof(struct noded));
    fourth = (struct noded *)malloc(sizeof(struct noded));
    // link 1 st and 2 nd
    headd->prev = NULL;
    headd->data = 100;
    headd->next = second;
    // link 2 nd and 3 rd
    second->prev = headd;
    second->data = 200;
    second->next = third;
    // link 3 rd and 4 th
    third->prev = second;
    third->data = 300;
    third->next = fourth;
    // terminating
    fourth->prev = third;
    fourth->data = 400;
    fourth->next = NULL;
    LL_trav_d(headd);
}
int create_node_sin_LL_cc()
{
    printf("we are creating the singly linked circular linked list\n");
    struct nodes *second;
    struct nodes *third;
    struct nodes *fourth;
    // allocate memory for nodes in linked list in heap
    head = (struct nodes *)malloc(sizeof(struct nodes));
    second = (struct nodes *)malloc(sizeof(struct nodes));
    third = (struct nodes *)malloc(sizeof(struct nodes));
    fourth = (struct nodes *)malloc(sizeof(struct nodes));
    // link 1 st and 2 nd
    head->data = 11;
    head->next = second;
    // link 2 nd and 3 rd
    second->data = 22;
    second->next = third;
    // link 3 rd and 4 th
    third->data = 33;
    third->next = fourth;
    // terminating
    fourth->data = 44;
    fourth->next = head;
    LL_trav_c(head);
}
int create_node_dub_LL_cc()
{
    printf("we are creating the doubly linked circular linked list\n");
    struct noded *second;
    struct noded *third;
    struct noded *fourth;
    // allocate memory for nodes in linked list in heap
    headd = (struct noded *)malloc(sizeof(struct noded));
    second = (struct noded *)malloc(sizeof(struct noded));
    third = (struct noded *)malloc(sizeof(struct noded));
    fourth = (struct noded *)malloc(sizeof(struct noded));
    // link 1 st and 2 nd
    headd->prev = fourth;
    headd->data = 111;
    headd->next = second;
    // link 2 nd and 3 rd
    second->prev = headd;
    second->data = 222;
    second->next = third;
    // link 3 rd and 4 th
    third->prev = second;
    third->data = 333;
    third->next = fourth;
    // terminating
    fourth->prev = third;
    fourth->data = 444;
    fourth->next = headd;
    LL_trav_d_c(headd);
}
struct nodes *ins_ND_LL_beg_op(struct nodes *head, int data)
{
    struct nodes *ptr = (struct nodes *)malloc(sizeof(struct nodes));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}
struct nodes *ins_ND_LL_pos_op(struct nodes *head, int data, int pos)
{
    struct nodes *ptr = (struct nodes *)malloc(sizeof(struct nodes));
    struct nodes *p = head;
    int i = 0;
    while (i != pos - 1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}
struct nodes *ins_ND_LL_end_op(struct nodes *head, int data)
{
    struct nodes *ptr = (struct nodes *)malloc(sizeof(struct nodes));
    struct nodes *p = head;
    ptr->next = head;
    ptr->data = data;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}
struct nodes *del_ND_LL_beg_op(struct nodes *head)
{
    struct nodes *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}
struct nodes *del_ND_LL_pos_op(struct nodes *head, int pos)
{
    struct nodes *p = head;
    struct nodes *q = head->next;
    for (int i = 0; i < pos - 1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}
struct nodes *del_ND_LL_end_op(struct nodes *head)
{
    struct nodes *p = head;
    struct nodes *q = head->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}
struct nodes *del_ND_LL_val_op(struct nodes *head, int val)
{
    struct nodes *p = head;
    struct nodes *q = head->next;
    while (q->data != val && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    if (q->data == val)
    {
        p->next = q->next;
        free(q);
    }
    return head;
}
struct noded *ins_ND_LL_beg_op_d(struct noded *headd, int data)
{
    struct noded *ptr = (struct noded *)malloc(sizeof(struct noded));
    ptr->next = headd;
    ptr->data = data;
    ptr->prev = NULL;
    return ptr;
}
struct noded *ins_ND_LL_pos_op_d(struct noded *headd, int data, int pos)
{
    struct noded *ptr = (struct noded *)malloc(sizeof(struct noded));
    struct noded *p = headd;
    int i = 0;
    while (i != pos - 1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    ptr->prev = p;
    return headd;
}
struct noded *ins_ND_LL_end_op_d(struct noded *headd, int data)
{
    struct noded *ptr = (struct noded *)malloc(sizeof(struct noded));
    struct noded *p = headd;
    ptr->next = headd;
    ptr->data = data;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    ptr->prev = p;
    return headd;
}
struct noded *del_ND_LL_beg_op_d(struct noded *headd)
{
    struct noded *ptr = headd;
    headd = headd->next;
    headd->prev = NULL;
    free(ptr);
    return headd;
}
struct noded *del_ND_LL_pos_op_d(struct noded *headd, int pos)
{
    struct noded *p = headd;
    struct noded *q = headd->next;
    for (int i = 0; i < pos - 1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    p->prev = q->prev;
    free(q);
    return headd;
}
struct noded *del_ND_LL_end_op_d(struct noded *headd)
{
    struct noded *p = headd;
    struct noded *q = headd->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    p->prev = q->prev;
    free(q);
    return headd;
}
struct noded *del_ND_LL_val_op_d(struct noded *headd, int val)
{
    struct noded *p = headd;
    struct noded *q = headd->next;
    while (q->data != val && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    if (q->data == val)
    {
        p->next = q->next;
        p->prev = q->prev;
        free(q);
    }
    return headd;
}
struct nodes *ins_ND_LL_beg_op_c(struct nodes *head, int data)
{
    struct nodes *ptr = (struct nodes *)malloc(sizeof(struct nodes));
    ptr->data = data;
    struct nodes *p = head->next;
    while (p->next != head)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}
struct nodes *ins_ND_LL_pos_op_c(struct nodes *head, int data, int pos)
{
    struct nodes *ptr = (struct nodes *)malloc(sizeof(struct nodes));
    ptr->data = data;
    struct nodes *currnode = head;
    int currpos = 1;
    int i = 0;
    while (currpos < pos - 1 && currnode->next != head)
    {
        currnode = currnode->next;
        currpos++;
    }
    ptr->next = currnode->next;
    currnode->next = ptr;
}
struct nodes *ins_ND_LL_end_op_c(struct nodes *head, int data)
{
    struct nodes *ptr = (struct nodes *)malloc(sizeof(struct nodes));
    ptr->next = NULL;
    ptr->data = data;
    struct nodes *last = head;
    while (last->next != head)
    {
        last = last->next;
    }
    last->next = ptr;
    ptr->next = head;
    return head;
}
struct noded *ins_ND_LL_beg_op_d_c(struct noded *headd, int data)
{
    struct noded *ptr = (struct noded *)malloc(sizeof(struct noded));
    ptr->data = data;
    struct noded *last = headd->prev;
    ptr->next = headd;
    ptr->prev = last;
    last->next = ptr;
    headd = ptr;
    return headd;
}
struct noded *ins_ND_LL_pos_op_d_c(struct noded *headd, int data, int pos)
{
    struct noded *ptr = (struct noded *)malloc(sizeof(struct noded));
    ptr->data = data;
    struct noded *currnode = headd;
    int currpos = 1;
    int i = 0;
    while (currpos < pos - 1 && currnode->next != headd)
    {
        currnode = currnode->next;
        currpos++;
    }
    ptr->next = currnode->next;
    ptr->prev = currnode;
    currnode->next->prev = ptr;
    currnode->next = ptr;
}
struct noded *ins_ND_LL_end_op_d_c(struct noded *headd, int data)
{
    struct noded *ptr = (struct noded *)malloc(sizeof(struct noded));
    ptr->data = data;
    struct noded *last = headd->prev;
    ptr->next = headd;
    ptr->prev = last;
    last->next = ptr;
    headd->prev = ptr;
}
struct nodes *del_ND_LL_beg_op_c(struct nodes *head)
{
    struct nodes *p = head;
    struct nodes *q = head;
    while (q->next != head)
        q = q->next;
    p = head->next;
    q->next = p;
    free(head);
    return p;
}
struct nodes *del_ND_LL_pos_op_c(struct nodes *head, int pos)
{
    struct nodes *p = head;
    struct nodes *q = head->next;
    for (int i = 0; i < pos - 1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}
struct nodes *del_ND_LL_end_op_c(struct nodes *head)
{
    struct nodes *p = head;
    struct nodes *q = head->next;
    while (q->next != head)
    {
        p = p->next;
        q = q->next;
    }
    p->next = head;
    free(q);
    return head;
}
struct nodes *del_ND_LL_val_op_c(struct nodes *head, int val)
{
    struct nodes *p = head;
    struct nodes *q = head->next;
    while (q->data != val && q->next != head)
    {
        p = p->next;
        q = q->next;
    }
    if (q->data == val)
    {
        p->next = q->next;
        free(q);
    }
    return head;
}
struct noded *del_ND_LL_beg_op_d_c(struct noded *headd)
{
    struct noded *last = headd->prev;
    struct noded *ptr = headd->next;
    ptr->prev = last;
    last->next = ptr;
    free(headd);
    return ptr;
}
struct noded *del_ND_LL_pos_op_d_c(struct noded *headd, int pos)
{
    struct noded *p = headd;
    struct noded *q = headd->next;
    for (int i = 0; i < pos - 1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    p->prev = q->prev;
    free(q);
    return headd;
}
struct noded *del_ND_LL_end_op_d_c(struct noded *headd)
{
    struct noded *p = headd;
    struct noded *q = headd->next;
    while (q->next != headd)
    {
        p = p->next;
        q = q->next;
    }
    p->next = headd;
    p->prev = q->prev;
    free(q);
    return headd;
}
struct noded *del_ND_LL_val_op_d_c(struct noded *headd, int val)
{
    struct noded *p = headd;
    struct noded *q = headd->next;
    while (q->data != val && q->next != headd)
    {
        p = p->next;
        q = q->next;
    }
    if (q->data == val)
    {
        p->next = q->next;
        p->prev = q->prev;
        free(q);
    }
    return headd;
}
int ins_ND_LL_beg()
{
    printf("you are inserting the node at begaining\n");
    head = ins_ND_LL_beg_op(head, 56);
    LL_trav(head);
}
int ins_ND_LL_end()
{
    printf("you are inserting the node at end\n");
    head = ins_ND_LL_end_op(head, 100);
    LL_trav(head);
} // inserting node at begaining
int ins_ND_LL_pos()
{
    printf("you are inserting the node at position\n");
    head = ins_ND_LL_pos_op(head, 100, 2);
    LL_trav(head);
}
int del_ND_LL_beg()
{
    LL_trav(head);
    printf("you are deletingthe node at begaining\n");
    head = del_ND_LL_beg_op(head);
    LL_trav(head);
}
int del_ND_LL_pos()
{
    LL_trav(head);
    printf("you are deletingthe node at index\n");
    head = del_ND_LL_pos_op(head, 2);
    LL_trav(head);
}
int del_ND_LL_val()
{
    LL_trav(head);
    printf("you are deleting the node at value\n");
    head = del_ND_LL_val_op(head, 20);
    LL_trav(head);
}
int del_ND_LL_end()
{
    LL_trav(head);
    printf("you are deletingthe node at end\n");
    head = del_ND_LL_end_op(head);
    LL_trav(head);
}
int ins_ND_LL_beg_d()
{
    printf("you are inserting doubly linked list at begaining\n");
    headd = ins_ND_LL_beg_op_d(headd, 56);
    LL_trav_d(headd);
}
int ins_ND_LL_end_d()
{
    printf("you are inserting doubly linked list at end\n");
    headd = ins_ND_LL_end_op_d(headd, 10000);
    LL_trav_d(headd);
}
int ins_ND_LL_pos_d()
{
    printf("you are inserting doubly linked list at position\n");
    printf("you are inserting the node at position\n");
    headd = ins_ND_LL_pos_op_d(headd, 100000, 2);
    LL_trav_d(headd);
}
int del_ND_LL_beg_d()
{
    printf("you are deleting doubly linked list at begaining\n");
    LL_trav_d(headd);
    printf("you are deletingthe node at begaining\n");
    headd = del_ND_LL_beg_op_d(headd);
    LL_trav_d(headd);
}
int del_ND_LL_end_d()
{
    printf("you are deleting doubly linked list at end\n");
    LL_trav_d(headd);
    printf("you are deletingthe node at end\n");
    headd = del_ND_LL_end_op_d(headd);
    LL_trav_d(headd);
}
int del_ND_LL_pos_d()
{
    LL_trav_d(headd);
    printf("you are deleting the node at index\n");
    headd = del_ND_LL_pos_op_d(headd, 2);
    LL_trav_d(headd);
}
int del_ND_LL_val_d()
{
    printf("you are deleting doubly linked list at value\n");
    LL_trav_d(headd);
    printf("you are deleting the node at value\n");
    headd = del_ND_LL_val_op_d(headd, 200);
    LL_trav_d(headd);
}
int ins_ND_LL_beg_cc()
{
    printf("we are inserting an element in a circular single linked list at begaining\n");
    head = ins_ND_LL_beg_op_c(head, 99);
    LL_trav_c(head);
}
int ins_ND_LL_pos_cc()
{
    printf("we are inserting an element in a circular single linked list at position\n");
    head = ins_ND_LL_pos_op_c(head, 0, 2);
    LL_trav_c(head);
}
int ins_ND_LL_end_cc()
{
    printf("we are inserting an element in a circular single linked list at end\n");
    head = ins_ND_LL_end_op_c(head, 99);
    LL_trav_c(head);
}
int del_ND_LL_beg_cc()
{
    LL_trav_c(head);
    printf("we are deleting an element in a circular single linked list at begaining\n");
    head = del_ND_LL_beg_op_c(head);
    LL_trav_c(head);
}
int del_ND_LL_pos_cc()
{
    LL_trav_c(head);
    printf("we are deleting an element in a circular single linked list at position\n");
    head = del_ND_LL_pos_op_c(head, 2);
    LL_trav_c(head);
}
int del_ND_LL_end_cc()
{
    LL_trav_c(head);
    printf("we are deleting an element in a circular single linked list at end\n");
    head = del_ND_LL_end_op_c(head);
    LL_trav_c(head);
}
int del_ND_LL_val_cc()
{
    LL_trav_c(head);
    printf("we are deleting an element in a circular single linked list at value\n");
    head = del_ND_LL_val_op_c(head, 33);
    LL_trav_c(head);
}
int ins_ND_LL_beg_cc_d()
{
    printf("we are inserting an element in a circular doubly linked list at begaining\n");
    headd = ins_ND_LL_beg_op_d_c(headd, 999);
    LL_trav_d_c(headd);
}
int ins_ND_LL_pos_cc_d()
{
    printf("we are inserting an element in a circular doubly linked list at position\n");
    headd = ins_ND_LL_pos_op_d_c(headd, 100, 2);
    LL_trav_d_c(headd);
}
int ins_ND_LL_end_cc_d()
{
    printf("we are inserting an element in a circular doubly linked list at end\n");
    headd = ins_ND_LL_end_op_d_c(headd, 77);
    LL_trav_d_c(headd);
}
int del_ND_LL_beg_cc_d()
{
    LL_trav_d_c(headd);
    printf("we are deleting an element in a circular doubly linked list at begaining\n");
    headd = del_ND_LL_beg_op_d_c(headd);
    LL_trav_d_c(headd);
}
int del_ND_LL_pos_cc_d()
{
    LL_trav_d_c(headd);
    printf("we are deleting an element in a circular doubly linked list at begaining\n");
    headd = del_ND_LL_pos_op_d_c(headd, 1);
    LL_trav_d_c(headd);
}
int del_ND_LL_end_cc_d()
{
    LL_trav_d_c(headd);
    printf("we are deleting an element in a circular doubly linked list at end\n");
    headd = del_ND_LL_end_op_d_c(headd);
    LL_trav_d_c(headd);
}
int del_ND_LL_val_cc_d()
{
    LL_trav_d_c(headd);
    printf("we are deleting an element in a circular doubly linked list at value\n");
    headd = del_ND_LL_val_op_d_c(headd, 222);
    LL_trav_d_c(headd);
}
int ins_ND_sin_LL()
{
    printf("\t\t\t  |  you are inserting a node\n");
    printf("\t\t\t  |  you have the nodes by default\n");
    create_node_sin_LL();
    int ins_ND_LL_op;
    printf("\t\t\t  |  Enter  1  for inserting at begaining\n");
    printf("\t\t\t  |  Enter  2  for inserting at end\n");
    printf("\t\t\t  |  Enter  3  for inserting at any position\n");
    scanf("%d", &ins_ND_LL_op);
    switch (ins_ND_LL_op)
    {
    case 1:
        printf("you are inserting the node at begaining\n");
        ins_ND_LL_beg();
        break;
    case 2:
        printf("you are inserting the node at end\n");
        ins_ND_LL_end();
        break;
    case 3:
        printf("you are inserting the node at position\n");
        ins_ND_LL_pos();
        break;
    default:
        break;
    }
}
int ins_ND_dub_LL()
{
    printf("\t\t\t  |  you are inserting a node in dubbly list\n");
    printf("\t\t\t  |  you have the nodes by default\n");
    create_node_dub_LL();
    int ins_ND_LL_op;
    printf("\t\t\t  |  Enter  1  for inserting at begaining\n");
    printf("\t\t\t  |  Enter  2  for inserting at end\n");
    printf("\t\t\t  |  Enter  3  for inserting at any position\n");
    scanf("%d", &ins_ND_LL_op);
    switch (ins_ND_LL_op)
    {
    case 1:
        printf("you are inserting the node at begaining\n");
        ins_ND_LL_beg_d();
        break;
    case 2:
        printf("you are inserting the node at end\n");
        ins_ND_LL_end_d();
        break;
    case 3:
        printf("you are inserting the node at position\n");
        ins_ND_LL_pos_d();
        break;
    default:
        break;
    }
}
int ins_ND_sin_LL_cc()
{
    printf("\t\t\t  |  you are inserting a node in a circular single linked list\n");
    printf("\t\t\t  |  you have the nodes by default\n");
    create_node_sin_LL_cc();
    int ins_ND_LL_op;
    printf("\t\t\t  |  Enter  1  for inserting at begaining\n");
    printf("\t\t\t  |  Enter  2  for inserting at end\n");
    printf("\t\t\t  |  Enter  3  for inserting at any position\n");
    scanf("%d", &ins_ND_LL_op);
    switch (ins_ND_LL_op)
    {
    case 1:
        printf("you are inserting the node at begaining\n");
        ins_ND_LL_beg_cc();
        break;
    case 2:
        printf("you are inserting the node at end\n");
        ins_ND_LL_end_cc();
        break;
    case 3:
        printf("you are inserting the node at position\n");
        ins_ND_LL_pos_cc();
        break;
    default:
        break;
    }
}
int ins_ND_dub_LL_cc()
{
    printf("you are inserting a node in dubbly-circular linked list\n");
    printf("you have the nodes by default\n");
    create_node_dub_LL_cc();
    int ins_ND_LL_op;
    printf("Enter  1  for inserting at begaining\n");
    printf("Enter  2  for inserting at end\n");
    printf("Enter  3  for inserting at any position\n");
    scanf("%d", &ins_ND_LL_op);
    switch (ins_ND_LL_op)
    {
    case 1:
        printf("you are inserting the node at begaining\n");
        ins_ND_LL_beg_cc_d();
        break;
    case 2:
        printf("you are inserting the node at end\n");
        ins_ND_LL_end_cc_d();
        break;
    case 3:
        printf("you are inserting the node at position\n");
        ins_ND_LL_pos_cc_d();
        break;
    default:
        break;
    }
}
int del_ND_sin_LL()
{
    printf("\t\t\t  |  you are deleting a node\n");
    printf("\t\t\t  |  you have the nodes by default\n");
    create_node_sin_LL();
    int del_ND_LL_op;
    printf("\t\t\t  |  Enter  1  for deleting at begaining\n");
    printf("\t\t\t  |  Enter  2  for deleting at end\n");
    printf("\t\t\t  |  Enter  3  for deleting at any position\n");
    printf("\t\t\t  |  Enter  4  for deleting at any value\n");
    scanf("%d", &del_ND_LL_op);
    switch (del_ND_LL_op)
    {
    case 1:
        printf("you are deleting the node at begaining\n");
        del_ND_LL_beg();
        break;
    case 2:
        printf("you are deleting the node at end\n");
        del_ND_LL_end();
        break;
    case 3:
        printf("you are deleting the node at position\n");
        del_ND_LL_pos();
        break;
    case 4:
        printf("you are deleting the node at value\n");
        del_ND_LL_val();
        break;
    default:
        break;
    }
}
int del_ND_dub_LL()
{
    printf("\t\t\t  |  you are deleting a node in dubbly linked list\n");
    printf("\t\t\t  |  you have the nodes by default\n");
    create_node_dub_LL();
    int del_ND_LL_op;
    printf("\t\t\t  |  Enter  1  for deleting at begaining\n");
    printf("\t\t\t  |  Enter  2  for deleting at end\n");
    printf("\t\t\t  |  Enter  3  for deleting at any position\n");
    printf("\t\t\t  |  Enter  4  for deleting at any value\n");
    scanf("%d", &del_ND_LL_op);
    switch (del_ND_LL_op)
    {
    case 1:
        printf("you are deleting the node at begaining\n");
        del_ND_LL_beg_d();
        break;
    case 2:
        printf("you are deleting the node at end\n");
        del_ND_LL_end_d();
        break;
    case 3:
        printf("you are deleting the node at position\n");
        del_ND_LL_pos_d();
        break;
    case 4:
        printf("you are deleting the node at value\n");
        del_ND_LL_val_d();
        break;
    default:
        break;
    }
}
int del_ND_sin_LL_cc()
{
    printf("\t\t\t  |  you are deleting a node ina singly linked circular linked list\n");
    printf("\t\t\t  |  you have the nodes by default\n");
    create_node_sin_LL_cc();
    int del_ND_LL_op;
    printf("\t\t\t  |  Enter  1  for deleting at begaining\n");
    printf("\t\t\t  |  Enter  2  for deleting at end\n");
    printf("\t\t\t  |  Enter  3  for deleting at any position\n");
    printf("\t\t\t  |  Enter  4  for deleting at any value\n");
    scanf("%d", &del_ND_LL_op);
    switch (del_ND_LL_op)
    {
    case 1:
        printf("you are deleting the node at begaining\n");
        del_ND_LL_beg_cc();
        break;
    case 2:
        printf("you are deleting the node at end\n");
        del_ND_LL_end_cc();
        break;
    case 3:
        printf("you are deleting the node at position\n");
        del_ND_LL_pos_cc();
        break;
    case 4:
        printf("you are deleting the node at value\n");
        del_ND_LL_val_cc();
        break;
    default:
        break;
    }
}
int del_ND_dub_LL_cc()
{
    printf("\t\t\t  |  you are deleting a node in dubbly-circular linked list\n");
    printf("\t\t\t  |  you have the nodes by default\n");
    create_node_dub_LL_cc();
    int del_ND_LL_op;
    printf("\t\t\t  |  Enter  1  for deleting at begaining\n");
    printf("\t\t\t  |  Enter  2  for deleting at end\n");
    printf("\t\t\t  |  Enter  3  for deleting at any position\n");
    printf("\t\t\t  |  Enter  4  for deleting at any value\n");
    scanf("%d", &del_ND_LL_op);
    switch (del_ND_LL_op)
    {
    case 1:
        printf("you are deleting the node at begaining\n");
        del_ND_LL_beg_cc_d();
        break;
    case 2:
        printf("you are deleting the node at end\n");
        del_ND_LL_end_cc_d();
        break;
    case 3:
        printf("you are deleting the node at position\n");
        del_ND_LL_pos_cc_d();
        break;
    case 4:
        printf("you are deleting the node at value\n");
        del_ND_LL_val_cc_d();
        break;
    default:
        break;
    }
} // main linked list operator - type differer
int link_li_sin_op()
{
    printf("\t\t\t  |  operating on single linked list  |  \n");
    printf("\t\t\t  |  enter  1  for creating a node    |  \n");
    printf("\t\t\t  |  enter  2  for inserting a node   |  \n");
    printf("\t\t\t  |  enter  3  for deleting a node    |  \n");
    scanf("%d", &link_list_oprs);
    switch (link_list_oprs)
    {
    case 1:
        printf("\t\t\t  |  you are creating a node in a linked list  |  \n");
        create_node_sin_LL();
        break;
    case 2:
        printf("\t\t\t  |  you are inserting the node                |  \n");
        ins_ND_sin_LL();
        break;
    case 3:
        printf("\t\t\t  |  you are deleting the node                 |  \n");
        del_ND_sin_LL();
        break;
    default:
        break;
    }
}
int link_li_dub_op()
{
    int link_list_oprd;
    printf("\t\t\t  |  you are operating on doubled link list  |  \n");
    printf("\t\t\t  |  enter  1  for creating a node           |  \n");
    printf("\t\t\t  |  enter  2  for inserting a node          |  \n");
    printf("\t\t\t  |  enter  3  for deleting a node           |  \n");
    scanf("%d", &link_list_oprd);
    switch (link_list_oprd)
    {
    case 1:
        printf("\t\t\t  |  you are creating a node in a doubled linked list  |  \n");
        create_node_dub_LL();
        break;
    case 2:
        printf("\t\t\t  |  you are inserting the node                        |  \n");
        ins_ND_dub_LL();
        break;
    case 3:
        printf("\t\t\t  |  you are deleting the node                         |  \n");
        del_ND_dub_LL();
        break;
    default:
        break;
    }
}
int link_li_sin_op_cc()
{
    printf("\t\t\t  |  operating on single-circular linked list  |  \n");
    printf("\t\t\t  |  enter  1  for creating a node             |  \n");
    printf("\t\t\t  |  enter  2  for inserting a node            |  \n");
    printf("\t\t\t  |  enter  3  for deleting a node             |  \n");
    scanf("%d", &link_list_oprs);
    switch (link_list_oprs)
    {
    case 1:
        printf("\t\t\t  |  you are creating a node in a linked list  |  \n");
        create_node_sin_LL_cc();
        break;
    case 2:
        printf("\t\t\t  |  you are inserting the node                |  \n");
        ins_ND_sin_LL_cc();
        break;
    case 3:
        printf("\t\t\t  |  you are deleting the node                 |      \n");
        del_ND_sin_LL_cc();
        break;
    default:
        break;
    }
}
int link_li_dub_op_cc()
{
    int link_list_oprd;
    printf("\t\t\t  | you are operating on doubled-circular link list\n  |\n");
    printf("\t\t\t  | enter  1  for creating a node                      |\n");
    printf("\t\t\t  | enter  2  for inserting a node                     |\n");
    printf("\t\t\t  | enter  3  for deleting a node                      |\n");
    scanf("%d", &link_list_oprd);
    switch (link_list_oprd)
    {
    case 1:
        printf("\t\t\t  |  you are creating a node in a doubled linked list  |  \n");
        create_node_dub_LL_cc();
        break;
    case 2:
        printf("\t\t\t  |  you are inserting the node                        |  \n");
        ins_ND_dub_LL_cc();
        break;
    case 3:
        printf("\t\t\t  |  you are deleting the node                         |  \n");
        del_ND_dub_LL_cc();
        break;
    default:
        break;
    }
}
int link_li_op()
{
    printf("enter 1 for single linked list\n");
    printf("enter 2 for double linked list\n");
    printf("enter 3 for single circular-linked list\n");
    printf("enter 4 for double circular-linked list\n");
    int link_li_ch;
    scanf(" %d", &link_li_ch);
    switch (link_li_ch)
    {
    case 1:
        link_li_sin_op();
        break;
    case 2:
        link_li_dub_op();
        break;
    case 3:
        link_li_sin_op_cc();
        break;
    case 4:
        link_li_dub_op_cc();
        break;
    default:
        break;
    }
}

// STACK
// using arrays
#define maxt 20
int stack_arr[maxt];
int top = -1;
int push(int data)
{
    if (top == maxt - 1)
    {
        printf("stack overflown\n");
    }
    top++;
    stack_arr[top] = data;
}
int pop()
{
    int val;
    if (top == -1)
    {
        printf("stack underflown\n");
        exit(1);
    }
    val = stack_arr[top];
    top--;
    return val;
}
void print_stack_arr()
{
    if (top == -1)
    {
        printf("stack underflown\n");
        return;
    }
    for (int i = top; i >= 0; i--)
    {
        printf("\t\telement  %d : value  %d  \n", i, stack_arr[i]);
    }
}
int st_arr()
{
    int data, n;
    printf("\t\tenter the number of elements in stack \n\t\t\t\t");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("enter the value for element %d \n", i);
        scanf("%d", &data);
        push(data);
    }
    print_stack_arr();
    do
    {
        /* code */
        int dec2;
        printf("Enter 1 for push and 2 for pop");
        scanf(" %d", &dec2);
        switch (dec2)
        {
        case 1:
            data = push(2);
            print_stack_arr();
            break;
        case 2:
            pop();
            print_stack_arr();
            break;
        case 3:
            // reversestack();
            print_stack_arr();
            break;
        default:
            exit(1);
            break;
        }
    } while (top != -1);
}
// using linked lists
struct Nodest *topt = NULL;
struct Nodest
{
    int data;
    struct Nodest *next;
};
void st_ll_trav(struct Nodest *ptr)
{
    int no_of_e = 0;
    while (ptr != NULL)
    {
        no_of_e++;
        printf("Element: %d value : %d\n", no_of_e, ptr->data);
        ptr = ptr->next;
    }
}
int isEmptyst(struct Nodest *topt)
{
    if (topt == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFullst(struct Nodest *topt)
{
    struct Nodest *p = (struct Nodest *)malloc(sizeof(struct Nodest));
    if (p == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
struct Nodest *pushst(struct Nodest *topt, int x)
{
    if (isFullst(topt))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        struct Nodest *n = (struct Nodest *)malloc(sizeof(struct Nodest));
        n->data = x;
        n->next = topt;
        topt = n;
        return topt;
    }
}
int popst(struct Nodest *tp)
{
    if (isEmptyst(tp))
    {
        printf("Stack Underflow\n");
    }
    else
    {
        struct Nodest *n = tp;
        topt = (tp)->next;
        int x = n->data;
        free(n);
        return x;
    }
}
int st_ll()
{
    int nst, x;
    printf("enter the number of elements\n");
    scanf("%d", &nst);
    for (int i = nst; i > 0; i--)
    {
        printf("enter element : %d\n", i);
        scanf("%d", &x);
        topt = pushst(topt, x);
    }
    st_ll_trav(topt);
    do
    {
        int dec2;
        printf("Enter 1 for push and 2 for pop");
        scanf(" %d", &dec2);
        switch (dec2)
        {
        case 1:
            topt = pushst(topt, 2);
            st_ll_trav(topt);
            break;
        case 2:
            popst(topt);
            st_ll_trav(topt);
            break;
        default:
            exit(1);
            break;
        }
    } while (topt != NULL);
    return 0;
}
int stack_op()
{
    int st_op;
    printf("You are working on stack\n");
    printf("You have two choices\n");
    printf("\t  1  Using arrays \n\t  2  Using linked list\n");
    scanf("%d", &st_op);
    switch (st_op)
    {
    case 1:
        st_arr();
        break;
    case 2:
        st_ll();
        break;
    default:
        break;
    }
}

// Queue
// using arrays
struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};
int isEmpty(struct queue *q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    return 0;
}
int isFull(struct queue *q)
{
    if (q->r == q->size - 1)
    {
        return 1;
    }
    return 0;
}
void enqueue(struct queue *q, int val)
{
    if (isFull(q))
    {
        printf("This Queue is full\n");
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;
        printf("Enqued element: %d\n", val);
    }
}
int dequeue(struct queue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("This Queue is empty\n");
    }
    else
    {
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}
int q_arr()
{
    int val;
    printf("you are working on queue\n");
    struct queue q;
    q.size = 400;
    q.f = q.r = 0;
    q.arr = (int *)malloc(q.size * sizeof(int));
    enqueue(&q, 12);
    enqueue(&q, 15);
    enqueue(&q, 1);
    printf("Dequeuing element %d\n", dequeue(&q));
    printf("Dequeuing element %d\n", dequeue(&q));
    printf("Dequeuing element %d\n", dequeue(&q));
    enqueue(&q, 45);
    enqueue(&q, 45);
    enqueue(&q, 45);
    printf("dqueed elememt\n");
    if (isEmpty(&q))
    {
        printf("Queue is empty\n");
    }
    if (isFull(&q))
    {
        printf("Queue is full\n");
    }
}
// using linked lists
struct nodes *f = NULL;
struct nodes *r = NULL;
void que_ll_t(struct nodes *ptr)
{
    printf("Printing the elements of this linked list\n");
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}
void enqueue_LL(int val)
{
    struct nodes *n = (struct nodes *)malloc(sizeof(struct nodes));
    if (n == NULL)
    {
        printf("Queue is Full");
    }
    else
    {
        n->data = val;
        n->next = NULL;
        if (f == NULL)
        {
            f = r = n;
        }
        else
        {
            r->next = n;
            r = n;
        }
    }
}
int dequeue_LL()
{
    int val = -1;
    struct nodes *ptr = f;
    if (f == NULL)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        f = f->next;
        val = ptr->data;
        free(ptr);
    }
    return val;
}
int q_ll()
{
    que_ll_t(f);
    printf("Dequeuing element %d\n", dequeue_LL());
    enqueue_LL(34);
    enqueue_LL(4);
    enqueue_LL(7);
    enqueue_LL(17);
    printf("Dequeuing element %d\n", dequeue_LL());
    printf("Dequeuing element %d\n", dequeue_LL());
    printf("Dequeuing element %d\n", dequeue_LL());
    printf("Dequeuing element %d\n", dequeue_LL());
    que_ll_t(f);
    return 0;
}
int queue_op()
{
    int q_op;
    printf("You are working on queue\n");
    printf("You have two choices\n");
    printf("\t  1  Using arrays \n\t  2  Using linked list\n");
    scanf("%d", &q_op);
    switch (q_op)
    {
    case 1:
        q_arr();
        break;
    case 2:
        q_ll();
        break;
    default:
        break;
    }
}

// trees
// using linked method
struct nodetr
{
    int data;
    struct nodetr *left;
    struct nodetr *right;
};
struct nodetr *createNodetr(int data)
{
    struct nodetr *pttr;                                   // creating a node pointer
    pttr = (struct nodetr *)malloc(sizeof(struct nodetr)); // Allocating memory in the heap
    pttr->data = data;                                     // Setting the data
    pttr->left = NULL;                                     // Setting the left and right children to NULL
    pttr->right = NULL;                                    // Setting the left and right children to NULL
    return pttr;                                           // Finally returning the created node
}
int pre_tree_trav(struct nodetr *root)
{
    if (root != NULL)
    {
        printf("  %d  ", root->data);
        pre_tree_trav(root->left);
        pre_tree_trav(root->right);
    }
}
int post_tree_trav(struct nodetr *root)
{
    if (root != NULL)
    {
        post_tree_trav(root->left);
        post_tree_trav(root->right);
        printf(" %d ", root->data);
    }
}
int in_tree_trav(struct nodetr *root)
{
    if (root != NULL)
    {
        in_tree_trav(root->left);
        printf(" %d ", root->data);
        in_tree_trav(root->right);
    }
}
int is_tree_bin(struct nodetr *root)
{
    static struct nodetr *prev = NULL;
    // printf("Testing...\n");
    if (root != NULL)
    {
        if (!is_tree_bin(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return is_tree_bin(root->right);
    }
    else
    {
        // printf("this is a binary search tree\n");
        return 1;
    }
}
struct nodetr *treesearchrecursi(struct nodetr *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (key == root->data)
    {
        return root;
    }
    else if (key < root->data)
    {
        return treesearchrecursi(root->left, key);
    }
    else
    {
        return treesearchrecursi(root->right, key);
    }
}
struct nodetr *searchIterative(struct nodetr *root, int key)
{
    while (root != NULL)
    {
        if (key == root->data)
        {
            return root;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return NULL;
}
void insert_in_tree(struct nodetr *root, int key)
{
    struct nodetr *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (key == root->data)
        {
            printf("Cannot insert %d, already in BST", key);
            return;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    struct nodetr *new = createNodetr(key);
    if (key < prev->data)
    {
        prev->left = new;
    }
    else
    {
        prev->right = new;
    }
}
struct nodetr *inOrderPredecessor(struct nodetr *root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}
struct nodetr *delete_in_tree(struct nodetr *root, int value)
{
    struct nodetr *iPre;
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }
    // searching for the node to be deleted
    if (value < root->data)
    {
        root->left = delete_in_tree(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = delete_in_tree(root->right, value);
    }
    // deletion strategy when the node is found
    else
    {
        iPre = inOrderPredecessor(root);
        root->data = iPre->data;
        root->left = delete_in_tree(root->left, iPre->data);
    }
    return root;
}
int linked_tree()
{
    printf("you are implimenting tree by using liked method\n");
    /*
    // Constructing the root node
    struct node *p;
    p = (struct node *) malloc(sizeof(struct node));
    p->data = 2;
    p->left = NULL;
    p->right = NULL;
    // Constructing the second node
    struct node *p1;
    p1 = (struct node *) malloc(sizeof(struct node));
    p->data = 1;
    p1->left = NULL;
    p1->right = NULL;
    // Constructing the third node
    struct node *p2;
    p2 = (struct node *) malloc(sizeof(struct node));
    p->data = 4;
    p2->left = NULL;
    p2->right = NULL;
    */
    // Constructing the root node - Using Function (Recommended)
    struct nodetr *p = createNodetr(5);
    struct nodetr *p1 = createNodetr(3);
    struct nodetr *p2 = createNodetr(6);
    struct nodetr *p3 = createNodetr(1);
    struct nodetr *p4 = createNodetr(4);
    // Finally The tree looks like this:
    //      5
    //     / \ 
    //    3   6
    //   / \ 
    //  1   4
    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    struct nodetr *root;
    printf("donre successfully\n");
    int travdec;
    printf("enter 1 for traversal by pre-order method\n");
    printf("enter 2 for traversal by post-orde rmethod\n");
    printf("enter 3 for traversal by in-order method\n");
    printf("enter 4 for to check if it is a binary tree\n");
    printf("enter 5 for to search an element in a binary tree\n");
    printf("enter 6 for inserting a new node\n");
    printf("enter 7 for deleting a node\n");
    scanf("%d", &travdec);
    switch (travdec)
    {
    case 1:
        pre_tree_trav(p);
        break;
    case 2:
        post_tree_trav(p);
        break;
    case 3:
        in_tree_trav(p);
        break;
    case 4:
        printf(" %d ", is_tree_bin(p));
        if (is_tree_bin(p))
        {
            printf("this is a binary search tree\n");
        }
        break;
        struct nodetr *n;
    case 5:
        printf("there are two method search\n");
        printf("\t 1  for recursive search \n");
        printf("\t 2  for itrative search \n");
        int searchtreedecider;
        scanf(" %d", &searchtreedecider);
        switch (searchtreedecider)
        {
        case 1:
            n = treesearchrecursi(p, 5);
            if (n != NULL)
            {
                printf("Found: %d", n->data);
            }
            else
            {
                printf("Element not found");
            }
            break;
        case 2:
            n = searchIterative(p, 5);
            if (n != NULL)
            {
                printf("Found: %d", n->data);
            }
            else
            {
                printf("Element not found");
            }
        default:
            break;
        }
    case 6:
        in_tree_trav(p);
        insert_in_tree(p, 11);
        printf("\n");
        printf("inserted\n");
        in_tree_trav(p);
        break;
    case 7:
        in_tree_trav(p);
        delete_in_tree(p, 4);
        printf("\n");
        in_tree_trav(p);
        break;
    default:
        break;
    }
    // return 0;
}
int bintree_op()
{
    int trtypeop;
    printf("you are working on tree\n");
    printf("enter 1 for implimenting the trees by linked method \n");
    // printf("enter 2 for implimenting the trees by array method \n");
    scanf("%d", &trtypeop);
    switch (trtypeop)
    {
    case 1:
        linked_tree();
        break;
    // case 2:
    // Arr_tree();
    // break;
    default:
        break;
    }
}

// graph
int BFS()
{
    // Initializing Queue (Array Implementation)
    // be alert !! we are using quee here . functions will be runned from quee compartment 
    struct queue q;
    q.size = 400;
    q.f = q.r = 0;
    q.arr = (int *)malloc(q.size * sizeof(int));
    // BFS Implementation
    int node;
    int i = 1;
    int visited[7] = {0, 0, 0, 0, 0, 0, 0};
    int a[7][7] = {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}};
    printf(" %d \n", i);
    visited[i] = 1;
    enqueue(&q, i); // Enqueue i for exploration
    while (!isEmpty(&q))
    {
        int node = dequeue(&q);
        for (int j = 0; j < 7; j++)
        {
            if (a[node][j] == 1 && visited[j] == 0)
            {
                printf(" %d \n", j);
                visited[j] = 1;
                enqueue(&q, j);
            }
        }
    }
    return 0;
}
int graph_op()
{
    int graph_ch_op;
    printf("working on graph\n");
    printf("enter 1 for starting with BFS\n");
    scanf("%d", &graph_ch_op);
    switch (graph_ch_op)
    {
    case 1:
        BFS();
        break;
    default:
        break;
    }
}

// here is the prepra/toin for every oper
int menu()
{
    printf("\t\t\t  |====================================================|  \n");
    printf("\t\t\t  |====================================================|  \n");
    printf("\t\t\t  |  implimentation of various data structures         |  \n");
    printf("\t\t\t  |====================================================|  \n");
    printf("\t\t\t  |  \t\tenter   1   for   Array                |  \n");
    printf("\t\t\t  |  \t\tenter   2   for   linked list          |  \n");
    printf("\t\t\t  |  \t\tenter   3   for   stack                |  \n");
    printf("\t\t\t  |  \t\tenter   4   for   queue                |  \n");
    printf("\t\t\t  |  \t\tenter   5   for   binary sarch tree    |  \n");
    printf("\t\t\t  |  \t\tenter   6   for   graph                |  \n");
    printf("\t\t\t  |  \t\tenter   7   for   exit                 |  \n");
    printf("\t\t\t  |====================================================|  \n");
    printf("\t\t\t  |\tenter your operation that you want             |  \n");
    printf("\t\t\t  |====================================================|  \n");
    printf("\t\t\t\t>>>\t");
    scanf("%d", &oper);
    switch (oper)
    {
    case 1:
        array_op();
        break;
    case 2:
        link_li_op();
        break;
    case 3:
        stack_op();
    case 4:
        queue_op();
    case 5:
        bintree_op();
    case 6:
        graph_op();
    case 7:
        exit(1);
    default:
        break;
    }
}
int main()
{
    menu();
}
