#include <bits/stdc++.h>

using namespace std;

struct Node{
    string items[10];  //Ten san pham
    double total_amount;  //Tong so tien thanh toan
    Node* next;           //Con tro next link toi node tiep theo
};

// Cau truc hang doi Queue
struct Queue {
    Node* front;  // Con tro phan tu dau tien trong hang doi
    Node* rear;   // Con tro phan tu cuoi cung trong hang doi

    Queue() {
        front = rear = NULL;  // Khoi tao hang doi rong
    }

    // Kiem tra hang doi co rong khong
    bool isEmpty() {
        return front == NULL;
    }

    // Them vao hang doi
    void enqueue(string items[], int item_count, double total_amount) {
        Node* new_node = new Node;
        for (int i = 0; i < item_count; i++) {
            new_node->items[i] = items[i];
        }
        new_node->total_amount = total_amount;
        new_node->next = NULL;
        
        if (rear == NULL) {
            front = rear = new_node;
        } else {
            rear->next = new_node;
            rear = new_node;
        }
    }

    // Loai bo nguoi dau tien trong hang doi khi thanh toan xong
    Node* dequeue() {
        if (isEmpty()) {
            cout << "Hang doi rong!" << endl;
            return NULL;
        }
        Node* removed_node = front;
        front = front->next;
        if (front == NULL) {
            rear = NULL;
        }
        return removed_node;
    }

    // Tinh tong so tien thu duoc
    double totalRevenue() {
        double total = 0;
        Node* current = front;
        while (current != NULL) {
            total += current->total_amount;
            current = current->next;
        }
        return total;
    }

    // Xac dinh so san pham A duoc ban
    int countProductA() {
        int count = 0;
        Node* current = front;
        while (current != NULL) {
            for (int i = 0; i < 10; i++) {
                if (current->items[i] == "A") {
                    count++;
                }
            }
            current = current->next;
        }
        return count;
    }
};

int main() {
    Queue queue;

    // Them cac gio hang vao hang doi
    string items1[] = {"A", "B", "C"};
    queue.enqueue(items1, 3, 100.0);  

    string items2[] = {"A", "A", "D"};
    queue.enqueue(items2, 3, 150.0);  

    string items3[] = {"B", "C"};
    queue.enqueue(items3, 2, 80.0);   

    // Tinh tong so tien thu duoc
    cout << "Tong tien thanh toan la: " << queue.totalRevenue() << endl;  

    // So san pham A da ban
    cout << "So san pham A da ban la: " << queue.countProductA() << endl;  

    // Xoa nguoi dau tien da thanh toan xong khoi hang doi
    Node* dequeued_person = queue.dequeue();
    if (dequeued_person) {
        cout << "Da thanh toan voi so tien la: " << dequeued_person->total_amount << endl;
        delete dequeued_person;  // Xoa
    }
	return 0;
}

