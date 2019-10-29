public class Main {
    public static void main(String[] args) {
        Stack stack = new Stack();

        try {
            stack.pop();
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
        stack.push(3);
        stack.push(4);
        stack.push(5);
        stack.print();
    }
}
