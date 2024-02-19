#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

struct item 
{
    int id;
    string name;
    double price;
    string category = "not working";
};

void bubbleSort(item items[], int n) 
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) 
    {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) 
        {
            if (items[j].id > items[j + 1].id) 
            {
                item temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

void bubbleSort2(item items[], int n) 
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) 
    {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) 
        {
            if (items[j].price > items[j + 1].price) 
            {
                item temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

void printItems(const item items[], int n) 
{
    for (int i = 0; i < n; i++) 
    {
        cout << items[i].id << "\t"
            << items[i].name << "\t\t"
            << items[i].price << "\t\t"
            << items[i].category << endl;
    }
}

void printItems2(const item items[], int n) 
{
    for (int i = 0; i < n; i++) 
    {
        cout << items[i].id << "\t"
            << items[i].name << "\t\t"
            << items[i].price << "\t\t"
            << items[i].category << endl;
    }
}

void removeItem(item items[], int& itemCount, int id) 
{
    int i;
    for (i = 0; i < itemCount; i++) 
    {
        if (items[i].id == id) 
        {
            cout << "Item at id " << id << " has been removed\n\n";
            break;
        }
    }
    if (i == itemCount) 
    { 
        cout << "Item with id " << id << " not found." << endl;
        return;
    }
    for (; i < itemCount - 1; i++) 
    {
        items[i] = items[i + 1];
    }
    itemCount--;
}

void addItem(item items[], int& itemCount, int id, const string& name, double price, const string& category) 
{
    if (itemCount >= 50) 
    { 
        cout << "Array is full. Cannot add more items." << endl;
        return;
    }
    item newItem;
    newItem.id = id;
    newItem.name = name;
    newItem.price = price;
    newItem.category = category;
    cout << "New Items called `Frying Pan` has been added.\n\n";

    items[itemCount++] = newItem;
}

int main() 
{
    string line;
    size_t pos = 0;
    int itemCount = 0;
    item Items[50];

    ifstream file("product_data.txt");
    if (file.is_open())
    {
        for (int i = 0; getline(file, line); i++) 
        {
            stringstream ss(line);
            string temp;
            int fieldIndex = 0;

            while (getline(ss, temp, ','))
            {
                if (fieldIndex != 0 && !temp.empty() && temp.front() == ' ')
                {
                    temp.erase(0, 1);
                }

                switch (fieldIndex) {
                case 0:
                    Items[i].id = stoi(temp);
                    break;
                case 1:
                    Items[i].name = temp;
                    break;
                case 2:
                    Items[i].price = stod(temp);
                    break;
                case 3:
                    Items[i].category = temp;
                    break;
                }
                fieldIndex++;
            }
            itemCount++;
        }
        file.close();
    }
    else
    {
        cout << "File is not open" << "\n";
    }

    removeItem(Items, itemCount, 10889);

    addItem(Items, itemCount, 11111, "Frying Pan", 10.99, "Home & Kitchen");

    bubbleSort(Items, itemCount);

    cout << "This is the sorted Items by the id of the Items:\n\n";
    printItems(Items, itemCount);
    cout << endl << endl;

    bubbleSort2(Items, itemCount);

    cout << "This is the sorted Items by the price of the Items:\n\n";
    printItems2(Items, itemCount);
    cout << endl << endl;

    string hi;
    cin >> hi;
    return 0;
}