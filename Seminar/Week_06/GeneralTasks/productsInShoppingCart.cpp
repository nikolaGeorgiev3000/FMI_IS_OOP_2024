#include <iostream>
#include <fstream>

const int MAX_PRODUCTS = 100;

class Product
{
private:
    char name[50];
    double price;
    int quantity;

public:
    Product() = default;

    Product(const char *_name, double _price, int _quantity) : price(_price), quantity(_quantity)
    {
        strncpy(name, _name, sizeof(name) - 1);
        name[sizeof(name) - 1] = '\0';
    }

    const char *getName() const
    {
        return name;
    }

    double getPrice() const
    {
        return price;
    }

    int getQuantity() const
    {
        return quantity;
    }

    void setQuantity(int _quantity)
    {
        quantity = _quantity;
    }
};

class ShoppingCart
{
private:
    Product products[MAX_PRODUCTS];
    int numProducts;

public:
    ShoppingCart() : numProducts(0) {}

    bool addProduct(const Product &product)
    {
        if (numProducts < MAX_PRODUCTS)
        {
            products[numProducts++] = product;
            return true;
        }
        return false;
    }

    bool removeProduct(const char *productName)
    {
        for (int i = 0; i < numProducts; ++i)
        {
            if (strcmp(products[i].getName(), productName) == 0)
            {
                // Shift elements to remove the product
                for (int j = i; j < numProducts - 1; ++j)
                {
                    products[j] = products[j + 1];
                }
                numProducts--;
                return true;
            }
        }
        return false;
    }

    int countProducts() const
    {
        return numProducts;
    }

    bool isEmpty() const
    {
        return numProducts == 0;
    }

    double getTotalPrice() const
    {
        double totalPrice = 0;
        for (int i = 0; i < numProducts; ++i)
        {
            totalPrice += products[i].getPrice() * products[i].getQuantity();
        }
        return totalPrice;
    }

    void sortByNames()
    {
        for (int i = 0; i < numProducts - 1; ++i)
        {
            for (int j = i + 1; j < numProducts; ++j)
            {
                if (strcmp(products[i].getName(), products[j].getName()) > 0)
                {
                    std::swap(products[i], products[j]);
                }
            }
        }
    }

    void sortByPrice()
    {
        for (int i = 0; i < numProducts - 1; ++i)
        {
            for (int j = i + 1; j < numProducts; ++j)
            {
                if (products[i].getPrice() > products[j].getPrice())
                {
                    std::swap(products[i], products[j]);
                }
            }
        }
    }

    void sortByQuantity()
    {
        for (int i = 0; i < numProducts - 1; ++i)
        {
            for (int j = i + 1; j < numProducts; ++j)
            {
                if (products[i].getQuantity() > products[j].getQuantity())
                {
                    std::swap(products[i], products[j]);
                }
            }
        }
    }

    void saveToFile(const char *filename) const
    {
        std::ofstream file(filename);
        if (!file)
        {
            std::cerr << "Error: Could not open file for writing\n";
            return;
        }

        for (int i = 0; i < numProducts; ++i)
        {
            file << "Name: " << products[i].getName() << ", Price: " << products[i].getPrice()
                 << ", Quantity: " << products[i].getQuantity() << std::endl;
        }

        file.close();
        std::cout << "Products saved to file successfully\n";
    }

    void readFromFile(const char *filename, ShoppingCart &cart)
    {
        std::ifstream file(filename);
        if (!file)
        {
            std::cerr << "Error: Could not open file for reading\n";
            return;
        }

        char line[100]; // Assuming each line in the file has a maximum length of 100 characters

        while (file.getline(line, sizeof(line)))
        {
            char name[50];
            double price;
            int quantity;

            // Parse the line to extract product information
            if (sscanf(line, "Name: %49[^,], Price: %lf, Quantity: %d", name, &price, &quantity) == 3)
            {
                // Create a Product object and add it to the shopping cart
                Product product(name, price, quantity);
                cart.addProduct(product);
            }
            else
            {
                std::cerr << "Error: Invalid data format in file\n";
            }
        }

        file.close();
        std::cout << "Products read from file successfully\n";
    }
};

int main()
{
    /* Test the classes here.*/

    return 0;
}
