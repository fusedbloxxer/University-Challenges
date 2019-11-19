package structures;

public interface BinaryTree<T> {
    void insert(T key);

    int search(T key);

    void rsd();

    void srd();

    void sdr();

    void delete(T key);
}