import java.util.Scanner;
import java.util.ArrayList;
import java.util.List;

public class LCM {
    public static void LCM(List<List<Integer>> arr) {
        for (List<Integer> sublist : arr) {
            int a = sublist.get(0), b = sublist.get(1);
            if (Math.min(a, b) < 1 || Math.max(a, b) > 1000) {
                System.out.println("Out of Range!");
            } else {
                System.out.println(findLCM(a, b));
            }
        }
    }

    // Helper method to calculate GCD (Greatest Common Divisor)
    private static long GCD(long a, long b) {
        while (b != 0) {
            long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    // Helper method to calculate LCM using the GCD
    private static long findLCM(long a, long b) {
        return (a * b) / GCD(a, b);
    }


    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the number of lists (n): ");
        int n = scanner.nextInt();

        List<List<Integer>> l = new ArrayList<>();

        // Input each list
        for (int i = 0; i < n; i++) {
            List<Integer> sublist = new ArrayList<>();
            System.out.println("Enter 2 elements for list " + (i + 1) + ":");
            for (int j = 0; j < 2; j++) {
                sublist.add(scanner.nextInt());
            }
            l.add(sublist);
        }
        LCM(l);
    }
}