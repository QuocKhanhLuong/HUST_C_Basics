/*Mô tả bài toán:

Mô tả bài toán:

Bạn được yêu cầu viết một chương trình C để quản lý cấu trúc thư mục của một hệ thống tập tin đơn giản, sử dụng một cây với con trỏ đến con trái nhất (leftMostChild), anh em bên phải (rightSibling), và cha (parent).

Cấu trúc dữ liệu Cây:

#define MAX_NAME_LENGTH 50

typedef struct TreeNode {
    char name[MAX_NAME_LENGTH];
    int is_dir; // 1 if directory, 0 if file
    struct TreeNode* leftMostChild;
    struct TreeNode* rightSibling;
    struct TreeNode* parent;
} TreeNode;
Use code with caution.
C
Yêu cầu chức năng:

Chương trình của bạn cần hỗ trợ các thao tác sau, mỗi thao tác tương ứng với một hàm:

CreateNode(char name[], int is_dir): Tạo một node mới (thư mục hoặc file) với tên name và loại is_dir (1 cho thư mục, 0 cho file). Trả về con trỏ đến node vừa tạo. Khởi tạo các con trỏ leftMostChild, rightSibling và parent thành NULL. (1 điểm)

Test case 1: Gọi CreateNode("root", 1). Kiểm tra rằng node mới được tạo có name là "root", is_dir là 1, leftMostChild, rightSibling, and parent are NULL.

InsertChild(TreeNode parent, TreeNode child):** Thêm một node con child vào node cha parent. Đặt child làm con trái nhất nếu parent chưa có con nào, nếu không, thêm child làm anh em bên phải của con trái nhất của parent. Cập nhật con trỏ parent của node con. (1.5 điểm)

Test case 1: Gọi CreateNode("parent", 1), CreateNode("child1", 1), CreateNode("child2", 0). Thực hiện InsertChild(parent, child1), InsertChild(parent, child2). Kiểm tra parent->leftMostChild là child1 và child1->rightSibling là child2 và child1->parent và child2->parent là parent.

Test case 2: Gọi CreateNode("parent", 1). Thực hiện InsertChild một vài lần.

Search(TreeNode root, char name[]):* Tìm kiếm node có tên name trong cây. Trả về con trỏ đến node đó nếu tìm thấy, NULL nếu không tìm thấy. Tìm kiếm theo thứ tự duyệt cây nào cũng được (ưu tiên DFS). (2 điểm)

Test case 1: Tạo cây có các node: root, dir1, file1, file2. Gọi Search(root, "file1"). Kiểm tra trả về con trỏ đến node "file1".

Test case 2: Gọi Search(root, "not_exist"). Kiểm tra trả về NULL.

PrintTree(TreeNode root, int level):* In cấu trúc cây theo dạng thụt lề (indentation) với số lượng khoảng trắng level*2 trước mỗi tên. Sử dụng Preorder Traversal (Node-Left-Right). (2.5 điểm)

Test case 1: Tạo cây: root (dir) -> dir1 (dir), file1 (file), file2 (file). Gọi PrintTree(root, 0). Kiểm tra in ra đúng định dạng (đúng thụt lề) sử dụng Preorder traversal:

root (dir)
  dir1 (dir)
  file1 (file)
  file2 (file)
Use code with caution.
Test case 2: Tạo cây phức tạp hơn, kiểm tra in ra đúng theo preorder traversal.

CountFiles(TreeNode root):* Đếm số lượng file (không phải thư mục) trong cây. Sử dụng Postorder Traversal (Left-Right-Node). (1.5 điểm)

Test case 1: Sử dụng cây từ test case 1 câu 4. Gọi CountFiles(root). Kiểm tra trả về 2.

Test case 2: Tạo cây phức tạp hơn, kiểm tra đếm đúng số file bằng postorder traversal.

FreeTree(TreeNode root):* Giải phóng toàn bộ bộ nhớ đã cấp phát cho cây (2 điểm).

Test case 1: Tạo 1 cây có các node và gọi FreeTree. Kiểm tra bằng cách chạy chương trình với Valgrind (hoặc tool tương tự) không còn memory leak. (có thể không chấm trực tiếp mà chỉ đánh giá khi chấm code)

Chương trình kết thúc khi đọc được xâu "*".
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50

typedef struct TreeNode {
    char name[MAX_NAME_LENGTH];
    int is_dir; // 1 if directory, 0 if file
    struct TreeNode* leftMostChild;
    struct TreeNode* rightSibling;
    struct TreeNode* parent;
} TreeNode;

TreeNode *CreateNode(char *name, int is_dir){
    TreeNode *p = (TreeNode*)malloc(sizeof(TreeNode));
    strcpy(p->name, name);
    p->is_dir = is_dir;
    p->leftMostChild = NULL;
    p->rightSibling = NULL;
    p->parent = NULL;
    return p;
}

TreeNode* Search(TreeNode *root, char *name){
    if(root == NULL)
        return NULL;
    if(strcmp(root->name, name) == 0)
        return root;
    TreeNode *p = root->leftMostChild;
    while(p!= NULL){
        TreeNode *q= Search(p, name);
        if(q != NULL)
            return q;
        p = p->rightSibling;
    }
    return NULL;
}

void InsertChild(TreeNode *root, char *name, int is_dir){
    TreeNode *p = Search(root, name);
    if(p == NULL)
        return;
    TreeNode *q = CreateNode(name, is_dir);
    if(p->leftMostChild == NULL){
        p->leftMostChild = q;
        q->parent = p;
        return;
    }
    TreeNode *h = p->leftMostChild;
    while(h->rightSibling != NULL){
        h = h->rightSibling;
    }
    h->rightSibling = q;
    q->parent = p;
}

void PrintTree(TreeNode *root, int level){
    if(root == NULL)
        return;
    for(int i = 0; i<level*2; i++)
        printf(" ");
    printf("%s", root->name);
    TreeNode *p = root->leftMostChild;
    while(p != NULL){
        PrintTree(p, level+1);
        p = p->rightSibling;
    }
}

int CountFiles(TreeNode *root){
    if(root ==NULL)
        return 0;
    int count = 0;
    TreeNode *p = root->leftMostChild;
    while(p != NULL){
        count += CountFiles(p);
        p = p->rightSibling;
    }
    if(root->is_dir == 0)
        count++;
    return count;
}

void FreeTree(TreeNode *root){
    if(root == NULL)
        return;
    TreeNode *p = root->leftMostChild;
    while(p != NULL){
        TreeNode *np = p->rightSibling;
        FreeTree(p);
        p = np;
    }
    free(root);
}

int main(){
    TreeNode *root = NULL;
    char cmd[20];
    while(1){
        scanf("%s", cmd);
        if(strcmp(cmd, "*") == 0) {
            break;
        } else if (strcmp(cmd,"CreateNode") == 0){
            char name[MAX_NAME_LENGTH];
            int is_dir;
            scanf("%s %d", name, &is_dir);
            root = CreateNode(name, is_dir);
        } else if (strcmp(cmd, "InsertChild") == 0){
            char name[MAX_NAME_LENGTH];
            int is_dir;
            scanf("%s %d", name, &is_dir);
            InsertChild(root, name, is_dir);
        } else if (strcmp(cmd, "Search") == 0){
            char name[MAX_NAME_LENGTH];
            scanf("%s", name);
            TreeNode *p = Search(root, name);
            if(p != NULL)
                printf("Found\n");
            else
                printf("Not found\n");
        } else if (strcmp(cmd, "PrintTree") == 0){
            PrintTree(root, 0);
            printf("\n");
        } else if (strcmp(cmd, "CountFiles") == 0){
            printf("%d\n", CountFiles(root));
        }
    }
    FreeTree(root);
    return 0;
}
