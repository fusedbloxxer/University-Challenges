package com.company.accounts;

import com.company.exceptions.LimitException;
import com.company.exceptions.WithdrawException;

public class LimitedAccount extends Account implements Cloneable {
    public static final double NO_LIMITS = -1;

    private double limit;

    public LimitedAccount() {
        this(0);
    }

    public LimitedAccount(double balance) {
        this(balance, NO_LIMITS);
    }

    public LimitedAccount(double balance, double limit) {
        super(balance);
        this.setLimit(limit);
    }

    @Override
    public void withdraw(double sum) throws WithdrawException, LimitException {
        if (sum > limit && limit != LimitedAccount.NO_LIMITS) {
            throw new LimitException("Cannot withdraw more than the current limit: " + limit);
        }
        super.withdraw(sum);
    }

    public void setLimit(double limit) throws LimitException {
        if (limit >= 0 || limit == LimitedAccount.NO_LIMITS) {
            this.limit = limit;
        } else {
            throw new LimitException();
        }
    }

    public double getLimit() {
        return limit;
    }

    @Override
    public String toString() {
        return "LimitedAccount{" +
                "limit=" + limit +
                ", balance=" + balance +
                ", number=" + number +
                '}';
    }

    @Override
    public void accept(Visitor visitor) {
        visitor.visit(this);
    }

    @Override
    public LimitedAccount clone() throws CloneNotSupportedException {
        return (LimitedAccount) super.clone();
    }
}
