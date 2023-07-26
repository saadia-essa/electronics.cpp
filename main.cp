// SimplePOSTerminal.cpp - saadia essa

#include <iomanip>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <float.h>

using namespace std;

class laptops {
    // Public placeholder class. Used only for easy access to the arrays bellow.
    public:
        // Variable used to calculate sub total after each purchase
        double subTotal = 0;
        // Array representation for Breads category
        string laptopsStrings[6] = {"ci3", "ci5", "ci7"};
        // Units per product
        string laptopstypes[6] = {"Dell", "hp", "lenovo", "macpro", "chromebook", "Lb"};
        // Price per product
        double laptopsPrices[6] = {5.23 ,2.58, 3.87, 1.89, 3.63, 5.75};
        // Array in which we record how many sales we have per product.
        double laptopsSales[6] = { 0 };
        // Array representation for Fruits category
        string wIndowss[7] = { "XP", "WINDOWS 95", "WINDOWS 7", "WINDOWS 8", "WINDOWS10", "WINDOWS 11", "WINDOWS 2000" };
        // Units per product
        string cpus[7] = {"intel atom", "intel core 2 duo", "pentium D", "I386", "CORE2", "CORE I5", "CORE I9"};
        // Price per product
        double otherelectronidprices[7] = {2.43, 1.98, 4.57, 2.01, 9.89, 6.33, 0.59};
        // Array in which we record how many sales we have per product.
        double fruitSales[7] = { 0 };
        // Array representation for Grocery category
        string keyboards[9] = {"Packet biscuits", "Chocolates", "Rice", "Pasta", "Oil", "Packet fish", "Toilet cleaner", "Toilet tissue", "Air freshener"};
        // Units per product
        string keyboardnames[9] = {"Pc", "Pc", "Kg", "Kg", "L", "Lb" , "Pc", "Pc", "Pc"};
        // Price per product
        double keyboardprices[9] = {2.65, 1.84, 3.33, 2.89, 4.55, 12.78, 2.5, 6.54, 1.88};
        // Array in which we record how many sales we have per product.
        double keyboardsales[9] = { 0 };
        // Array representation for Vegetables category
        string ipads[9] = {"Spinach", "Zucchini", "Potatoes", "Onions", "Garlic", "Cilantro", "Broccoli", "Cauliflower", "Cucumber"};
        // Units per product
        string ipadstypes[9] = {"Kg", "Kg", "Kg", "Kg", "Kg", "Kg", "Kg", "Pc", "Kg"};
        // Price per product
        double ipadprices[9] = {1.21, 1.85, 0.98, 1.01, 3.22, 0.99, 5.8, 3.74, 2.87};
        // Array in which we record how many sales we have per product.
        double ipadsales[9] = { 0 };
};


double select_products(double total, string product[], double price[], string units[], double sales[], int size) {
    // Gets 3 arrays for product name, product price and product units. Then prints a menu and calculates the subTotal of the purchase. Also records what products were purchased.
    int choice = 99999;
    double subTotal = total;
    double amount = 0;
    // Loop until user select 0. for exit
    while (choice != 0) {
        for (int i = 0; i < size; i++) {
            // Prints Product name     Product Price    Product Units
            cout << i + 1 << ". " << product[i] << "\t\t" << price[i] << "\t" << units[i] << endl;
        }
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        // Validates if the cin failed (user enter something different than int), if true then forces user to enter again and displays msg.
        while (std::cin.fail()) {
            std::cout << "Please enter a number!" << std::endl;
            std::cin.clear();
            std::cin.ignore(256, '\n');
            std::cin >> choice;
        }
        // If choice is in the limits we ask the user to enter amount of units for the selected product.
        if (choice > 0 && choice <= size) {
            cout << "Enter amount of " << units[choice - 1] << endl;
            cin >> amount;
            subTotal = subTotal + (amount * price[choice - 1]);
            sales[choice - 1] = sales[choice - 1] + amount;
        }
        else {
            cout << "The valid choices are 1 through " << size << "\nRun the program again and select one of those.\n";
        }
        cout << "current balance: " << subTotal << endl;
    }

    return subTotal;
}

