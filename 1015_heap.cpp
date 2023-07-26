#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

int N;

struct Element {
    int index;
    int value;
};

bool compareValues(const Element& a, const Element& b) {
    if (a.value == b.value) {
        return a.index < b.index;
    }
    return a.value < b.value;
}

void heapSort(vector<Element>& heap)
{
    Element temp;
    for (int i = 1; i < N; i++)
    {
        int child = i;
        do {
            int root = (child - 1) / 2;
            if (compareValues(heap[root], heap[child]))
            {
                temp = heap[root];
                heap[root] = heap[child];
                heap[child] = temp;
            }
            child = root;
        } while (child != 0);
    }
    for (int i = N-1; i >= 0; i--)
    {
        temp = heap[0];
        heap[0] = heap[i];
        heap[i] = temp;
        int root = 0;
        int child = 1;
        do {
            child = 2 * root + 1;
            if (child >= i)
                break;
            if (compareValues(heap[child], heap[child+1]) && child < i-1)
                child++;
            if (compareValues(heap[root], heap[child]) && child < i)
            {
                temp = heap[root];
                heap[root] = heap[child];
                heap[child] = temp;
            }
            root = child;
        } while (child < i);
    }
}

int main() {
    cin >> N;

    clock_t start, end;
    double result;

    start = clock();

    srand(time(0));
    vector<int> A(N);
    vector<Element> sortedA(N);

    for (int i = 0; i < N; i++) {
        A[i] = rand() % 1001;
//        cout << A[i] << " ";
        sortedA[i].index = i;
        sortedA[i].value = A[i];
    }
//    cout << endl << endl;

    heapSort(sortedA);

    vector<int> P(N);
    for (int i = 0; i < N; i++) {
        P[sortedA[i].index] = i;
    }

/*    for (int i = 0; i < N; i++) {
        cout << P[i] << " ";
    }
    cout << endl; */

    end = clock();
    result = (double)(end - start);

    cout << "수행 시간 : " << result << "ms" << endl;

    return 0;
}