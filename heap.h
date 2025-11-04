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
        data[size] = idx;
        size++;
        upheap(size-1, weightArr);

    }

    int pop(int weightArr[]) {
        // TODO: remove and return smallest index
        // Replace root with last element, then call downheap()
        int min = data[0];
        data[0] = data[size-1];
        size--;
        downheap(0, weightArr);
        return min;
    }

    void upheap(int pos, int weightArr[]) {
        while (pos > 0) {
            int parent = (pos - 1) / 2;
            if (weightArr[data[parent]] > weightArr[data[pos]]) {
                swap(data[pos], data[parent]);
                pos = parent;
            }
            else {
                break;
            }
        }
}

    void downheap(int pos, int weightArr[]) {
        // TODO: swap parent downward while larger than any child
        while (pos < size) { //traversing the heap
            int left = 2 * pos + 1; // Defined the left side
            int right = 2 * pos + 2; //defined the right side
            int smallest = pos;
            if (left < size && weightArr[data[left]] < weightArr[data[smallest]]) {
                smallest = left;
            }
            if (right < size && weightArr[data[right]] < weightArr[data[smallest]]) {
                smallest = right;
            }

            if (smallest != pos) { //Confirms if conditions are met to swap
                swap(data[pos], data[smallest]);
                pos = smallest;
            }
            else {
                break;
            }
        }
    }
};

#endif