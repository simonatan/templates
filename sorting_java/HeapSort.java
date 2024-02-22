public class HeapSort{
    public static void sort(int[] list) {
        heapSort(list);
    }

    private static void heapSort(int[] list) {
        assert list != null;
        for(int i = Math.max(0, list.length / 2 - 1); i >= 0; i--) {
            sink(list, list.length, i);
        }

        for(int i = list.length - 1; i >= 0; i--) {
            swap(list, 0, i);
            sink(list, i, 0);
        }
    }

    private static void sink(int[] list, int n, int i) {
        while (true) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int largest = i;

            if (right < n && list[right] > list[largest]) {
                largest = right;
            }
            if (left < n && list[left] > list[largest]) {
                largest = left;
            }

            if (largest != i) {
                swap(list, largest, i);
                i = largest;
            } else {
                break;
            }
        }
    }

    private static void swap(int[] list, int i, int j) {
        int temp = list[i];
        list[i] = list[j];
        list[j] = temp;
    }
}

