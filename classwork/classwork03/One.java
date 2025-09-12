import java.util.Scanner;
import java.util.Map;
import java.util.HashMap;

public class One {
    private static Scanner scanner = new Scanner(System.in);
    public static void main(String[] args) {

        Map<String, String> converter = new HashMap<>();
        converter.put("a", "alfa");
        converter.put("b", "bravo");
        converter.put("c", "charlie");
        converter.put("d", "delta");
        converter.put("e", "echo");
        converter.put("f", "foxtrot");
        converter.put("g", "golf");
        converter.put("h", "hotel");
        converter.put("i", "india");
        converter.put("j", "juliett");
        converter.put("k", "kilo");
        converter.put("l", "lima");
        converter.put("m", "mike");
        converter.put("n", "november");
        converter.put("o", "oscar");
        converter.put("p", "papa");
        converter.put("q", "quebec");
        converter.put("r", "romeo");
        converter.put("s", "sierra");
        converter.put("t", "tango");
        converter.put("u", "uniform");
        converter.put("v", "victor");
        converter.put("w", "whiskey");
        converter.put("x", "xray");
        converter.put("y", "yankee");
        converter.put("z", "zulu");
        System.out.println("Enter a word to convert to NATO alphabet: ");
        String input = scanner.next();
        input = input.toLowerCase();
        for (int i = 0; i < input.length(); i++) {
            if (input.charAt(i) == ' ') {
                continue;
            }
            System.out.println(converter.get(input.substring(i, i + 1)));
        }
    }
}