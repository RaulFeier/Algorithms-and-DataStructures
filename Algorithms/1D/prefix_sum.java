import java.util.*;

class prefix{
    public static void main(){
        int arr[] = {0, 1, 6, 11, 9, 7, 5, 20};
        int n = arr.length;
        int pref[] = new int [n];

        pref[0] = arr[0];
        for(int i = 1; i < n; i++){
            pref[i] = pref[i - 1] + arr[i];
        }

        for(int i = 0; i < n; i++){
            System.out.print(pref[i] + " ");
        }
    }
}