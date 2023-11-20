#pragma once

#include "quick_sort.h"
#include "insertion_sort.h"

#include <vector>

template <typename T>
void hybridSort(std::vector<T>& v, int low, int high)
{
    if (low >= high) {
        return;
    }

    if (high - low <= 16) {
        insertionSort(v, low, high);
    } else {
        int middle = partition(v, low, high);
        hybridSort(v, low, middle - 1);
        hybridSort(v, middle + 1, high);
    }
}

template <typename T>
void hybridSort(std::vector<T>& v)
{
    hybridSort(v, 0, v.size() - 1);
}
