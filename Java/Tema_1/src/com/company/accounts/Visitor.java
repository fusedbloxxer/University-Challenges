package com.company.accounts;

public interface Visitor {
    void visit(LimitedAccount account);

    void visit(StrictAccount account);
}
