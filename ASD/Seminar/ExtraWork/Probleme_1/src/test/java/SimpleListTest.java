package test.java;

import main.java.SimpleList;
import org.junit.Assert;
import org.junit.Test;

public class SimpleListTest {
    @Test
    public void testInsertion() {
        Assert.assertEquals("1 2 3", new SimpleList<>(3, 2, 1).toString());
        Assert.assertEquals("1 4", new SimpleList<>(4, 1).toString());
        Assert.assertEquals("3", new SimpleList<>(3).toString());
        Assert.assertEquals("", new SimpleList<Integer>().toString());
    }

    @Test
    public void testRemoveKthFunction() {
        SimpleList<Integer> list = new SimpleList<>(3, 2, 1, 0);
        Assert.assertEquals("0 1 2", list.removeKth(0).toString());
        Assert.assertEquals("0 2", list.removeKth(1).toString());
        Assert.assertEquals("2", list.removeKth(1).toString());
        Assert.assertEquals("", list.removeKth(0).toString());
    }

    @Test
    public void testReverseFunction() {
        Assert.assertEquals("0 1 2 3 4", new SimpleList<>(0, 1, 2, 3, 4).reverse().toString());
        Assert.assertEquals("0 1 2 3", new SimpleList<>(0, 1, 2, 3).reverse().toString());
        Assert.assertEquals("1 2", new SimpleList<>(1, 2).reverse().toString());
        Assert.assertEquals("0", new SimpleList<>(0).reverse().toString());
    }

    @Test
    public void testPalindromeFunction() {
        Assert.assertFalse(new SimpleList<>(1, 2, 3).isPalindrome());
        Assert.assertFalse(new SimpleList<>(1, 2).isPalindrome());
        Assert.assertFalse(new SimpleList<>(1, 2, 2).isPalindrome());
        Assert.assertTrue(new SimpleList<>(1).isPalindrome());
        Assert.assertTrue(new SimpleList<>(1, 1).isPalindrome());
        Assert.assertTrue(new SimpleList<>(1, 2, 1).isPalindrome());
    }
}
