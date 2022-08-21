#include <iostream>
#include <string>

class DatabaseHelper
{
    private:
        DatabaseHelper();
        static DatabaseHelper* databaseConnection;
        std::string data;

    public:
        DatabaseHelper(const DatabaseHelper&) = delete;
        void operator = (const DatabaseHelper&) = delete;
        static DatabaseHelper* GetConnection();
        std::string selectData() const;
        void insertData(std::string d);
};

DatabaseHelper* DatabaseHelper::databaseConnection = nullptr;

int main()
{
    DatabaseHelper::GetConnection()->insertData("123");
    std::cout << "Data: " << DatabaseHelper::GetConnection()->selectData() << std::endl;
    return 0;
}

DatabaseHelper::DatabaseHelper()
{
    std::cout << "connecting to the database\n";
}

DatabaseHelper *DatabaseHelper::GetConnection()
{
    if (databaseConnection == nullptr)
        databaseConnection = new DatabaseHelper();
    return databaseConnection;
}

std::string DatabaseHelper::selectData() const
{
    return data;
}

void DatabaseHelper::insertData(std::string d)
{
    std::cout << "new data: " << d << "(entered into the database)\n";
    data = d;
}