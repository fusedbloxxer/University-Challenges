package structures;

import com.sun.istack.internal.NotNull;

public interface BinaryTree<T> {
    void insert(T key);

    int search(T key);

    T findMax();

    void rsd();

    void srd();

    void sdr();

    void delete(T key);
}