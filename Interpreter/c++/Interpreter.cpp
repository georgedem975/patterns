#include <iostream>
#include <string>

class AbstractExpression
        {
public:
            virtual void interpret() = 0;
            virtual ~AbstractExpression(){}

protected:
            AbstractExpression(){}
        };

class TerminalExpression : public AbstractExpression
        {
private:
            std::string statement;
public:
            TerminalExpression(const std::string& st) : statement(st) {};
            ~TerminalExpression() override {}
            void  interpret() override;
        };

class NonTerminalExpression : public  AbstractExpression
        {
private:
            AbstractExpression* expression = nullptr;
            int times;
public:
            NonTerminalExpression(AbstractExpression* ex, int t) : expression(ex), times(t) {};
            ~NonTerminalExpression() override;
            void interpret() override;
        };

int main()
{
    AbstractExpression* te = new TerminalExpression("hello");
    AbstractExpression* nte = new NonTerminalExpression(te, 2);
    nte->interpret();
    delete te;
    delete nte;
    return 0;
}

void TerminalExpression::interpret()
{
    std::cout << this->statement << " TerminalExpression\n";
}

NonTerminalExpression::~NonTerminalExpression() noexcept
{
    this->expression = nullptr;
}

void NonTerminalExpression::interpret()
{
    for (int i = 0; i < times; i++)
    {
        this->expression->interpret();
    }
}