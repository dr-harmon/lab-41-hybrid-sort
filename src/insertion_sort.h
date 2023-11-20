#pragma once

#include <vector>

template <typename T>
void insertionSort(std::vector<T>& v, int low, int high)
{
    for (int i = low + 1; i <= high; i++) {
        T cur = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > cur) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = cur;
    }
}

template <typename T>
void insertionSort(std::vector<T>& v)
{ 
    insertionSort(v, 0, v.size() - 1);
}
