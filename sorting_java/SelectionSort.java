public class SelectionSort {
    public static void selectionSort(int[] list) {
        for(int i = 0; i < list.length - 1; i++) {
            int cur_min = list[i], cur_min_ind = i;
            for(int j = i + 1; j < list.length; j++) {
                if (cur_min > list[j]) {
                    cur_min = list[j];
                    cur_min_ind = j;
                }
            }
            if (cur_min_ind != i) {
                list[cur_min_ind] = list[i];
                list[i] = cur_min;
            }
        }
    }
}
