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

void bubbleSort(Data arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j].nama > arr[j + 1].nama)
            {
                swap(arr[j], arr[j + 1]);
            }
        }
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

    bubbleSort(arr, n);

    cout << "\nHasil setelah diurutkan dengan Bubble Sort:" << endl;
    printArray(arr, n);

    return 0;
}
