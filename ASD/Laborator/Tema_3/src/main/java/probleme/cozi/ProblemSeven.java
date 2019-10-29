package probleme.cozi;

import exceptions.DigitalBinaryImageException;
import utils.HelperSingleton;

import java.io.FileNotFoundException;
import java.io.BufferedReader;
import java.io.FileReader;
import java.util.Scanner;

public class ProblemSeven {
    private static final String FILE_NAME = "digitalbinary.txt";

    public static void main(String[] args) throws FileNotFoundException, DigitalBinaryImageException {
        printMatrix(comp(printMatrix(readMatrix())));
    }

    private static int[][] comp(int[][] m) {
        int num = 2;
        for (int i = 0; i < m.length; i++) {
            for (int j = 0; j < m.length; j++) {
                if (label(m, i, j, num)) {
                    ++num;
                }
            }
        }
        return m;
    }

    private static boolean label(int[][] m, int i, int j, int num) {
        if (inBounds(m, i, j)) {
            m[i][j] = num;

            label(m, i - 1, j, num);
            label(m, i + 1, j, num);
            label(m, i, j - 1, num);
            label(m, i, j + 1, num);
            return true;
        }
        return false;
    }

    private static boolean inBounds(int[][] m, int i, int j) {
        return i >= 0 && j >= 0 && i < m.length && j < m.length && m[i][j] == 1;
    }

    private static int[][] readMatrix() throws FileNotFoundException, DigitalBinaryImageException {
        Scanner scanner = new Scanner(new BufferedReader(new FileReader(HelperSingleton.DEFAULT_PATH + FILE_NAME)));
        int size = scanner.nextInt();
        int[][] matrix = new int[size][size];
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if ((matrix[i][j] = scanner.nextInt()) > 1 || matrix[i][j] < 0) {
                    throw new DigitalBinaryImageException();
                }
            }
        }
        return matrix;
    }

    private static int[][] printMatrix(int[][] matrix) {
        for (int[] ints : matrix) {
            for (int j = 0; j < matrix.length; j++) {
                System.out.print(ints[j] + " ");
            }
            System.out.println();
        }
        System.out.println();
        return matrix;
    }
}
