package main.java;

public class SimpleList<T> {
    private SimpleNode<T> head;
    private int size;

    SimpleList() {
        this.head = null;
        this.size = 0;
    }

    @SafeVarargs
    public SimpleList(T... elements) {
        for (T element : elements) {
            addFirst(element);
        }
    }

    private void removeFirst() {
        if (head != null) {
            head = head.getNext();
        }
        --size;
    }

    public boolean isPalindrome() {
        SimpleList<T> list = new SimpleList<>();
        for (SimpleNode<T> node = head; node != null; node = node.getNext()) {
            list.addFirst(node.getValue());
        }

        SimpleNode<T> nodeOne = head;
        SimpleNode<T> nodeTwo = list.head;
        while (nodeOne != null && nodeTwo != null) {
            if (nodeOne.getValue() != nodeTwo.getValue()) {
                return false;
            }
            nodeOne = nodeOne.getNext();
            nodeTwo = nodeTwo.getNext();
        }
        return true;
    }

    public SimpleList<T> reverse() {
        for (SimpleNode<T> node = head; node.getNext() != null;) {
            SimpleNode<T> temp = node.getNext();
            node.setNext(node.getNext().getNext());
            temp.setNext(head);
            head = temp;
        }
        return this;
    }

    public SimpleList<T> removeKth(int k) {
        if ((k = size - k - 1) < 0 || k > size) {
            throw new IndexOutOfBoundsException("K is out of bounds.");
        }
        if (k == 0) {
            removeFirst();
        } else {
            removeInterior(k);
        }
        return this;
    }

    private void removeInterior(int k) {
        SimpleNode<T> node = head;
        for (int i = 0; i < k - 1; i++) {
            node = node.getNext();
        }
        node.setNext(node.getNext().getNext());
        --size;
    }

    void addFirst(T element) {
        head = new SimpleNode<>(element, head);
        ++size;
    }

    public int getSize() {
        return size;
    }

    @Override
    public String toString() {
        StringBuilder builder = new StringBuilder();
        for (SimpleNode<T> node = head; node != null; node = node.getNext()) {
            builder.append(node.getValue());
            if (node.getNext() != null) {
                builder.append(" ");
            }
        }
        return builder.toString();
    }
}
