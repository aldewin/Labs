#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <fstream>

using namespace std;

// самописный метод split
string* split(string str, char splitSymbol) {
    string ans[7];
    int idx = 0;
    
    string word;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] != splitSymbol) {
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
    int weight;
    int price;
    int count;
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
            name = "";
            cout << "Invalid value entered" << endl;
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
            weight = 0;
            cout << "Invalid value entered" << endl;
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
            price = 0;
            cout << "Invalid value entered" << endl;
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
            count = 0;
            cout << "Invalid value entered" << endl;
        }
    }

    void setDate(string parDate) {
        bool okDate = true;
        string *arrDate = split(parDate, '.');
        if (sizeof(arrDate) < 3) {
            okDate = false;
        }
        for (int i = 0; i < sizeof(arrDate) && okDate; i++) {
            for (int j = 0; j < sizeof(arrDate[i]) && okDate; j++) {
                if (!(arrDate[i][0] >= '0' && arrDate[i][0] <= '3' && arrDate[i][1] >='0' && arrDate[i][1] <= '9')) {
                    okDate = false;
                }
            }
        }
        
        if (okDate) {
            date = parDate;
        } else {
            date = "00.00.00";
            cout << "Invalid value entered" << endl;
        }
            
        
        date = parDate;
    }

    void setSale(string parSale) {
        if (parSale == "Yes") {
            sale = true;
        } else if (parSale == "No") {
            sale = false;
        } else {
            sale = false;
            cout << "Invalid value entered" << endl;
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
    cout << "Input Name: ";
    string name;
    cin >> name;
    good.setName(name);
    //count
    cout << "Input Count: ";
    string count;
    cin >> count;
    good.setCount(count);
    // date;
    cout << "Input Date: ";
    string date;
    cin >> date;
    good.setDate(date);
    // price
    cout << "Input Price: ";
    string price;
    cin >> price;
    good.setPrice(price);
    // sale
    cout << "Input Sale (Yes or No): ";
    string sale;
    cin >> sale;
    good.setSale(sale);
    // weight
    cout << "Input Weight: ";
    string weight;
    cin >> weight;
    good.setWeight(weight);

    goods[id++] = good;
    cout << "Object add to the system" << endl;
}

void deleteFromSystem() {
    int delID;
    cout << "Input ID: ";
    cin >> delID;
    if (delID < id) {
        deleteGoods.push_back(delID);
    }
}

void showAll() {
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
}

void loadFromFile() {
    ifstream fin;
    fin.open("goods.txt");
    while (!fin.eof()) {
        string str;
        getline(fin, str);
        string* strArr = split(str, ' ');
        
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
}
