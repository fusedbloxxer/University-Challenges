package com.company.accounts;

import com.company.exceptions.MinBalanceException;
import com.company.exceptions.WithdrawException;

public class StrictAccount extends Account implements Cloneable {
    private double minBalance;

    public StrictAccount() {
        this(0);
    }

    public StrictAccount(double balance) {
        this(balance, 0);
    }

    public StrictAccount(double balance, double minBalance) {
        super(balance);
        this.setMinBalance(minBalance);
    }

    @Override
    public void withdraw(double sum) throws WithdrawException, MinBalanceException {
        if (sum > super.balance - this.minBalance) {
            throw new MinBalanceException("Cannot withdraw more than: " + (balance - minBalance));
        }
        super.withdraw(sum);
    }

    public void setMinBalance(double minBalance) throws MinBalanceException {
        if (minBalance < 0) {
            throw new MinBalanceException();
        }
        this.minBalance = minBalance;
    }

    public double getMinBalance() {
        return minBalance;
    }

    @Override
    public String toString() {
        return "StrictAccount{" +
                "minBalance=" + minBalance +
                ", balance=" + balance +
                ", number=" + number +
                '}';
    }

    @Override
    public StrictAccount clone() throws CloneNotSupportedException {
        return (StrictAccount) super.clone();
    }

    @Override
    public void accept(Visitor visitor) {
        visitor.visit(this);
    }
}
