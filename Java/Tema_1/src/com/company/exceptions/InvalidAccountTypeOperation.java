package com.company.exceptions;

public class InvalidAccountTypeOperation extends RuntimeException {
    public InvalidAccountTypeOperation() {
        this("This account type doesn't support the operation.");
    }

    public InvalidAccountTypeOperation(String message) {
        super(message);
    }
}
