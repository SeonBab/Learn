#include <vector>

void merge(std::vector<int>& array, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; ++i)
    {
        L[i] = array[left + i];
    }
    for (int j = 0; j < n2; ++j)
    {
        R[j] = array[mid + j + 1];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            array[k++] = L[i++];
        }
        else
        {
            array[k++] = R[j++];
        }
    }

    while (i < n1)
    {
        array[k++] = L[i++];
    }

    while (j < n2)
    {
        array[k++] = R[j++];
    }
}

void mergeSort(std::vector<int>& array, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);
        merge(array, left, mid, right);
    }
}

int solution(std::vector<int> array) {
    int answer{}, temp{}, min{}, index{};

    mergeSort(array, 0, array.size() - 1);

    answer = array[array.size() / 2];

    return answer;
}