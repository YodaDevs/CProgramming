int binary_search(int *v, int size, int element){
    
    int begin = 0;
    int end = size - 1;
    int middle;
    while (begin <= end) {
            middle = (begin + end) / 2;
        if (v[middle] < element) {
            begin = middle + 1;
        } else if (v[middle] > element) {
            end = middle - 1;
        } else {
            return middle;
        }
    }
    return -1;
}
