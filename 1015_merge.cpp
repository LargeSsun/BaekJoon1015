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

bool compareValues(const Element &a, const Element &b) {
    if (a.value == b.value) {
        return a.index < b.index;
    }
    return a.value < b.value;
}

void Merge(vector<Element>& arr, int left, int right)
{
    vector<Element> tempArr(N);
    for (int i = left; i <= right; i++)
    {
        tempArr[i] = arr[i];
    }

    int mid = (left + right) / 2;

    int tempLeft = left;
    int tempRight = mid + 1;
    int curIndex = left;

    while (tempLeft <= mid && tempRight <= right)
    {
        if (compareValues(tempArr[tempLeft], tempArr[tempRight]))
        {
            arr[curIndex++] = tempArr[tempLeft++];
        }
        else
        {
            arr[curIndex++] = tempArr[tempRight++];
        }
    }
    int remain = mid - tempLeft;
    for (int i = 0; i <= remain; i++)
    {
        arr[curIndex + i] = tempArr[tempLeft + i];
    }
}
void Partition(vector<Element>& arr, int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        Partition(arr, left, mid);
        Partition(arr, mid + 1, right);
        Merge(arr, left, right);
    }
}

int main() {
    cin >> N;

    srand(time(0));
    vector<int> A(N);

    vector<Element> sortedA(N);

    for (int i = 0; i < N; i++) {
        A[i] = rand() % 101;
        cout << A[i] << " ";
        sortedA[i].index = i;
        sortedA[i].value = A[i];
    }
    cout << endl << endl;

    Partition(sortedA, 0, N - 1);

    vector<int> P(N);
    for (int i = 0; i < N; i++) {
        P[sortedA[i].index] = i;
    }

    for (int i = 0; i < N; i++) {
        cout << P[i] << " ";
    }
    cout << endl;

    return 0;
}
