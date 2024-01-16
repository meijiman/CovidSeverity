#ifdef __cplusplus
extern "C"
{
#endif

#include "CovidSeverity.h"

arr_object o;
int G[MAX][MAX];
int level[4] = {10, 5, 3, 1};

void init(int n) {
    o.arr = (object *) malloc(n * sizeof(object));
    o.size = n;
    for (int i = 0; i < o.size; i++) {
        o.arr[i].id = i + 1;
        o.arr[i].f = INVALID;
    }
}

void printObjects() {
    for (int i = 0; i < o.size; i++) {
        printf("id: %2d, ", o.arr[i].id);
        if (o.arr[i].f == -1) {
            printf("Fx ");
        } else {
            printf("F%d ", o.arr[i].f);
        }
        printf("\n");
    }
}

void printResult(arr_int result) {
    for (int i = 0; i < result.size; i++) {
        printf("%d ", result.arr[i]);
    }
    printf("\n");
}

void markF(int b[], int numOfPositiveCases) {
    int f = 0;
    for (int i = 0; i < numOfPositiveCases; i++) {
        o.arr[b[i] - 1].f = 0;
    }
    while (f < 4) {
        for (int i = 0; i < o.size; i++) {
            for (int j = 0; j < o.size; j++) {
                if (G[i][j] == 1) {
                    if (searchById(i + 1)->f == f) {
                        if (searchById(j + 1)->f < f) {
                            if (f + 1 < 3) {
                                searchById(j + 1)->f = f + 1;
                            } else {
                                searchById(j + 1)->f = 3;
                            }
                        }
                        G[i][j] = 0;
                        G[j][i] = 0;
                    }
                }
            }
        }
        f++;
    }
}

object *searchById(int id) {
    for (int i = 0; i < o.size; i++) {
        if (o.arr[i].id == id) {
            return &o.arr[i];
        }
    }
}

matrix_int getGroup() {
    int visited[o.size];
    for (int i = 0; i < o.size; i++) {
        visited[i] = 0;
    }
    matrix_int result;
    result.arr = (arr_int *) malloc(sizeof(arr_int));
    result.size = 0;
    for (int i = 0; i < o.size; i++) {
        if (visited[i] == 0) {
            arr_int r;
            r.arr = (int *) malloc(sizeof(int));
            r.size = 0;
            DFSUtil(i, visited, &r);
//			printf("\n");
            result.size++;
            result.arr = (arr_int *) realloc(result.arr, result.size * sizeof(arr_int));
            result.arr[result.size - 1] = r;
        }
    }
    return result;
}


void DFSUtil(int i, int visited[], arr_int *r) {
    int j;
    visited[i] = 1;
//	printf(" %d->",i + 1);
    r->size++;
    r->arr = (int *) realloc(r->arr, r->size * sizeof(int));
    r->arr[r->size - 1] = i + 1;
    for (j = 0; j < o.size; j++) {
        if (G[i][j] == 1 && visited[j] == 0)
            DFSUtil(j, visited, r);
    }
}

arr_int covidSeverity(int n, int** a, int *b, int numOfContacts, int numOfPositiveCases) {
    init(n);
    for (int i = 0; i < o.size; i++) {
        for (int j = 0; j < o.size; j++) {
            G[i][j] = 0;
        }
    }
    for (int i = 0; i < numOfContacts; i++) {
        G[a[i][0] - 1][a[i][1] - 1] = 1;
        G[a[i][1] - 1][a[i][0] - 1] = 1;
    }
    markF(b, numOfPositiveCases);
//	printObjects();
    for (int i = 0; i < numOfContacts; i++) {
        G[a[i][0] - 1][a[i][1] - 1] = 1;
        G[a[i][1] - 1][a[i][0] - 1] = 1;
    }
    matrix_int groups = getGroup();
    arr_int result;
    result.arr = (int *) malloc(groups.size * sizeof(int));
    result.size = groups.size;
    for (int i = 0; i < groups.size; i++) {
        int sum = 0;
        for (int j = 0; j < groups.arr[i].size; j++) {
            if (searchById(groups.arr[i].arr[j])->f != INVALID) {
                sum += level[searchById(groups.arr[i].arr[j])->f];
            }
        }
        result.arr[i] = sum;
    }
    sort(result);
    return result;
}

void sort(arr_int arr) {
    for (int i = 0; i < arr.size; i++) {
        for (int j = i + 1; j < arr.size; j++) {
            if (arr.arr[i] < arr.arr[j]) {
                int temp = arr.arr[i];
                arr.arr[i] = arr.arr[j];
                arr.arr[j] = temp;
            }
        }
    }
}
#ifdef __cplusplus
} // extern "C"
#endif
