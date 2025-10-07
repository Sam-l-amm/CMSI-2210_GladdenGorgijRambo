import java.util.Scanner;

public class Three {
    private static Scanner scanner = new Scanner(System.in);
    public static void main(String[] args) {

        System.out.print("Enter the initial balance: ");
        double balance = scanner.nextDouble();
        
        System.out.print("Enter the annual interest rate (in percent): ");
        double annualRate = scanner.nextDouble();
        double monthlyRate = (annualRate / 100) / 12;
        for (int month = 1; month <= 3; month++) {
            balance = balance * (1 + monthlyRate);
            System.out.printf("After month %d, the balance is: $%.2f%n", month, balance);
        }
    }
}