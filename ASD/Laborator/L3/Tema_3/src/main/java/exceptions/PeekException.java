package exceptions;

public class PeekException extends Exception {
    private static final String PEEK_EXCEPTION = "No elements to peek.";

    public PeekException() {
        super(PEEK_EXCEPTION);
    }

    PeekException(String message) {
        super(message);
    }
}
