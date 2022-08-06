import abc


class State(metaclass=abc.ABCMeta):

    def __init__(self):
        self._traffic_light: 'TrafficLight' = None

    @abc.abstractmethod
    def next_state(self):
        pass

    @abc.abstractmethod
    def previous_state(self):
        pass


class TrafficLight:

    def __init__(self, st: State):
        self.__state = None
        self.set_state(st)

    def set_state(self, st: State):
        self.__state = st
        self.__state._traffic_light = self

    def next_state(self):
        self.__state.next_state()

    def previous_state(self):
        self.__state.previous_state()


class GreenState(State):

    def next_state(self):
        print('from green to yellow')
        self._traffic_light.set_state(YellowState())

    def previous_state(self):
        print('Green color')


class YellowState(State):

    def next_state(self):
        print('from yellow to red')
        self._traffic_light.set_state(RedState())

    def previous_state(self):
        print('from yellow to green')
        self._traffic_light.set_state(GreenState())


class RedState(State):

    def next_state(self):
        print('red color')

    def previous_state(self):
        print('from red to yellow')
        self._traffic_light.set_state(YellowState())


if __name__ == '__main__':

    traffic_light = TrafficLight(GreenState())

    traffic_light.next_state()
    traffic_light.next_state()
    traffic_light.next_state()
    traffic_light.previous_state()
    traffic_light.previous_state()
    traffic_light.previous_state()