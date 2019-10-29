public interface ContainerInterface {
    void push(int element);
    int pop() throws Exception;
    int peek() throws Exception;
    int search(int element);
    void print();
    boolean empty();
}
