#include <stdio.h>
int main()
{
    int i, j, temp;
    int n = 10;
    int arr[] = {60, 70, 80, 90, 100, 10, 20, 30, 40, 50};
    for (i = 0; i < n - 1; i++)
    {
        int min = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            arr[temp] = arr[i];
            arr[i] = arr[min];
            arr[min] = arr[temp];
        }
    }
    // printing te array
    for (i = 0; i < n; i++)
    {
        printf("%d \n", arr[i]);
    }
}