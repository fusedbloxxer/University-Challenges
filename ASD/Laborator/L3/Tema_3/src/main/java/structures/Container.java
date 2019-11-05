package structures;

import exceptions.PeekException;
import exceptions.PopException;

public interface Container {
    void push(int element);

    int pop() throws PopException;

    int peek() throws PeekException;

    int search(int element);

    void print();

    boolean empty();
}
