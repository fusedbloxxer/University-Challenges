package com.company.exceptions;

public class LimitException extends RuntimeException {

    public LimitException() {
        this("You cannot have negative limits.");
    }

    public LimitException(String message) {
        super(message);
    }
}
