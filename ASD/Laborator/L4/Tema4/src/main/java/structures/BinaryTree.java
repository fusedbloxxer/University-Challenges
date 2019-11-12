package structures;

public class BinaryTree <T extends Comparable<T>> implements Tree<T> {
    private Node<T> root;

    public void insert(Node<T> node, T key) {
    }

    public boolean search(Node<T> node, T key) {
        return false;
    }

    public T findMax(Node<T> node) {
        if (node != null) {
            T maxElement = findMax(node.getLeft());
            T rightElement = findMax(node.getRight());

            if (maxElement.compareTo(rightElement) < 0) {
                maxElement = rightElement;
            }

            if (maxElement.compareTo(node.getValue()) < 0) {
                maxElement = node.getValue();
            }

            return maxElement;
        }
    }

    public void rsd(Node<T> node) {
        if (node != null) {
            System.out.print(node + " ");
            rsd(node.getLeft());
            rsd(node.getRight());
        }
    }

    public void srd(Node<T> node) {
        if (node != null) {
            srd(node.getLeft());
            System.out.print(node + " ");
            srd(node.getRight());
        }
    }

    public void sdr(Node<T> node) {
        if (node != null) {
            System.out.print(node + " ");
            srd(node.getLeft());
            srd(node.getRight());
        }
    }

    public void delete(Node<T> node, T key) {

    }
}
