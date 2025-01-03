/*Bài toán: Phân Tích Văn Bản và Đếm Tần Suất Từ

Cho một đoạn văn bản đầu vào (gồm nhiều dòng), bạn hãy viết chương trình C để thực hiện các công việc sau:
Đọc văn bản: Đọc văn bản từ đầu vào. Văn bản có thể chứa nhiều dòng, các dòng có thể chứa ký tự in hoa, in thường, chữ số và các ký tự đặc biệt khác. Đọc cho đến khi gặp dòng chứa ký tự # thì dừng.
Chuẩn hóa văn bản: Chuyển tất cả các ký tự in hoa thành chữ thường, loại bỏ các ký tự không phải chữ cái hoặc chữ số (các ký tự đặc biệt), và thay thế các dấu cách liền nhau bằng một dấu cách duy nhất.
Tách từ: Tách các từ trong văn bản (mỗi từ được ngăn cách bởi dấu cách).
Đếm tần suất: Đếm số lần xuất hiện của mỗi từ trong văn bản.
In kết quả: In ra danh sách các từ và số lần xuất hiện tương ứng, mỗi từ trên một dòng, theo thứ tự từ điển (từ A-Z).

Lưu ý:
Bạn có thể sử dụng mảng ký tự (char array) hoặc string để lưu trữ văn bản và các từ.
Bạn có thể sử dụng thư viện string.h cho các thao tác trên chuỗi.
Bạn có thể sử dụng thư viện ctype.h cho các thao tác kiểm tra ký tự (ví dụ: isalpha(), isdigit(), tolower()).
Các từ sẽ được in theo thứ tự từ điển.
Nếu một từ xuất hiện nhiều lần, bạn chỉ in ra từ đó một lần, kèm theo tần suất xuất hiện của từ đó.
*/