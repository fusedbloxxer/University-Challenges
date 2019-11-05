package probleme.liste;

import structures.GenericList;
import structures.GenericNode;
import structures.SimpleList;

import java.util.stream.IntStream;

public class ProblemTen {
    public static void main(String[] args) {
        GenericList<Integer> A = new GenericList<>();
        GenericList<Integer> B = new GenericList<>();
        IntStream.range(3, 10).forEach(A::pushBack);
        IntStream.range(2, 9).forEach(B::pushBack);
        A.print();
        B.print();

        // TODO: Check if it is correct ?
        GenericList<Integer> C = mergeLists(A, B);
        C.print();
    }

    private static GenericList<Integer> mergeLists(GenericList<Integer> A, GenericList<Integer> B) {
        GenericList<Integer> C = A;
        GenericNode<Integer> nodeA = A.getHead(), nodeB = B.getHead();

        if (nodeA == null && nodeB == null) {
            C.setHead(null);
            C.setTail(null);
        } else if (nodeA != null && nodeB == null) {
            C.setHead(nodeA);
            C.setTail(nodeA);
        } else if (nodeA == null) {
            C.setHead(nodeB);
            C.setTail(nodeB);
        } else {
            if (nodeA.getValue().compareTo(nodeB.getValue()) < 0) {
                C.setHead(nodeA);
                nodeA = nodeA.getNext();
            } else {
                C.setHead(nodeB);
                nodeB = nodeB.getNext();
            }

            GenericNode<Integer> nodeC = C.getHead();
            while (nodeA != null && nodeB != null) {
                if (nodeA.getValue().compareTo(nodeB.getValue()) < 0) {
                    nodeC.setNext(nodeA);
                    nodeA = nodeA.getNext();
                } else {
                    nodeC.setNext(nodeB);
                    nodeB = nodeB.getNext();
                }
                nodeC = nodeC.getNext();
            }

            if (nodeA != null) {
                nodeC.setNext(nodeA);
            }

            if (nodeB != null) {
                nodeC.setNext(nodeB);
            }

            C.setTail(nodeC.getNext());
        }
        return C;
    }
}
