#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <fstream>

using namespace std;

// самописный метод split
string* splitSpace(string str) {
    string ans[7];
    int idx = 0;
    
    string word;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] != ' ') {
            word += str[i];
        } else {
            ans[idx++] = word;
            word = "";
        }
    }
    return ans;
}

int id;

struct Goods {
private:
    int goodsID;
    string name;
    int weight = 0;
    int price = 0;
    int count = 0;
    string date;
    bool sale;

public:
    void setGoodsID(int id) {
        goodsID = id;
    }

    int getGoodsId() {
        return goodsID;
    }

    string getName()  {
        return name;
    }

    int getWeight() const {
        return weight;
    }

    int getPrice() const {
        return price;
    }

    int getCount() const {
        return count;
    }

    string getDate()  {
        return date;
    }

    bool isSale() const {
        return sale;
    }

    void setName(string parName) {
        bool okName = true;
        for (int i = 0; i < parName.length() && okName; i++) {
            if (!(parName[i] >= 97 && parName[i] <= 122)) {
                okName = false;
            }
        }
        if (okName)
            name = parName;
        else {
            cout << "INVALID VALUE ENTERED" << endl;
        }
    }

    void setWeight(string parWeight) {
        bool okWeight = parWeight[0] != '0';
        for (int i = 0; i < parWeight.length() && okWeight; i++) {
            if (!(parWeight[i] >= '0' && parWeight[i] <= '9')) {
                okWeight = false;
            }
        }
        if (okWeight)
            weight = stoi(parWeight);
        else {
            cout << "INVALID VALUE ENTERED" << endl;
        }
    }

    void setPrice(string parPrice) {
        bool okPrice = parPrice[0] != '0';
        for (int i =0; i < parPrice.length() && okPrice; i++) {
            if (!(parPrice[i] >= '0' && parPrice[i] <= '9')) {
                okPrice = false;
            }
        }
        if (okPrice)
            price = stoi(parPrice);
        else {
            cout << "INVALID VALUE ENTERED" << endl;
        }
        
    }

    void setCount(string parCount) {
        bool okCount = parCount[0] != '0';
        for (int i = 0; i < parCount.length() && okCount;  i++) {
            if (!(parCount[i] >= '0' && parCount[i] <= '9')) {
                okCount = false;
            }
        }
        if (okCount)
            count = stoi(parCount);
        else {
            cout << "INVALID VALUE ENTERED" << endl;
        }
    }

    void setDate(string parDate) {
        bool okDate = true;
        
        string arrDate[3];
        int idx = 0;
        
        string word;
        for (int i = 0; i < parDate.length() && okDate; i++) {
            if (parDate[i] != '.' && parDate[i] >= '0' && parDate[i] <= '9') {
                word += parDate[i];
            } else if (parDate[i] == '.') {
                arrDate[idx++] = word;
                word = "";
            } else {
                okDate = false;
            }
        }
    
        
        if (okDate) {
            int day = stoi(arrDate[0]);
            int month = stoi(arrDate[1]);
            if (!(day >= 1 && day <= 31 && month >= 1 && month <= 12)) {
                okDate = false;
            }
        }
        
        if (okDate) {
            date = parDate;
        } else {
            cout << "INVALID VALUE ENTERED" << endl;
        }
    }

    void setSale(string parSale) {
        if (parSale == "Yes") {
            sale = true;
        } else if (parSale == "No") {
            sale = false;
        } else {
            sale = false;
            cout << "INVALID VALUE ENTERED" << endl;
        }
    }


};

Goods goods[100];
vector<int> deleteGoods;

void addSystem();
void deleteFromSystem();
void showAll();
void saveToFile();
void loadFromFile();

