#include <iostream>

class TrafficLight;

class State
{
    protected:
        TrafficLight* trafficLight;

    public:
        virtual ~State() {}
        void SetTrafficLight(TrafficLight* tr);
        virtual void nextState() = 0;
        virtual void previousState() = 0;
};

class TrafficLight
{
    private:
        State* state;

    public:
        TrafficLight(State* st) : state(nullptr)
        {
            SetState(st);
        }
        void SetState(State* st);
        void nextState();
        void previousState();
};

class GreenState : public State
{
    public:
        void nextState() override;
        void previousState() override;
};

class YellowState : public State
{
    public:
        void nextState() override;
        void previousState() override;
};

class RedState : public State
{
    public:
        void nextState() override;
        void previousState() override;
};

int main()
{
    TrafficLight* trafficLight = new TrafficLight(new GreenState());

    trafficLight->nextState();
    trafficLight->nextState();
    trafficLight->nextState();
    trafficLight->previousState();
    trafficLight->previousState();
    trafficLight->previousState();

    delete trafficLight;
    
    return 0;
}

void State::SetTrafficLight(TrafficLight *tr)
{
    trafficLight = tr;
}

void TrafficLight::SetState(State *st)
{
    if (state != nullptr) delete state;
    state= st;
    state->SetTrafficLight(this);
}

void TrafficLight::nextState()
{
    state->nextState();
}

void TrafficLight::previousState()
{
    state->previousState();
}

void GreenState::nextState()
{
    std::cout << "from green to yellow\n";
    trafficLight->SetState(new YellowState());
}

void GreenState::previousState()
{
    std::cout << "green color\n";
}

void YellowState::nextState()
{
    std::cout << "from yellow to red\n";
    trafficLight->SetState(new RedState());
}

void YellowState::previousState()
{
    std::cout << "from yellow to green\n";
    trafficLight->SetState(new GreenState());
}

void RedState::nextState()
{
    std::cout << "red color\n";
}

void RedState::previousState()
{
    std::cout << "from red to yellow\n";
    trafficLight->SetState(new YellowState());
}