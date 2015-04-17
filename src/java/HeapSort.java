import lib.Heap;
import lib.IntArrayConsumer;
import lib.Sort;

import java.util.Arrays;

public class HeapSort implements IntArrayConsumer {

    public void accept(final int[] in) {
        Heap.heapify(in);
        int last = in.length - 1;
        while(last >= 0) {
            System.err.println();
            System.err.println(last);
            System.err.println(Arrays.toString(in));
            int buf = in[last];
            in[last] = in[0];
            in[0] = buf;
            Heap.downHeap(in, last);
            last--;
        }
    }

    public static void main(String[] args) throws Throwable {
        Sort.test(args[0], new HeapSort());
    }
}
