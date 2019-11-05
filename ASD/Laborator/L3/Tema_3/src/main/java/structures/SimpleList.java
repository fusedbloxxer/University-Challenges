package structures;

public class SimpleList {
    private SimpleNode head, tail;

    public SimpleList() {
        head = tail = null;
    }

    public void reverse(boolean withMemory) {
        if (withMemory) {
            SimpleList list = new SimpleList();
            for (SimpleNode node = head; node != null; node = node.getNext()) {
                list.pushFront(node.getValue());
            }
            list.print();
        } else {
            SimpleNode node = head;
            while (node != null && node.getNext() != null) {
                SimpleNode temp = node.getNext();
                node.setNext(temp.getNext());
                temp.setNext(head);
                head = temp;
            }
            print();
        }
    }


    public void removeFront() {
        if (head != null) {
            if (head == tail) {
                head = tail = null;
            } else {
                head = head.getNext();
            }
        }
    }

    public void removeBack() {
        if (head != null) {
            if (head == tail) {
                head = tail = null;
            } else {
                SimpleNode node = head;
                while (node.getNext() != tail) {
                    node = node.getNext();
                }
                node.setNext(null);
                tail = node;
            }
        }
    }

    public void pushBack(int element) {
        if (head == null) {
            head = tail = new SimpleNode(element);
        } else {
            tail.setNext(new SimpleNode(element));
            tail = tail.getNext();
        }
    }

    public void pushFront(int element) {
        if (head == null) {
            head = tail = new SimpleNode(element);
        } else {
            head = new SimpleNode(element, head);
        }
    }

    public void print() {
        System.out.print("The List is: ");
        for (SimpleNode node = head; node != null; node = node.getNext()) {
            System.out.print(node.getValue() + " ");
        }
        System.out.println();
    }

    public void clear() {
        while (head != null) {
            removeFront();
        }
    }
}
