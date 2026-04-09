#include <iostream>
using namespace std;
enum class Subject
{
    // Khối đại cương
    CALCULUS,          // Giải tích
    GENERAL_PHYSICS,   // Vật lý đại cương
    CRITICAL_THINKING, // Tư duy phản biện
    ENGLISH_1,         // Tiếng Anh 1

    // Khối Công nghệ thông tin (IT)
    INTRO_TO_PROGRAMMING,    // Nhập môn lập trình
    DATA_STRUCTURES,         // Cấu trúc dữ liệu và giải thuật
    OBJECT_ORIENTED_PROG,    // Lập trình hướng đối tượng (OOP)
    DATABASE_SYSTEMS,        // Hệ quản trị cơ sở dữ liệu
    OPERATING_SYSTEMS,       // Hệ điều hành
    SOFTWARE_ENGINEERING,    // Công nghệ phần mềm
    COMPUTER_NETWORKS,       // Mạng máy tính
    ARTIFICIAL_INTELLIGENCE, // Trí tuệ nhân tạo

    // Khối Kinh tế / Quản lý
    MACROECONOMICS,       // Kinh tế vĩ mô
    MICROECONOMICS,       // Kinh tế vi mô
    MARKETING_PRINCIPLES, // Nguyên lý Marketing
    ACCOUNTING            // Kế toán
};