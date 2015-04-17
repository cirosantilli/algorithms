package lib;

import java.io.PrintStream;
import java.util.Arrays;

public class Heap {

    public static int child1(int i) {
        return 2 * i + 1;
    }

    public static int child2(int i) { return child1(i) + 1;
    }

    public static int lastParent(int[] arr) {
        return lastParent(arr.length);
    }

    /** Return the index for the last parent node. */
    public static int lastParent(int length) {
        return (length / 2) - 1;
    }

    public static void heapify(int[] arr) {
        for (int i = lastParent(arr); i >= 0; i--) {
            maxHeapify(arr, i);
        }
    }

    public static int maxHeapify(int[] arr, int i) {
        return maxHeapify(arr, i, arr.length);
    }

    /** Make the heap property valid for a parent and its immediate children. */
    public static int maxHeapify(int[] arr, int i, int length) {
        int child1I = child1(i);
        int child2I = child2(i);
        int child1 = arr[child1I];
        int child2;
        int swapWith;
        int swapWithI;
        int cur;
        if (child2I == length)
            child2 = Integer.MIN_VALUE;
        else
            child2 = arr[child2I];
        cur = arr[i];
        if (child1 < child2) {
            swapWith = child2;
            swapWithI = child2I;
        } else {
            swapWith = child1;
            swapWithI = child1I;
        }
        if (cur < swapWith) {
            arr[swapWithI] = cur;
            arr[i] = swapWith;
        } else {
            swapWithI = i;
        }
        return swapWithI;
    }

    public static void downHeap(int[] arr) {
        downHeap(arr, arr.length);
    }

    public static void downHeap(int[] arr, int length) {
        int lastParent = lastParent(length);
        int i = 0;
        int lastI = -1;
        System.err.println(length);
        System.err.println(lastParent);
        while ((i != lastI) && (i <= lastParent)) {
            lastI = i;
            System.err.println(Arrays.toString(arr));
            i = maxHeapify(arr, i, length);
            System.err.println(Arrays.toString(arr));
        }
    }
}