int category_menu(laptops &laptopsObj) {
    // Based on selected menu option, calls for select_products function to calculate the subTotal.
    // Takes laptops object refrence as argument.
    int choice;
    const int laptops_CHOICE = 1, FRUITS_CHOICE = 2, GROVERY_CHOICE = 3, VEGETABLES_CHOICE = 4, EXIT_CHOICE = 0;
    cout << "**************************\n"
        << "**\tPOS Menu\t**\n"
        << "**************************\n\n"
        << "1. laptops\n"
        << "2. windows\n"
        << "3. cpus\n"
        << "4. Vegetables\n"
        << "0. Exit \n"
        << "Enter your choice: ";
    cin >> choice;
    switch (choice)
    {
    case laptops_CHOICE:
        // Calls select_products function that takes an laptops object and 3 arrays for a givem product category, then creates a menu from which the user can sellect what products to buy\
        // Once the user is done buying products the function returns the subTotal, while at the same time, records what products were purchased.
        laptopsObj.subTotal =+ select_products(laptopsObj.subTotal, laptopsObj.laptopsStrings, laptopsObj.laptopsPrices, laptopsObj.laptopstypes, laptopsObj.laptopsSales, 6);
        category_menu(laptopsObj);
        break;
    case FRUITS_CHOICE:
        laptopsObj.subTotal =+ select_products(laptopsObj.subTotal, laptopsObj.wIndowss, laptopsObj.otherelectronidprices, laptopsObj.cpus, laptopsObj.fruitSales,7);
        category_menu(laptopsObj);
        break;
    case GROVERY_CHOICE:
        laptopsObj.subTotal =+ select_products(laptopsObj.subTotal, laptopsObj.keyboards, laptopsObj.keyboardprices, laptopsObj.keyboardnames, laptopsObj.keyboardsales,9);
        category_menu(laptopsObj);
        break;
    case VEGETABLES_CHOICE:
        laptopsObj.subTotal =+ select_products(laptopsObj.subTotal, laptopsObj.ipads, laptopsObj.ipadprices, laptopsObj.ipadstypes, laptopsObj.ipadsales,9);
        category_menu(laptopsObj);
        break;
    case EXIT_CHOICE:
        break;
    default:
        cout << "The valid choices are 1 through 4 and 0 to Exit.\n Run the program again and select one of those.\n";
        category_menu(laptopsObj);
    }
    return 0;
}

int payment_menu(laptops &laptopsObj) {
    // Payment option. Checks if the subtotal is 0, else it loops until the customer pays in full.
    // Takes laptops object refrence as argument.
    double bill = laptopsObj.subTotal;
    if (laptopsObj.subTotal > 0)
    {
        //initialize payment variable
        double payment;
        // The user must pay the full bill before exiting from this menu.
        while (laptopsObj.subTotal > 0) {
            cout << "Your current bill is: " << laptopsObj.subTotal << endl;
            cout << "Please enter payment amount:";
            cin >> payment;
            while (std::cin.fail()) {
                std::cout << "Please enter a number!" << std::endl;
                std::cin.clear();
                std::cin.ignore(256, '\n');
                std::cin >> payment;
            }
            laptopsObj.subTotal = laptopsObj.subTotal - payment;
        }
        cout << "Thank you for you purchase!" << endl;
        // If the user pays more than his/hers bill, we calculate the change.
        if (laptopsObj.subTotal < 0) {
            cout << "Your change is: " << laptopsObj.subTotal * -1 << endl;
            laptopsObj.subTotal = 0;
        }
    }
    else
    {
        //save check if we try to pay without any bill accumulation.
        cout << "You have no sale overdue!" << endl;
    }

    return 0;
}

int customer_menu(laptops &laptopsObj) {
    // Customer menu. Gives options to display products or payment option.
    // Takes laptops object refrence as argument.
    int choice;
    const int SALE_CHOICE = 1, BUY_CHOICE = 2, EXIT_CHOICE = 0;
    cout << "**************************\n"
        << "**\tPOS Menu\t**\n"
        << "**************************\n\n"
        << "1. Sale\n"
        << "2. Pay\n"
        << "0. Exit\n"
        << "Enter your choice: ";
    cin >> choice;
    switch (choice)
    {
    case SALE_CHOICE:
        category_menu(laptopsObj);
        customer_menu(laptopsObj);
        break;
    case BUY_CHOICE:
        payment_menu(laptopsObj);
        customer_menu(laptopsObj);
        break;
    case EXIT_CHOICE:
        if (laptopsObj.subTotal > 0) {
            cout << "Please pay your bill before you exit." << endl;
            customer_menu(laptopsObj);
        }
        break;
    default:
        cout << "The valid choices are 1 through 2 and 0 to Exit\nRun the program again and select one of those.\n";
        customer_menu(laptopsObj);
    }
    return 0;
}

void total_sales_by_cat(laptops &laptopsObj) {
    // Prints total sales  by category
    cout << "\nlaptops Category: \n";
    // Loops through laptopsSales array and displays how many products were purchased and their units.
    for (int i = 0; i < sizeof(laptopsObj.laptopsSales) / sizeof(laptopsObj.laptopsSales[0]); i++) {
        if (laptopsObj.laptopsSales[i] > 0) {
            cout << i + 1 << ". " << laptopsObj.laptopsStrings[i] << " sold " << laptopsObj.laptopsSales[i] << " " << laptopsObj.laptopstypes[i] << endl;
        }
    }
    cout << "\nFruits Category: \n";
    // Loops through fruitSales array and displays how many products were purchased and their units.
    for (int i = 0; i < sizeof(laptopsObj.fruitSales)/ sizeof(laptopsObj.fruitSales[0]); i++) {
        if (laptopsObj.fruitSales[i] > 0) {
            cout << i + 1 << ". " << laptopsObj.wIndowss[i] << " sold " << laptopsObj.fruitSales[i] << " " << laptopsObj.cpus[i] << endl;
        }
    }
    cout << "\nGrocery Category: \n";
    // Loops through keyboardsales array and displays how many products were purchased and their units.
    for (int i = 0; i < sizeof(laptopsObj.keyboardsales)/ sizeof(laptopsObj.keyboardsales[0]); i++) {
        if (laptopsObj.keyboardsales[i] > 0) {
            cout << i + 1 << ". " << laptopsObj.keyboards[i] << " sold " << laptopsObj.keyboardsales[i] << " " << laptopsObj.keyboardnames[i] << endl;
        }
    }
    cout << "\nVegetables Category: \n";
    // Loops through ipadsales array and displays how many products were purchased and their units.
    for (int i = 0; i < sizeof(laptopsObj.ipadsales)/ sizeof(laptopsObj.ipadsales[0]); i++) {
        if (laptopsObj.ipadsales[i] > 0) {
            cout << i + 1 << ". " << laptopsObj.ipads[i] << " sold " << laptopsObj.ipadsales[i] << " " << laptopsObj.ipadstypes[i] << endl;
        }
    }
}

