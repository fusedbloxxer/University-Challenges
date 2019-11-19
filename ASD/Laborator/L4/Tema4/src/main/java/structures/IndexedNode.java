package structures;

public class IndexedNode<T> extends Node<T> {
    private int leftSize;

    IndexedNode(T value) {
        super(value);
        this.leftSize = 0;
    }

    public int getLeftSize() {
        return leftSize;
    }

    public void setLeftSize(int leftSize) {
        this.leftSize = leftSize;
    }

    @Override
    public String toString() {
        return leftSize + ":" + super.toString() + " ";
    }
}
