import java.util.Collections;

import lib.Searcher;
import lib.StringSearch;

public class KnuthMorrisPratt implements Searcher {
    private int[] pattern;
    private int[] skip;

    // TODO calculate the real skip table.
    public void preProcess(int[] pattern) {
        this.pattern = pattern;
        int patternLength = pattern.length;
        this.skip = new int[patternLength];
        for (int i = 0; i < patternLength; i++)
            this.skip[i] = 1;
    }

    public int search(int[] text) {
        int lastPatternI = this.pattern.length;
        int lastTextI = text.length - lastPatternI;
        int j;
    outer:
        for (int i = 0; i <= lastTextI; i += this.skip[j]) {
            for (j = 0; j < lastPatternI; j++) {
                if (text[i + j] != this.pattern[j])
                    continue outer;
            }
            return i;
        }
        return -1;
    }

    public static void main(String[] args) throws Throwable {
        StringSearch.test(new KnuthMorrisPratt());
    }
}
