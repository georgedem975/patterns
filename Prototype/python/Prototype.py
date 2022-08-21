class Sheep:

    __name: str = ''

    def __init__(self, donor: 'Sheep' = None):
        if donor is not None:
            self.__name = donor.get_name()

    def set_name(self, name: str):
        self.__name = name

    def get_name(self) -> str:
        return self.__name

    def clone(self):
        return Sheep(self)


if __name__ == '__main__':

    sheep_donor: Sheep = Sheep()
    sheep_donor.set_name('sheep')

    sheep_clone: Sheep = sheep_donor.clone()

    print(sheep_donor.get_name())
    print(sheep_clone.get_name())