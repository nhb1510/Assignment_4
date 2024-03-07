#include <stdio.h>
#include <string.h>

enum ProductType 
{
    CLOTHING,
    FOOTWEAR,
    ELECTRONICS
};

union SizeWeight 
{
    int size;
    float weight;
};

struct Product {
    char name[50];
    float price;
    enum ProductType type;
    union SizeWeight sizeWeight;
};

int main() {
    int numProducts;
    printf("Enter the number of products: ");
    scanf("%d", &numProducts);

    struct Product products[numProducts];

    // Nhập thông tin cho từng sản phẩm
    for (int i = 0; i < numProducts; ++i) {
        printf("\nEnter information for product %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", products[i].name);
        printf("Price: ");
        scanf("%f", &products[i].price);
        printf("Type (0: Clothing, 1: Footwear, 2: Electronics): ");
        scanf("%d", (int *)&products[i].type);

        if (products[i].type == CLOTHING || products[i].type == FOOTWEAR) {
            printf("Size: ");
            scanf("%d", &products[i].sizeWeight.size);
        } else if (products[i].type == ELECTRONICS) {
            printf("Weight: ");
            scanf("%f", &products[i].sizeWeight.weight);
        }
    }

    // Tìm kiếm thông tin của một sản phẩm bằng tên
    char searchName[50];
    printf("\nEnter the name of the product to retrieve information: ");
    scanf("%s", searchName);

    // Duyệt qua mảng sản phẩm để tìm kiếm sản phẩm bằng tên
    int found = 0;
    for (int i = 0; i < numProducts; ++i) {
        if (strcmp(products[i].name, searchName) == 0) {
            printf("\nProduct Information:\n");
            printf("Name: %s\n", products[i].name);
            printf("Price: %.2f\n", products[i].price);
            printf("Type: %d\n", products[i].type);
            if (products[i].type == CLOTHING || products[i].type == FOOTWEAR) {
                printf("Size: %d\n", products[i].sizeWeight.size);
            } else if (products[i].type == ELECTRONICS) {
                printf("Weight: %.2f\n", products[i].sizeWeight.weight);
            }
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Product not found.\n");
    }

    return 0;
}
