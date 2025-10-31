//
// Created by Manju Muralidharan on 10/19/25.
//

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
using namespace std;

struct MinHeap {
    int data[64];
    int size;

    MinHeap() { size = 0; }

    void push(int idx, int weightArr[]) {
        // TODO: insert index at end of heap, restore order using upheap()
        size++;
        data[idx] = weightArr[size];
        upheap(idx, weightArr);

    }

    int pop(int weightArr[]) {
        // TODO: remove and return smallest index
        // Replace root with last element, then call downheap()
        int min = weightArr[0];
        downheap(0, weightArr);
        size--;
        return min;
    }

    void upheap(int pos, int weightArr[]) {
        while (pos > 0) {
            int parent = (pos - 1) / 2;
            if (weightArr[parent] > weightArr[pos]) {
                swap(weightArr[pos], weightArr[parent]);
                pos = parent;
            }
            else {
                break;
            }
        }
}

    void downheap(int pos, int weightArr[]) {
        // TODO: swap parent downward while larger than any child
        while (pos < size) {
            int parent = (pos - 1) / 2;
            if (weightArr[parent] < weightArr[pos]) {
                swap(weightArr[pos], weightArr[parent]);
                pos = parent;
            }
            else {
                break;
            }
        }
    }
};

#endif