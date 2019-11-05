package probleme.liste;

import structures.GenericList;
import structures.GenericNode;

import java.util.Scanner;
import java.util.stream.IntStream;

public class ProblemExtraTwo {
    public static void main(String[] args) throws Exception {
        GenericList<Integer> list = new GenericList<>();
        Scanner scanner = new Scanner(System.in);
        IntStream.range(scanner.nextInt(), scanner.nextInt() + 1)
                .forEach(list::pushBack);
        list.print();
        System.out.println(circular(list, scanner.nextInt()));
    }

    private static <T> GenericNode<T> survivor(GenericNode<T> node, GenericList<T> list, int step) {
        if (list.getHead() == list.getHead().getNext()) {
            // Single element.
            System.out.println();
            return node;
        } else {

            for (int i = 2; i < step; ++i) {
                node = node.getNext();
            }

            if (step == 1) {
                System.out.print(list.getHead().getValue() + " ");
                list.removeFront();
                node = list.getHead();
                list.getTail().setNext(node);
            } else {
                if (node.getNext() == list.getHead()) {
                    list.setHead(node.getNext().getNext());
                }
                System.out.print(node.getNext().getValue() + " ");
                node.setNext(node.getNext().getNext());
            }

            return survivor(node.getNext(), list, step);
        }
    }

    private static <T> T circular(GenericList<T> list, int step) throws Exception {
        if (step == 0 || step < 0) {
            throw new Exception("Step cannot be zero or negative.");
        }

        list.setCircular(true);
        System.out.print("Eliminated: ");
        return survivor(list.getHead(), list, step).getValue();
    }

    private static <T> void printCircular(GenericList<T> list) {
        GenericNode<T> node = list.getHead();
        if (node != null) {
            while (node.getNext() != list.getHead()) {
                System.out.print(node.getValue() + " ");
                node = node.getNext();
            }
            System.out.println(node.getValue() + " ");
            System.out.println();
        }
    }
}
