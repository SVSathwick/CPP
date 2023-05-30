#include <iostream>
#include <vector>

//int removeDuplicates(std::vector<int>& arr) {
//    int res = 1;
//
//    for (int i = 1; i < arr.size(); i++)
//    {
//        if (arr[res - 1] != arr[i])
//        {
//            arr[res] = arr[i];
//            res++;
//        }
//    }
//
//    return res;
//}

int removeDuplicates(std::vector<int>& arr) {
    int curr = 0;
    int i = 1;
    bool swap = false;
    while (i < arr.size()) {
        if (arr[i] == arr[curr]) {
            //swap is required only when atleast one duplicate present
            swap = true;
        }
        else {
            if (swap) {
                std::swap(arr[i], arr[curr+1]);
            }
            curr++;
        }
        i++;
    }
    
    return curr+1;
}

int main()
{
    {
        std::vector<int> v1{10, 20, 30, 40, 40, 40, 50, 50, 60, 70, 70};

        std::cout << "Before: ";
        for (const auto& i : v1) {
            std::cout << i << " ";
        }
        std::cout << std::endl;

        int res = removeDuplicates(v1);
        std::cout << "After: ";
        for (int i = 0; i < res; i++) {
            std::cout << v1[i] << " ";
        }
        std::cout << std::endl;
    }

    {
        std::vector<int> v1{10, 20, 30, 40, 50};

        std::cout << "Before: ";
        for (const auto& i : v1) {
            std::cout << i << " ";
        }
        std::cout << std::endl;

        int res = removeDuplicates(v1);
        std::cout << "After: ";
        for (int i = 0; i < res; i++) {
            std::cout << v1[i] << " ";
        }
        std::cout << std::endl;
    }

    {
        std::vector<int> v1{10, 20};

        std::cout << "Before: ";
        for (const auto& i : v1) {
            std::cout << i << " ";
        }
        std::cout << std::endl;

        int res = removeDuplicates(v1);
        std::cout << "After: ";
        for (int i = 0; i < res; i++) {
            std::cout << v1[i] << " ";
        }
        std::cout << std::endl;
    }

    {
        std::vector<int> v1{10};

        std::cout << "Before: ";
        for (const auto& i : v1) {
            std::cout << i << " ";
        }
        std::cout << std::endl;

        int res = removeDuplicates(v1);
        std::cout << "After: ";
        for (int i = 0; i < res; i++) {
            std::cout << v1[i] << " ";
        }
        std::cout << std::endl;
    }

    {
        std::vector<int> v1{1, 1, 2};

        std::cout << "Before: ";
        for (const auto& i : v1) {
            std::cout << i << " ";
        }
        std::cout << std::endl;

        int res = removeDuplicates(v1);
        std::cout << "After: ";
        for (int i = 0; i < res; i++) {
            std::cout << v1[i] << " ";
        }
        std::cout << std::endl;
    }
}