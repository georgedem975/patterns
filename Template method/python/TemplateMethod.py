import abc


class Transmitter(metaclass=abc.ABCMeta):

    def _voice_record(self):
        print("recording a fragment of speech")

    def _simpling(self):
        pass

    def _digitization(self):
        pass

    @abc.abstractmethod
    def _modulation(self):
        pass

    def _transmission(self):
        print("ignal transmission via radio channel")

    def process_start(self):
        self._voice_record()
        self._simpling()
        self._digitization()
        self._modulation()
        self._transmission()


class AnalogTransmitter(Transmitter):

    def _modulation(self):
        print("modulation of the analog signal")


class DigitTransmitter(Transmitter):

    def _simpling(self):
        print("sampling of the recorded fragment")

    def _digitization(self):
        print("digitization")

    def _modulation(self):
        print("digital signal modulation")


if __name__ == '__main__':
    analog_transmitter = AnalogTransmitter()
    analog_transmitter.process_start()

    print()

    digit_transmitter = DigitTransmitter()
    digit_transmitter.process_start()