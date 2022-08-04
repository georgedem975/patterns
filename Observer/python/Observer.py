import abc
from typing import List


class IObserver(metaclass=abc.ABCMeta):

    @abc.abstractmethod
    def update(self, p: int):
        pass


class IObservable(metaclass=abc.ABCMeta):

    @abc.abstractmethod
    def add__observer(self, o: IObserver):
        pass


    @abc.abstractmethod
    def remove_observer(self, o: IObserver):
        pass


    @abc.abstractmethod
    def notify(self):
        pass


class Product(IObservable):

    def __init__(self, price: int):
        self.__price = price
        self.__observers: List[IObserver] = []


    def change_price(self, price: int):
        self.__price = price
        self.notify()


    def add__observer(self, o: IObserver):
        self.__observers.append(o)


    def remove_observer(self, o: IObserver):
        self.__observers.remove(o)


    def notify(self):
        for o in self.__observers:
            o.update(self.__price)


class Wholesale(IObserver):

    def __init__(self, obj: IObservable):
        self.__product = obj
        obj.add__observer(self)


    def update(self, p: int):
        if p < 300:
            print('the wholesaler bought the goods at a price {}'.format(p))
            self.__product.remove_observer(self)


class Buyer(IObserver):

    def __init__(self, obj: IObservable):
        self.__product = obj
        obj.add__observer(self)
        

    def update(self, p: int):
        if p < 350:
            print('the buyer purchased the product at the price {}'.format(p))
            self.__product.remove_observer(self)


if __name__ == '__main__':

    product = Product(400)

    wholesale = Wholesale(product)
    buyer = Buyer(product)

    product.change_price(320)
    product.change_price(280)