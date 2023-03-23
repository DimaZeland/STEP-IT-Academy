#include<array>
#include<algorithm>
#include<ctime>
#include<fstream>
#include<iostream>
#include<string>
#include<vector>

int main() {
    //1
    srand(time(0));
    std::array<int, 12> arr;
    std::generate(arr.begin(), arr.end(), [] { return rand() % 1000 - 500; });
    //2
    std::vector<int> v1(arr.size() / 2), v2(arr.size() / 2);
    std::copy(arr.begin(), arr.begin() + arr.size() / 2, v1.begin());
    std::copy(arr.begin() + (arr.size() / 2 + 1), arr.end(), v2.begin());
    //3
    std::random_shuffle(v1.begin(), v1.end());
    std::random_shuffle(v2.begin(), v2.end());
    std::cout << "v1\n";
    for (auto &x: v1)
        std::cout << x << '\n';
    std::cout << "v2\n";
    for (auto &x: v2)
        std::cout << x << '\n';
    //4
    std::remove_copy(v1.begin(), v1.end(), arr.begin(), -1);
    std::remove_copy(v2.begin(), v2.end(), arr.begin() + arr.size() / 2, -1);
    //5
    std::swap(*std::min_element(arr.begin(), arr.end()), *std::max_element(arr.begin(), arr.end()));
    //6
    int i = 0;
    std::cout << "\narray:\n";
    for (auto &x: arr)
        std::cout << i++ << ' ' << x << '\n';

    std::cout << "\nEnter a integer number: ";
    i = 0;
    std::cin >> i;
    if (arr.end() == std::find(arr.begin(), arr.end(), i))
        std::cout << "\nElement " << i << " is not in the array.\n";
    else
        std::cout << "\nElement " << i << " is in the array.\n";
    //7
    int size = std::count_if(arr.begin(), arr.end(),
                             [=](int a) { if (a > 99 || a < -99) return true; else return false; });
    std::vector<int> v3(size);
    std::remove_copy_if(arr.begin(), arr.end(), v3.begin(),
                        [=](auto a) { if (a < 100 && a > -100) return true; else return false; });
    std::cout << "\nvector v3:\n";
    for (auto &x: v3)
        std::cout << x << '\n';
    //8
    auto pIterator = (std::find_if(arr.begin(), arr.end(), [=](int a) { if (a < 0) return true; else return false; }));
    i = 0;
    auto start = arr.begin();
    while (pIterator != start)
        start += ++i;
    std::cout << "\nIndex of first element in the vector<int> v3 with value is less then zero is " << i << std::endl;
    //9
    i = 0;
    int j = 0;
    std::cout << "\nIndexes of the elements which value is multiple of 5: \n";
    std::for_each(arr.begin(), arr.end(), [&](int a) {
        if (0 == a % 5 && 0 != a) {
            std::cout << i << '\n';
            ++j;
        }
        ++i;
    });
    //10
    std::vector<int> v4(j);
    std::copy_if(arr.begin(), arr.end(), v4.begin(),
                 [=](int a) { if (0 == a % 5 && 0 != a) return true; else return false; });
    std::cout << "\nvector v4:\n";
    for (auto &x: v4)
        std::cout << x << '\n';

    system("pause");
    return 0;
}