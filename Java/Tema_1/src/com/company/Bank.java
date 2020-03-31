package com.company;

import com.company.accounts.*;
import com.company.exceptions.AccountNotFoundException;

import java.util.ArrayList;
import java.util.InputMismatchException;
import java.util.List;
import java.util.Optional;

final public class Bank {
    private final String name;
    private final UpdateVisitor visitor;
    private final List<Account> accounts;

    private static Bank INSTANCE = null;

    private Bank(String name) {
        this.name = new String(name);
        this.accounts = new ArrayList<>();
        this.visitor = new UpdateVisitor();
        System.out.println("The bank was created.");
    }

    public static Bank createSingleton(String name) throws InputMismatchException {
        synchronized (Bank.class) {
            if (INSTANCE == null) {
                synchronized (Bank.class) {
                    INSTANCE = new Bank(name);
                }
            }
        }
        if (!INSTANCE.name.equals(name)) {
            throw new InputMismatchException("Bank name is different! Original name is: " + INSTANCE.name);
        }
        return INSTANCE;
    }

    public static Bank getInstance() {
        if (INSTANCE == null) {
            throw new RuntimeException("Create an instance first!");
        }
        return INSTANCE;
    }

    public void addAccount(Account account) {
        try {
            this.accounts.add(account.clone());
        } catch (CloneNotSupportedException e) {
            e.printStackTrace();
        }
    }

    public void newAccount(String accountType) {
        this.accounts.add(AccountFactory.newAccount(accountType));
    }

    public List<Account> getAccounts() {
        return new ArrayList<>(accounts);
    }

    private Account findAccount(int accountNumber) throws AccountNotFoundException {
        Optional<Account> account = this.accounts.parallelStream().
                filter(acc -> acc.getNumber() == accountNumber)
                .findFirst();

        if (account.isPresent()) {
            return account.get();
        }

        throw new AccountNotFoundException("Account with id " + accountNumber + " does not exist.");
    }

    public String accountReport(int accountNumber) throws AccountNotFoundException {
        return findAccount(accountNumber).toString();
    }

    public void updateAccount(int accountNumber, double data) throws AccountNotFoundException {
        findAccount(accountNumber).accept(visitor.setMinBalance(data).setWithdrawLimit(data));
    }

    public String getName() {
        return name;
    }

    @Override
    public String toString() {
        return "Bank{" +
                "name='" + name + '\'' +
                ", accounts=" + accounts +
                '}';
    }
}
