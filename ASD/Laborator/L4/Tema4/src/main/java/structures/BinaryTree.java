package structures;

public class BinaryTree<T extends Comparable<T>> implements Tree<T> {
    private Node<T> root;

    public void insert(Node<T> node, T key) {
        if (root == null) {
            // Insert at root if it doesn't exist.
            root = new Node<T>(key);
        } else if (key.compareTo(node.getValue()) < 0) {
            // Insert in the left branch.
            if (node.getLeft() == null) {
                node.setLeft(new Node<T>(key));
            } else {
                insert(node.getLeft(), key);
            }
        } else {
            // Insert in the right branch.
            if (node.getRight() == null) {
                node.setRight(new Node<T>(key));
            } else {
                insert(node.getRight(), key);
            }
        }
    }

    public boolean search(Node<T> node, T key) {
        if (node != null) {
            if (node.getValue().equals(key)) {
                return true;
            } else {
                return search(node.getLeft(), key) || search(node.getRight(), key);
            }
        }
        return false;
    }

    public T findMax(Node<T> node) {
        if (node == null) {
            return null;
        }

        T max = node.getValue();
        T leftMax = findMax(node.getLeft());
        T rightMax = findMax(node.getRight());

        if (leftMax != null && max.compareTo(leftMax) < 0) {
            max = leftMax;
        }

        if (rightMax != null && max.compareTo(rightMax) < 0) {
            max = rightMax;
        }

        return max;
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
            sdr(node.getLeft());
            sdr(node.getRight());
            System.out.print(node + " ");
        }
    }

    public void delete(Node<T> node, T key) {
        // TODO
    }

    public void keyFinder(Node<T> node, T keyOne, T keyTwo) {
        // TODO
    }

    @Override
    public void insert(T key) {
        insert(root, key);
    }

    @Override
    public boolean search(T key) {
        return search(root, key);
    }

    @Override
    public T findMax() {
        return findMax(root);
    }

    @Override
    public void rsd() {
        rsd(root);
    }

    @Override
    public void srd() {
        srd(root);
    }

    @Override
    public void sdr() {
        sdr(root);
    }

    @Override
    public void delete(T key) {
        delete(root, key);
    }

    @Override
    public void keyFinder(T keyOne, T keyTwo) {
        keyFinder(root, keyOne, keyTwo);
    }
}
