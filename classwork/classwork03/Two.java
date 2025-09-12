import java.util.Scanner;
import java.util.Map;
import java.util.HashMap;

public class Two {

    private static Scanner scanner = new Scanner(System.in);
    public static void main(String[] args) {

        Map<String, String> morseCode = new HashMap<>();
        morseCode.put("a", ".-");
        morseCode.put("b", "-...");
        morseCode.put("c", "-.-.");
        morseCode.put("d", "-..");
        morseCode.put("e", ".");
        morseCode.put("f", "..-.");
        morseCode.put("g", "--.");
        morseCode.put("h", "....");
        morseCode.put("i", "..");
        morseCode.put("j", ".---");
        morseCode.put("k", "-.-");
        morseCode.put("l", ".-..");
        morseCode.put("m", "--");
        morseCode.put("n", "-.");
        morseCode.put("o", "---");
        morseCode.put("p", ".--.");
        morseCode.put("q", "--.-");
        morseCode.put("r", ".-.");
        morseCode.put("s", "...");
        morseCode.put("t", "-");
        morseCode.put("u", "..-");
        morseCode.put("v", "...-");
        morseCode.put("w", ".--");
        morseCode.put("x", "-..-");
        morseCode.put("y", "-.--");
        morseCode.put("z", "--..");

        System.out.println("Enter a word to convert to Morse code: ");
        String input = scanner.next();
        input = input.toLowerCase();
        for (int i = 0; i < input.length(); i++) {
            System.out.println(morseCode.get(input.substring(i, i + 1)));
        }   
    }
}