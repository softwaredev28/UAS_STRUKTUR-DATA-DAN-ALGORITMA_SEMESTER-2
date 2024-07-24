/*
    Nama  : Muhammad Ketsar Ali Abi Wahid
    NIM   : 230401070204
    Kelas : IT201
    Prodi : PJJ Informatika
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Data
{
    string nama;
    string alamat;
};

void selectionSort(Data arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j].nama < arr[min_idx].nama)
            {
                min_idx = j;
            }
        }
        swap(arr[min_idx], arr[i]);
    }
}

void printArray(Data arr[], int size)
{
    cout << "+-----------------+----------------+" << endl;
    cout << "| Nama            | Alamat         |" << endl;
    cout << "+-----------------+----------------+" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "| " << left << setw(15) << arr[i].nama << " | " << setw(14) << arr[i].alamat << " |" << endl;
    }
    cout << "+-----------------+----------------+" << endl;
}

int main()
{
    Data arr[] = {
        {"Fahmi", "Jakarta"},
        {"Romi", "Solo"},
        {"Andri", "Jakarta"},
        {"Fadillah", "Banyuwangi"},
        {"Ruli", "Bandung"},
        {"Rudi", "Bali"},
        {"Dendi", "Purwokerto"},
        {"Zaki", "Madiun"}};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Data sebelum diurutkan:" << endl;
    printArray(arr, n);

    selectionSort(arr, n);

    cout << "\nHasil setelah diurutkan dengan Selection Sort:" << endl;
    printArray(arr, n);

    return 0;
}
