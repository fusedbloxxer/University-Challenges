package com.company;

import com.company.accounts.Account;
import com.company.accounts.AccountFactory;
import com.company.accounts.LimitedAccount;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Bank.createSingleton("ING Romania");

        Bank.getInstance().newAccount("Base account");
        Bank.getInstance().newAccount("Limited account");
        Bank.getInstance().newAccount("Strict account");

        Bank.getInstance().updateAccount(0, 50);
        Bank.getInstance().updateAccount(1, 35.44);
        Bank.getInstance().updateAccount(2, 23.81);

        LimitedAccount account = (LimitedAccount) AccountFactory.newAccount("limited");
        account.setLimit(200);
        account.deposit(1000);
        account.withdraw(200);

        Bank.getInstance().addAccount(account);

        System.out.println(Bank.getInstance().accountReport(0));
        System.out.println(Bank.getInstance());

        try (Scanner scanner = new Scanner(new BufferedReader(new FileReader("mips_code.asm")))) {
            StringBuilder stringBuilder = new StringBuilder();
            stringBuilder.append("__asm(");
            while (scanner.hasNextLine()) {
                stringBuilder.append("\"").append(scanner.nextLine().replaceAll("\"", "\\\\\"")).append("\"").append("\n");
            }
            System.out.println(stringBuilder.append(");").toString());
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }
}
