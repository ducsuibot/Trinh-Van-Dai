#include <iostream>
#include <string>

using namespace std;

// Dinh nghia File
struct FileNode {
    string fileName;    
    long fileSize;      
    long fileTime;      
    FileNode* next;     

    // Khoi tao node
    FileNode(const string& fName, long fSize, long fTime) {
        fileName = fName;
        fileSize = fSize;
        fileTime = fTime;
        next = NULL;  
    }
};

// Chen file theo thoi gian
void insertFile(FileNode*& head, const string& fileName, long fileSize, long fileTime) {
    FileNode* newNode = new FileNode(fileName, fileSize, fileTime);
    // Neu danh sach rong hoac file moi 
    if (head == NULL || fileTime > head->fileTime) {
        newNode->next = head;
        head = newNode;
        return;
    }

    // Tim vi tri tot
    FileNode* current = head;
    while (current->next != NULL && current->next->fileTime > fileTime) {
        current = current->next;
    }

    // CHen vao cho tot moi tim
    newNode->next = current->next;
    current->next = newNode;
}

// Tinh tong kich thuoc file
long calculateTotalSize(FileNode* head) {
    long totalSize = 0;
    FileNode* current = head;
    while (current != NULL) {
        totalSize += current->fileSize;
        current = current->next;
    }
    return totalSize;
}

// Xoa file khong can 
void removeFilesToFitSize(FileNode*& head, long maxSize) {
    long currentSize = calculateTotalSize(head);
    // Ngon thi khong can xoa
    if (currentSize <= maxSize) {
        cout << "No need to remove files." << endl;
        return;
    }

    // Nang qua thi xoa bot cho nhe
    while (currentSize > maxSize && head != NULL) {
        FileNode* temp = head;
        head = head->next;
        currentSize -= temp->fileSize;
        delete temp;
    }

    cout << "Files removed to fit the size." << endl;
}

// ham xuat binh thuong
void printFiles(FileNode* head) {
    FileNode* current = head;
    while (current != NULL) {
        cout << "File Name: " << current->fileName
             << " | Size: " << current->fileSize << " bytes"
             << " | Time (seconds since epoch): " << current->fileTime << endl;
        current = current->next;
    }
}

int main() {
    FileNode* head = NULL;  

    // Tao thoi gian dau
    long currentTime = 0; // CHon bua thoi gian bat dau la 0

    // Them vai cai file
    insertFile(head, "File1.txt", 500000, currentTime); 
    currentTime += 1; 
    insertFile(head, "File2.txt", 1000000, currentTime); 
    currentTime += 1; 
    insertFile(head, "File3.txt", 2000000, currentTime); 

    // Xuat file
    cout << "Danh sách các file:\n";
    printFiles(head);

    // Tinh kich thuoc file
    long totalSize = calculateTotalSize(head);
    cout << "\nTong kich thuoc cac file: " << totalSize << " bytes" << endl;

    // Dinh nghia 32GB la gi
    long usbSizeLimit = 32 * 1024 * 1024 * 1024;

    // Xoa may dua nho nho
    removeFilesToFitSize(head, usbSizeLimit);

    // Thong bao xoa ai
    cout << "\nDanh sach file bi xoa la:\n";
    printFiles(head);

    return 0;
}

