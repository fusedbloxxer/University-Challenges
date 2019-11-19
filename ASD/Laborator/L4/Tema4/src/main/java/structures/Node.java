package structures;

public class Node<T> {
    private T value;
    private Node<T> left, right;

    Node(T value) {
        this(value, null, null);
    }

    private Node(T value, Node<T> left, Node<T> right) {
        this.value = value;
        this.left = left;
        this.right = right;
    }

    T getValue() {
        return value;
    }

    public void setValue(T value) {
        this.value = value;
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

    boolean hasLeft() {
        return left != null;
    }

    boolean hasRight() {
        return right != null;
    }

    @Override
    public String toString() {
        return value + " ";
    }

    public int getCount() {
        int count = 0;

        if (left != null) {
            ++count;
        }

        if (right != null) {
            ++count;
        }

        return count;
    }
}
