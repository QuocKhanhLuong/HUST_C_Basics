/*Mô tả bài toán:

Bạn được yêu cầu viết một chương trình C để quản lý thông tin về các sản phẩm trong một cửa hàng, sử dụng cấu trúc dữ liệu cây nhị phân tìm kiếm (Binary Search Tree - BST). Mỗi nút trong cây sẽ chứa thông tin của một sản phẩm.

Cấu trúc dữ liệu Cây nhị phân:

#define MAX_NAME_LENGTH 50

typedef struct ProductNode {
    int id;                   // Mã sản phẩm (duy nhất)
    char name[MAX_NAME_LENGTH]; // Tên sản phẩm
    float price;               // Giá sản phẩm
    struct ProductNode* left;
    struct ProductNode* right;
} ProductNode;
Use code with caution.
C
Yêu cầu chức năng:

Chương trình của bạn cần hỗ trợ các thao tác sau, mỗi thao tác tương ứng với một hàm:

CreateNode(int id, char name[], float price): Tạo một nút mới (sản phẩm) với thông tin id, name, price. Khởi tạo left và right thành NULL. Trả về con trỏ đến nút vừa tạo. (1 điểm)

Test case 1: Gọi CreateNode(101, "Product A", 25.0). Kiểm tra rằng node mới được tạo có id là 101, name là "Product A", price là 25.0 và left và right là NULL.

Insert(ProductNode root, ProductNode new_node):** Thêm một sản phẩm new_node vào cây BST. Cây được sắp xếp theo id của sản phẩm. Nếu id của sản phẩm mới nhỏ hơn root, thêm vào bên trái; lớn hơn, thêm vào bên phải. Nếu cây rỗng, trả về new_node. (1.5 điểm)

Test case 1: root = NULL; Insert(root, CreateNode(105, "Product B", 30.0)); Kiểm tra root là node vừa insert.

Test case 2: Sử dụng kết quả test case 1, Insert(root, CreateNode(102, "Product C", 20.0)); Insert(root, CreateNode(108, "Product D", 40.0)); Kiểm tra cây có cấu trúc BST đúng.

Search(ProductNode root, int id):* Tìm kiếm sản phẩm với mã sản phẩm id trong cây BST. Trả về con trỏ đến node sản phẩm nếu tìm thấy, NULL nếu không tìm thấy. (2 điểm)

Test case 1: Tạo cây như test case 2 câu 2. Search(root, 102), Search(root, 108)

Test case 2: Sử dụng cây từ test case 1 câu 3. Search(root, 110): Kiểm tra trả về NULL.

InorderTraversal(ProductNode root):* In danh sách sản phẩm theo thứ tự Inorder (Left-Node-Right), mỗi sản phẩm trên một dòng, các trường cách nhau bằng dấu cách. Nếu cây rỗng in ra "Tree is empty!". (2.5 điểm)

Test case 1: Tạo cây như test case 2 câu 2. Gọi InorderTraversal(root): Kiểm tra in ra đúng định dạng theo thứ tự Inorder:

102 Product C 20.00
105 Product B 30.00
108 Product D 40.00
Use code with caution.
Test case 2: root = NULL; InorderTraversal(root). Kiểm tra in ra "Tree is empty!".

Height(ProductNode root):* Tính chiều cao của cây nhị phân. Nếu cây rỗng, trả về -1. (1.5 điểm)

Test case 1: Tạo cây như test case 2 câu 2. Height(root). Kiểm tra trả về 2.

Test case 2: root = NULL; Height(root). Kiểm tra trả về -1

FreeTree(ProductNode root):* Giải phóng toàn bộ bộ nhớ đã cấp phát cho cây. (2 điểm)

Test case 1: Tạo cây và FreeTree sau khi dùng. Kiểm tra bằng Valgrind. (không chấm trực tiếp)

Chương trình kết thúc khi đọc được số -1.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50

typedef struct ProductNode {
    int id;                   // Mã sản phẩm (duy nhất)
    char name[MAX_NAME_LENGTH]; // Tên sản phẩm
    float price;               // Giá sản phẩm
    struct ProductNode* left;
    struct ProductNode* right;
} ProductNode;

ProductNode *CreateNode(int id, char *name, float price){
    ProductNode *p = (ProductNode*)malloc(sizeof(ProductNode));
    p->id = id;
    strcpy(p->name, name);
    p->price = price;
    p->left = NULL;
    p->right = NULL;
    return p;
}

ProductNode* Insert(ProductNode *root, ProductNode *new_node){
    if(root == NULL)
        return new_node;
    if(new_node->id < root->id)
        root->left = Insert(root->left, new_node);
    else
        root->right = Insert(root->right, new_node);
    return root;
}

ProductNode* Search(ProductNode *root, int id){
    if(root == NULL)
        return NULL;
    if(root->id == id)
        return root;
    if(id < root->id)
        return Search(root->left, id);
    return Search(root->right, id);
}

void InorderTraversal(ProductNode *root){
    if(root == NULL){
        printf("Tree is empty!\n");
        return;
    }
    InorderTraversal(root->left);
    printf("%d %s %.2f\n", root->id, root->name, root->price);
    InorderTraversal(root->right);
}

int Height(ProductNode *root){
    if(root == NULL)
        return -1;
    int lh = Height(root->left);
    int rh = Height(root->right);
    return 1 + (lh > rh ? lh : rh);
}

void FreeTree(ProductNode *root){
    if(root == NULL)
        return;
    FreeTree(root->left);
    FreeTree(root->right);
    free(root);
}

int main(){
    ProductNode *root = NULL;
    int id;
    char name[MAX_NAME_LENGTH];
    float price;
    while(1){
        scanf("%d", &id);
        if(id == -1)
            break;
        scanf("%s%f", name, &price);
        ProductNode *p = CreateNode(id, name, price);
        root = Insert(root, p);
    }
    while(1){
        scanf("%d", &id);
        if(id == -1)
            break;
        ProductNode *p = Search(root, id);
        if(p != NULL)
            printf("%d %s %.2f\n", p->id, p->name, p->price);
        else
            printf("Not found\n");
    }
    InorderTraversal(root);
    printf("%d\n", Height(root));
    FreeTree(root);
    return 0;
}
