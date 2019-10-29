package exceptions;

public class PopException extends Exception {
    private static final String POP_EXCEPTION = "No elements to pop.";

    public PopException() {
        super(POP_EXCEPTION);
    }

    public PopException(String message) {
        super(message);
    }
}
