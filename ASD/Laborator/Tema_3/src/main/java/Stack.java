public class Stack implements ContainerInterface {
    private SimpleNode head;

    public Stack() {
        head = null;
    }

    public void push(int element) {
        head = new SimpleNode(element, head);
    }

    public int pop() throws Exception {
        if (head == null) {
            throw new Exception("No elements to pop.");
        } else {
            SimpleNode temp = head;
            head = head.getNext();
            temp.setNext(null);
            return temp.getValue();
        }
    }

    public int peek() throws Exception {
        if (head == null) {
            throw new Exception("No elements to peek.");
        } else {
            return head.getValue();
        }
    }

    public boolean empty() {
        return head == null;
    }

    public int search(int element) {
        SimpleNode node = head; int index = 0;
        while (node != null) {
            if (element == node.getValue()) {
                return index;
            }
            node = node.getNext();
        }
        return -1;
    }

    public void print() {
        SimpleNode node = head;
        while (node != null) {
            System.out.print(node.getValue() + " ");
            node = node.getNext();
        }
    }

}
