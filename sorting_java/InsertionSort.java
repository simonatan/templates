public class InsertionSort {
    public static void sort(int[] list) {
        insertionSort(list);
    }

    private static void insertionSort(int[] list) {
        for(int i = 1; i < list.length; i++) {
            int cur_el = list[i], j;
            for(j = i - 1; j >= 0 && list[j] > cur_el; j--) {
                list[j + 1] = list[j];
            }
            list[j + 1] = cur_el;
        }
    }
}
