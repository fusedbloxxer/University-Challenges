package com.company.accounts;

import com.company.exceptions.DepositException;
import com.company.exceptions.WithdrawException;

public class Account implements Visitable, Cloneable {
    private static int ACCOUNT_COUNT = 0;

    protected double balance;
    final protected int number;

    public Account() {
        this(0);
    }

    public Account(double balance) {
        this.deposit(balance);
        this.number = ACCOUNT_COUNT++;
    }

    public void deposit(double sum) throws DepositException {
        if (sum < 0) {
            throw new DepositException();
        }
        this.balance += sum;
    }

    public void withdraw(double sum) throws WithdrawException {
        if (sum > balance) {
            throw new WithdrawException("Cannot withdraw more that the current balance: " + balance);
        }
        this.balance -= sum;
    }

    public double getBalance() {
        return balance;
    }

    public int getNumber() {
        return number;
    }

    @Override
    public String toString() {
        return "Account{" +
                "balance=" + balance +
                ", number=" + number +
                '}';
    }

    @Override
    public Account clone() throws CloneNotSupportedException {
        return (Account) super.clone();
    }

    @Override
    public void accept(Visitor visitor) {
        // Null Object Pattern
    }
}
