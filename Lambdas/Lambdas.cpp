#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//C++ 14 feature - auto return type
auto add(int x, int y) {
    return x + y;
}

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

#pragma region SampleLoggerUsingLambdas
    auto writeLine = [](const std::string& message)
    {
        printf("Printing using Lambda: ");
        cout << message << endl;
    };

    writeLine("Sathwick");
    writeLine("Sunitha");
#pragma endregion
 
#pragma region LambdaPrintGreater
    auto printGreater = [](const int& x, const int& y) {
        if (x > y)
            cout << x << " is Greater than " << y << endl;
        else if(y > x)
            cout << y << " is Greater than " << x << endl;
    };
    printGreater(10, 20);
#pragma endregion

#pragma region LambdaSquare
    auto square = [](const int& x) {return x * x; };
    cout << "square of 10 using Lambda: " << square(10) << endl;

    auto squarePassByRef = [](int& x) { x = x*x; };
    int i = 20;
    squarePassByRef(i);
    cout << "square of 20 using Lambda(PassByRef):" << i << endl;
#pragma endregion

//C++ 14 features - Lambdas accepting auto parameters
#pragma region LabdasAcceptingAuto
    auto add = [](auto x, auto y) { 
        return x + y;
    };
    cout << "Addition of 2 and 3: " << add(2, 3) << endl;
    cout << "Addition of 2.2 and 3.3: " << add(2.2, 3.3) << endl;
    cout << "Additon of x and y: " << add('x', 'y') << endl;
    cout << "Addition of 10 and 20: " << add(10, 20) << endl;
    cout << "Addition of x and 20: " << add('x', 20) << endl;
    //cout << "Addition of Sathwick and Sivvala: " << add("Sathwick", "Sivvala") << endl;
#pragma endregion

#pragma region CountPositives
    auto numbers = std::vector<int>{ 0, 2, -3, 5, -1, 6, 8, -4, 9 };
    auto nPositives = std::count_if(std::begin(numbers), std::end(numbers), [](auto const n) { return n > 0; });

    auto isPositive = [](int const n) {return n > 0; };
    auto nPositives1 = std::count_if(std::begin(numbers), std::end(numbers), isPositive);
    auto nPositives2 = std::count_if(numbers.begin(), numbers.end(), isPositive);
#pragma endregion
    return 0;
}