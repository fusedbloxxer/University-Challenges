package structures;

import exceptions.PeekException;
import exceptions.PopException;

public class Stack implements Container {
    private SimpleNode head;

    public Stack() {
        head = null;
    }

    public void push(int element) {
        head = new SimpleNode(element, head);
    }

    public int pop() throws PopException {
        if (head == null) {
            throw new PopException();
        } else {
            SimpleNode temp = head;
            head = head.getNext();
            temp.setNext(null);
            return temp.getValue();
        }
    }

    public int peek() throws PeekException {
        if (head == null) {
            throw new PeekException();
        } else {
            return head.getValue();
        }
    }

    public boolean empty() {
        return head == null;
    }

    public int search(int element) {
        SimpleNode node = head;
        int index = 0;
        while (node != null) {
            if (element == node.getValue()) {
                return index;
            }
            ++index;
            node = node.getNext();
        }
        return -1;
    }

    public void print() {
        System.out.print("The structure contains: ");
        SimpleNode node = head;
        while (node != null) {
            System.out.print(node.getValue() + " ");
            node = node.getNext();
        }
        System.out.println();
    }

}
