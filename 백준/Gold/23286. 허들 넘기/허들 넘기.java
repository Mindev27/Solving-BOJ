import java.io.*;
import java.util.*;

public class Main {
   public static void main(String[] argv) {
      Scanner sc = new Scanner(System.in);

      int n=sc.nextInt();
      int m=sc.nextInt();
      int t=sc.nextInt();

      int[][] map = new int[n+1][n+1];
      int INF = (int)1e9;

      for(int i=1; i<=n; i++)   Arrays.fill(map[i],INF); //INF로 초기화

      for(int i=1; i<=n; i++) { //본인의 점은 0으로 만들기
         for(int j=1;j<=n; j++) {
            if(i==j) map[i][j]=0;
         }
      }

      for(int i=1; i<=m; i++) { //맵 만들기
         int a=sc.nextInt();
         int b=sc.nextInt();
         int c=sc.nextInt();

         map[a][b] = c;
      }


      for(int k=1; k<=n; k++) { //플로이드 워셜
         for(int a=1; a<=n; a++) {
            for(int b=1; b<=n; b++) {
               map[a][b] = Math.min(map[a][b], Math.max(map[a][k], map[k][b]));
            }
         }
      }


      for(int i=0; i<t; i++) {
         int a=sc.nextInt(); //시작
         int b=sc.nextInt(); //끝

         if(map[a][b]==INF) System.out.println(-1);
         else System.out.println(map[a][b]);
      }
   }
}