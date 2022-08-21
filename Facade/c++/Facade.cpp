#include <iostream>

class ProviderCommunication
{
    public:
        void receive();
        void payment();
};

class Site
{
    public:
        void placement();
        void del();
};

class Database
{
    public:
        void insert();
        void del();
};

class MarketPlace
{
    private:
        ProviderCommunication providerCommunication;
        Site site;
        Database database;

    public:
        void productReceipt();
        void productRelease();
};

int main()
{
    MarketPlace marketPlace;

    marketPlace.productReceipt();

    std::cout << std::endl;

    marketPlace.productRelease();
    
    return 0;
}

void ProviderCommunication::receive()
{
    std::cout << "receiving products from the manufacturer\n";
}

void ProviderCommunication::payment()
{
    std::cout << "payment\n";
}

void Site::placement()
{
    std::cout << "placement on the website\n";
}

void Site::del()
{
    std::cout << "removal from the site\n";
}

void Database::insert()
{
    std::cout << "writing to the database\n";
}

void Database::del()
{
    std::cout << "deleting from the database\n";
}

void MarketPlace::productReceipt()
{
    providerCommunication.receive();
    site.placement();
    database.insert();
}

void MarketPlace::productRelease()
{
    providerCommunication.payment();
    site.del();
    database.del();
}