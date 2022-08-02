#include <iostream>
#include <string>
#include <stack>

class Memento
{
    public:
        virtual int GetDollars() = 0;
        virtual int GetEuro() = 0;
        virtual ~Memento() {}
};

class ExchangeMemento : public Memento
{
    private:
        int dollars;
        int euro;

    public:
        ExchangeMemento(int d, int e) : dollars(d), euro(e) {}
        int GetDollars() override;
        int GetEuro() override;
};

class Exchange
{
    private:
        int dollars;
        int euro;

    public:
        Exchange(int d, int e) : dollars(d), euro(e) {}
        void GetDollars();
        void GetEuro();
        void sell();
        void buy();
        ExchangeMemento* save();
        void restore(Memento* exchangeMemento);
};

class Memory
{
    private:
        std::stack<Memento*> history;
        Exchange* exchange;

    public:
        Memory(Exchange* ex) : exchange(ex) {}
        void backup();
        void undo();
};

int main()
{
    Exchange* exchange = new Exchange(10, 10);

    Memory* memory = new Memory(exchange);

    exchange->GetDollars();
    exchange->GetEuro();

    std::cout << "sell dollars, buy euro\n";
    exchange->sell();
    exchange->buy();

    exchange->GetDollars();
    exchange->GetEuro();

    std::cout << "save\n";
    memory->backup();

    std::cout << "sell dollars, buy euro\n";
    exchange->sell();
    exchange->buy();

    exchange->GetDollars();
    exchange->GetEuro();

    std::cout << "restoring the state\n";
    memory->undo();

    exchange->GetDollars();
    exchange->GetEuro();

    return 0;
}

int ExchangeMemento::GetDollars()
{
    return dollars;
}

int ExchangeMemento::GetEuro()
{
    return euro;
}

void Exchange::GetDollars()
{
    std::cout << "Dollars: " << this->dollars << std::endl;
}

void Exchange::GetEuro()
{
    std::cout << "Euro: " << this->euro << std::endl;
}

void Exchange::sell()
{
    this->dollars ? --this->dollars : 0;
}

void Exchange::buy()
{
    ++this->euro;
}

ExchangeMemento *Exchange::save()
{
    return new ExchangeMemento(this->dollars, this->euro);
}

void Exchange::restore(Memento *exchangeMemento)
{
    this->dollars = exchangeMemento->GetDollars();
    this->euro = exchangeMemento->GetEuro();

    delete exchangeMemento;
}

void Memory::backup()
{
    history.push(exchange->save());
}

void Memory::undo()
{
    if (history.empty()) return;

    exchange->restore(history.top());
    history.pop();
}