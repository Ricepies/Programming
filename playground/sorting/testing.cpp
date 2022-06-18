#include "insertionSort.cpp"
int main(int argc, char const *argv[])
{
    std::vector<int> vec = {1, 3, 45632, 1236, 176, 1, 662, 73};
    insertion_sort(vec);
    for (auto i : vec)
        std::cout << i << std::endl;
    return 0;
}