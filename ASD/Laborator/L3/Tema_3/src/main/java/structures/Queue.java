package structures;

import exceptions.PeekException;
import exceptions.PopException;

public class Queue implements Container {
    private SimpleNode head, tail;

    public Queue() {
        head = tail = null;
    }

    public void push(int element) {
        if (head == null) {
            head = tail = new SimpleNode(element);
        } else {
            tail.setNext(new SimpleNode(element));
            tail = tail.getNext();
        }
    }

    public int pop() throws PopException {
        if (head == null) {
            throw new PopException();
        } else if (head == tail) {
            int element = head.getValue();
            head = tail = null;
            return element;
        } else {
            int element = head.getValue();
            head = head.getNext();
            return element;
        }
    }

    public int peek() throws PeekException {
        if (head == null) {
            throw new PeekException();
        } else {
            return head.getValue();
        }
    }

    public int search(int element) {
        SimpleNode node = head;
        int index = 0;
        while (node != null) {
            if (node.getValue() == element) {
                return index;
            }
            ++index;
            node = node.getNext();
        }
        return -1;
    }

    public void print() {
        System.out.print("The structure contains: ");
        for (SimpleNode node = head; node != null; node = node.getNext()) {
            System.out.print(node.getValue() + " ");
        }
        System.out.println();
    }

    public boolean empty() {
        return head == null;
    }
}
