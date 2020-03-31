package com.company.exceptions;

public class MinBalanceException extends RuntimeException {

    public MinBalanceException() {
        this("Min balance cannot be negative.");
    }

    public MinBalanceException(String message) {
        super(message);
    }
}
