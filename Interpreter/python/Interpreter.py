import abc


class AbstractExpression(metaclass=abc.ABCMeta):

    @abc.abstractmethod
    def interpret(self):
        pass


class TerminalExpression(AbstractExpression):

    def __init__(self, s: str):
        self.string = s

    def interpret(self):
        print(self.string + " TerminalExpression")


class NonTerminalExpression(AbstractExpression):
    
    def __init__(self, ex: AbstractExpression, t: int):
        self.expression = ex
        self.times = t

    def interpret(self):
        for i in range(int(self.times)):
            self.expression.interpret()


if __name__ == "__main__":
    te = TerminalExpression("hello")
    nte = NonTerminalExpression(te, 2)

    nte.interpret()