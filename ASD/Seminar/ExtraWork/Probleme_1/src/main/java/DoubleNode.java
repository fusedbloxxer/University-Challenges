package main.java;

public class DoubleNode <T> {
    private T value;
    private DoubleNode<T> prev, next;

    DoubleNode(Builder<T> builder) {
        this.value = builder.value;
        this.prev = builder.prev;
        this.next = builder.next;
    }

    public T getValue() {
        return value;
    }

    public void setValue(T value) {
        this.value = value;
    }

    public DoubleNode<T> getPrev() {
        return prev;
    }

    public void setPrev(DoubleNode<T> prev) {
        this.prev = prev;
    }

    public DoubleNode<T> getNext() {
        return next;
    }

    public void setNext(DoubleNode<T> next) {
        this.next = next;
    }

    public static class Builder<T> {
        private T value;
        private DoubleNode<T> prev, next;

        Builder(T value) {
            this.value = value;
        }

        public Builder<T> setPrev(DoubleNode<T> prev) {
            this.prev = prev;
            return this;
        }

        public Builder<T> setNext(DoubleNode<T> next) {
            this.next = next;
            return this;
        }

        public DoubleNode<T> build() {
            return new DoubleNode<>(this);
        }
    }
}