int main() {
    cout << "1. Add System" << endl;
    cout << "2. Delete of the System" << endl;
    cout << "3. Show All" << endl;
    cout << "4. Save to File" << endl;
    cout << "5. Load from File" << endl;
    // endl;
    cout << endl;
    
    
    string choice;
    while (true) {
        cout << "Enter number: ";
        cin >> choice;
        cout << endl;
        if (choice == "1") {
            addSystem();
        } else if (choice == "2") {
            deleteFromSystem();
        } else if (choice == "3") {
            showAll();
        } else if (choice == "4") {
            saveToFile();
        } else if (choice == "5") {
            loadFromFile();
        } else {
            break;
        }
    }
}


void addSystem() {
    Goods good;
    good.setGoodsID(id);
    // name
    string name;
    while (good.getName() == "") {
        cout << "Input Name: ";
        cin >> name;
        good.setName(name);
    }
    //count
    string count;
    while (good.getCount() == 0) {
        cout << "Input Count: ";
        cin >> count;
        good.setCount(count);
    }
    // date;
    string date;
    while (good.getDate() == "") {
        cout << "Input Date: ";
        cin >> date;
        good.setDate(date);
    }
    // price
    string price;
    while (good.getPrice() == 0) {
        cout << "Input Price: ";
        cin >> price;
        good.setPrice(price);
    }
    // sale
    string sale;
    cout << "Input Sale (Yes or No): ";
    cin >> sale;
    good.setSale(sale);
    // weight
    string weight;
    while (good.getWeight() == 0) {
        cout << "Input Weight: ";
        cin >> weight;
        good.setWeight(weight);
    }

    goods[id++] = good;
    // success
    cout << "Operation was successfully completed" << endl;
    cout << endl;
}

void deleteFromSystem() {
    int delID = 101;
    
    while (delID >= id) {
        cout << "Input ID: ";
        cin >> delID;
        if (delID < id) {
            deleteGoods.push_back(delID);
        } 
    }
    // success
    cout << "Operation was successfully completed" << endl;
    cout << endl;
}

void showAll() {
    cout << "Show Array" << endl;
    for (int i = 0; i <id; ++i) {
        bool okID = true;
        for (int j = 0; j < deleteGoods.size() && okID; ++j) {
            if (deleteGoods[j] == i) okID = false;
        }
        if (okID) {
            cout << "Goods {" <<
                 "goodsID=" << goods[i].getGoodsId() <<
                 ", name='" << goods[i].getName() << '\'' <<
                 ", weight=" << goods[i].getWeight() <<
                 ", price=" << goods[i].getPrice() <<
                 ", count=" << goods[i].getCount() <<
                 ", date=" << goods[i].getDate() <<
                 ", sale=" << goods[i].isSale() <<
                 '}' << endl;
        }
    }
    // success
    cout << "Operation was successfully completed" << endl;
    cout << endl;
}

void saveToFile() {
    ofstream fout;
    fout.open("goods.txt");
    for (int i = 0; i < id; ++i) {
        bool okID = true;
        for (int j = 0; j < deleteGoods.size() && okID; ++j) {
            if (deleteGoods[j] == i) okID = false;
        }
        if (okID) {
            fout << goods[i].getGoodsId() <<
                 " " << goods[i].getName() << '\'' <<
                 " " << goods[i].getWeight() <<
                 " " << goods[i].getPrice() <<
                 " " << goods[i].getCount() <<
                 " " << goods[i].getDate() <<
                 " " << goods[i].isSale() <<
                 '}' << endl;
        }
    }
    fout.close();
    
    // success
    cout << "Operation was successfully completed" << endl;
    cout << endl;
}

void loadFromFile() {
    ifstream fin;
    fin.open("goods.txt");
    while (!fin.eof()) {
        string str;
        getline(fin, str);
        string* strArr = splitSpace(str);
        
        // new Goods
        Goods item;
        item.setGoodsID(stoi(strArr[0]));
        item.setName(strArr[1]);
        item.setWeight(strArr[2]);
        item.setPrice(strArr[3]);
        item.setCount(strArr[4]);
        item.setDate(strArr[5]);
        item.setSale(strArr[6]);
        // add to arrar
        goods[id++] = item;
    }
    fin.close();
    
    // success
    cout << "Operation was successfully completed" << endl;
    cout << endl;
}
