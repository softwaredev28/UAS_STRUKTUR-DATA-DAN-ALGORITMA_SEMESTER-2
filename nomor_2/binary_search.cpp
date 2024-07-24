/*
    Nama  : Muhammad Ketsar Ali Abi Wahid
    NIM   : 230401070204
    Kelas : IT201
    Prodi : PJJ Informatika
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Element
{
    int value;
    int index;
};

bool compareByValue(const Element &a, const Element &b)
{
    return a.value < b.value;
}

void printArray(const vector<Element> &arr)
{
    for (const auto &elem : arr)
    {
        cout << elem.value << " ";
    }
    cout << endl;
}

void findAllOccurrences(const vector<Element> &arr, int x)
{
    int left = 0;
    int right = arr.size() - 1;
    vector<int> indices;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid].value == x)
        {
            indices.push_back(arr[mid].index);
            int temp = mid;
            while (--temp >= left && arr[temp].value == x)
            {
                indices.push_back(arr[temp].index);
            }
            temp = mid;
            while (++temp <= right && arr[temp].value == x)
            {
                indices.push_back(arr[temp].index);
            }
            break;
        }

        if (arr[mid].value < x)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    if (indices.size() == 0)
    {
        cout << "Angka " << x << " tidak ada dalam array" << endl;
    }
    else
    {
        sort(indices.begin(), indices.end());
        cout << "Angka " << x << " ada di indeks ";
        for (int i = 0; i < indices.size(); i++)
        {
            cout << indices[i] + 1;
            if (i != indices.size() - 1)
                cout << " dan ";
        }
        cout << endl;
    }
}

int main()
{
    vector<Element> arr = {{19, 0}, {40, 1}, {10, 2}, {90, 3}, {2, 4}, {50, 5}, {60, 6}, {50, 7}, {1, 8}};

    cout << "Array sebelum diurutkan: " << endl;
    for (const auto &elem : arr)
    {
        cout << elem.value << " ";
    }
    cout << endl;

    sort(arr.begin(), arr.end(), compareByValue);

    cout << "Array setelah diurutkan: " << endl;
    printArray(arr);
    cout << endl;

    int test1 = 1;
    int test2 = 50;
    int test3 = 100;

    cout << "Test case a: " << endl;
    findAllOccurrences(arr, test1);
    cout << endl;

    cout << "Test case b: " << endl;
    findAllOccurrences(arr, test2);
    cout << endl;

    cout << "Test case c: " << endl;
    findAllOccurrences(arr, test3);
    cout << endl;

    return 0;
}
