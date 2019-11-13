package structures;

import com.sun.istack.internal.NotNull;

public interface Tree<T extends Comparable<T>> {
    void insert(T key);

    boolean search(T key);

    T findMax();

    void rsd();

    void srd();

    void sdr();

    void delete(T key);

    void keyFinder(T keyOne, T keyTwo);
}