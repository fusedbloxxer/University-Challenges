package utils;

import structures.GenericList;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.Scanner;

public class HelperSingleton {
    public static final String DEFAULT_PATH = "src/main/resources/";
    private static HelperSingleton SINGLETON;

    private HelperSingleton() {
    }

    public static HelperSingleton getInstance() {
        if (SINGLETON == null) {
            synchronized (HelperSingleton.class) {
                if (SINGLETON == null) {
                    SINGLETON = new HelperSingleton();
                }
            }
        }
        return SINGLETON;
    }

    public GenericList<String> readLines(String fileName) throws FileNotFoundException {
        GenericList<String> list = new GenericList<>();
        Scanner scanner = new Scanner(new BufferedReader(new FileReader(HelperSingleton.DEFAULT_PATH + fileName)));
        while (scanner.hasNextLine()) {
            list.pushBack(scanner.nextLine());
        }
        return list;
    }
}
