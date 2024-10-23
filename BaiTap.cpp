#include <iostream>
using namespace std;

struct Data_Birth {
    int year;
    int birthCount;
};

void Find_Year_Max_Min(Data_Birth data[], int size) {
    int maxBirth = 0;
    int minBirth = INT_MAX;
	int count = 0;
   
    for (int i = 0; i < size; i++){
    	for (int j = i + 1; j < size; j++){
    		if (data[i].birthCount == data[j].birthCount) 
			count += 1;
		}
	}
	cout << "Co " << count << " nam co so luong nguoi sinh bang nhau.";
	cout << endl;
	
	for (int i = 0; i < size; i++) {
        if (data[i].birthCount > maxBirth) {
            maxBirth = data[i].birthCount;
        } // Tim nam co so luong nguoi sinh ra nhieu nhat
        if (data[i].birthCount < minBirth) {
            minBirth = data[i].birthCount;
        }
    }

    cout << "Nam co so luong nguoi sinh ra lon nhat (" << maxBirth << "): ";
    for (int i = 0; i < size; i++) {
        if (data[i].birthCount == maxBirth) {
            cout << data[i].year << " ";
        }
    }
    cout << endl;

    cout << "Nam co so luong nguoi sinh ra be nhat (" << minBirth << "): ";
    for (int i = 0; i < size; i++) {
        if (data[i].birthCount == minBirth) {
            cout << data[i].year << " ";
        }
    }
    cout << endl;
}

int main() {
    int n;

    cout << "Nhap so luong nam: ";
    cin >> n;

    Data_Birth* data = new Data_Birth[n];

    for (int i = 0; i < n; i++) {
        cout << "Nhap nam va so nguoi sinh ra (nam so): ";
        cin >> data[i].year >> data[i].birthCount;
    }

    Find_Year_Max_Min(data, n);

    delete[] data;
    return 0;
}

