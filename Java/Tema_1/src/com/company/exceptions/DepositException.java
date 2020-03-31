package com.company.exceptions;

public class DepositException extends RuntimeException {

    public DepositException() {
        this("Deposit sum cannot be negative.");
    }

    public DepositException(String message) {
        super(message);
    }
}
