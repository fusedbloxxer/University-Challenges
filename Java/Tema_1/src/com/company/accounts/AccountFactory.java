package com.company.accounts;

import com.company.exceptions.AccountFactoryException;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

final public class AccountFactory {

    private static final Pattern baseAccountPattern = Pattern.compile(".*base.*");
    private static final Pattern strictAccountPattern = Pattern.compile(".*strict.*");
    private static final Pattern limitedAccountPattern = Pattern.compile(".*limited.*");

    private AccountFactory() {
        throw new RuntimeException("Cannot create an account factory");
    }

    public static Account newAccount(String accountType) throws AccountFactoryException {
        String lowerCase = accountType.toLowerCase();
        if (baseAccountPattern.matcher(lowerCase).matches()) {
            return new Account();
        } else if (strictAccountPattern.matcher(lowerCase).matches()) {
            return new StrictAccount();
        } else if (limitedAccountPattern.matcher(lowerCase).matches()) {
            return new LimitedAccount();
        } else {
            throw new AccountFactoryException();
        }
    }
}
