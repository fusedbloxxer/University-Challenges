package structures;

import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class ProblemThree {
    public static void main(String[] args) {
        IndexedBinaryTree<Integer> binaryTree = new IndexedBinaryTree<>();
        // addElements(binaryTree);
        binaryTree.insert(20);
        binaryTree.insert(40);
        binaryTree.insert(30);
        binaryTree.insert(25);
        binaryTree.insert(35);
        binaryTree.insert(10);
        binaryTree.insert(6);
        binaryTree.insert(2);
        binaryTree.insert(8);
        binaryTree.insert(7);
        binaryTree.insert(15);
        binaryTree.insert(18);
        binaryTree.srd();

        System.out.println();
        Scanner scanner = new Scanner(System.in);
        for (; ; ) {
            System.out.println("Insert element: ");
            Integer element = binaryTree.kThPosition(scanner.nextInt());
            System.out.println(element == null ? "Element not found" : element);
        }
    }

    private static void addElements(BinaryTree<Integer> binaryTree) {
        List<Integer> list = IntStream.range(0, 10).boxed().sorted(Comparator.reverseOrder()).collect(Collectors.toList());
        Collections.shuffle(list);
        System.out.println(list);
        list.forEach(binaryTree::insert);
        binaryTree.delete(1);
        binaryTree.delete(2);
        binaryTree.delete(3);
        binaryTree.srd();
    }
}