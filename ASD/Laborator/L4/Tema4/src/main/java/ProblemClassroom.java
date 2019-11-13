import java.util.Collection;
import java.util.Collections;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class ProblemClassroom {

    private static final int COUNT = 10;

    public static void main(String[] args) {
        BinaryTree<Integer> tree = getIntegerBinaryTree();

        tree.print();
        System.out.println();
        tree.srd();
    }

    private static BinaryTree<Integer> getIntegerBinaryTree() {
        List<Integer> list = IntStream.range(0, COUNT).boxed().collect(Collectors.toList());
        BinaryTree<Integer> tree = new BinaryTree<>();
        Collections.shuffle(list);
        System.out.println(list);
        list.forEach(tree::insert);
        return tree;
    }
}

class BinaryTree<T extends Comparable<T>> {
    private Node<T> root;

    BinaryTree() {
        this.root = null;
    }

    void print() {
        Queue<Node<T>> queue = new Queue<>();
        queue.push(root);

        do {
            Node<T> node = queue.pop();

            if (node.getLeft() != null) {
                queue.push(node.getLeft());
            }

            if (node.getRight() != null) {
                queue.push(node.getRight());
            }

            System.out.print(node.getValue() + " ");
        } while (!queue.isEmpty());
    }

    void insert(T key) {
        insert(root, key);
    }

    void srd() {
        srd(root);
    }

    private void insert(Node<T> node, T key) {
        if (root == null) {
            root = new Node<>(key);
        } else if (key.compareTo(node.getValue()) < 0) {
            if (node.getLeft() != null) {
                insert(node.getLeft(), key);
            } else {
                node.setLeft(new Node<>(key));
            }
        } else if (node.getRight() != null) {
            insert(node.getRight(), key);
        } else {
            node.setRight(new Node<>(key));
        }
    }

    private void srd(Node<T> node) {
        if (node != null) {
            srd(node.getLeft());
            System.out.print(node.getValue() + " ");
            srd(node.getRight());
        }
    }
}

class Queue<T> {
    private Node<T> head, tail;

    Queue() {
        this.head = this.tail = null;
    }

    T pop() throws RuntimeException {
        if (head == null) {
            throw new RuntimeException("Cannot pop more elements.");
        } else if (head == tail) {
            T popped = head.getValue();
            head = tail = null;
            return popped;
        } else {
            T popped = head.getValue();
            head = head.getRight();
            head.setLeft(null);
            return popped;
        }
    }

    void push(T element) {
        if (tail == null) {
            head = tail = new Node<>(element);
        } else {
            tail.setRight(new Node<>(element, tail, null));
            tail = tail.getRight();
        }
    }

    boolean isEmpty() {
        return head == null;
    }

    void print() {
        for (Node<T> node = head; node != null; node = node.getRight()) {
            System.out.print(node.getValue() + " ");
        }
    }
}

class Node<T> {
    private T value;
    private Node<T> left, right;

    Node(T value) {
        this(value, null, null);
    }

    Node(T value, Node<T> left, Node<T> right) {
        this.value = value;
        this.left = left;
        this.right = right;
    }

    T getValue() {
        return value;
    }

    Node<T> getLeft() {
        return left;
    }

    void setLeft(Node<T> left) {
        this.left = left;
    }

    Node<T> getRight() {
        return right;
    }

    void setRight(Node<T> right) {
        this.right = right;
    }
}
