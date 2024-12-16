#include <algorithm>
#include <iostream>
#include <vector>
#include <string>


using namespace std;

class Item {
public:
    Item(const string& name, const string& category, int quantity, double price)
        : name(name), category(category), quantity(quantity), price(price) {}

    string getName() const { return name; }
    string getCategory() const { return category; }
    int getQuantity() const { return quantity; }
    double getPrice() const { return price; }

    void setQuantity(int newQuantity) { quantity = newQuantity; }

    void display() const {
       cout << "Назва: " << name << ", Категорія: " << category
                  << ", Кількість: " << quantity << ", Ціна: " << price << " грн" << endl;
    }

private:
    string name;
    string category;
    int quantity;
    double price;
};

class Inventory {
public:
    void addItem(const Item& item) {
        items.push_back(item);
    }

    void updateQuantity(const string& name, int newQuantity) {
        for (auto& item : items) {
            if (item.getName() == name) {
                item.setQuantity(newQuantity);
                cout << "Оновлена кількість товару "<<name<< " на : " << newQuantity << endl;
                return;
            }
        }
        cout << "Товар не знайдено!" << endl;
    }

    void listItemsByCategory(const string& category) const {
        cout << "Товари в категорії "" << category << "":" << endl;
        for (const auto& item : items) {
            if (category == item.getCategory()) {
                item.display();
            }
        }
    }

    void showItemsBelowThreshold(int threshold) const {
        cout << "Товари з кількістю менше ніж " << threshold << ":" << endl;
        for (const auto& item : items) {
            if (item.getQuantity() < threshold) {
                item.display();
            }
        }
    }

    double totalInventoryValue() const {
        double totalValue = 0.0;
        for (const auto& item : items) {
            totalValue += item.getPrice() * item.getQuantity();
        }
        return totalValue;
    }

    void removeItemByName(const string& name) {
        cout << "Товари без видаленого: " <<endl;
        for (auto& item : items) {
            if (name == item.getName()) {
                items.erase(items.begin(), items.end());
                cout << "Товар " << name << " видалено." << endl;
                return;
            }
            item.display();
        }
    }

    void sortItemsByPrice() {
        // Сортуємо товари від більшого до найменьшого
        sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
            return a.getPrice() > b.getPrice();
        });
        cout << "Відсортовані товари: (від більшого за ціною до меньшого):" <<endl;
        for (const auto& item : items) {
            item.display();
        }
    }

private:
    vector<Item> items; // Вектор для зберігання товарів
};

int main() {
    Inventory inventory; // Створення єкземпляру
    system("chcp 65001");

    // Додавання товарів
    inventory.addItem(Item("Chocolate", "products", 6, 45.0));
    inventory.addItem(Item("Notebook Acer", "electrical engineering", 1, 25000.0));
    inventory.addItem(Item("Carrot", "products", 10, 14.0));

    cout<<endl;

    // Приклад оновлення кількості товару "шоколадка"
    inventory.updateQuantity("Chocolate", 20);


    cout<<endl;

    // Приклад виведення товарів за назвою категорії
    inventory.listItemsByCategory("products");

    cout<<endl;

    // Показати товари з кількістю менше ніж 5
    inventory.showItemsBelowThreshold(5);

    cout<<endl;

    // Порахувати загальну вартість усього інвентара
    cout << "Загальна вартість інвентара: " << inventory.totalInventoryValue() << " грн" << endl;

    cout<<endl;

    // Сортування від більшого за ціною до меньшого
    inventory.sortItemsByPrice();

    cout<<endl;

    // Видалити товар за назвою
    inventory.removeItemByName("Carrot");


}