void highest_sold_by_cat(laptops &laptopsObj) {
    // Prints highest salesvolumeby category
    // We use vectors here because we are not sure how many items will have the highest sold volume. For example if we have two or more products with the same items sold, we must display both. We don't know how many items we will have.
    vector<int> highest_laptops_index;
    vector<int> highest_fruits_index;
    vector<int> highest_grocery_index;
    vector<int> highest_vegetables_index;

    // Place holder for highest volume sold for each category.
    double temp_laptops = 0;
    double temp_fruits = 0;
    double temp_grocery = 0;
    double temp_vagetables = 0;

    // Using *max_element we can extract the highest number in the array.
    temp_laptops = *max_element(laptopsObj.laptopsSales, (laptopsObj.laptopsSales + sizeof(laptopsObj.laptopsSales) / sizeof(laptopsObj.laptopsSales[0])));
    // Loop through laptopsSales and if we find the sales value to be equal to the max value  we record the index of the element. We can have more than one items.
    for (int i = 0; i < sizeof(laptopsObj.laptopsSales) / sizeof(laptopsObj.laptopsSales[0]); i++) {
        if (laptopsObj.laptopsSales[i] == temp_laptops && temp_laptops!=0) {
            // Add the index of the item with the highest sales in the vector bellow.
            highest_laptops_index.push_back(i);
        }
    }
    // Using *max_element we can extract the highest number in the array.
    temp_fruits = *max_element(laptopsObj.fruitSales, (laptopsObj.fruitSales + sizeof(laptopsObj.fruitSales) / sizeof(laptopsObj.fruitSales[0])));
    // Loop through fruitSales and if we find the sales value to be equal to the max value  we record the index of the element. We can have more than one items.
    for (int i = 0; i < sizeof(laptopsObj.fruitSales) / sizeof(laptopsObj.fruitSales[0]); i++) {
        if (laptopsObj.fruitSales[i]  == temp_fruits && temp_fruits !=0) {
            // Add the index of the item with the highest sales in the vector bellow.
            highest_fruits_index.push_back(i);
        }
    }
    // Using *max_element we can extract the highest number in the array.
    temp_grocery = *max_element(laptopsObj.keyboardsales, (laptopsObj.keyboardsales + sizeof(laptopsObj.keyboardsales) / sizeof(laptopsObj.keyboardsales[0])));
    // Loop through keyboardsales and if we find the sales value to be equal to the max value  we record the index of the element. We can have more than one items.
    for (int i = 0; i < sizeof(laptopsObj.keyboardsales) / sizeof(laptopsObj.keyboardsales[0]); i++) {
        if (laptopsObj.keyboardsales[i] == temp_grocery && temp_grocery!=0) {
            // Add the index of the item with the highest sales in the vector bellow.
            highest_grocery_index.push_back(i);
        }
    }
    // Using *max_element we can extract the highest number in the array.
    temp_vagetables = *max_element(laptopsObj.ipadsales, (laptopsObj.ipadsales + sizeof(laptopsObj.ipadsales) / sizeof(laptopsObj.ipadsales[0])));
    // Loop through ipadsales and if we find the sales value to be equal to the max value  we record the index of the element. We can have more than one items.
    for (int i = 0; i < sizeof(laptopsObj.ipadsales) / sizeof(laptopsObj.ipadsales[0]); i++) {
        if (laptopsObj.ipadsales[i] == temp_vagetables && temp_vagetables !=0) {
            // Add the index of the item with the highest sales in the vector bellow.
            highest_vegetables_index.push_back(i);
        }
    }

    //Loops through the vector of indexes and prints all items that have the highest sells per category.
    if (!highest_laptops_index.empty()) {
        cout << "\nlaptops Category, highest sold item(s): \n";
        for (int i : highest_laptops_index) {
            cout << i + 1 << ". " << laptopsObj.laptopsStrings[i] << " sold " << laptopsObj.laptopsSales[i] << " " << laptopsObj.laptopstypes[i] << " for $" << laptopsObj.laptopsSales[i] * laptopsObj.laptopsPrices[i] << endl;
        }
            
    }
    //Loops through the vector of indexes and prints all items that have the highest sells per category.
    if (!highest_fruits_index.empty()) {
        cout << "\nFruits Category, highest sold item(s): \n";
        for (int i : highest_fruits_index) {
            cout << i + 1 << ". " << laptopsObj.wIndowss[i] << " sold " << laptopsObj.fruitSales[i] << " " << laptopsObj.cpus[i] << " for $" << laptopsObj.fruitSales[i] * laptopsObj.otherelectronidprices[i] << endl;
        }
    }
    //Loops through the vector of indexes and prints all items that have the highest sells per category.
    if (!highest_grocery_index.empty()) {
        cout << "\nGrocery Category, highest sold item(s): \n";
        for (int i : highest_grocery_index) {
            cout << i + 1 << ". " << laptopsObj.keyboards[i] << " sold " << laptopsObj.keyboardsales[i] << " " << laptopsObj.keyboardnames[i] << " for $" << laptopsObj.keyboardsales[i] * laptopsObj.keyboardprices[i] << endl;
        }
    }
    //Loops through the vector of indexes and prints all items that have the highest sells per category.
    if (!highest_vegetables_index.empty()) {
        cout << "\nVegetables Category, highest sold item(s): \n";
        for (int i : highest_vegetables_index) {
            cout << i + 1 << ". " << laptopsObj.ipads[i] << " sold " << laptopsObj.ipadsales[i] << " " << laptopsObj.ipadstypes[i] << " for $" << laptopsObj.ipadsales[i] * laptopsObj.ipadprices[i] << endl;
        }
    }
}

