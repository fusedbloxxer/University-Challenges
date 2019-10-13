package main.java;

import java.util.LinkedList;
import java.util.List;

public class Stuff {
    public static void main(String[] args) {
        Bob bob = new Bob() {
            @Override
            public Bob getNext() {
                return null;
            }
        };

        bob = new BobSimplu();
        bob.getNext();
        LinkedList
    }
}

interface Bob {
    Bob getNext();
    void setBob(Bob bob);
}

class BobSimplu implements Bob {

    @Override
    public BobSimplu getNext() {
        return this;
    }

    @Override
    public void setBob(BobSimplu bob) {

    }
}