package BFS;
import java.util.*;

class main {
  static class pair {
    int first, second;

    public pair(int first, int second) {
      this.first = first;
      this.second = second;
    }
  }

  static ArrayList<Integer> dirx = new ArrayList<>(Arrays.asList(1, -1, 0, 0));
  static ArrayList<Integer> diry = new ArrayList<>(Arrays.asList(0, 0, 1, -1));

  static void bfs(Integer x, Integer y, ArrayList<ArrayList<Integer>> list,
                  boolean[][] visit, Integer col, Integer lin) {
    ArrayDeque<pair> q = new ArrayDeque<>();

    q.add(new pair(x, y));
    visit[x][y] = true;

    while (!q.isEmpty()) {
      pair crt = q.peek();
      q.remove();

      for (int i = 0; i < 4; i++) {
        int xx = dirx.get(i) + crt.first;
        int yy = diry.get(i) + crt.second;

        if (xx >= 0 && yy >= 0 && xx < lin && yy < col && !visit[xx][yy] &&
            list.get(xx).get(yy) == 0) {
          q.add(new pair(xx, yy));
          visit[xx][yy] = true;
        }
      }
    }
  }

  public static void main(String[] args) {
    Scanner scan = new Scanner(System.in);

    Integer lin = scan.nextInt();
    Integer col = scan.nextInt();

    ArrayList<ArrayList<Integer>> list = new ArrayList<ArrayList<Integer>>();

    boolean[][] visit = new boolean[lin][col];
    for (int i = 0; i < lin; i++) {
      ArrayList<Integer> innerList = new ArrayList<>();

      for (int j = 0; j < col; j++) {
        Integer x = scan.nextInt();
        innerList.add(x);
      }
      list.add(innerList);
    }

    Integer x = 1;
    Integer y = 1;

    bfs(x, y, list, visit, col, lin);

    scan.close();
  }
}