void highest_volume_sold_by_cat(laptops &laptopsObj) {
    // Prints highest sales volume by category
    // We use vectors here because we are not sure how many items will have the highest volume. For example if we have two or more products with the same items sold, we must display both. We don't know how many items we will have.
    // Difference from the function above is that here we acutally care for the amount in $ and not only the items count. For example we might have 5 items sold but only for $5 and we can have 1 item sold for 6$. We must display the highest amount of money.
    vector<int> highest_volume_laptops_index;
    vector<int> highest_volume_fruits_index;
    vector<int> highest_volume_grocery_index;
    vector<int> highest_volume_vegetables_index;

    // Place holder for highest volume sold for each category.
    double temp_laptops = 0;
    double temp_fruits = 0;
    double temp_grocery = 0;
    double temp_vagetables = 0;
    // Loop through laptopsSales and we look for the highest amount payed for an item.
    for (int i = 0; i < sizeof(laptopsObj.laptopsSales) / sizeof(laptopsObj.laptopsSales[0]); i++) {
        if (laptopsObj.laptopsSales[i] * laptopsObj.laptopsPrices[i] > temp_laptops) {
            temp_laptops = laptopsObj.laptopsSales[i] * laptopsObj.laptopsPrices[i];
        }
    }
    // Looping through laptopsSales looking for items that have same amount as the temp variable. Ten we add the index in a vector.
    for (int i = 0; i < sizeof(laptopsObj.laptopsSales) / sizeof(laptopsObj.laptopsSales[0]); i++) {
        if ((laptopsObj.laptopsSales[i] * laptopsObj.laptopsPrices[i] == temp_laptops) && temp_laptops!=0) {
            highest_volume_laptops_index.push_back(i);
        }
    }
    // Loop through fruitSales and we look for the highest amount payed for an item.
    for (int i = 0; i < sizeof(laptopsObj.fruitSales) / sizeof(laptopsObj.fruitSales[0]); i++) {
        if (laptopsObj.fruitSales[i] * laptopsObj .otherelectronidprices[i] > temp_fruits) {
            temp_fruits = laptopsObj.fruitSales[i] * laptopsObj.otherelectronidprices[i];
        }
    }
    // Looping through fruitSales looking for items that have same amount as the temp variable. Ten we add the index in a vector.
    for (int i = 0; i < sizeof(laptopsObj.fruitSales) / sizeof(laptopsObj.fruitSales[0]); i++) {
        if ((laptopsObj.fruitSales[i] * laptopsObj.otherelectronidprices[i] == temp_fruits) && temp_fruits != 0) {
            highest_volume_fruits_index.push_back(i);
        }
    }
    // Loop through keyboardsales and we look for the highest amount payed for an item.
    for (int i = 0; i < sizeof(laptopsObj.keyboardsales) / sizeof(laptopsObj.keyboardsales[0]); i++) {
        if (laptopsObj.keyboardsales[i] * laptopsObj.keyboardprices[i] > temp_grocery) {
            temp_grocery = laptopsObj.keyboardsales[i] * laptopsObj.keyboardprices[i];
        }
    }
    // Looping through keyboardsales looking for items that have same amount as the temp variable. Ten we add the index in a vector.
    for (int i = 0; i < sizeof(laptopsObj.keyboardsales) / sizeof(laptopsObj.keyboardsales[0]); i++) {
        if ((laptopsObj.keyboardsales[i] * laptopsObj.keyboardprices[i] == temp_grocery) && temp_grocery != 0) {
            highest_volume_grocery_index.push_back(i);
        }
    }
    // Loop through ipadsales and we look for the highest amount payed for an item.
    for (int i = 0; i < sizeof(laptopsObj.ipadsales) / sizeof(laptopsObj.ipadsales[0]); i++) {
        if (laptopsObj.ipadsales[i] * laptopsObj.ipadprices[i] > temp_vagetables) {
            temp_vagetables = laptopsObj.ipadsales[i] * laptopsObj.ipadprices[i];
        }
    }
    // Looping through ipadsales looking for items that have same amount as the temp variable. Ten we add the index in a vector.
    for (int i = 0; i < sizeof(laptopsObj.ipadsales) / sizeof(laptopsObj.ipadsales[0]); i++) {
        if ((laptopsObj.ipadsales[i] * laptopsObj.ipadprices[i] == temp_vagetables) && temp_vagetables != 0) {
            highest_volume_vegetables_index.push_back(i);
        }
    }
    //Loops through the vector of indexes and prints all items that have the highest volume sold per category.
    if (!highest_volume_laptops_index.empty()) {
        cout << "\nlaptops Category, highest volume sold item(s): \n";
        for (int i : highest_volume_laptops_index) {
            cout << i + 1 << ". " << laptopsObj.laptopsStrings[i] << " sold " << laptopsObj.laptopsSales[i] << " " << laptopsObj.laptopstypes[i] << " for $" << laptopsObj.laptopsSales[i] * laptopsObj.laptopsPrices[i] << endl;
        }

    }
    //Loops through the vector of indexes and prints all items that have the highest volume sold per category.
    if (!highest_volume_fruits_index.empty()) {
        cout << "\nFruits Category, highest volume sold item(s): \n";
        for (int i : highest_volume_fruits_index) {
            cout << i + 1 << ". " << laptopsObj.wIndowss[i] << " sold " << laptopsObj.fruitSales[i] << " " << laptopsObj.cpus[i] << " for $" << laptopsObj.fruitSales[i] * laptopsObj.otherelectronidprices[i] << endl;
        }
    }
    //Loops through the vector of indexes and prints all items that have the highest volume sold per category.
    if (!highest_volume_grocery_index.empty()) {
        cout << "\nGrocery Category, highest volume sold item(s): \n";
        for (int i : highest_volume_grocery_index) {
            cout << i + 1 << ". " << laptopsObj.keyboards[i] << " sold " << laptopsObj.keyboardsales[i] << " " << laptopsObj.keyboardnames[i] << " for $" << laptopsObj.keyboardsales[i] * laptopsObj.keyboardprices[i] << endl;
        }
    }
    //Loops through the vector of indexes and prints all items that have the highest volume sold per category.
    if (!highest_volume_vegetables_index.empty()) {
        cout << "\nVegetables Category, highest volume sold item(s): \n";
        for (int i : highest_volume_vegetables_index) {
            cout << i + 1 << ". " << laptopsObj.ipads[i] << " sold " << laptopsObj.ipadsales[i] << " " << laptopsObj.ipadstypes[i] << " for $" << laptopsObj.ipadsales[i] * laptopsObj.ipadprices[i] << endl;
        }
    }
}

