package structures;

public class IndexedBinaryTree<T extends Comparable<T>> extends BinarySearchTree<T> {

    private T kThPosition(IndexedNode<T> node, int k) {
        if (node != null) {
            if (node.getLeftSize() == k) {
                return node.getValue();
            } else if (k < node.getLeftSize()) {
                return kThPosition((IndexedNode<T>) node.getLeft(), k);
            } else {
                return kThPosition((IndexedNode<T>) node.getRight(), k - node.getLeftSize() - 1);
            }
        } else {
            return null;
        }
    }

    T kThPosition(int k) {
        return kThPosition((IndexedNode<T>) root, k);
    }

    @Override
    void insert(Node<T> node, T key) {
        if (key.compareTo(node.getValue()) < 0) {
            if (node.hasLeft()) {
                insert(node.getLeft(), key);
            } else {
                node.setLeft(new IndexedNode<>(key));
            }
            ((IndexedNode<T>) node).setLeftSize(((IndexedNode<T>) node).getLeftSize() + 1);
        } else if (node.hasRight()) {
            insert(node.getRight(), key);
        } else {
            node.setRight(new IndexedNode<>(key));
        }
    }

    @Override
    public void insert(T key) {
        if (root == null) {
            root = new IndexedNode<>(key);
        } else {
            insert(root, key);
        }
    }

    @Override
    public void delete(T key) {
        super.delete(key);
        refreshIndexes((IndexedNode<T>) root);
    }

    private int refreshIndexes(IndexedNode<T> node) {
        if (node != null) {
            node.setLeftSize(refreshIndexes((IndexedNode<T>) node.getLeft()));
            return node.getLeftSize() + 1 + refreshIndexes((IndexedNode<T>) node.getRight());
        }
        return 0;
    }
}
