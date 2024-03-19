#include <iostream>

const short MAX_LENGTH = 21;

struct Vegetable {
    char nameVeg[MAX_LENGTH];
    double weightVeg;

    void inputVegetable() {
        std::cout << "Veggie name: ";
        std::cin.getline(this->nameVeg, MAX_LENGTH);

        std::cout << "Veggie weight: ";
        std::cin >> this->weightVeg;
        std::cin.ignore(); // Clear the '\n' from the input buffer
    }
};

struct Dressing {
    char nameDrs[MAX_LENGTH];
    double quantity;
    char allergenName[MAX_LENGTH];

    void inputDressing() {
        std::cout << "Dressing name: ";
        std::cin.getline(this->nameDrs, MAX_LENGTH);

        std::cout << "Dressing quantity: ";
        std::cin >> this->quantity;
        std::cin.ignore();

        std::cout << "Allergen name: ";
        std::cin.getline(this->allergenName, MAX_LENGTH);
    }
};

struct Salad {
    char nameSalad[MAX_LENGTH];
    Vegetable veggies[3];
    Dressing saladDressing;
    double saladPrice;

    void inputSalad() {
        std::cout << "Salad name: ";
        std::cin.getline(this->nameSalad, MAX_LENGTH);

        for (int i = 0; i < 3; ++i) {
            this->veggies[i].inputVegetable();
        }

        std::cout << "Salad dressing: \n";
        this->saladDressing.inputDressing();

        std::cout << "Salad price: ";
        std::cin >> this->saladPrice;
        std::cin.ignore();
    }

    double getWeight() const {
        double resultWeight = 0.0;

        for (int i = 0; i < 3; ++i) {
            resultWeight += this->veggies[i].weightVeg;
        }

        return resultWeight;
    }

    void printAllergen() const {
        std::cout << this->saladDressing.allergenName;
    }

    void printSalad() const {
        std::cout << this->nameSalad << std::endl << std::endl;

        std::cout << "Contents: ";
        for (int i = 0; i < 3; ++i) {
            std::cout << this->veggies[i].nameVeg << ", ";
        }

        std::cout << this->saladDressing.nameDrs << std::endl;

        std::cout << "Price: " << this->saladPrice << std::endl;

        std::cout << "Weight: " << this->getWeight() << std::endl;

        std::cout << "Allergen: ";
        this->printAllergen();
    }
};

void analyseSalads(Salad salads[], int n) {
    std::cout << "Salads: ";
    for (int i = 0; i < n; ++i) {
        std::cout << salads[i].nameSalad;
        if (i == n - 1) break; // Avoid last comma
        std::cout << ", ";
    }

    double totalSaladCost = 0.0;

    for (int i = 0; i < n; ++i) {
        totalSaladCost += salads[i].saladPrice;
    }
    std::cout << "\nTotal cost: " << totalSaladCost << std::endl;

    std::cout << "Allergens: ";
    for (int i = 0; i < n; ++i) {
        std::cout << salads[i].saladDressing.allergenName; // printAllergen()
        if (i == n - 1) {
            std::cout << std::endl;
            break; // Avoid last comma
        }
        std::cout << ", ";
    }
}

int main() {
    Salad salad1 = {};
    salad1.inputSalad();
    std::cout << std::endl;
    salad1.printSalad();


    Salad salad_arr[5];
    for (int i = 0; i < 5; i++)
        salad_arr[i].inputSalad();

    analyseSalads(salad_arr, 5);

    return 0;
}