void lowest_volume_sold_by_cat(laptops &laptopsObj) {
    // Prints lowest sales volume by category
    // We use vectors here because we are not sure how many items will have the lowest volume. For example if we have two or more products with the same items sold, we must display both. We don't know how many items we will have.
    vector<int> lowest_volume_laptops_index;
    vector<int> lowest_volume_fruits_index;
    vector<int> lowest_volume_grocery_index;
    vector<int> lowest_volume_vegetables_index;

    // Setting temp values to max double value in order to find the lowest count of an items sold.
    double temp_laptops = DBL_MAX;
    double temp_fruits = DBL_MAX;
    double temp_grocery = DBL_MAX;
    double temp_vagetables = DBL_MAX;

    // Looping through laptopsSales and looking for lowest amount payed for a product for a givem category. Then we assign it to the temp value.
    for (int i = 0; i < sizeof(laptopsObj.laptopsSales) / sizeof(laptopsObj.laptopsSales[0]); i++) {
        if ((laptopsObj.laptopsSales[i] * laptopsObj.laptopsPrices[i] < temp_laptops) && laptopsObj.laptopsSales[i] * laptopsObj.laptopsPrices[i] != 0) {
            temp_laptops = laptopsObj.laptopsSales[i] * laptopsObj.laptopsPrices[i];
        }
    }
    // Looping through laptopsSales looking for items that have the same amount of $ payed as the lowest amount payed. Then we add them to a vector.
    for (int i = 0; i < sizeof(laptopsObj.laptopsSales) / sizeof(laptopsObj.laptopsSales[0]); i++) {
        if ((laptopsObj.laptopsSales[i] * laptopsObj.laptopsPrices[i] == temp_laptops) && temp_laptops != 0) {
            lowest_volume_laptops_index.push_back(i);
        }
    }
    // Looping through fruitSales and looking for lowest amount payed for a product for a givem category. Then we assign it to the temp value.
    for (int i = 0; i < sizeof(laptopsObj.fruitSales) / sizeof(laptopsObj.fruitSales[0]); i++) {
        if ((laptopsObj.fruitSales[i] * laptopsObj.otherelectronidprices[i] < temp_fruits) && laptopsObj.fruitSales[i] * laptopsObj.otherelectronidprices[i] != 0) {
            temp_fruits = laptopsObj.fruitSales[i] * laptopsObj.otherelectronidprices[i];
        }
    }
    // Looping through fruitSales looking for items that have the same amount of $ payed as the lowest amount payed. Then we add them to a vector.
    for (int i = 0; i < sizeof(laptopsObj.fruitSales) / sizeof(laptopsObj.fruitSales[0]); i++) {
        if ((laptopsObj.fruitSales[i] * laptopsObj.otherelectronidprices[i] == temp_fruits) && temp_fruits != 0) {
            lowest_volume_fruits_index.push_back(i);
        }
    }
    // Looping through keyboardsales and looking for lowest amount payed for a product for a givem category. Then we assign it to the temp value.
    for (int i = 0; i < sizeof(laptopsObj.keyboardsales) / sizeof(laptopsObj.keyboardsales[0]); i++) {
        if ((laptopsObj.keyboardsales[i] * laptopsObj.keyboardprices[i] < temp_grocery) && laptopsObj.keyboardsales[i] * laptopsObj.keyboardprices[i] != 0) {
            temp_grocery = laptopsObj.keyboardsales[i] * laptopsObj.keyboardprices[i];
        }
    }
    // Looping through keyboardsales looking for items that have the same amount of $ payed as the lowest amount payed. Then we add them to a vector.
    for (int i = 0; i < sizeof(laptopsObj.keyboardsales) / sizeof(laptopsObj.keyboardsales[0]); i++) {
        if ((laptopsObj.keyboardsales[i] * laptopsObj.keyboardprices[i] == temp_grocery) && temp_grocery != 0) {
            lowest_volume_grocery_index.push_back(i);
        }
    }
    // Looping through ipadsales and looking for lowest amount payed for a product for a givem category. Then we assign it to the temp value.
    for (int i = 0; i < sizeof(laptopsObj.ipadsales) / sizeof(laptopsObj.ipadsales[0]); i++) {
        if ((laptopsObj.ipadsales[i] * laptopsObj.ipadprices[i] < temp_vagetables) && laptopsObj.ipadsales[i] * laptopsObj.ipadprices[i] != 0) {
            temp_vagetables = laptopsObj.ipadsales[i] * laptopsObj.ipadprices[i];
        }
    }
    // Looping through ipadsales looking for items that have the same amount of $ payed as the lowest amount payed. Then we add them to a vector.
    for (int i = 0; i < sizeof(laptopsObj.ipadsales) / sizeof(laptopsObj.ipadsales[0]); i++) {
        if ((laptopsObj.ipadsales[i] * laptopsObj.ipadprices[i] == temp_vagetables) && temp_vagetables != 0) {
            lowest_volume_vegetables_index.push_back(i);
        }
    }
    //Loops through the vector of indexes and prints all items that have the lowest volume sold per category.
    if (!lowest_volume_laptops_index.empty()) {
        cout << "\nlaptops Category, lowest volume sold item(s): \n";
        for (int i : lowest_volume_laptops_index) {
            cout << i + 1 << ". " << laptopsObj.laptopsStrings[i] << " sold " << laptopsObj.laptopsSales[i] << " " << laptopsObj.laptopstypes[i] << " for $" << laptopsObj.laptopsSales[i] * laptopsObj.laptopsPrices[i] << endl;
        }

    }
    //Loops through the vector of indexes and prints all items that have the lowest volume sold per category.
    if (!lowest_volume_fruits_index.empty()) {
        cout << "\nFruits Category, lowest volume sold item(s): \n";
        for (int i : lowest_volume_fruits_index) {
            cout << i + 1 << ". " << laptopsObj.wIndowss[i] << " sold " << laptopsObj.fruitSales[i] << " " << laptopsObj.cpus[i] << " for $" << laptopsObj.fruitSales[i] * laptopsObj.otherelectronidprices[i] << endl;
        }
    }
    //Loops through the vector of indexes and prints all items that have the lowest volume sold per category.
    if (!lowest_volume_grocery_index.empty()) {
        cout << "\nGrocery Category, lowest volume sold item(s): \n";
        for (int i : lowest_volume_grocery_index) {
            cout << i + 1 << ". " << laptopsObj.keyboards[i] << " sold " << laptopsObj.keyboardsales[i] << " " << laptopsObj.keyboardnames[i] << " for $" << laptopsObj.keyboardsales[i] * laptopsObj.keyboardprices[i] << endl;
        }
    }
    //Loops through the vector of indexes and prints all items that have the lowest volume sold per category.
    if (!lowest_volume_vegetables_index.empty()) {
        cout << "\nVegetables Category, lowest volume sold item(s): \n";
        for (int i : lowest_volume_vegetables_index) {
            cout << i + 1 << ". " << laptopsObj.ipads[i] << " sold " << laptopsObj.ipadsales[i] << " " << laptopsObj.ipadstypes[i] << " for $" << laptopsObj.ipadsales[i] * laptopsObj.ipadprices[i] << endl;
        }
    }
}

