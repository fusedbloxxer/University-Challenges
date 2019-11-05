package structures;

public class SimpleNode {
    private int value;
    private SimpleNode next;

    public SimpleNode(int value) {
        this(value, null);
    }

    public SimpleNode(int value, SimpleNode next) {
        this.value = value;
        this.next = next;
    }

    public int getValue() {
        return value;
    }

    public void setValue(int value) {
        this.value = value;
    }

    public SimpleNode getNext() {
        return next;
    }

    public void setNext(SimpleNode next) {
        this.next = next;
    }
}
