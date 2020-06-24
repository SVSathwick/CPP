#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool sortInReverse(int x, int y)
{
    return x > y;
}

struct Point
{
    int x;
    int y;
    int z;
    Point(int x, int y, int z) :x(x), y(y), z(z) {}
};

bool sortByX(const Point& p1, const Point& p2)
{
    return p1.x < p2.x;
}
bool sortByY(const Point& p1, const Point& p2)
{
    return p1.y < p2.y;
}
bool sortByZ(const Point& p1, const Point& p2)
{
    return p1.z < p2.z;
}

int main()
{
#pragma region LambdasOnPrimitiveTypes
    {
        /*std::vector<int> numbers = { 1, 2, 54, 22, 376, 334, 786, 3, 33, 12 };

        cout << "Before sorting: ";
        for (auto it : numbers)
            cout << it << " ";

        std::sort(numbers.begin(), numbers.end());
        cout << "\nAfter sorting: ";
        for (auto it : numbers)
            cout << it << " ";*/

        //Sorting using funtion pointer
        /*std::sort(numbers.begin(), numbers.end(), &sortInReverse);
        cout << "\nAfter sorting in reverse: ";
        for (auto it : numbers)
            cout << it << " ";*/

            //Sorting using Lambdas
            /*std::sort(numbers.begin(), numbers.end(),
                [](int x, int y) { return x > y; });
            cout << "\nAfter sorting in reverse: ";
            for (auto it : numbers)
                cout << it << " ";*/

    }
#pragma endregion

#pragma region LambdasOnCustomTypes
    std::vector<Point> points;
    points.push_back(Point(1, 99, 3));
    points.push_back(Point(111, 22, 13));
    points.push_back(Point(21, 12, 555));
    points.push_back(Point(11, 15, 19));
    points.push_back(Point(120, 60, 30));
    points.push_back(Point(2, 4, 6));
    points.push_back(Point(23, 55, 88));

    cout << "Points before Sorting: " << endl;
    for (const auto& it : points)
    {
        cout << "x: " << it.x << ", y: " << it.y << ", z:" << it.z << endl;
    }

    //Sorting using function pointers
    /*std::sort(points.begin(), points.end(), &sortByX);
    cout << "Points after Sorting by 'X': " << endl;
    for (const auto& it : points)
    {
        cout << "x: " << it.x << ", y: " << it.y << ", z:" << it.z << endl;
    }

    std::sort(points.begin(), points.end(), &sortByY);
    cout << "Points after Sorting by 'Y': " << endl;
    for (const auto& it : points)
    {
        cout << "x: " << it.x << ", y: " << it.y << ", z:" << it.z << endl;
    }

    std::sort(points.begin(), points.end(), &sortByZ);
    cout << "Points after Sorting by 'Z': " << endl;
    for (const auto& it : points)
    {
        cout << "x: " << it.x << ", y: " << it.y << ", z:" << it.z << endl;
    }*/

    //Sorting using Lambdas
    std::sort(points.begin(), points.end(), 
        [](const Point& p1, const Point& p2) { return p1.x < p2.x; });
    cout << "Points after Sorting by 'X'(using Lambdas): " << endl;
    for (const auto& it : points)
    {
        cout << "x: " << it.x << ", y: " << it.y << ", z:" << it.z << endl;
    }

    std::sort(points.begin(), points.end(),
        [](const Point& p1, const Point& p2) { return p1.y < p2.y; });
    cout << "Points after Sorting by 'Y'(using Lambdas): " << endl;
    for (const auto& it : points)
    {
        cout << "x: " << it.x << ", y: " << it.y << ", z:" << it.z << endl;
    }

    std::sort(points.begin(), points.end(),
        [](const Point& p1, const Point& p2) { return p1.z < p2.z; });
    cout << "Points after Sorting by 'Z'(using Lambdas): " << endl;
    for (const auto& it : points)
    {
        cout << "x: " << it.x << ", y: " << it.y << ", z:" << it.z << endl;
    }
#pragma endregion

    
    return 0;
}