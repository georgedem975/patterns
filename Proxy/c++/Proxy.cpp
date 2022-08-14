#include <iostream>
#include <string>
#include <map>

class ISite
{
    public:
        virtual std::string GetPage(int num) = 0;
        virtual ~ISite() {}
};

class Site : public ISite
{
    public:
        std::string GetPage(int num) override;
};

class SiteProxy : public ISite
{
    private:
        ISite* site;
        std::map<int, std::string> cache;

    public:
        SiteProxy(ISite* site) : site(site) {}
        ~SiteProxy();
        std::string GetPage(int num) override;
};

int main()
{
    ISite* mySite = new SiteProxy(new Site());

    std::cout << mySite->GetPage(1) << std::endl;
    std::cout << mySite->GetPage(2) << std::endl;
    std::cout << mySite->GetPage(3) << std::endl;

    std::cout << mySite->GetPage(2) << std::endl;

    return 0;
}

std::string Site::GetPage(int num)
{
    std::string page = "page " + std::to_string(num);
    return page;
}

SiteProxy::~SiteProxy() noexcept
{
    delete site;
}

std::string SiteProxy::GetPage(int num)
{
    std::string page;
    if (cache.find(num) == cache.end())
    {
        page = site->GetPage(num);
        cache[num] = page;
    }
    else
    {
        page = cache[num];
        page.insert(0, "from cache ");
    }
    return page;
}