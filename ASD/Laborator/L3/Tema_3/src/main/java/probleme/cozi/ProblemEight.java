package probleme.cozi;

import exceptions.PeekException;
import exceptions.PopException;
import structures.Container;
import structures.GenericList;
import structures.Queue;
import structures.Stack;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class ProblemEight {

    public static final String HELLO_WORLD = "HELLO WORLD";

    public static void main(String[] args) throws PopException, PeekException {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter n: ");
        int n = scanner.nextInt();
        System.out.println("Enter k: ");
        int k = scanner.nextInt();

        Stack stack = getStack(scanner, n);
        GenericList<Queue> queues = getQueues(k);

        while (!stack.empty()) {
            int element = stack.pop();
            boolean deposited = false;

            for (int i = 0; i < k; i++) {
                if (queues.get(i).empty()) {
                    queues.get(i).push(element);
                    deposited = true;
                    break;
                } else if (element > queues.get(i).peekTail()) {
                    queues.get(i).push(element);
                    deposited = true;
                    break;
                }
            }

            if (!deposited) {
                for (int i = 0; i < queues.size(); i++) {
                    queues.get(i).print();
                }
                System.out.println("Cannot fit elements.");
                return;
            }
        }

        for (int i = 0; i < queues.size(); i++) {
            if (queues.get(i).empty()) {
                queues.remove(i);
                i--;
            }
        }

        printQueues(queues);

        System.out.println("OUTPUT: ");
        while (queues.size() != 0) {
            int min = 0;
            for (int i = 1; i < queues.size(); i++) {
                min = ((queues.get(min).peek() > queues.get(i).peek()) ? i : min);
            }
            System.out.print(queues.get(min).pop() + " ");
            if (queues.get(min).empty()) {
                queues.remove(min);
            }
            // printQueues(queues);
        }
    }

    private static void printQueues(GenericList<Queue> queues) {
        for (int i = 0; i < queues.size(); i++) {
            queues.get(i).print();
        }
        System.out.println();
    }

    private static GenericList<Queue> getQueues(int k) {
        GenericList<Queue> queues = new GenericList<>();
        for (int i = 0; i < k; i++) {
            queues.pushBack(new Queue());
        }
        return queues;
    }

    private static Stack getStack(Scanner scanner, int n) {
        Stack stack = new Stack();
        List<Integer> list = getElements(scanner, n);
        list.forEach(stack::push);
        stack.print();
        return stack;
    }

    private static List<Integer> getElements(Scanner scanner, int n) {
        List<Integer> list;
        System.out.println("Zero for random elements: ");
        if (scanner.nextInt() == 0) {
            Collections.shuffle(list = IntStream.range(1, n + 1).boxed().collect(Collectors.toList()));
        } else {
            System.out.println("Enter " + n + " elements: ");
            list = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                list.add(scanner.nextInt());
            }
        }
        return list;
    }
}