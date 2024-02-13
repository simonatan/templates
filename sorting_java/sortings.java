public class Main {

    public static void main(String[] args) {
        int[] list = {2, 3, 1, 4, 10, 4, 1, 2};

//        bubbleSort(list);
        selectionSort(list);
//        insertionSort(list);
        print(list);

    }

    private static void print(int[] list) {
        for(int i = 0; i < list.length; i++) {
            System.out.print(list[i] + " ");
        }
    }

    private static void bubbleSort(int[] list) {
        for(int k = 0; k < list.length - 1; k++) {
            for(int i = 0; i < list.length - 1 - k; i++) {
                if (list[i] > list[i + 1]) {
                    int temp = list[i];
                    list[i] = list[i + 1];
                    list[i + 1] = temp;
                }
            }
        }
    }

    private static void selectionSort(int[] list) {
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
