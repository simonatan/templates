public class sortings {

    public static void main(String[] args) {
        int[] list = {2, 3, 1, 4, 10, 4, 1, 2};

//        BubbleSort.bubbleSort(list);
//        SelectionSort.selectionSort(list);
//        InsertionSort.insertionSort(list);
        QuickSort.quickSort(list, 0, list.length - 1);
        print(list);

    }

    private static void print(int[] list) {
        for(int i = 0; i < list.length; i++) {
            System.out.print(list[i] + " ");
        }
    }
}
