/*
    Chương trình minh họa thuật toán page replacement dựa trên nguyên lý LFU
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

#define PAGE_MAX 10000  // Số lượng page tối đa mà memory có thể lưu trữ cùng một thời điểm

void replacePage_LFU(int frameSize, int pageNum, int pages[]);

int main()
{
    cout << "Page replacement algorithm - LFU" << endl << endl;

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

    // Chạy thuật toán page replacement dựa trên LFU
    replacePage_LFU(frameSize, pageNum, pages);

    return 0;
}

void replacePage_LFU(int frameSize, int pageNum, int pages[])
{
    bool doesExist[PAGE_MAX] = { false };   // Page có tồn tại sẵn trong memory hay không
    int pageFaults = 0;                     // Số lượng page fault

    vector<int> pageVec;                    // Vector lưu tất cả page
    unordered_map<int, int> pageFreqs;      // Map lưu page ứng với từng tần xuất của page

    for (int i = 0; i < pageNum; i++) {
        // Nếu page đã tồn tại trong memory, không cần làm gì cả
        if (doesExist[pages[i]] == true) {
            cout << "[" << i << "] Page " << pages[i] << " exists in memory. No page fault!" << endl;
            pageFreqs[pages[i]]++;          // Tăng tần xuất của page lên 1 đơn vị
        }
        // Còn nếu không, thêm page vào queue
        else {
            cout << "[" << i << "] Page " << pages[i] << " does not exist in memory. Increase page fault by 1." << endl;
            pageVec.push_back(pages[i]);
            pageFreqs[pages[i]]++;          // Tăng tần xuất của page lên 1 đơn vị
            doesExist[pages[i]] = true;     // Đánh dấu page này đã tồn tại
            pageFaults++;                   // Tăng số lượng page fault lên 1

            // Nếu kích thước queue vượt kích thước frame quy định,
            // thì xóa page ít được sử dụng nhất khỏi vector
            if (pageVec.size() > frameSize) {
                // Ban đầu, giả sử page đầu tiên trong vector có tần xuất ít nhất
                int leastFreqPage = pageFreqs.begin()->first;
                int leastFreq = pageFreqs.begin()->second;

                // Tìm kiếm chính xác page có tần xuất ít nhất
                for (auto& it : pageFreqs) {
                    // Nếu tìm được page có tần xuất ít hơn page đang có tần xuất ít nhất hiện tại, thì page đó trở thành page có tần xuất ít nhất
                    if (it.second < leastFreq) {
                        leastFreqPage = it.first;
                        leastFreq = it.second;
                    }
                }

                // Xóa page có tần suất ít nhất khỏi vector
                pageVec.erase(std::remove(pageVec.begin(), pageVec.end(), leastFreqPage), pageVec.end());
                // Đừng quên xóa page này khỏi map
                pageFreqs.erase(leastFreqPage);
                // Cuối cùng đánh dấu page này không tồn tại nữa
                doesExist[leastFreqPage] = false;

                cout << "\tRemove the least frequently-used page: " << leastFreqPage << endl;
            }
        }
    }

    // In ra kết quả
    cout << endl;
    cout << "Frame size: " << frameSize << endl;
    cout << "Page faults: " << pageFaults << endl;
    cout << "Page hits: " << pageNum - pageFaults << endl;

    cout << "Final list of reference strings:";
    for (int i = 0; i < pageVec.size(); ++i) {
        cout << " " << pageVec[i];
    }
    cout << endl;

    return;
}
