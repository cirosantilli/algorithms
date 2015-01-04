import java.io.BufferedReader;
import java.io.FileReader;
import java.util.Scanner;

/** Shared sort input parsing. */
class Sort {

    public static int[] parseInput(String path) throws Throwable {
        BufferedReader br = new BufferedReader(new FileReader(path));
        String sizeS = br.readLine();
        String inS = br.readLine();
        int size = Integer.parseInt(sizeS.trim());
        Scanner scanner;
        int i;
        int[] in = new int[size];
        scanner = new Scanner(inS);
        i = 0;
        while (scanner.hasNextInt()) {
            in[i] = scanner.nextInt();
            i++;
        }
        return in;
    }

    public static void printOutput(final int[] output) {
        for (int i = 0; i < output.length - 1; i++) {
            System.out.print(output[i] + " ");
        }
        System.out.print(output[output.length - 1] + "\n");
    }
}
