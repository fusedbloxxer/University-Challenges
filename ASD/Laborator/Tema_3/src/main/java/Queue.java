public class Queue implements ContainerInterface {
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

    public int pop() throws Exception {
        if (head == tail) {

        } else {

        }
    }

    public int peek() throws Exception {
        return 0;
    }

    public int search(int element) {
        return 0;
    }

    public void print() {
        for (SimpleNode node = head; node != null; node = node.getNext()) {
            System.out.print(node.getValue() + " ");
        }
    }

    public boolean empty() {
        return head == null;
    }
}
