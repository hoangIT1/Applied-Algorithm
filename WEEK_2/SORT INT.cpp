/* 
  QUICK SORT IMPLEMENT
*/

#include <iostream>
using namespace std;
 
long long a[1000001];
long long n;
void Partition(long long A[], int left, int right)
{
    // Kiểm tra xem nếu mảng có 1 phần tử thì không cần sắp xếp
    if (left >= right)
        return;
 
    int pivot = A[(left + right) / 2]; // Chọn phần tử chính giữa dãy làm chốt
 
    // i là vị trí đầu và j là cuối đoạn
    int i = left, j = right;
    while (i < j)
    {
        while (A[i] < pivot) // Nếu phần tử bên trái nhỏ hơn pivot thì ok, bỏ qua
            i++;
        while (A[j] > pivot) // Nếu phần tử bên phải nhỏ hơn pivot thì ok, bỏ qua
            j--;
        if (i <= j)
        {
            if (i < j) // nếu i != j (tức không trùng thì mới cần hoán đổi)
                swap(A[i], A[j]); // Thực hiện đổi chổ ta được A[i] < pivot và A[j] > pivot
            i++;
            j--;
        }
    }
 
    Partition(A, left, j);
    Partition(A, i, right);
}
 
// Hàm sắp xếp chính
void QuickSort(long long A[], int n)
{
    Partition(A, 0, n - 1);
}
int main() {
	cin>>n;
	for (int i = 0;i<n;i++) {
		cin>>a[i];
	}
	QuickSort(a,n);
	for (int i = 0;i<n;i++) {
		cout<<a[i]<<" ";
	}
}
