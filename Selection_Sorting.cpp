#include <bits/stdc++.h>
using namespace std;

void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i];
        if (i == size - 1)
        {
            cout << "";
        }
        else
        {
            cout << ",";
        }
    }
}
void Selection_Sort(int Array[], int size)
{
    int element, index_of_min;
    int temp;
    int count;
    for (int i = 0; i < size - 1; i++) // for number of the passes involve in the process of selection sort.
    {
        cout << "For Pass : " << i + 1 << endl;
        index_of_min = i;
        element = Array[i];
        for (int j = i + 1; j < size; j++)
        {
            if (Array[j] < Array[index_of_min])
            {
                index_of_min = j;
            }
        }

        // swapping the positions of the elements of the A[i] and A[Index_of_Min].
        temp = Array[index_of_min];
        Array[index_of_min] = Array[i];
        Array[i] = temp;
        display(Array, size);
        cout << endl;
    }
}
int main()
{
    // There will be total n-1 Passes in for the comparison.
    int size;

    cout << "Enter the size: ";
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the element " << i + 1 << " : ";
        cin >> arr[i];
    }

    cout << "Unsorted Element are: " << endl;
    display(arr, size);
    cout << endl;
    cout << endl;
    Selection_Sort(arr, size);
    cout << endl;
    cout << "Sorted Element are : " << endl;
    display(arr, size);
    return 0;
}