public class QuickSort {

    public static void sort(int[] list) {
        assert list != null;
        quickSort(list, 0, list.length - 1);
    }

    private static void quickSort(int[] list, int low, int high) {
        if (low < high) {
            int split_index = partition(list, low, high);
            quickSort(list, low, split_index);
            quickSort(list, split_index + 1, high);
        }
    }

    private static int partition(int[] ar, int lo, int hi) {
        int pivot = ar[lo];
        int i = lo - 1, j = hi + 1;
        while (true) {
            do {
                i++;
            } while (ar[i] < pivot);
            do {
                j--;
            } while (ar[j] > pivot);
            if (i < j) swap(ar, i, j);
            else return j;
        }
    }

    private static void swap(int[] list, int i, int j) {
        int temp = list[i];
        list[i] = list[j];
        list[j] = temp;
    }
}
