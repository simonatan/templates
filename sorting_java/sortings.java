public class sortings {

    public static void main(String[] args) {
        int[] list = {2, 3, 1, 4, 10, 4, 1, 2};

//        BubbleSort.sort(list);
//        SelectionSort.sort(list);
//        InsertionSort.sort(list);
//        QuickSort.sort(list);
//        MergeSort.sort(list);
        HeapSort.sort(list);
        print(list);
    }

    private static void print(int[] list) {
        for(int i = 0; i < list.length; i++) {
            System.out.print(list[i] + " ");
        }
    }
}
