#include <iostream>
#include <string>

class Reader
{
    public:
        virtual ~Reader() {}
        virtual void parse(std::string& url) = 0;
};

class ResourceReader
{
    private:
        Reader* reader;

    public:
        ResourceReader(Reader* r) : reader(r) {}
        ~ResourceReader();
        void SetStrategy(Reader* r);
        void read(std::string& url);
};

class NewsSiteReader : public Reader
{
    public:
        void parse(std::string& url) override;
};

class SocialNetworkReader : public Reader
{
    public:
        void parse(std::string& url) override;
};

class TelegramChannelReader : public Reader
{
    public:
        void parse(std::string& url) override;
};

int main()
{
    ResourceReader* resourceReader = new ResourceReader(new NewsSiteReader());

    std::string url = "news site";
    resourceReader->read(url);

    url = "social network";
    resourceReader->SetStrategy(new SocialNetworkReader());
    resourceReader->read(url);

    url = "telegram channel";
    resourceReader->SetStrategy(new TelegramChannelReader());
    resourceReader->read(url);
    return 0;
}

ResourceReader::~ResourceReader()
{
    delete reader;
}

void ResourceReader::SetStrategy(Reader *r)
{
    if (reader != nullptr) delete reader;
    reader = r;
}

void ResourceReader::read(std::string &url)
{
    reader->parse(url);
}

void NewsSiteReader::parse(std::string &url)
{
    std::cout << "parse site " << url << std::endl;
}

void SocialNetworkReader::parse(std::string &url)
{
    std::cout << "parse social networks " << url << std::endl;
}

void TelegramChannelReader::parse(std::string &url)
{
    std::cout << "parse telegram channel " << url << std::endl;
}