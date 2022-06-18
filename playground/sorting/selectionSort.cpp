#include "driver.cpp"

void selection_sort(std::vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        int min = i;
        for (int j = i + 1; j < vec.size(); j++)
        {
            if (vec[j] < vec[min])
                min = j;
        }
        std::swap(vec[i], vec[min]);
    }
}
