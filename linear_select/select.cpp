#include "select.hpp"

using namespace std;


int randomized_select(vector<int>& arr, int p, int r, int i)
{
    if (p == r) return arr[p];

    int q = partition_r(arr, p, r);
    int k = q - p + 1;

    if (i < k)
    {
        return randomized_select(arr, p, q - 1, i);
    }

    else if (i == k)
    {
        return arr[q];
    }

    else
    {
        return randomized_select(arr, q + 1, r, i - k);
    }

}

int partition_r(vector<int>& arr, int p, int r)
{
    srand(time(NULL));
    int num = rand();
    int pivot = p + num % (r - p + 1);
    swap(arr[pivot], arr[r]);

    int i = p - 1;
    for (int j = p; j < r; j++)
    {
        if (arr[j] <= arr[r])
        {
            i = i + 1;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[r]);
    return (i + 1);
}


int linear_select(vector<int>& arr, int p, int r, int i)
{
    int size = r - p + 1;
    int rest = size % 5;
    int num_group, medindex_group, medindex_rest, median;

    if (p >= r) return arr[p];

    for (int m = p; m < r; m += 5)
    {
        insertion_sort(arr, m, min(m + 4, r));
    }

    if (rest == 0)
    {
        num_group = size / 5;
        medindex_rest = 0;
    }
    else
    {
        num_group = size / 5 + 1;

        if (rest % 2 != 0)
        {
            medindex_rest = (rest + 1) / 2;
        }
        else
        {
            medindex_rest = rest / 2;
        }
    }

    if (num_group % 2 != 0)
    {
        medindex_group = (num_group - 1) / 2;
    }
    else
    {
        medindex_group = num_group / 2 - 1;
    }

    if (num_group == 1)
    {
        median = arr[p + (r - p) / 2];
    }

    else
    {
        int s = 0;
        vector<int> temp(arr.size());  
        for (int m = p + 2; m < r; m += 5)
        {
            temp[s] = arr[m];
            s++;
        }
        temp.resize(s);
        median = linear_select(temp, 0, temp.size() - 1, medindex_group);
    }

    int q = partition_l(arr, p, r, median);
    int k = q - p + 1;

    if (i < k)
    {
        return linear_select(arr, p, q - 1, i);
    }
    else if (i == k)
    {
        return arr[q];
    }
    else
    {
        return linear_select(arr, q + 1, r, i - k);
    }
}

int partition_l(vector<int>& arr, int p, int r, int pivot)
{
    int m;
    for (m = 0; m < arr.size(); m++)
    {
        if (arr[m] == pivot) break;
    }
    swap(arr[m], arr[r]);

    int i = p - 1;
    for (int j = p; j < r; j++)
    {
        if (arr[j] <= arr[r])
        {
            i = i + 1;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[r]);
    return (i + 1);
}

void insertion_sort(vector<int>& arr, int p, int r)
{
    for (int i = p + 1; i < r - p + 1; i++)
    {
        for (int j = i; ((j > 0) && (arr[j] < arr[j - 1])); j--)
        {
                swap(arr[j], arr[j - 1]);
        }
    }
}


bool check(vector<int>& arr, int i, int x)
{
    int c1 = 1;
    int c2 = -1;
    for (int k = 0; k < arr.size(); k++)
    {
        if (arr[k] < x) c1++;
        if (arr[k] == x) c2++;
    }

    if ((c1 <= i) && (i <= c1 + c2)) return true;
    else return false;
}

