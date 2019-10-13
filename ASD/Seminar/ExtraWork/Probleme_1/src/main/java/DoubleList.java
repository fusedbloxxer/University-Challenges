package main.java;

public class DoubleList<T> {
    private DoubleNode<T> head, tail;

    DoubleList() {
        this.tail = null;
    }

    @SafeVarargs
    public DoubleList(T... elements) {
        for (T element : elements) {
            addLast(element);
        }
    }

    public void addLast(T element) {
        DoubleNode<T> node = new DoubleNode.Builder<>(element)
                .setPrev(tail)
                .setNext(null)
                .build();

        if (tail == null) {
            head = node;
        } else {
            tail.setNext(node);
        }
        tail = node;
    }

    public DoubleList<T> removeLast() {
        if (tail != null) {
            if (tail == head) {
                head = tail = null;
            } else {
                tail = tail.getPrev();
                tail.setNext(null);
            }
        }
        return this;
    }

    void max() {

    }

    @Override
    public String toString() {
        StringBuilder builder = new StringBuilder();
        for (DoubleNode<T> node = head; node != null; node = node.getNext()) {
            builder.append(node.getValue());
            if (node.getNext() != null) {
                builder.append(" ");
            }
        }
        return builder.toString();
    }
}
