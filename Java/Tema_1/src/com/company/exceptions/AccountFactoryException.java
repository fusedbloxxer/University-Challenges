package com.company.exceptions;

public class AccountFactoryException extends RuntimeException {

    public AccountFactoryException() {
        this("Cannot create an account.");
    }

    public AccountFactoryException(String message) {
        super(message);
    }
}
