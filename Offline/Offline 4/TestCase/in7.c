int arr[14];
int leftArr[14];
int rightArr[14];

void merge(int start, int mid, int end)
{

    int len1;
    len1 = mid - start + 1;
    int len2;
    len2 = end - mid;

    int i;
    for (i = 0; i < len1; i++)
        leftArr[i] = arr[start + i];

    int j;
    for (j = 0; j < len2; j++)
        rightArr[j] = arr[mid + 1 + j];

    int k;
    i = 0;
    j = 0;
    k = start;

    while (i < len1 && j < len2)
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k] = leftArr[i];
            i++;
        }
        else
        {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < len1)
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < len2)
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(int start, int end)
{
    if (start < end)
    {
        int mid;
        mid = start + (end - start) / 2;
        mergeSort(start, mid);
        mergeSort(mid + 1, end);
        merge(start, mid, end);
    }
}

void display(int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf(arr[i]);
}

int main()
{

    int size;
    size = 6;

    arr[0] = 5;
    arr[1] = 4;
    arr[2] = 3;
    arr[3] = 12;
    arr[4] = 1;
    arr[5] = 0;

    display(size);

    mergeSort(0, size - 1);

    display(size);
}
