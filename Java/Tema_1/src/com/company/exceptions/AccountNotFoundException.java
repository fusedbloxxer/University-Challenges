package com.company.exceptions;

public class AccountNotFoundException extends RuntimeException {
    public AccountNotFoundException() {
        this("Account was not found.");
    }

    public AccountNotFoundException(String message) {
        super(message);
    }
}
