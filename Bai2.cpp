#include <iostream>
#include <string>
using namespace std;

// Dinh nghia struct
struct WordNode {
    string word;       // Tu trong cau
    WordNode* next;    // Con tro node tiep theo

    WordNode(const string& w) {
        word = w;
        next = nullptr;
    }
};

// Ham chen dnah sach lien ket
void insertWord(WordNode*& head, const string& word) {
    WordNode* newNode = new WordNode(word);
    if (head == nullptr) {
        head = newNode;
    } else {
        WordNode* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Tim tu nhieu nhat trong cau
string findMostFrequentWord(WordNode* head) {
    WordNode* temp = head;
    int maxCount = 0;
    string mostFrequentWord;
    
    while (temp != nullptr) {
        int count = 0;
        WordNode* check = head;
        
        // Dem so lan xuat hien
        while (check != nullptr) {
            if (check->word == temp->word) {
                count++;
            }
            check = check->next;
        }
        
        // Check tu xuat hien nhieu nhat
        if (count > maxCount) {
            maxCount = count;
            mostFrequentWord = temp->word;
        }
        temp = temp->next;
    }
    
    return mostFrequentWord;
}

// Ham xoa tu
void removeDuplicateWords(WordNode*& head) {
    if (head == nullptr) {
        return;
    }
    
    WordNode* current = head;
    while (current != nullptr && current->next != nullptr) {
        if (current->word == current->next->word) {
            WordNode* temp = current->next;
            current->next = current->next->next;
            delete temp;
        } else {
            current = current->next;
        }
    }
}

// Ham dem tu
int countDistinctWords(WordNode* head) {
    int count = 0;
    WordNode* temp = head;
    
    while (temp != nullptr) {
        WordNode* check = head;
        bool isUnique = true;
        
        // Check var
        while (check != temp) {
            if (check->word == temp->word) {
                isUnique = false;
                break;
            }
            check = check->next;
        }
        
        // Neu chua thi ...
        if (isUnique) {
            count++;
        }
        
        temp = temp->next;
    }
    
    return count;
}

// Xuat cac tu
void printWords(WordNode* head) {
    WordNode* temp = head;
    while (temp != nullptr) {
        cout << temp->word << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    WordNode* head = nullptr;

    // Nhap vao de lam viec
    string sentence;
    cout << "Nh?p m?t câu: ";
    getline(cin, sentence);

    // Chia de tri
    string word;
    for (char c : sentence) {
        if (c == ' ') {
            if (!word.empty()) {
                insertWord(head, word);
                word.clear();
            }
        } else {
            word += c;
        }
    }
    if (!word.empty()) {
        insertWord(head, word);
    }

    // In luc moi tao
    cout << "Danh sach tu trong cau: ";
    printWords(head);

    // Tim tu xuaat hien nhieu nhat
    string mostFrequentWord = findMostFrequentWord(head);
    cout << "Tu xuat hien nhieu nhat: " << mostFrequentWord << endl;

    // Xu ly tu lay
    removeDuplicateWords(head);
    cout << "Danh sach tu sau khi loai tu lay: ";
    printWords(head);

    // Dem hahahaha
    int distinctWordCount = countDistinctWords(head);
    cout << "So tu vung co trong cau: " << distinctWordCount << endl;

    return 0;
}

