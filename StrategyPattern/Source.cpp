#include <iostream>
using namespace std;

class ISorterStrategy
{
public:
    virtual void sort() const = 0;
};

class CMergeSorter : public ISorterStrategy
{
public:
    virtual void sort() const {
        cout << "Merge sort()\n";
    }
};

class CQuickSorter : public ISorterStrategy {
public:
    virtual void sort() const {
        cout << "Quick sort()\n";
    }
};

class CHeapSorter : public ISorterStrategy
{
public:
    virtual void sort() const {
        cout << "Heap sort()\n";
    }
};

// Context
class Collection
{
private:
    ISorterStrategy* m_pSorter;
public:
    Collection() { m_pSorter = nullptr; }
    void set_sort(ISorterStrategy* pSortStrategy) {
        m_pSorter = pSortStrategy;
    }
    void sort() const {
        m_pSorter->sort();
    }
};


int main(int argc, char* argv[])
{
    CMergeSorter mergeSorter;
    CQuickSorter quickSoter;
    CHeapSorter heapSorter;

    Collection colA;
    colA.set_sort(&mergeSorter);
    colA.sort();

    Collection colB;
    colB.set_sort(&quickSoter);
    colB.sort();

    return 0;
}