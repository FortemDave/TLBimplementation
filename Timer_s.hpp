template<typename T>

class Timer_s
{
private:
T time;

public:
Timer_s()
{
this->time = 0;
}

T curr_time()
{
this->time++;
return this->time;
}

~Timer_s()
{
}
};
