package probleme.liste;

import structures.SimpleList;

import java.util.stream.IntStream;

public class ProblemNine {
    public static void main(String[] args) {
        SimpleList list = new SimpleList();
        IntStream.range(0, 10).forEach(list::pushBack);

        System.out.print("Initial - ");
        list.print();
        System.out.print("Reversed, with memory - ");
        list.reverse(true);
        System.out.print("Reversed, no memory - ");
        list.reverse(false);
    }
}
