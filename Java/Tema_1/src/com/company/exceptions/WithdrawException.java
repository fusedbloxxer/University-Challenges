package com.company.exceptions;

public class WithdrawException extends RuntimeException {

    public WithdrawException() {
        this("Cannot withdraw more than current balance.");
    }

    public WithdrawException(String message) {
        super(message);
    }

}
