package com.company.accounts;

public class UpdateVisitor implements Visitor {
    private double minBalance, withdrawLimit;

    public UpdateVisitor() {
        this(0, 0);
    }

    public UpdateVisitor(double minBalance, double withdrawLimit) {
        super();
        this.minBalance = minBalance;
        this.withdrawLimit = withdrawLimit;
    }

    public UpdateVisitor setMinBalance(double minBalance) {
        this.minBalance = minBalance;
        return this;
    }

    public UpdateVisitor setWithdrawLimit(double withdrawLimit) {
        this.withdrawLimit = withdrawLimit;
        return this;
    }

    @Override
    public void visit(LimitedAccount account) {
        account.setLimit(withdrawLimit);
    }

    @Override
    public void visit(StrictAccount account) {
        account.setMinBalance(minBalance);
    }
}
