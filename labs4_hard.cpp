#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

// самописный метод split
string* splitSpace(string str) {
    string *ans = new string[7];
    int idx = 0;
    
    string word;
    for (char i : str) {
            if (i != ' ') {
                word += i;
            } else {
                ans[idx++] = word;
                word = "";
            }
        }
    return ans;
}

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
    
        if (idx != 2) okDate = false;
        
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

// Dynamic List
class ArrayList {
public:
    ArrayList();
    ~ArrayList();
    
    void add(Goods element);
    int size();
    Goods get(int index);
    void popFront();
    void remove(int index);
    
private:
    class Node {
    public:
        Node *next;
        Goods val;

        Node(Goods val, Node *next = nullptr) {
            this->val = val;
            this->next = next;
        }
    };

    int sizeList;
    Node *head;
};

ArrayList::ArrayList() {
    sizeList = 0;
    head = nullptr;
}

ArrayList::~ArrayList() {
    while (sizeList > 0) {
        popFront();
        sizeList--;
    }
}

void ArrayList::add(Goods element) {
    if (head == nullptr) {
        head = new Node(element);

    } else {
        Node *curr = this->head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = new Node(element);
        
    }
    sizeList++;
}

int ArrayList::size() {
    return sizeList;
}

Goods ArrayList::get(int index) {
    int count = 0;
    Node *curr = this->head;
    while (count < index && curr != nullptr) {
        curr = curr->next;
        count++;
    }
    return curr->val;
}

void ArrayList::popFront() {
    Node *temp = head;
    head = head->next;
    delete temp;
    sizeList--;
}

void ArrayList::remove(int index) {
    if (index == 0) {
        popFront();
    } else {
        Node *prev = this->head;
        for (int i = 0; i < index - 1; i++) {
            prev = prev->next;
        }
        Node *delNode = prev->next;
        prev->next = delNode->next;
        delete delNode;
        sizeList--;
    }
}

// Begin Programm
ArrayList goods;
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


// 1
void addSystem() {
    Goods good;
    good.setGoodsID(goods.size());
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

    goods.add(good);
    // success
    cout << "Operation was successfully completed" << endl;
    cout << endl;
}

// 2
void deleteFromSystem() {
    int delID = goods.size();
    
    cout << "You can delete id under numbers: ";
    for (int i = 0; i < goods.size(); i++) {
        cout << goods.get(i).getGoodsId() << " ";
    }
    cout << endl;
    bool okID = false;
    while (!okID) {
        cout << "Input ID: ";
        cin >> delID;
        for (int i = 0; i < goods.size() && !okID; i++) {
            if (delID == goods.get(i).getGoodsId()) {
                goods.remove(i);
                okID = true;
            }
        }
        
    }
    // success
    cout << "Operation was successfully completed" << endl;
    cout << endl;
}

// 3
void showAll() {
    cout << "Show Array" << endl;
    if (goods.size() == 0) cout << "Oops, list is empty" << endl;
    for (int i = 0; i < goods.size(); ++i) {
            cout << "Goods {" <<
                 "goodsID=" << goods.get(i).getGoodsId() <<
                 ", name='" << goods.get(i).getName() << '\'' <<
                 ", weight=" << goods.get(i).getWeight() <<
                 ", price=" << goods.get(i).getPrice() <<
                 ", count=" << goods.get(i).getCount() <<
                 ", date=" << goods.get(i).getDate() <<
                 ", sale=" << goods.get(i).isSale() <<
                 '}' << endl;
    }
    // success
    cout << "Operation was successfully completed" << endl;
    cout << endl;
}

void saveToFile() {
    ofstream fout;
    fout.open("goods.txt");
    for (int i = 0; i < goods.size(); ++i) {
            fout << "Goods {" <<
            "goodsID=" << goods.get(i).getGoodsId() <<
            ", name='" << goods.get(i).getName() << '\'' <<
            ", weight=" << goods.get(i).getWeight() <<
            ", price=" << goods.get(i).getPrice() <<
            ", count=" << goods.get(i).getCount() <<
            ", date=" << goods.get(i).getDate() <<
            ", sale=" << goods.get(i).isSale() <<
            '}' << endl;
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
        goods.add(item);
    }
    fin.close();
    
    // success
    cout << "Operation was successfully completed" << endl;
    cout << endl;
}
