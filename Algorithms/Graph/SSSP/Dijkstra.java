package Algorithms.Graph.SSSP;
import java.util.*;

public class Dijkstra {
  class IntegerPair implements Comparable {
    Integer _first, _second;

    public IntegerPair(Integer f, Integer s) {
      _first = f;
      _second = s;
    }

    public int compareTo(Object o) {
      if (this.first() != ((IntegerPair)o).first())
        return this.first() - ((IntegerPair)o).first();
      else
        return this.second() - ((IntegerPair)o).second();
    }

    Integer first() { return _first; }
    Integer second() { return _second; }
  }

  public static final int INF = 1000000000;

  public static void main(String[] args) {

    Scanner sc = new Scanner(System.in);

    int n = sc.nextInt();
    int m = sc.nextInt();

    ArrayList<ArrayList<IntegerPair>> list = new ArrayList<>(n);
    for (int i = 0; i < m; i++) {
      int u = sc.nextInt();
      int v = sc.nextInt();
      int w = sc.nextInt();

      list.get(u).add(new IntegerPair(v, w));
    }

    for (int i = 0; i < list.size(); i++) {
      for (IntegerPair v : list.get(i)) {
        System.out.print(v.first() + " " + v.second());
      }
    }

    sc.close();
  }
}