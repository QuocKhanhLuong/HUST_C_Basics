/*Bài toán: Tìm Đường Đi Ngắn Nhất của Robot

Một robot di chuyển trên một mặt phẳng lưới 2D. Robot có thể di chuyển theo 4 hướng: lên (U), xuống (D), trái (L), phải (R). 
Robot bắt đầu từ vị trí (0, 0). Bạn được cho một chuỗi các lệnh điều khiển robot. 
Hãy tìm vị trí cuối cùng của robot, và tính khoảng cách ngắn nhất mà robot có thể di chuyển đến vị trí này bằng cách chỉ đi theo đường thẳng từ vị trí xuất phát (0,0). 
Khoảng cách này được tính theo công thức Euclidean: sqrt(x^2 + y^2).

Yêu cầu:
Viết chương trình C để thực hiện các công việc sau:
Đọc lệnh di chuyển: Đọc một chuỗi các lệnh điều khiển robot từ đầu vào. Mỗi lệnh có thể là 'U', 'D', 'L', hoặc 'R'.
Tính vị trí cuối: Xác định vị trí cuối cùng của robot sau khi thực hiện tất cả các lệnh.
Tính khoảng cách ngắn nhất: Tính khoảng cách ngắn nhất (theo đường thẳng) từ vị trí bắt đầu (0, 0) đến vị trí cuối cùng.
In kết quả: In ra vị trí cuối cùng (x, y) và khoảng cách ngắn nhất, phân tách nhau bởi dấu cách.

Lưu ý:
Chuỗi lệnh sẽ chỉ chứa các ký tự 'U', 'D', 'L', 'R'.
Khoảng cách cần được làm tròn đến 2 chữ số thập phân.
Đầu vào kết thúc bằng một ký tự '#'
*/

#include <stdio.h>
#include <math.h>

int main(){
    char c;
    int x = 0;
    int y = 0;
    while(1){
        scanf("%c", &c);
        if(c == '#') break;
        if(c == 'U') y++;
        if(c == 'D') y--;   
        if(c == 'L') x--;
        if(c == 'R') x++;
    }
    printf("(%d, %d) %.2f", x, y, sqrt(x*x + y*y));
}
