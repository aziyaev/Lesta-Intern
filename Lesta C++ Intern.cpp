#include <iostream>
#include <chrono>
#include "CycleBufferList.cpp"
#include "CycleBufferQueue.cpp"
#include "IsEvenMethods.cpp"
#include "Sort.cpp"

using namespace std;
using namespace std::chrono;

int main()
{
    IsEven isEvenMethods;
    int testSize = 10000000;

    auto start = high_resolution_clock::now();
    for (int i = 0; i < testSize; i++) {
        isEvenMethods.IsEven_MODULO_TASK1(i);
    }
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);
    cout << "isEven_MODULO_TASK1 duration: " << duration.count() << " microseconds" << endl;

    start = high_resolution_clock::now();
    for (int i = 0; i < testSize; i++) {
        isEvenMethods.IsEven_BITEWISE_TASK1(i);
    }
    stop = high_resolution_clock::now();

    duration = duration_cast<microseconds>(stop - start);
    cout << "isEven_BITEWISE_TASK1 duration: " << duration.count() << " microseconds" << endl;
    

    for (int i = 0; i < testSize; i++) {
        isEvenMethods.IsEven_BITEWISE_TASK1(i);
    }

    testSize = 5;
    
    CycleBufferList* listBuffer;
    CycleBufferQueue* queueBuffer;
    bool isEmpty = false;
    bool isFull = false;

    listBuffer = new CycleBufferList(testSize);
    
    isEmpty = listBuffer->isEmpty() == true;
    isFull = listBuffer->isFull() == true;
    cout << "Cycle Buffer List testing is empty:" << isEmpty << endl;
    cout << "Cycle Buffer List testing is full:" << isFull << endl;
    if (!isEmpty || isFull)
        throw logic_error("Buffer must be empty");

    for (int i = 0; i < testSize; i++) {
        listBuffer->push(i);
    }

    isEmpty = listBuffer->isEmpty() == true;
    isFull = listBuffer->isFull() == true;
    cout << "Cycle Buffer List testing is empty:" << isEmpty << endl;
    cout << "Cycle Buffer List testing is full:" << isFull << endl;
    if (isEmpty || !isFull)
        throw logic_error("Buffer must be full");

    cout << "Cycle Buffer List testing pop():" << endl;
    for (int i = 0; i < testSize; i++) {
        cout << (listBuffer->pop() == i) << endl;
    }

    isEmpty = listBuffer->isEmpty() == true;
    isFull = listBuffer->isFull() == true;
    std::cout << "Cycle Buffer List testing is empty:" << isEmpty << endl;
    std::cout << "Cycle Buffer List testing is full:" << isFull << endl;
    if (!isEmpty || isFull)
        throw logic_error("Buffer must be empty");


    queueBuffer = new CycleBufferQueue(testSize);

    isEmpty = queueBuffer->isEmpty() == true;
    isFull = queueBuffer->isFull() == true;
    cout << "Cycle Buffer Queue testing is empty:" << isEmpty << endl;
    cout << "Cycle Buffer Queue testing is full:" << isFull << endl;
    if (!isEmpty || isFull)
        throw logic_error("Buffer must be empty");

    for (int i = 0; i < testSize; i++) {
        queueBuffer->push(i);
    }

    isEmpty = queueBuffer->isEmpty() == true;
    isFull = queueBuffer->isFull() == true;
    cout << "Cycle Buffer Queue testing is empty:" << isEmpty << endl;
    cout << "Cycle Buffer Queue testing is full:" << isFull << endl;
    if (isEmpty || !isFull)
        throw logic_error("Buffer must be full");

    cout << "Cycle Buffer Queue testing pop():" << endl;
    for (int i = 0; i < testSize; i++) {
        cout << (queueBuffer->pop() == i) << endl;
    }

    isEmpty = queueBuffer->isEmpty() == true;
    isFull = queueBuffer->isFull() == true;
    std::cout << "Cycle Buffer Queue testing is empty:" << isEmpty << endl;
    std::cout << "Cycle Buffer Queue testing is full:" << isFull << endl;
    if (!isEmpty || isFull)
        throw logic_error("Buffer must be empty");

    cout << "All tests passed!" << std::endl;

    srand(time(0));

    int rnd = rand() % 1000000;
    int* array{ new int[rnd] };
    for (int i = 0; i < rnd; ++i) {
        array[i] = rand() % 1000000;
    }

    Sort sort;

    start = high_resolution_clock::now();
    sort.QuickSort(array, rnd);
    stop = high_resolution_clock::now();

    duration = duration_cast<microseconds>(stop - start);
    cout << "QuickSort " << rnd << " elements duration: " << duration.count() << " microseconds" << endl;

    return 0;
}