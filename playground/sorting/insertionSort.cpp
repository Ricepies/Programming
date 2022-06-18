#include "driver.cpp"

void insertion_sort(std::vector<int> &vec)
{
    for (int i = 1; i < vec.size(); i++)
    {
        int j = i;
        while (j > 0 && vec[j] < vec[j - 1])
        {
            std::swap(vec[j], vec[j - 1]);
            j--;
        }
    }
}
