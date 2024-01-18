import java.util.*;

import java.io.*;

class Node {

   int x;

   int y;

   int z;

   int c;

   Node(int x, int y, int z, int c) {

      this.x = x;

      this.y = y;

      this.z = z;

      this.c = c;

   }

}

public class Main {

   public static int[] dx = {0, 1, 0, -1, 0, 0};

   public static int[] dy = {-1, 0, 1, 0, 0, 0};

   public static int[] dz = {0, 0, 0, 0, 1, -1};

   public static int l, r, c, ans;

   public static char[][][] map;

   public static boolean[][][] visit;

   public static Queue<Node> q = new LinkedList<>();

   public static void main(String[] args) {

      Scanner sc = new Scanner(System.in);

      while(true) {

         l = sc.nextInt();

         r = sc.nextInt();

         c = sc.nextInt();

         if(l == 0 && r == 0 && c == 0) break;

         map = new char[l][r][c];

         visit = new boolean[l][r][c];

         q.clear();

         ans = 0;

         sc.nextLine(); // 빈 줄 처리

         for(int i = 0; i < l; i++) {

            for(int j = 0; j < r; j++) {

               String s = sc.nextLine();

               for(int z = 0; z < c; z++) {

                  map[i][j][z] = s.charAt(z);

                  if(map[i][j][z] == 'S') {

                     q.add(new Node(i, j, z, 0));

                     visit[i][j][z] = true;

                  }

               }

            }

            if(i < l - 1) sc.nextLine(); // 레벨 사이의 빈 줄 처리

         }

         bfs();

         if(ans != 0) System.out.println("Escaped in " + ans + " minute(s).");

         else System.out.println("Trapped!");

      }

      sc.close();

   }

   public static void bfs() {

      while(!q.isEmpty()) {

         Node tmp = q.poll();

         if(map[tmp.x][tmp.y][tmp.z] == 'E') {

            ans = tmp.c;

            return;

         }

         for(int z = 0; z < 6; z++) {

            int nl = tmp.x + dx[z];

            int nr = tmp.y + dy[z];

            int nc = tmp.z + dz[z];

            if(nl >= 0 && nr >= 0 && nc >= 0 && nl < l && nr < r && nc < c && !visit[nl][nr][nc] && map[nl][nr][nc] != '#') {

               q.add(new Node(nl, nr, nc, tmp.c + 1));

               visit[nl][nr][nc] = true;

            }

         }

      }

   }

}

