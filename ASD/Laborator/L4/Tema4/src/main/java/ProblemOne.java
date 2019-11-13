import structures.BinaryTree;
import structures.Tree;

import java.util.Collections;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class ProblemOne {
    public static void main(String[] args) {
        Tree<Integer> tree = new BinaryTree<>();
        List<Integer> list = IntStream.range(1, 10).boxed().collect(Collectors.toList());
        Collections.shuffle(list);
        list.forEach(tree::insert);
        System.out.println(list);

        tree.rsd();
        System.out.println();
        tree.srd();
        System.out.println();
        tree.sdr();
        System.out.println();

        list.parallelStream().forEach(x -> {
            System.out.println(x + " : " + tree.search(x));
        });

        System.out.println(tree.findMax());
    }
}
