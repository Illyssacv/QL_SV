#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

static string getenv_or(const char *key, const char *fallback)
{
    const char *v = getenv(key);
    return v ? string(v) : string(fallback);
}

int main()
{
    try
    {
        const string host = getenv_or("MYSQL_HOST", "127.0.0.1");
        const string port = getenv_or("MYSQL_PORT", "3306");
        const string user = getenv_or("MYSQL_USER", "root");
        const string pass = getenv_or("MYSQL_PASSWORD", "");
        const string dbName = getenv_or("MYSQL_DATABASE", "school");

        const string tcp = "tcp://" + host + ":" + port;

        sql::Driver *driver = get_driver_instance();
        sql::Connection *con = driver->connect(tcp, user, pass);
        sql::Statement *stmt = con->createStatement();

        try
        {
            stmt->execute("CREATE DATABASE IF NOT EXISTS `" + dbName + "`");
        }
        catch (sql::SQLException &)
        {
            // User app thường chỉ có quyền trên DB đã tạo sẵn (MYSQL_DATABASE trong Docker).
        }
        stmt->execute("USE `" + dbName + "`");
        try
        {
            stmt->execute(
                "CREATE TABLE IF NOT EXISTS student(id INT PRIMARY KEY AUTO_INCREMENT, fullName VARCHAR(255),birthDate DATE, age INT,email VARCHAR(255),phoneNumber VARCHAR(20), userName VARCHAR(255),password varchar(255), createdAt DATETIME,role VARCHAR(50), isActive VARCHAR(50),major VARCHAR(255),classId VARCHAR(255), schoolYear VARCHAR(255),totalTuition BIGINT UNSIGNED, paidTuition BIGINT UNSIGNED, gpa FLOAT, progressScore FLOAT, participationScore FLOAT, grade VARCHAR(50),subjectScores JSON)");
        }
        catch (sql::SQLException &e)
        {
            cerr << "Error creating table: " << e.what() << endl;
        }
        try
        {
            stmt->execute("CREATE TABLE IF NOT EXISTS instructor(id INT PRIMARY KEY AUTO_INCREMENT,fullName VARCHAR(255),birthDate DATE, age INT,email VARCHAR(255),phoneNumber VARCHAR(20), userName VARCHAR(255),password varchar(255), createdAt DATETIME,role VARCHAR(50), isActive VARCHAR(50),instructorID VARCHAR(255),department VARCHAR(255), officeLocation VARCHAR(255))");
        }
        catch (sql::SQLException &e)
        {
            cerr << "Error creating table: " << e.what() << endl;
        }

        delete stmt;
        delete con;
    }
    catch (sql::SQLException &e)
    {
        cerr << "SQL error: " << e.what() << endl;
        return 1;
    }
    return 0;
}
