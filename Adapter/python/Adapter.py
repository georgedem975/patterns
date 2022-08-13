import abc
from abc import ABCMeta


class IScale(metaclass=ABCMeta):

    @abc.abstractmethod
    def get_weight(self) -> float:
        pass


class RussianScales(IScale):

    def __init__(self, cw: float):
        self.__current_weight = cw

    def get_weight(self) -> float:
        return self.__current_weight


class BritishScales:

    def __init__(self, cw: float):
        self.__current_weight = cw

    def get_weight(self) -> float:
        return self.__current_weight


class AdapterForBritishScales(IScale):

    def __init__(self, british_scales: BritishScales):
        self.__british_scales = british_scales

    def get_weight(self) -> float:
        return self.__british_scales.get_weight() * .453


if __name__ == '__main__':
    kg: float = 55
    lb: float = 55

    rScales = RussianScales(kg)
    bScales = AdapterForBritishScales(BritishScales(lb))

    print(rScales.get_weight())
    print(bScales.get_weight())