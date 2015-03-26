package lib;

import java.util.Arrays;

public class StringSearch {
    public static void test(Searcher searcher) {
        int[][] texts = {
            // 4-2-4
            {0, 1, 2, 3},
            // 6-3-6
            {0, 1, 2, 3, 4, 5},
            // no-match
            {0},
            // two-matches
            {0, 1, 1, 0, 1, 1},
            // 17-6-3
            {1, 2, 1, 0, 0, 1, 0, 2, 0, 0, 1, 0, 1, 0, 2, 0, 0},

            // 18-6-3
            {2, 2, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1},
            // no-match-18-6-3
            {2, 2, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1},

            // empty-pattern
            // empty-data
        };
        int[][] patterns = {
            {1, 2},
            {2, 3, 4},
            {1},
            {1, 1},
            {0, 1, 0, 1, 0, 2},

            {0, 0, 1, 0, 0, 0, 1, 0},
            {0, 0, 1, 0, 0, 0, 1, 1},
        };
        int[] expected_outputs = {
            1,
            2,
            -1,
            1,
            9,

            8,
            -1,

        };
        for (int i = 0; i < texts.length; i++) {
            searcher.preProcess(patterns[i]);
            int output = searcher.search(texts[i]);
            if (output != expected_outputs[i]) {
                System.out.println(i);
                System.out.println(output);
                System.out.println(expected_outputs[i]);
                System.out.println("ASSERT FAILED");
                System.exit(1);
            }
        }
        System.out.println("ALL ASSERTS PASSED");
    }
}
