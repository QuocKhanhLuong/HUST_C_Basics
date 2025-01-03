/*Bài toán: Theo Dõi Nhiệt Độ Máy Chủ

Một trung tâm dữ liệu có một máy chủ, và nhiệt độ của máy chủ này được theo dõi liên tục trong một khoảng thời gian. 
Mỗi ngày, hệ thống sẽ ghi nhận sự thay đổi nhiệt độ của máy chủ so với ngày trước đó.

Yêu cầu:
Bạn hãy viết chương trình C để giúp trung tâm dữ liệu phân tích dữ liệu nhiệt độ của máy chủ. Dữ liệu đầu vào bao gồm:
Số nguyên dương N (1 ≤ N ≤ 100), là số ngày mà trung tâm dữ liệu ghi nhận sự thay đổi nhiệt độ.
Tiếp theo là N dòng, mỗi dòng chứa 2 số nguyên:
D (0 ≤ D ≤ 365): Ngày ghi nhận (không đảm bảo thứ tự)
Change (-20 ≤ Change ≤ 20): Sự thay đổi nhiệt độ của máy chủ so với ngày trước đó.

Nhiệm vụ:
Tính nhiệt độ: Giả sử nhiệt độ ban đầu của máy chủ là 0. Tính toán nhiệt độ của máy chủ vào mỗi ngày ghi nhận.
Tìm nhiệt độ cao nhất: Tìm và in ra nhiệt độ cao nhất mà máy chủ đã đạt được trong suốt quá trình theo dõi.
In ra ngày đầu tiên: In ra ngày đầu tiên mà máy chủ đạt được nhiệt độ cao nhất.

Lưu ý:
Các ngày ghi nhận có thể không theo thứ tự tăng dần.
Nếu có nhiều ngày có cùng nhiệt độ cao nhất, chỉ in ra ngày đầu tiên mà nhiệt độ đó đạt được.
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int N;
    scanf("%d", &N);
    int maxTemp = 0;
    int maxTempDay = 0;
    int temp = 0;
    for(int i = 0; i < N; i++){
        int D;
        int change;
        scanf("%d %d", &D, &change);
        temp += change;
        if(temp >= maxTemp){
            maxTemp = temp;
            maxTempDay = D;
        }
    }
    printf("%d\n%d", maxTemp, maxTempDay);
}