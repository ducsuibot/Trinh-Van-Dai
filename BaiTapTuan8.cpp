#include <iostream>

using namespace std;

// Cau truc cua hang tu trong da thuc
struct Node {
    int heSo;    // He so
    int soMu;    // So mu
    Node* next;  // Con tro duyet den so hang tiep theo
};

// Ham tao nut moi
Node* createNode(int heSo, int soMu) {
    Node* newNode = new Node;
    if (newNode == NULL) { // Kiem tra con tro newNode
        cerr << "Khong the cap phat bo nho!" << endl;
        exit(1); // Thoat neu khong cap phat
    }
    newNode->heSo = heSo;
    newNode->soMu = soMu;
    newNode->next = NULL; // Gan con tro tiep theo tai NULL
    return newNode;
}

// Ham them so hang vao da thuc
void themSoHang(Node** dau, int heSo, int soMu) {
    if (heSo == 0) {
        return; // Neu he so bang 0 thi khong them
    }

    Node* newNode = createNode(heSo, soMu);
    if (*dau == NULL) {
        *dau = newNode; // Neu danh sach rong thi gan len dau
    } else {
        Node* temp = *dau;
        Node* prev = NULL;

        // Duyet vi tri chen
        while (temp != NULL && temp->soMu > soMu) {
            prev = temp;
            temp = temp->next;
        }

        // Chen cho dung thu tu cho dep
        if (prev == NULL) { // Chen vao dau
            newNode->next = *dau;
            *dau = newNode;
        } else {
            newNode->next = temp;
            prev->next = newNode;
        }
    }
}

// Ham in da thuc
void inDaThuc(Node* dau) {
    if (dau == NULL) {
        cout << "Da thuc rong." << endl;
        return;
    }

    Node* temp = dau;
    while (temp != NULL) {
        cout << temp->heSo << "x^" << temp->soMu;
        if (temp->next != NULL) {
            cout << " + ";
        }
        temp = temp->next;
    }
    cout << endl;
}

// Giai phong bo nho
void giaiPhongBoNho(Node* dau) {
    Node* temp;
    while (dau != NULL) {
        temp = dau;
        dau = dau->next;
        delete temp;
    }
}

int main() {
    Node* dau = NULL; // Khoi tao danh sach rong

    int n;
    cout << "Nhap so luong so hang: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int heSo, soMu;
        cout << "Nhap he so thu " << i + 1 << ": ";
        cin >> heSo;
        cout << "Nhap so mu thu " << i + 1 << ": ";
        cin >> soMu;
        themSoHang(&dau, heSo, soMu); // Them neu he so khac 0
    }

    cout << "Da thuc vua nhap: ";
    inDaThuc(dau);

    // Giai phong bo nho
    giaiPhongBoNho(dau);

    return 0;
}

