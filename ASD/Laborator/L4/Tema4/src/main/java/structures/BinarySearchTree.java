package structures;

public class BinarySearchTree<T extends Comparable<T>> implements BinaryTree<T> {
    Node<T> root;

    void insert(Node<T> node, T key) {
        if (key.compareTo(node.getValue()) < 0) {
            if (node.hasLeft()) {
                insert(node.getLeft(), key);
            } else {
                node.setLeft(new Node<>(key));
            }
        } else if (node.hasRight()) {
            insert(node.getRight(), key);
        } else {
            node.setRight(new Node<>(key));
        }
    }

    int search(Node<T> node, T key) {
        if (node != null) {
            int comparison = key.compareTo(node.getValue());
            if (comparison == 0) {
                return 1;
            } else if (comparison < 0) {
                return search(node.getLeft(), key);
            } else {
                return search(node.getRight(), key);
            }
        }
        return 0;
    }

    T findMax(Node<T> node) {
        if (node.hasRight()) {
            return findMax(node.getRight());
        }
        return node.getValue();
    }

    void rsd(Node<T> node) {
        if (node != null) {
            System.out.print(node + " ");
            rsd(node.getLeft());
            rsd(node.getRight());
        }
    }

    void srd(Node<T> node) {
        if (node != null) {
            srd(node.getLeft());
            System.out.print(node + " ");
            srd(node.getRight());
        }
    }

    void sdr(Node<T> node) {
        if (node != null) {
            sdr(node.getLeft());
            sdr(node.getRight());
            System.out.print(node + " ");
        }
    }

    void delete(Node<T> node, T key) {
        if (key.compareTo(node.getValue()) < 0) {
            if (node.hasLeft()) {
                if (key.compareTo(node.getLeft().getValue()) == 0) {

                    if (node.getLeft().getCount() <= 1) {
                        // Has 1 child
                        if (node.getLeft().hasLeft()) {
                            node.setLeft(node.getLeft().getLeft());
                        } else {
                            node.setLeft(node.getLeft().getRight());
                        }
                    } else {
                        // Has 2 children
                        Node<T> parent, pred;
                        parent = pred = node.getLeft().getLeft();

                        while (pred.hasRight()) {
                            parent = pred;
                            pred = pred.getRight();
                        }

                        node.getLeft().setValue(pred.getValue());

                        // A
                        if (pred == parent) {
                            node.getLeft().setLeft(pred.getLeft());
                        } else {
                            parent.setRight(pred.getLeft());
                        }
                    }

                } else {
                    delete(node.getLeft(), key);
                }
            }
        } else if (node.hasRight()) {
            if (key.compareTo(node.getRight().getValue()) == 0) {

                if (node.getRight().getCount() <= 1) {
                    // Has 1 child
                    if (node.getRight().hasLeft()) {
                        node.setRight(node.getRight().getLeft());
                    } else {
                        node.setRight(node.getRight().getRight());
                    }
                } else {
                    // Has 2 children - Get Predecessor and its parent
                    Node<T> parent, pred;
                    parent = pred = node.getRight().getLeft();

                    while (pred.hasRight()) {
                        parent = pred;
                        pred = pred.getRight();
                    }

                    node.getRight().setValue(pred.getValue());

                    if (pred == parent) {
                        node.getRight().setLeft(pred.getLeft());
                    } else {
                        parent.setRight(pred.getLeft());
                    }
                }

            } else {
                delete(node.getRight(), key);
            }
        }
    }

    public void keyFinder(T keyOne, T keyTwo) {
        keyFinder(root, keyOne, keyTwo);
    }

    private void keyFinder(Node<T> node, T keyOne, T keyTwo) {
        if (node != null) {
            if (keyOne.compareTo(node.getValue()) > 0) {
                keyFinder(node.getRight(), keyOne, keyTwo);
                return;
            }

            if (keyTwo.compareTo(node.getValue()) < 0) {
                keyFinder(node.getLeft(), keyOne, keyTwo);
                return;
            }

            System.out.print(node.getValue() + " ");

            keyFinder(node.getLeft(), keyOne, keyTwo);
            keyFinder(node.getRight(), keyOne, keyTwo);
        }
    }

    @Override
    public void insert(T key) {
        if (root == null) {
            root = new Node<>(key);
        } else {
            insert(root, key);
        }
    }

    @Override
    public int search(T key) {
        return search(root, key);
    }

    public T findMax() {
        return root == null ? null : findMax(root);
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
        if (root != null) {
            if (key.compareTo(root.getValue()) == 0) {

                if (root.getCount() == 1) {
                    // Has 1 child
                    if (root.hasLeft()) {
                        root = root.getLeft();
                    } else {
                        root = root.getRight();
                    }
                } else {
                    // Has 2 children
                    Node<T> parent, pred;
                    parent = pred = root.getLeft();

                    while (pred.hasRight()) {
                        parent = pred;
                        pred = pred.getRight();
                    }

                    root.setValue(pred.getValue());

                    // A
                    if (pred == parent) {
                        root.setLeft(pred.getLeft());
                    } else {
                        parent.setRight(pred.getLeft());
                    }
                }

            } else {
                delete(root, key);
            }
        }
    }
}
