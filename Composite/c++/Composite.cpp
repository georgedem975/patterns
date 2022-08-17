#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Item
{
    protected:
        std::string itemName;
        std::string ownerName;

    public:
        Item(std::string name) : itemName(name) {}
        void SetOwner(std::string o);
        virtual void add(Item* subItem) = 0;
        virtual void remove(Item* subItem) = 0;
        virtual void display() = 0;
};

class ClickableItem : public Item
{
    public:
        ClickableItem(std::string name) : Item(name) {}
        void add(Item* subItem) override;
        void remove(Item* subItem) override;
        void display() override;
};

class DropDownItem : public Item
{
    private:
        std::vector<Item*> children;

    public:
        DropDownItem(std::string name) : Item(name) {}
        void add(Item* subItem) override;
        void remove(Item* subItem) override;
        void display() override;
};

int main()
{
    Item* file = new DropDownItem("file->");

    Item* create = new DropDownItem("create->");
    Item* open = new DropDownItem("open->");
    Item* exit = new ClickableItem("exit");

    file->add(create);
    file->add(open);
    file->add(exit);

    Item* project = new ClickableItem("project...");
    Item* repository = new ClickableItem("repository...");

    create->add(project);
    create->add(repository);

    Item* solution = new ClickableItem("solution...");
    Item* folder = new ClickableItem("folder...");

    open->add(solution);
    open->add(folder);

    file->display();
    std::cout << std::endl;

    file->remove(create);

    file->display();

    return 0;
}

void Item::SetOwner(std::string o)
{
    ownerName = o;
}

void ClickableItem::add(Item *subItem)
{
    throw std::exception();
}

void ClickableItem::remove(Item *subItem)
{
    throw std::exception();
}

void ClickableItem::display()
{
    std::cout << itemName << std::endl;
}

void DropDownItem::add(Item *subItem)
{
    subItem->SetOwner(this->itemName);
    children.push_back(subItem);
}

void DropDownItem::remove(Item *subItem)
{
    children.erase(std::remove(children.begin(), children.end(), subItem), children.end());
}

void DropDownItem::display()
{
    for (const auto child : children)
    {
        if (ownerName != "")
            std::cout << ownerName << itemName;
        child->display();
    }
}