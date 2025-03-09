#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int> &a)
{
    int n = a.size();
    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[min_idx])
            {
                min_idx = j;
            }
        }
        swap(a[i], a[min_idx]);
    }
}

void insertionSort(vector<int> &a)
{
    int n = a.size();
    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}

void bubbleSort(vector<int> &a)
{
    int n = a.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

int partition(vector<int> &a, int low, int high)
{
    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (a[j] <= pivot)
        {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[high]);
    return i + 1;
}

void quickSort(vector<int> &a, int low, int high)
{
    if (low < high)
    {
        int pi = partition(a, low, high);
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}

void merge(vector<int> &a, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(a.begin() + left, a.begin() + mid + 1);
    vector<int> R(a.begin() + mid + 1, a.begin() + right + 1);

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int> &a, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);
        merge(a, left, mid, right);
    }
}

// Hàm đo thời gian thực thi
double measureTime(void (*sortFunc)(vector<int> &), vector<int> &a)
{
    vector<int> temp = a;
    auto start = chrono::high_resolution_clock::now();
    sortFunc(temp);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = end - start;
    return duration.count();
}

double measureTimeMergeSort(vector<int> &a)
{
    vector<int> temp = a;
    auto start = chrono::high_resolution_clock::now();
    mergeSort(temp, 0, temp.size() - 1);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = end - start;
    return duration.count();
}

double measureTimeQuickSort(vector<int> &a)
{
    vector<int> temp = a;
    auto start = chrono::high_resolution_clock::now();
    quickSort(temp, 0, temp.size() - 1);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = end - start;
    return duration.count();
}

int main()
{
    // Tạo dãy số ngẫu nhiên với kích thước tối đa
    const int MAX_N = 10000;
    vector<int> original(MAX_N);

    // Tạo số ngẫu nhiên cố định (dùng seed để tái tạo dãy)
    mt19937 gen(42);
    uniform_int_distribution<> dis(1, 10000);
    for (int i = 0; i < MAX_N; i++)
    {
        original[i] = dis(gen);
    }

    // Các giá trị n để khảo sát
    vector<int> sizes = {100, 1000, 5000, 10000};

    // In tiêu đề bảng
    cout << "Thoi gian thuc thi (mili giay) voi cung 1 day so:\n";
    cout << "------------------------------------------------------\n";
    cout << setw(8) << "n" << setw(10) << "Select" << setw(10) << "Insert"
         << setw(10) << "Bubble" << setw(10) << "Quick" << setw(10) << "Merge" << "\n";
    cout << "------------------------------------------------------\n";

    for (int n : sizes)
    {
        // Lấy đoạn con của dãy gốc với kích thước n
        vector<int> a(original.begin(), original.begin() + n);

        // Đo thời gian cho từng thuật toán
        double selectTime = measureTime(selectionSort, a);
        double insertTime = measureTime(insertionSort, a);
        double bubbleTime = measureTime(bubbleSort, a);
        double quickTime = measureTimeQuickSort(a);
        double mergeTime = measureTimeMergeSort(a);

        // In kết quả với căn chỉnh
        cout << setw(8) << n
             << setw(10) << fixed << setprecision(2) << selectTime
             << setw(10) << fixed << setprecision(2) << insertTime
             << setw(10) << fixed << setprecision(2) << bubbleTime
             << setw(10) << fixed << setprecision(2) << quickTime
             << setw(10) << fixed << setprecision(2) << mergeTime << "\n";
    }
    cout << "------------------------------------------------------\n";

    return 0;
}