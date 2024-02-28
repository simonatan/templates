import java.util.Arrays;

public class MergeSort {

    public static int[] mergeSort(int[] list) {
        int n = list.length;
        if (n <= 1) return list;

        int[] left = mergeSort(Arrays.copyOfRange(list, 0, n / 2));
        int[] right = mergeSort(Arrays.copyOfRange(list, n / 2, n));

        return merge(left, right);
    }

    private static int[] merge(int[] list1, int[] list2) {
        int n1 = list1.length, n2 = list2.length;
        int n = n1 + n2;
        int i1 = 0, i2 = 0;
        int[] list = new int[n];

        for(int i = 0; i < n; i++) {
            if (i1 == n1) {
                list[i] = list2[i2++];
            } else if (i2 == n2) {
                list[i] = list1[i1++];
            } else {
                if (list1[i1] < list2[i2]) {
                    list[i] = list1[i1++];
                } else {
                    list[i]  = list2[i2++];
                }
            }
        }
        return list;
    }
}