void lowest_sold_by_cat(laptops &laptopsObj) {
    // Prints lowest sales by category
    // We use vectors here because we are not sure how many items will have the lowest volume. For example if we have two or more products with the same items sold, we must display both. We don't know how many items we will have.
    vector<int> lowest_laptops_index;
    vector<int> lowest_fruits_index;
    vector<int> lowest_grocery_index;
    vector<int> lowest_vegetables_index;

    // Setting temp values to max double value in order to find the lowest count of an items sold.
    double temp_laptops = DBL_MAX;
    double temp_fruits = DBL_MAX;
    double temp_grocery = DBL_MAX;
    double temp_vagetables = DBL_MAX;

    // Looping through laptopsSales and looking for lowest selling  product for a givem category. Then we assign it to the temp value.
    for (int i = 0; i < sizeof(laptopsObj.laptopsSales) / sizeof(laptopsObj.laptopsSales[0]); i++) {
        if (laptopsObj.laptopsSales[i] <= temp_laptops && laptopsObj.laptopsSales[i] != 0) {
            temp_laptops = laptopsObj.laptopsSales[i];
        }
    }
    // Looping through laptopsSales looking for items that have the same amount items sold as the lowest amount of items sold. Then we add them to a vector.
    for (int i = 0; i < sizeof(laptopsObj.laptopsSales) / sizeof(laptopsObj.laptopsSales[0]); i++) {
        if (laptopsObj.laptopsSales[i] == temp_laptops && laptopsObj.laptopsSales[i] != 0) {
            lowest_laptops_index.push_back(i);
        }
    }
    // Looping through fruitSales and looking for lowest selling  product for a givem category. Then we assign it to the temp value.
    for (int i = 0; i < sizeof(laptopsObj.fruitSales) / sizeof(laptopsObj.fruitSales[0]); i++) {
        if (laptopsObj.fruitSales[i] <= temp_fruits && laptopsObj.fruitSales[i] != 0) {
            temp_fruits = laptopsObj.fruitSales[i];
        }
    }
    // Looping through fruitSales looking for items that have the same amount items sold as the lowest amount of items sold. Then we add them to a vector.
    for (int i = 0; i < sizeof(laptopsObj.fruitSales) / sizeof(laptopsObj.fruitSales[0]); i++) {
        if (laptopsObj.fruitSales[i] == temp_fruits && laptopsObj.fruitSales[i] != 0) {
            lowest_fruits_index.push_back(i);
        }
    }
    // Looping through keyboardsales and looking for lowest selling  product for a givem category. Then we assign it to the temp value.
    for (int i = 0; i < sizeof(laptopsObj.keyboardsales) / sizeof(laptopsObj.keyboardsales[0]); i++) {
        if (laptopsObj.keyboardsales[i] <= temp_grocery && laptopsObj.keyboardsales[i] != 0) {
            temp_grocery = laptopsObj.keyboardsales[i];
        }
    }
    // Looping through keyboardsales looking for items that have the same amount items sold as the lowest amount of items sold. Then we add them to a vector.
    for (int i = 0; i < sizeof(laptopsObj.keyboardsales) / sizeof(laptopsObj.keyboardsales[0]); i++) {
        if (laptopsObj.keyboardsales[i] == temp_grocery && laptopsObj.keyboardsales[i] != 0) {
            lowest_grocery_index.push_back(i);
        }
    }
    // Looping through ipadsales and looking for lowest selling  product for a givem category. Then we assign it to the temp value.
    for (int i = 0; i < sizeof(laptopsObj.ipadsales) / sizeof(laptopsObj.ipadsales[0]); i++) {
        if (laptopsObj.ipadsales[i] <= temp_vagetables && laptopsObj.ipadsales[i] != 0) {
            temp_vagetables = laptopsObj.ipadsales[i];
        }
    }
    // Looping through ipadsales looking for items that have the same amount items sold as the lowest amount of items sold. Then we add them to a vector.
    for (int i = 0; i < sizeof(laptopsObj.ipadsales) / sizeof(laptopsObj.ipadsales[0]); i++) {
        if (laptopsObj.ipadsales[i] == temp_vagetables && laptopsObj.ipadsales[i] != 0) {
            lowest_vegetables_index.push_back(i);
        }
    }
    
    //Loops through the vector of indexes and prints all items that have the lowest items sold per category.
    if (!lowest_laptops_index.empty()) {
        cout << "\nlaptops Category, lowest sold item(s): \n";
        for (int i : lowest_laptops_index) {
            cout << i + 1 << ". " << laptopsObj.laptopsStrings[i] << " sold " << laptopsObj.laptopsSales[i] << " " << laptopsObj.laptopstypes[i] << " for $" << laptopsObj.laptopsSales[i] * laptopsObj.laptopsPrices[i] << endl;
        }

        
    }
    //Loops through the vector of indexes and prints all items that have the lowest items sold per category.
    if (!lowest_fruits_index.empty()) {
        cout << "\nFruits Category, lowest sold item(s): \n";
        for (int i : lowest_fruits_index) {
            cout << i + 1 << ". " << laptopsObj.wIndowss[i] << " sold " << laptopsObj.fruitSales[i] << " " << laptopsObj.cpus[i] << " for $" << laptopsObj.fruitSales[i] * laptopsObj.otherelectronidprices[i] << endl;
        }
    }
    //Loops through the vector of indexes and prints all items that have the lowest items sold per category.
    if (!lowest_grocery_index.empty()) {
        cout << "\nGrocery Category, lowest sold item(s): \n";
        for (int i : lowest_grocery_index) {
            cout << i + 1 << ". " << laptopsObj.keyboards[i] << " sold " << laptopsObj.keyboardsales[i] << " " << laptopsObj.keyboardnames[i] << " for $" << laptopsObj.keyboardsales[i] * laptopsObj.keyboardprices[i] << endl;
        }
    }
    //Loops through the vector of indexes and prints all items that have the lowest items sold per category.
    if (!lowest_vegetables_index.empty()) {
        cout << "\nVegetables Category, lowest sold item(s): \n";
        for (int i : lowest_vegetables_index) {
            cout << i + 1 << ". " << laptopsObj.ipads[i] << " sold " << laptopsObj.ipadsales[i] << " " << laptopsObj.ipadstypes[i] << " for $" << laptopsObj.ipadsales[i] * laptopsObj.ipadprices[i] << endl;
        }
    }
}


