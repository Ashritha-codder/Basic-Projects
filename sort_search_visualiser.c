#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX 200
#define STRLEN 128
#define EPS 1e-6

/* =========================================================
   BASIC HELPERS
   ========================================================= */

void line(void) {
    printf("------------------------------------------------------------\n");
}

/* =========================================================
   PRINTING FUNCTIONS
   ========================================================= */

void print_int_arr(int a[], int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        if (i > 0)
            printf(" ");
        printf("%d", a[i]);
    }
    printf("]\n");
}

void print_float_arr(float a[], int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        if (i > 0)
            printf(" ");
        printf("%.6g", a[i]);
    }
    printf("]\n");
}

void print_char_arr(char a[], int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        if (i > 0)
            printf(" ");
        printf("'%c'", a[i]);
    }
    printf("]\n");
}

void print_str_arr(char a[][STRLEN], int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        if (i > 0)
            printf(" ");
        printf("\"%s\"", a[i]);
    }
    printf("]\n");
}

/* =========================================================
   SWAP FUNCTIONS
   ========================================================= */

void swap_int(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void swap_float(float *x, float *y) {
    float temp = *x;
    *x = *y;
    *y = temp;
}

void swap_char(char *x, char *y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

void swap_str(char a[], char b[]) {
    char temp[STRLEN];

    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
}

/* =========================================================
   ORDER DETECTION
   1 = Ascending
  -1 = Descending
   0 = Unsorted
   ========================================================= */

int detect_order_int(int a[], int n) {
    int asc = 1;
    int desc = 1;

    for (int i = 1; i < n; i++) {
        if (a[i] < a[i - 1])
            asc = 0;

        if (a[i] > a[i - 1])
            desc = 0;
    }

    if (asc)
        return 1;

    if (desc)
        return -1;

    return 0;
}

int detect_order_float(float a[], int n) {
    int asc = 1;
    int desc = 1;

    for (int i = 1; i < n; i++) {
        if (a[i] < a[i - 1] - EPS)
            asc = 0;

        if (a[i] > a[i - 1] + EPS)
            desc = 0;
    }

    if (asc)
        return 1;

    if (desc)
        return -1;

    return 0;
}

int detect_order_char(char a[], int n) {
    int asc = 1;
    int desc = 1;

    for (int i = 1; i < n; i++) {
        if (a[i] < a[i - 1])
            asc = 0;

        if (a[i] > a[i - 1])
            desc = 0;
    }

    if (asc)
        return 1;

    if (desc)
        return -1;

    return 0;
}

int detect_order_str(char a[][STRLEN], int n) {
    int asc = 1;
    int desc = 1;

    for (int i = 1; i < n; i++) {
        int cmp = strcmp(a[i], a[i - 1]);

        if (cmp < 0)
            asc = 0;

        if (cmp > 0)
            desc = 0;
    }

    if (asc)
        return 1;

    if (desc)
        return -1;

    return 0;
}

/* =========================================================
   INTEGER SORTING
   ========================================================= */

/* ---------- Bubble Sort ---------- */

void bubble_int(int a[], int n, int asc) {

    printf("\nBubble Sort (Integer)\n");

    for (int pass = 1; pass <= n - 1; pass++) {

        printf("Pass %d\n", pass);

        for (int j = 0; j < n - pass; j++) {

            printf("Compare %d and %d ",
                   a[j], a[j + 1]);

            int should_swap;

            if (asc)
                should_swap = a[j] > a[j + 1];
            else
                should_swap = a[j] < a[j + 1];

            if (should_swap) {
                swap_int(&a[j], &a[j + 1]);
                printf("-> swapped\n");
            } else {
                printf("-> no swap\n");
            }

            print_int_arr(a, n);
        }

        line();
    }
}

/* ---------- Selection Sort ---------- */

void selection_int(int a[], int n, int asc) {

    printf("\nSelection Sort (Integer)\n");

    for (int i = 0; i < n - 1; i++) {

        int best = i;

        for (int j = i + 1; j < n; j++) {

            if (asc) {
                if (a[j] < a[best])
                    best = j;
            } else {
                if (a[j] > a[best])
                    best = j;
            }
        }

        printf("Selecting %d and placing at index %d\n",
               a[best], i);

        swap_int(&a[i], &a[best]);

        print_int_arr(a, n);
        line();
    }
}

/* ---------- Insertion Sort ---------- */

void insertion_int(int a[], int n, int asc) {

    printf("\nInsertion Sort (Integer)\n");

    for (int i = 1; i < n; i++) {

        int key = a[i];
        int j = i - 1;

        printf("Insert %d into sorted portion\n", key);

        while (j >= 0 &&
              (asc ? a[j] > key : a[j] < key)) {

            a[j + 1] = a[j];
            j--;

            print_int_arr(a, n);
        }

        a[j + 1] = key;

        print_int_arr(a, n);
        line();
    }
}

/* ---------- Quick Sort ---------- */

int partition_int(int a[], int low, int high, int asc) {

    int pivot = a[high];
    int i = low - 1;

    printf("Pivot = %d\n", pivot);

    for (int j = low; j < high; j++) {

        int condition;

        if (asc)
            condition = a[j] <= pivot;
        else
            condition = a[j] >= pivot;

        if (condition) {

            i++;
            swap_int(&a[i], &a[j]);
        }
    }

    swap_int(&a[i + 1], &a[high]);

    return i + 1;
}

void quick_int_rec(int a[], int low, int high, int asc) {

    if (low < high) {

        int p = partition_int(a, low, high, asc);

        quick_int_rec(a, low, p - 1, asc);
        quick_int_rec(a, p + 1, high, asc);
    }
}

void quick_int(int a[], int n, int asc) {

    printf("\nQuick Sort (Integer)\n");

    quick_int_rec(a, 0, n - 1, asc);

    print_int_arr(a, n);
}

/* ---------- Merge Sort ---------- */

void merge_int(int a[], int left, int mid, int right, int asc) {

    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++)
        L[i] = a[left + i];

    for (int j = 0; j < n2; j++)
        R[j] = a[mid + 1 + j];

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {

        if (asc) {

            if (L[i] <= R[j])
                a[k++] = L[i++];
            else
                a[k++] = R[j++];

        } else {

            if (L[i] >= R[j])
                a[k++] = L[i++];
            else
                a[k++] = R[j++];
        }
    }

    while (i < n1)
        a[k++] = L[i++];

    while (j < n2)
        a[k++] = R[j++];

    free(L);
    free(R);
}

void merge_int_rec(int a[], int left, int right, int asc) {

    if (left < right) {

        int mid = (left + right) / 2;

        merge_int_rec(a, left, mid, asc);
        merge_int_rec(a, mid + 1, right, asc);

        merge_int(a, left, mid, right, asc);
    }
}

void merge_sort_int(int a[], int n, int asc) {

    printf("\nMerge Sort (Integer)\n");

    merge_int_rec(a, 0, n - 1, asc);

    print_int_arr(a, n);
}

/* =========================================================
   FLOAT SORTING
   ========================================================= */

void bubble_float(float a[], int n, int asc) {

    printf("\nBubble Sort (Float)\n");

    for (int pass = 1; pass <= n - 1; pass++) {

        printf("Pass %d\n", pass);

        for (int j = 0; j < n - pass; j++) {

            int should_swap;

            if (asc)
                should_swap = a[j] > a[j + 1];
            else
                should_swap = a[j] < a[j + 1];

            if (should_swap) {
                swap_float(&a[j], &a[j + 1]);
                printf("Swapped\n");
            }

            print_float_arr(a, n);
        }

        line();
    }
}

void selection_float(float a[], int n, int asc) {

    printf("\nSelection Sort (Float)\n");

    for (int i = 0; i < n - 1; i++) {

        int best = i;

        for (int j = i + 1; j < n; j++) {

            if (asc) {
                if (a[j] < a[best])
                    best = j;
            } else {
                if (a[j] > a[best])
                    best = j;
            }
        }

        swap_float(&a[i], &a[best]);

        print_float_arr(a, n);
    }
}

void insertion_float(float a[], int n, int asc) {

    printf("\nInsertion Sort (Float)\n");

    for (int i = 1; i < n; i++) {

        float key = a[i];
        int j = i - 1;

        while (j >= 0 &&
              (asc ? a[j] > key : a[j] < key)) {

            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;

        print_float_arr(a, n);
    }
}

int partition_float(float a[], int low, int high, int asc) {

    float pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {

        int condition;

        if (asc)
            condition = a[j] <= pivot;
        else
            condition = a[j] >= pivot;

        if (condition) {
            i++;
            swap_float(&a[i], &a[j]);
        }
    }

    swap_float(&a[i + 1], &a[high]);

    return i + 1;
}

void quick_float_rec(float a[], int low, int high, int asc) {

    if (low < high) {

        int p = partition_float(a, low, high, asc);

        quick_float_rec(a, low, p - 1, asc);
        quick_float_rec(a, p + 1, high, asc);
    }
}

void quick_float(float a[], int n, int asc) {

    printf("\nQuick Sort (Float)\n");

    quick_float_rec(a, 0, n - 1, asc);

    print_float_arr(a, n);
}

void merge_float(int a[], int left, int mid, int right, int asc) {
    /* Not used */
}

void merge_float_rec(float a[], int left, int right, int asc) {

    if (left < right) {

        int mid = (left + right) / 2;

        merge_float_rec(a, left, mid, asc);
        merge_float_rec(a, mid + 1, right, asc);

        int n1 = mid - left + 1;
        int n2 = right - mid;

        float *L = malloc(n1 * sizeof(float));
        float *R = malloc(n2 * sizeof(float));

        for (int i = 0; i < n1; i++)
            L[i] = a[left + i];

        for (int j = 0; j < n2; j++)
            R[j] = a[mid + 1 + j];

        int i = 0;
        int j = 0;
        int k = left;

        while (i < n1 && j < n2) {

            if (asc) {

                if (L[i] <= R[j])
                    a[k++] = L[i++];
                else
                    a[k++] = R[j++];

            } else {

                if (L[i] >= R[j])
                    a[k++] = L[i++];
                else
                    a[k++] = R[j++];
            }
        }

        while (i < n1)
            a[k++] = L[i++];

        while (j < n2)
            a[k++] = R[j++];

        free(L);
        free(R);
    }
}

void merge_sort_float(float a[], int n, int asc) {

    printf("\nMerge Sort (Float)\n");

    merge_float_rec(a, 0, n - 1, asc);

    print_float_arr(a, n);
}

/* =========================================================
   CHARACTER SORTING
   ========================================================= */

void bubble_char(char a[], int n, int asc) {

    printf("\nBubble Sort (Character)\n");

    for (int pass = 1; pass <= n - 1; pass++) {

        for (int j = 0; j < n - pass; j++) {

            int should_swap;

            if (asc)
                should_swap = a[j] > a[j + 1];
            else
                should_swap = a[j] < a[j + 1];

            if (should_swap)
                swap_char(&a[j], &a[j + 1]);

            print_char_arr(a, n);
        }

        line();
    }
}

void selection_char(char a[], int n, int asc) {

    printf("\nSelection Sort (Character)\n");

    for (int i = 0; i < n - 1; i++) {

        int best = i;

        for (int j = i + 1; j < n; j++) {

            if (asc) {
                if (a[j] < a[best])
                    best = j;
            } else {
                if (a[j] > a[best])
                    best = j;
            }
        }

        swap_char(&a[i], &a[best]);

        print_char_arr(a, n);
    }
}

void insertion_char(char a[], int n, int asc) {

    printf("\nInsertion Sort (Character)\n");

    for (int i = 1; i < n; i++) {

        char key = a[i];
        int j = i - 1;

        while (j >= 0 &&
              (asc ? a[j] > key : a[j] < key)) {

            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;

        print_char_arr(a, n);
    }
}

int partition_char(char a[], int low, int high, int asc) {

    char pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {

        int condition;

        if (asc)
            condition = a[j] <= pivot;
        else
            condition = a[j] >= pivot;

        if (condition) {
            i++;
            swap_char(&a[i], &a[j]);
        }
    }

    swap_char(&a[i + 1], &a[high]);

    return i + 1;
}

void quick_char_rec(char a[], int low, int high, int asc) {

    if (low < high) {

        int p = partition_char(a, low, high, asc);

        quick_char_rec(a, low, p - 1, asc);
        quick_char_rec(a, p + 1, high, asc);
    }
}

void quick_char(char a[], int n, int asc) {

    printf("\nQuick Sort (Character)\n");

    quick_char_rec(a, 0, n - 1, asc);

    print_char_arr(a, n);
}

void merge_char_rec(char a[], int left, int right, int asc) {

    if (left < right) {

        int mid = (left + right) / 2;

        merge_char_rec(a, left, mid, asc);
        merge_char_rec(a, mid + 1, right, asc);

        int n1 = mid - left + 1;
        int n2 = right - mid;

        char *L = malloc(n1 * sizeof(char));
        char *R = malloc(n2 * sizeof(char));

        for (int i = 0; i < n1; i++)
            L[i] = a[left + i];

        for (int j = 0; j < n2; j++)
            R[j] = a[mid + 1 + j];

        int i = 0;
        int j = 0;
        int k = left;

        while (i < n1 && j < n2) {

            if (asc) {

                if (L[i] <= R[j])
                    a[k++] = L[i++];
                else
                    a[k++] = R[j++];

            } else {

                if (L[i] >= R[j])
                    a[k++] = L[i++];
                else
                    a[k++] = R[j++];
            }
        }

        while (i < n1)
            a[k++] = L[i++];

        while (j < n2)
            a[k++] = R[j++];

        free(L);
        free(R);
    }
}

void merge_sort_char(char a[], int n, int asc) {

    printf("\nMerge Sort (Character)\n");

    merge_char_rec(a, 0, n - 1, asc);

    print_char_arr(a, n);
}

/* =========================================================
   STRING SORTING
   ========================================================= */

void bubble_str(char a[][STRLEN], int n, int asc) {

    printf("\nBubble Sort (String)\n");

    for (int pass = 1; pass <= n - 1; pass++) {

        for (int j = 0; j < n - pass; j++) {

            int cmp = strcmp(a[j], a[j + 1]);

            int should_swap;

            if (asc)
                should_swap = cmp > 0;
            else
                should_swap = cmp < 0;

            if (should_swap)
                swap_str(a[j], a[j + 1]);

            print_str_arr(a, n);
        }

        line();
    }
}

void selection_str(char a[][STRLEN], int n, int asc) {

    printf("\nSelection Sort (String)\n");

    for (int i = 0; i < n - 1; i++) {

        int best = i;

        for (int j = i + 1; j < n; j++) {

            int cmp = strcmp(a[j], a[best]);

            if (asc) {

                if (cmp < 0)
                    best = j;

            } else {

                if (cmp > 0)
                    best = j;
            }
        }

        swap_str(a[i], a[best]);

        print_str_arr(a, n);
    }
}

void insertion_str(char a[][STRLEN], int n, int asc) {

    printf("\nInsertion Sort (String)\n");

    for (int i = 1; i < n; i++) {

        char key[STRLEN];
        strcpy(key, a[i]);

        int j = i - 1;

        while (j >= 0 &&
              (asc ? strcmp(a[j], key) > 0
                   : strcmp(a[j], key) < 0)) {

            strcpy(a[j + 1], a[j]);
            j--;
        }

        strcpy(a[j + 1], key);

        print_str_arr(a, n);
    }
}

int partition_str(char a[][STRLEN],
                  int low,
                  int high,
                  int asc) {

    char pivot[STRLEN];
    strcpy(pivot, a[high]);

    int i = low - 1;

    for (int j = low; j < high; j++) {

        int cmp = strcmp(a[j], pivot);

        int condition;

        if (asc)
            condition = cmp <= 0;
        else
            condition = cmp >= 0;

        if (condition) {

            i++;
            swap_str(a[i], a[j]);
        }
    }

    swap_str(a[i + 1], a[high]);

    return i + 1;
}

void quick_str_rec(char a[][STRLEN],
                   int low,
                   int high,
                   int asc) {

    if (low < high) {

        int p = partition_str(a, low, high, asc);

        quick_str_rec(a, low, p - 1, asc);
        quick_str_rec(a, p + 1, high, asc);
    }
}

void quick_str(char a[][STRLEN], int n, int asc) {

    printf("\nQuick Sort (String)\n");

    quick_str_rec(a, 0, n - 1, asc);

    print_str_arr(a, n);
}

void merge_str_rec(char a[][STRLEN],
                   int left,
                   int right,
                   int asc) {

    if (left < right) {

        int mid = (left + right) / 2;

        merge_str_rec(a, left, mid, asc);
        merge_str_rec(a, mid + 1, right, asc);

        int n1 = mid - left + 1;
        int n2 = right - mid;

        char (*L)[STRLEN] =
            malloc(n1 * sizeof(*L));

        char (*R)[STRLEN] =
            malloc(n2 * sizeof(*R));

        for (int i = 0; i < n1; i++)
            strcpy(L[i], a[left + i]);

        for (int j = 0; j < n2; j++)
            strcpy(R[j], a[mid + 1 + j]);

        int i = 0;
        int j = 0;
        int k = left;

        while (i < n1 && j < n2) {

            int cmp = strcmp(L[i], R[j]);

            if (asc) {

                if (cmp <= 0)
                    strcpy(a[k++], L[i++]);
                else
                    strcpy(a[k++], R[j++]);

            } else {

                if (cmp >= 0)
                    strcpy(a[k++], L[i++]);
                else
                    strcpy(a[k++], R[j++]);
            }
        }

        while (i < n1)
            strcpy(a[k++], L[i++]);

        while (j < n2)
            strcpy(a[k++], R[j++]);

        free(L);
        free(R);
    }
}

void merge_sort_str(char a[][STRLEN], int n, int asc) {

    printf("\nMerge Sort (String)\n");

    merge_str_rec(a, 0, n - 1, asc);

    print_str_arr(a, n);
}

/* =========================================================
   LINEAR SEARCH
   ========================================================= */

int linear_search_int(int a[], int n, int key) {

    printf("\nLinear Search (Integer)\n");

    for (int i = 0; i < n; i++) {

        printf("Step %d: compare %d with %d\n",
               i + 1, a[i], key);

        if (a[i] == key) {

            printf("Found at index %d\n", i);
            return i;
        }
    }

    printf("Key not found\n");

    return -1;
}

int linear_search_float(float a[], int n, float key) {

    printf("\nLinear Search (Float)\n");

    for (int i = 0; i < n; i++) {

        printf("Step %d: compare %.6g with %.6g\n",
               i + 1, a[i], key);

        if (fabs(a[i] - key) < EPS) {

            printf("Found at index %d\n", i);
            return i;
        }
    }

    printf("Key not found\n");

    return -1;
}

int linear_search_char(char a[], int n, char key) {

    printf("\nLinear Search (Character)\n");

    for (int i = 0; i < n; i++) {

        printf("Step %d: compare '%c' with '%c'\n",
               i + 1, a[i], key);

        if (a[i] == key) {

            printf("Found at index %d\n", i);
            return i;
        }
    }

    printf("Key not found\n");

    return -1;
}

int linear_search_str(char a[][STRLEN],
                      int n,
                      char key[]) {

    printf("\nLinear Search (String)\n");

    for (int i = 0; i < n; i++) {

        printf("Step %d: compare \"%s\" with \"%s\"\n",
               i + 1, a[i], key);

        if (strcmp(a[i], key) == 0) {

            printf("Found at index %d\n", i);
            return i;
        }
    }

    printf("Key not found\n");

    return -1;
}

/* =========================================================
   BINARY SEARCH
   ========================================================= */

int binary_search_int(int a[], int n, int key, int asc) {

    printf("\nBinary Search (Integer)\n");

    int low = 0;
    int high = n - 1;

    while (low <= high) {

        int mid = (low + high) / 2;

        printf("Low=%d, Mid=%d, High=%d\n",
               low, mid, high);

        if (a[mid] == key) {

            printf("Found at index %d\n", mid);
            return mid;
        }

        if (asc) {

            if (a[mid] < key)
                low = mid + 1;
            else
                high = mid - 1;

        } else {

            if (a[mid] < key)
                high = mid - 1;
            else
                low = mid + 1;
        }
    }

    printf("Key not found\n");

    return -1;
}

int binary_search_float(float a[],
                        int n,
                        float key,
                        int asc) {

    printf("\nBinary Search (Float)\n");

    int low = 0;
    int high = n - 1;

    while (low <= high) {

        int mid = (low + high) / 2;

        printf("Low=%d, Mid=%d, High=%d\n",
               low, mid, high);

        if (fabs(a[mid] - key) < EPS) {

            printf("Found at index %d\n", mid);
            return mid;
        }

        if (asc) {

            if (a[mid] < key)
                low = mid + 1;
            else
                high = mid - 1;

        } else {

            if (a[mid] < key)
                high = mid - 1;
            else
                low = mid + 1;
        }
    }

    printf("Key not found\n");

    return -1;
}

int binary_search_char(char a[],
                       int n,
                       char key,
                       int asc) {

    printf("\nBinary Search (Character)\n");

    int low = 0;
    int high = n - 1;

    while (low <= high) {

        int mid = (low + high) / 2;

        printf("Low=%d, Mid=%d, High=%d\n",
               low, mid, high);

        if (a[mid] == key) {

            printf("Found at index %d\n", mid);
            return mid;
        }

        if (asc) {

            if (a[mid] < key)
                low = mid + 1;
            else
                high = mid - 1;

        } else {

            if (a[mid] < key)
                high = mid - 1;
            else
                low = mid + 1;
        }
    }

    printf("Key not found\n");

    return -1;
}

int binary_search_str(char a[][STRLEN],
                      int n,
                      char key[],
                      int asc) {

    printf("\nBinary Search (String)\n");

    int low = 0;
    int high = n - 1;

    while (low <= high) {

        int mid = (low + high) / 2;

        int cmp = strcmp(a[mid], key);

        printf("Low=%d, Mid=%d, High=%d\n",
               low, mid, high);

        if (cmp == 0) {

            printf("Found at index %d\n", mid);
            return mid;
        }

        if (asc) {

            if (cmp < 0)
                low = mid + 1;
            else
                high = mid - 1;

        } else {

            if (cmp < 0)
                high = mid - 1;
            else
                low = mid + 1;
        }
    }

    printf("Key not found\n");

    return -1;
}

/* =========================================================
   MAIN PROGRAM
   ========================================================= */

int main(void) {

    printf("====================================================\n");
    printf("       UNIVERSAL SORT & SEARCH VISUALIZER\n");
    printf("====================================================\n");

    printf("Supports: Integer, Float, Character, String\n");
    printf("Sorting: Bubble, Selection, Insertion, Quick, Merge\n");
    printf("Searching: Linear, Binary\n\n");

    int dtype;

    printf("Choose Data Type:\n");
    printf("1. Integer\n");
    printf("2. Float\n");
    printf("3. Character\n");
    printf("4. String\n");
    printf("Choice: ");

    if (scanf("%d", &dtype) != 1)
        return 0;

    if (dtype < 1 || dtype > 4) {

        printf("Invalid data type choice.\n");
        return 0;
    }

    int n;

    printf("\nEnter number of elements (max %d): ", MAX);

    if (scanf("%d", &n) != 1 ||
        n <= 0 ||
        n > MAX) {

        printf("Invalid size.\n");
        return 0;
    }

    int order_choice;

    printf("\nSort Order:\n");
    printf("1. Ascending\n");
    printf("2. Descending\n");
    printf("Choice: ");

    scanf("%d", &order_choice);

    if (order_choice != 1 &&
        order_choice != 2) {

        printf("Invalid order choice.\n");
        return 0;
    }

    int asc = (order_choice == 1);

    int sort_choice;

    printf("\nSorting Algorithm:\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("4. Quick Sort\n");
    printf("5. Merge Sort\n");
    printf("Choice: ");

    scanf("%d", &sort_choice);

    if (sort_choice < 1 ||
        sort_choice > 5) {

        printf("Invalid sorting choice.\n");
        return 0;
    }

    clock_t start, end;

    double sort_time;
    double search_time;

    /* =====================================================
       INTEGER
       ===================================================== */

    if (dtype == 1) {

        int arr[MAX];

        printf("\nEnter %d integers:\n", n);

        for (int i = 0; i < n; i++)
            scanf("%d", &arr[i]);

        start = clock();

        if (sort_choice == 1)
            bubble_int(arr, n, asc);

        else if (sort_choice == 2)
            selection_int(arr, n, asc);

        else if (sort_choice == 3)
            insertion_int(arr, n, asc);

        else if (sort_choice == 4)
            quick_int(arr, n, asc);

        else
            merge_sort_int(arr, n, asc);

        end = clock();

        sort_time =
            (double)(end - start) / CLOCKS_PER_SEC;

        printf("\nSorted Array:\n");
        print_int_arr(arr, n);

        printf("Sorting Time: %.6f seconds\n",
               sort_time);

        int search_choice;

        printf("\nSearch Method:\n");
        printf("1. Linear Search\n");
        printf("2. Binary Search\n");
        printf("Choice: ");

        scanf("%d", &search_choice);

        int key;

        printf("Enter integer to search: ");
        scanf("%d", &key);

        start = clock();

        if (search_choice == 1)
            linear_search_int(arr, n, key);

        else if (search_choice == 2)
            binary_search_int(arr, n, key, asc);

        else
            printf("Invalid search choice.\n");

        end = clock();

        search_time =
            (double)(end - start) / CLOCKS_PER_SEC;

        printf("Search Time: %.6f seconds\n",
               search_time);
    }

    /* =====================================================
       FLOAT
       ===================================================== */

    else if (dtype == 2) {

        float arr[MAX];

        printf("\nEnter %d float values:\n", n);

        for (int i = 0; i < n; i++)
            scanf("%f", &arr[i]);

        start = clock();

        if (sort_choice == 1)
            bubble_float(arr, n, asc);

        else if (sort_choice == 2)
            selection_float(arr, n, asc);

        else if (sort_choice == 3)
            insertion_float(arr, n, asc);

        else if (sort_choice == 4)
            quick_float(arr, n, asc);

        else
            merge_sort_float(arr, n, asc);

        end = clock();

        sort_time =
            (double)(end - start) / CLOCKS_PER_SEC;

        printf("\nSorted Array:\n");
        print_float_arr(arr, n);

        printf("Sorting Time: %.6f seconds\n",
               sort_time);

        int search_choice;

        printf("\nSearch Method:\n");
        printf("1. Linear Search\n");
        printf("2. Binary Search\n");
        printf("Choice: ");

        scanf("%d", &search_choice);

        float key;

        printf("Enter float value to search: ");
        scanf("%f", &key);

        start = clock();

        if (search_choice == 1)
            linear_search_float(arr, n, key);

        else if (search_choice == 2)
            binary_search_float(arr, n, key, asc);

        else
            printf("Invalid search choice.\n");

        end = clock();

        search_time =
            (double)(end - start) / CLOCKS_PER_SEC;

        printf("Search Time: %.6f seconds\n",
               search_time);
    }

    /* =====================================================
       CHARACTER
       ===================================================== */

    else if (dtype == 3) {

        char arr[MAX];

        printf("\nEnter %d characters:\n", n);

        for (int i = 0; i < n; i++)
            scanf(" %c", &arr[i]);

        start = clock();

        if (sort_choice == 1)
            bubble_char(arr, n, asc);

        else if (sort_choice == 2)
            selection_char(arr, n, asc);

        else if (sort_choice == 3)
            insertion_char(arr, n, asc);

        else if (sort_choice == 4)
            quick_char(arr, n, asc);

        else
            merge_sort_char(arr, n, asc);

        end = clock();

        sort_time =
            (double)(end - start) / CLOCKS_PER_SEC;

        printf("\nSorted Array:\n");
        print_char_arr(arr, n);

        printf("Sorting Time: %.6f seconds\n",
               sort_time);

        int search_choice;

        printf("\nSearch Method:\n");
        printf("1. Linear Search\n");
        printf("2. Binary Search\n");
        printf("Choice: ");

        scanf("%d", &search_choice);

        char key;

        printf("Enter character to search: ");
        scanf(" %c", &key);

        start = clock();

        if (search_choice == 1)
            linear_search_char(arr, n, key);

        else if (search_choice == 2)
            binary_search_char(arr, n, key, asc);

        else
            printf("Invalid search choice.\n");

        end = clock();

        search_time =
            (double)(end - start) / CLOCKS_PER_SEC;

        printf("Search Time: %.6f seconds\n",
               search_time);
    }

    /* =====================================================
       STRING
       ===================================================== */

    else if (dtype == 4) {

        char arr[MAX][STRLEN];

        printf("\nEnter %d strings:\n", n);

        for (int i = 0; i < n; i++)
            scanf("%127s", arr[i]);

        start = clock();

        if (sort_choice == 1)
            bubble_str(arr, n, asc);

        else if (sort_choice == 2)
            selection_str(arr, n, asc);

        else if (sort_choice == 3)
            insertion_str(arr, n, asc);

        else if (sort_choice == 4)
            quick_str(arr, n, asc);

        else
            merge_sort_str(arr, n, asc);

        end = clock();

        sort_time =
            (double)(end - start) / CLOCKS_PER_SEC;

        printf("\nSorted Array:\n");
        print_str_arr(arr, n);

        printf("Sorting Time: %.6f seconds\n",
               sort_time);

        int search_choice;

        printf("\nSearch Method:\n");
        printf("1. Linear Search\n");
        printf("2. Binary Search\n");
        printf("Choice: ");

        scanf("%d", &search_choice);

        char key[STRLEN];

        printf("Enter string to search: ");
        scanf("%127s", key);

        start = clock();

        if (search_choice == 1)
            linear_search_str(arr, n, key);

        else if (search_choice == 2)
            binary_search_str(arr, n, key, asc);

        else
            printf("Invalid search choice.\n");

        end = clock();

        search_time =
            (double)(end - start) / CLOCKS_PER_SEC;

        printf("Search Time: %.6f seconds\n",
               search_time);
    }

    printf("\n====================================================\n");
    printf("Program finished successfully.\n");
    printf("====================================================\n");

    return 0;
}