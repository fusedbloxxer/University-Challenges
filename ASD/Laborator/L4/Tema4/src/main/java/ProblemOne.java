import structures.BinarySearchTree;

import java.io.IOException;
import java.util.Scanner;

public class ProblemOne {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
        BinarySearchTree<Integer> binarySearchTree = new BinarySearchTree<>();
        binarySearchTree.insert(5);
        binarySearchTree.insert(3);
        binarySearchTree.insert(2);
        binarySearchTree.insert(4);
        binarySearchTree.insert(1);
        binarySearchTree.insert(7);
        binarySearchTree.insert(6);
        binarySearchTree.insert(9);
        binarySearchTree.insert(8);
        binarySearchTree.insert(10);

        binarySearchTree.keyFinder(1, 4);
        System.out.println();
        menu(scanner, binarySearchTree);
    }

    private static void menu(Scanner scanner, BinarySearchTree<Integer> binarySearchTree) {
        for (; ; ) {
            System.out.println("1. Insert\n2. Search\n3. FindMax\n4. RSD\n5. SRD\n6. SDR\n7. Delete");
            System.out.print("Enter option: ");
            switch (scanner.nextInt()) {
                case 1:
                    System.out.print("Enter an element: ");
                    int element = scanner.nextInt();
                    binarySearchTree.insert(element);
                    System.out.println("Element " + element + " was inserted.");
                    break;
                case 2:
                    System.out.print("Enter an element: ");
                    element = scanner.nextInt();
                    System.out.println("Seaching for element " + element + ": " + binarySearchTree.search(element));
                    break;
                case 3:
                    Integer max = binarySearchTree.findMax();
                    System.out.println(max == null ? "No element was found." : "Max element is: " + max);
                    break;
                case 4:
                    System.out.print("RSD: ");
                    binarySearchTree.rsd();
                    System.out.println();
                    break;
                case 5:
                    System.out.print("SRD: ");
                    binarySearchTree.srd();
                    System.out.println();
                    break;
                case 6:
                    System.out.print("SDR: ");
                    binarySearchTree.sdr();
                    System.out.println();
                    break;
                case 7:
                    System.out.print("Enter an element: ");
                    element = scanner.nextInt();
                    binarySearchTree.delete(element);
                    System.out.println("Element " + element + " was deleted.");
                    break;
                case 0:
                    return;
                default:
                    System.out.println("Invalid input.");
                    break;
            }
            System.out.println();
            System.out.println();
        }
    }
}
