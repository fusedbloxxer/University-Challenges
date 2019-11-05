package probleme.stive;

import exceptions.PopException;
import structures.GenericList;
import structures.Stack;
import utils.HelperSingleton;

import java.io.FileNotFoundException;

public class ProblemThree {
    private static final String FILE_NAME = "parsequence.txt";

    public static void main(String[] args) throws FileNotFoundException {
        GenericList<String> list = HelperSingleton.getInstance().readLines(FILE_NAME);
        for (int i = 0; i < list.size(); i++) {
            String line = list.get(i);
            try {
                System.out.println(line + ": " + isPara(line));
            } catch (PopException e) {
                System.out.println(line + ": " + e.getMessage());
            }
        }
    }

    private static boolean isPara(String seq) throws PopException {
        Stack stack = new Stack();
        for (int i = 0; i < seq.length(); i++) {
            if (seq.charAt(i) == '(') {
                stack.push('(');
            } else {
                try {
                    stack.pop();
                } catch (PopException ex) {
                    throw new PopException("First bad pos for ')' is " + i);
                }
            }
        }
        return stack.empty();
    }
}
