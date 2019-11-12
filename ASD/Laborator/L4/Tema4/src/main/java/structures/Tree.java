package structures;

public interface Tree <T extends Comparable<T>> {
    void insert(Node<T> node, T key);
    boolean search(Node<T> node, T key);
    T findMax(Node<T> node);
    void rsd(Node<T> node);
    void srd(Node<T> node);
    void sdr(Node<T> node);
    void delete(Node<T> node, T key);
}