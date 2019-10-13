package main.java;

public class Main {
    public static void main(String[] args) {
        DoubleList<Integer> list = new DoubleList<>();
        list.addLast(1);
        list.addLast(2);
        list.addLast(3);
        list.addLast(4);
        list.addLast(5);
        System.out.println(list);
    }
}
