import exceptions.PeekException;
import exceptions.PopException;
import structures.Container;
import structures.Queue;
import structures.Stack;

import java.util.Scanner;

public class Menu {
    public static final String MESSAGE = "1. Push ( element )\n2. Pop ()\n3. Peek ()\n" +
            "4. Empty()\n5. Search (element)\n6. Print ()";
    public static final String INPUT_ERROR = "Wrong value was inserted.";

    private Menu() {
    }

    public static void test() {
        Scanner scanner = new Scanner(System.in);

        for (; ; ) {
            System.out.println("0. Exit\n1. structures.Stack\n2. structures.Queue");
            switch (scanner.nextInt()) {
                case 0: {
                    return;
                }
                case 1: {
                    Menu.start(new Stack(), scanner);
                }
                break;
                case 2: {
                    Menu.start(new Queue(), scanner);
                }
                break;
                default: {
                    System.out.println(INPUT_ERROR);
                }
                break;
            }
        }
    }

    private static void start(Container container, Scanner scanner) {
        for (; ; ) {
            System.out.println(container.getClass().getSimpleName() + ": ");
            System.out.println(MESSAGE);
            switch (scanner.nextInt()) {
                case 0: {
                    return;
                }
                case 1: {
                    System.out.println("Insert element: ");
                    container.push(scanner.nextInt());
                }
                break;
                case 2: {
                    try {
                        System.out.println(container.pop());
                    } catch (PopException e) {
                        System.out.println(e.getMessage());
                    }
                }
                break;
                case 3: {
                    try {
                        System.out.println(container.peek());
                    } catch (PeekException e) {
                        System.out.println(e.getMessage());
                    }
                }
                break;
                case 4: {
                    System.out.println(container.empty() ? "List is empty." : "List is not empty.");
                }
                break;
                case 5: {
                    System.out.println("Search the following element: ");
                    System.out.println(container.search(scanner.nextInt()));
                }
                break;
                case 6: {
                    container.print();
                }
                break;
                default: {
                    System.out.println(INPUT_ERROR);
                }
                break;
            }
        }
    }
}
