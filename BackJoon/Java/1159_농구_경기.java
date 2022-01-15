import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        Map<String, Integer> list = new HashMap<>();
        int count = Integer.parseInt(br.readLine());
        for(int i=0; i<count; ++i) {
            String firstName = String.valueOf(br.readLine().charAt(0));
            if(list.containsKey(firstName)) {
                list.put(firstName, list.get(firstName) + 1);
            }
            else list.put(firstName, 1);
        }

        String answer = list.entrySet().stream()
                .filter(data -> data.getValue() >= 5)
                .map(data -> data.getKey())
                .collect(Collectors.toList()).stream().sorted()
                .collect(Collectors.joining());

        if(Objects.equals(answer, "")) System.out.println("PREDAJA");
        else System.out.println(answer);
    }
}
