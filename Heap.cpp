// Max heap
#include <bits/stdc++.h>
using namespace std;
void max_heapify(int Arr[], int i, int N)
{
    int left = 2 * i;
    int right = 2 * i + 1;
    int largest;
    if (left <= N and Arr[left] > Arr[i])
        largest = left;
    else
        largest = i;
    if (right <= N and Arr[right] > Arr[largest])
        largest = right;
    if (largest != i)
    {
        swap(Arr[i], Arr[largest]);
        max_heapify(Arr, largest, N);
    }
}
void build_maxheap(int Arr[], int N)
{
    for (int i = N / 2; i >= 1; i--)
    {
        max_heapify(Arr, i, N);
    }
}
int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;
    int arr[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    build_maxheap(arr, n);
    for (int i = 1; i <= n; i++)
        cout << arr[i] << " ";
}