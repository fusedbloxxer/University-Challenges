package test.java;

import main.java.DoubleList;
import org.junit.Assert;
import org.junit.Test;

import java.util.LinkedList;
import java.util.List;

public class DoubleListTest {

    @Test
    public void shouldInsertLastElement() {
        Assert.assertEquals("1 2 3 4 5", new DoubleList<>(1, 2, 3, 4, 5).toString());
        Assert.assertEquals("1 2 3", new DoubleList<>(1, 2, 3).toString());
        Assert.assertEquals("1 2", new DoubleList<>(1, 2).toString());
        Assert.assertEquals("1", new DoubleList<>(1).toString());
        Assert.assertEquals("", new DoubleList<>().toString());
    }

    @Test
    public void shouldRemoveLastElement() {
        Assert.assertEquals("1 2 3 4", new DoubleList<>(1, 2, 3, 4, 5).removeLast().toString());
        Assert.assertEquals("1 2 3", new DoubleList<>(1, 2, 3, 4).removeLast().toString());
        Assert.assertEquals("1 2", new DoubleList<>(1, 2, 3).removeLast().toString());
        Assert.assertEquals("1", new DoubleList<>(1, 2).removeLast().toString());
        Assert.assertEquals("", new DoubleList<>(1).removeLast().toString());

        List<Integer> list = new LinkedList<>();
    }
}
