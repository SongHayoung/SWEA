package com.ssafy.algo;


import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;

public class test {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T, tc = 1, N;
        T= sc.nextInt();
        while(T--!=0) {
            N = sc.nextInt();
            final int target = sc.nextInt();
            List<Score> scores = new ArrayList<>();
            for(int i = 1; i <= N; ++i)
                scores.add(new Score(sc.nextInt()*35 + sc.nextInt()*45 + sc.nextInt()*20, i));
            System.out.print("#" + tc++ + " ");
            switch ((int)((double) scores.stream()
                    .sorted((a,b) -> a.compareTo(b))
                    .collect(Collectors.toList())
                    .indexOf(scores.stream()
                            .filter(score -> score.num == target)
                            .collect(Collectors.toList())
                            .get(0)) / N * 10)){
                case 0: System.out.println("A+"); break;
                case 1: System.out.println("A0"); break;
                case 2: System.out.println("A-"); break;
                case 3: System.out.println("B+"); break;
                case 4: System.out.println("B0"); break;
                case 5: System.out.println("B-"); break;
                case 6: System.out.println("C+"); break;
                case 7: System.out.println("C0"); break;
                case 8: System.out.println("C-"); break;
                case 9: System.out.println("D0"); break;
                default: break;
            }
        }

    }
    private static class Score implements Comparable<Score>{
        int score;
        int num;
        public Score(int score, int num) {
            this.score = score;
            this.num = num;
        }
        @Override
        public int compareTo(Score score) {
            return -Integer.compare(this.score, score.score);
        }
    }
}