int admin_menu(laptops &laptopsObj) {
    // Admin menu.
    int choice;
    const int TOTAL_CHOICE = 1, HIGHEST_CHOICE = 2, HIGHEST_SOLD_CHOICE = 3, LOWEST_CHOICE = 4, LOWEST_SOLD_CHOICE = 5, EXIT_CHOICE = 0;
    cout << "**************************\n"
        << "**\tPOS Menu\t**\n"
        << "**************************\n\n"
        << "1. Display total sales volume by category\n"
        << "2. Display name and units of highest sold item in each category\n"
        << "3. Display name and sales volume for highest sold item in each category\n"
        << "4. Display name and units of lowest sold item in each category\n"
        << "5. Display name and sales volume for lowest sold item in each category\n"
        << "0. Exit\n"
        << "Enter your choice: ";
    cin >> choice;
    switch (choice)
    {
    case TOTAL_CHOICE:
        total_sales_by_cat(laptopsObj);
        admin_menu(laptopsObj);
        break;
    case HIGHEST_CHOICE:
        highest_sold_by_cat(laptopsObj);
        admin_menu(laptopsObj);
        break;
    case HIGHEST_SOLD_CHOICE:
        highest_volume_sold_by_cat(laptopsObj);
        admin_menu(laptopsObj);
        break;
    case LOWEST_CHOICE:
        lowest_sold_by_cat(laptopsObj);
        admin_menu(laptopsObj);
        break;
    case LOWEST_SOLD_CHOICE:
        lowest_volume_sold_by_cat(laptopsObj);
        admin_menu(laptopsObj);
        break;
    case EXIT_CHOICE:
        break;
    default:
        cout << "The valid choices are 1 through 5 and 0 to Exit Run the\n" << "program again and select one of those.\n";
        admin_menu(laptopsObj);
    }
    return 0;
}

int initial_menu(laptops &laptopsObj) {
    // Initial menu or Main menu. Displays menu options and calls sub-menues if selected.
    // Takes laptops object refrence as argument.
    int choice;
    const int CUSTOMER_CHOICE = 1, ADMIN_CHOICE = 2, EXIT_CHOICE = 0;
    cout << "**************************\n"
        << "**\tPOS Menu\t**\n"
        << "**************************\n\n"
        << "1. Customer\n"
        << "2. Admin\n"
        << "0. Exit\n"
        << "Enter your choice: ";
    cin >> choice;
    switch (choice)
    {
        case CUSTOMER_CHOICE:
            customer_menu(laptopsObj);
            initial_menu(laptopsObj);
            break;
        case ADMIN_CHOICE:
            admin_menu(laptopsObj);
            initial_menu(laptopsObj);
            break;
        case EXIT_CHOICE:
            break;
        default:
            cout << "The valid choices are 1 through 2 and 0 to Exit. Run the\n" << "program again and select one of those.\n";
            initial_menu(laptopsObj);
    }
    return 0;
}

int main()
{
    // Initialize laptops object
    laptops laptopsObj;
    // Call initial menu.
    initial_menu(laptopsObj);
    return 0;
}

