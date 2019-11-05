package exceptions;

public class DigitalBinaryImageException extends Exception {
    private static final String NOT_BINARY_ERROR = "Matrix is not binary !";

    public DigitalBinaryImageException() {
        super(NOT_BINARY_ERROR);
    }

    DigitalBinaryImageException(String message) {
        super(message);
    }
}
