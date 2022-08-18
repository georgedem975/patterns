#include <iostream>
#include <string>

class Phone
{
        std::string data;

    public:
        Phone() : data("") {}
        std::string aboutPhone();
        void appendData(std::string str);
};

class IDeveloper
{
    public:
        virtual void createDisplay() = 0;
        virtual void createBox() = 0;
        virtual void systemInstall() = 0;
        virtual Phone* GetPhone() = 0;
};

class AndroidDeveloper : public IDeveloper
{
        Phone* phone;

    public:
        AndroidDeveloper();
        ~AndroidDeveloper();
        void createDisplay() override;
        void createBox() override;
        void systemInstall() override;
        Phone* GetPhone() override;
};

class IPhoneDeveloper : public IDeveloper
{
        Phone* phone;

    public:
        IPhoneDeveloper();
        ~IPhoneDeveloper();
        void createDisplay() override;
        void createBox() override;
        void systemInstall() override;
        Phone* GetPhone() override;
};

class Director
{
        IDeveloper* developer;

    public:
        Director(IDeveloper* developer) : developer(developer) {}
        void SetDeveloper(IDeveloper* developer);
        Phone* MountOnlyPhone();
        Phone* MountFullPhone();
};

int main()
{
    IDeveloper* androidDeveloper = new AndroidDeveloper();
    Director director(androidDeveloper);

    Phone* samsung = director.MountFullPhone();
    std::cout << samsung->aboutPhone() << std::endl;

    IDeveloper* iphoneDeveloper = new IPhoneDeveloper();
    director.SetDeveloper(iphoneDeveloper);

    Phone* iphone = director.MountOnlyPhone();
    std::cout << iphone->aboutPhone() << std::endl;
    
    return 0;
}

std::string Phone::aboutPhone()
{
    return data;
}

void Phone::appendData(std::string str)
{
    data += str;
}

AndroidDeveloper::AndroidDeveloper()
{
    phone = new Phone();
}

AndroidDeveloper::~AndroidDeveloper()
{
    delete phone;
}

void AndroidDeveloper::createDisplay()
{
    phone->appendData("(create) display Samsung; ");
}

void AndroidDeveloper::createBox()
{
    phone->appendData("(create) corpus Samsung; ");
}

void AndroidDeveloper::systemInstall()
{
    phone->appendData("(install) system Android; ");
}

Phone *AndroidDeveloper::GetPhone()
{
    return phone;
}

IPhoneDeveloper::IPhoneDeveloper()
{
    phone = new Phone();
}

IPhoneDeveloper::~IPhoneDeveloper()
{
    delete phone;
}

void IPhoneDeveloper::createDisplay()
{
    phone->appendData("(create) display Iphone; ");
}

void IPhoneDeveloper::createBox()
{
    phone->appendData("(create) corpus Iphone; ");
}

void IPhoneDeveloper::systemInstall()
{
    phone->appendData("(install) system IOS; ");
}

Phone *IPhoneDeveloper::GetPhone()
{
    return phone;
}

void Director::SetDeveloper(IDeveloper *developer)
{
    this->developer = developer;
}

Phone *Director::MountOnlyPhone()
{
    developer->createBox();
    developer->createDisplay();
    return developer->GetPhone();
}

Phone *Director::MountFullPhone()
{
    developer->createBox();
    developer->createDisplay();
    developer->systemInstall();
    return developer->GetPhone();
}