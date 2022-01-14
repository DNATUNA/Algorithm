import java.io.*;

public class Main {

    static double[] list;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        list = new double[n];

        for(int i=0; i<n; ++i) {
            list[i] = Double.parseDouble(br.readLine());
        }

        double answer = getMaxSubSet();
        if(answer == 1.0) answer= getMaxElement();

        System.out.printf("%.3f", answer);
    }

    public static double getMaxSubSet() {
        double max = 1, tmp = 1;
        for(int i=0; i<list.length; ++i) {
            tmp *= list[i];
            if(tmp < 1) {
                tmp = 1;
            } else {
                max = Math.max(max, tmp);
            }
        }

        return max;
    }

    public static double getMaxElement() {
        double max = 0;
        for(int i=0; i<list.length; ++i) {
            max = Math.max(max, list[i]);
        }

        return max;
    }
}
