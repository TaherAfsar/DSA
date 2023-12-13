#include <stdio.h>
int main()
{
    int n = 10;
    int temp, i, j;
    int arr[] = {
        60,
        70,
        80,
        90,
        100,
        10,
        20,
        30,
        40,
        50,
    };
    for (i = 1; i < n; i++)
    {
        temp = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
    // printing te array
    for (i = 0; i < n; i++)
    {
        printf("%d \n", arr[i]);
    }
}