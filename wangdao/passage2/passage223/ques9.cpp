typedef int ElemType;
void SearchExchangeInsert(ElemType A[], ElemType x, int n) {
    int low = 0, high = n - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if(A[mid] == x) break;
        else if(A[mid] < x) low = mid + 1;
        else high = mid - 1;
    }
    if(A[mid] == x && mid != n + 1) {
        ElemType temp = A[mid];
        A[mid] = A[mid + 1];
        A[mid + 1] = temp;
    }
    if(low > high) {
        for (int i = n - 1; i > high; i--) A[i + 1] = A[i];
        A[high + 1] = x;
    }
}