/*
	Chương trình minh họa thuật toán page replacement dựa trên nguyên lý FIFO
*/
#include <iostream>
#include <queue>
using namespace std;

#define PAGE_MAX 10000	// Số lượng page tối đa mà memory có thể lưu trữ cùng một thời điểm

void replacePage_Fifo(int frameSize, int pageNum, int pages[]);

int main()
{
	cout << "Page replacement algorithm - FIFO" << endl << endl;

	// Nhập số lượng page reference strings
	int pageNum;
	cout << "Enter the length of page reference strings: ";
	cin >> pageNum;

	// Nhập danh sách giá trị các page reference strings
	// Mỗi page reference strings cách nhau bằng một dấu space
	int pages[PAGE_MAX];
	cout << "Enter the list of page reference strings: ";
	for (int i = 0; i < pageNum; i++) {
		cin >> pages[i];
	}

	// Nhập kích thước frame mà memory hỗ trợ
	// Con số này có thể lớn hơn, bằng, hoặc nhỏ hơn số lượng page reference strings
	int frameSize;
	cout << "Enter the size of frames: ";
	cin >> frameSize;
	cout << endl;

	// Chạy thuật toán page replacement dựa trên FIFO
	replacePage_Fifo(frameSize, pageNum, pages);

	return 0;
}

void replacePage_Fifo(int frameSize, int pageNum, int pages[])
{
	bool doesExist[PAGE_MAX] = {false};	// Page có tồn tại sẵn trong memory hay không
	std::queue<int> Q;					// Hàng đợi lưu trữ tất cả page
	int pageFaults = 0;					// Số lượng page fault
	int oldestPage = 0;					// Page cũ nhất

	for (int i = 0; i < pageNum; i++) {
		// Nếu page đã tồn tại trong memory, không cần làm gì cả
		if (doesExist[pages[i]] == true) {
			cout << "[" << i << "] Page " << pages[i] << " exists in memory. No page fault!" << endl;
		}
		// Còn nếu không, thêm page vào queue
		else {
			cout << "[" << i << "] Page " << pages[i] << " does not exist in memory. Increase page fault by 1." << endl;
			Q.push(pages[i]);
			doesExist[pages[i]] = true;		// Đánh dấu page này đã tồn tại
			pageFaults++;					// Tăng số lượng page fault lên 1

			// Nếu kích thước queue vượt kích thước frame quy định,
			// thì xóa page cũ nhất khỏi queue
			if (Q.size() > frameSize) {
				oldestPage = Q.front();			// Tìm page cũ nhất (chính là page ở đầu của queue)
				Q.pop();						// Xóa page cũ nhất
				doesExist[oldestPage] = false;	// Đánh dấu page này không tồn tại nữa
				
				cout << "\tRemove the front page out of the queue: " << oldestPage << endl;
			}
		}
	}

	// In ra kết quả
	cout << endl;
	cout << "Frame size: " << frameSize << endl;
	cout << "Page faults: " << pageFaults << endl;
	cout << "Page hits: " << pageNum - pageFaults << endl;

	cout << "Final queue:";
	while (!Q.empty()) {
		cout << " " << Q.front();
		Q.pop();
	}
	cout << endl;

	return;
}