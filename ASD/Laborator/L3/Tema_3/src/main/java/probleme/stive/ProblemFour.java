package probleme.stive;

import exceptions.PeekException;
import exceptions.PopException;
import structures.GenericList;
import structures.Stack;
import utils.HelperSingleton;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.Scanner;

public class ProblemFour {

    public static final String PINS_TXT = "pins.txt";

    public static void main(String[] args) throws FileNotFoundException, PeekException, PopException {
        GenericList<GenericList<Integer>> list = readLine();
        for (int i = 0; i < list.size(); i++) {
            System.out.print(isConfigValid(list.get(i)) ? "VALID-> " : "INVALID-> ");
            list.get(i).print();
        }
    }

    private static GenericList<GenericList<Integer>> readLine() throws FileNotFoundException {
        GenericList<GenericList<Integer>> genericList = new GenericList<>();
        Scanner scanner = new Scanner(new BufferedReader(new FileReader(HelperSingleton.DEFAULT_PATH + PINS_TXT)));
        while (scanner.hasNext()) {
            int n = scanner.nextInt();
            genericList.pushBack(new GenericList<>());
            for (int i = 0; i < n; i++) {
                genericList.get(genericList.size() - 1).pushBack(scanner.nextInt());
            }
        }
        return genericList;
    }

    private static boolean isConfigValid(GenericList<Integer> list) throws PeekException, PopException {
        Stack stack = new Stack();
        for (int i = 0; i < list.size(); i++) {
            int element = list.get(i);
            if (stack.empty()) {
                stack.push(element);
            } else if (stack.peek() == element) {
                stack.pop();
            } else if (stack.peek() < element) {
                stack.push(element);
            } else {
                return false;
            }
        }
        return true;
    }
}
