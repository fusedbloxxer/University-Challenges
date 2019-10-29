package probleme.liste;

import structures.SimpleList;

import java.util.stream.IntStream;

public class ProblemNine {
    public static void main(String[] args) {
        SimpleList list = new SimpleList();
        IntStream.range(0, 10).forEach(list::pushBack);

        list.print();
        list.reverse(true);
        list.reverse(false);
    }
}
