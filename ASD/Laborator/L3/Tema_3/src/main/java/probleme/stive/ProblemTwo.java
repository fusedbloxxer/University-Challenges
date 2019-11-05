package probleme.stive;

import exceptions.PeekException;
import exceptions.PopException;
import structures.Stack;
import utils.HelperSingleton;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.Scanner;

public class ProblemTwo {
    private static final String FILE_NAME = "aabb.txt";

    public static void main(String[] args) throws FileNotFoundException, PeekException, PopException {
        Scanner scanner = new Scanner(new BufferedReader(new FileReader(HelperSingleton.DEFAULT_PATH + FILE_NAME)));
        while (scanner.hasNext()) {
            String line = scanner.nextLine();
            System.out.println(line + ": " + isSame(line.toCharArray()));
        }
    }

    private static boolean isSame(char[] chars) throws PeekException, PopException {
        Stack stack = new Stack();
        for (char ch : chars) {
            if (stack.empty() || stack.peek() == ch) {
                stack.push(ch);
            } else {
                stack.pop();
            }
        }
        return stack.empty();
    }
}
