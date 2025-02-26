#include<iostream>
#include<vector>
#include<variant>

using namespace std;

class CircularInteger {
private:
    int value;
    int minValue;
    int maxValue;

public:
    CircularInteger(int initialValue, int min, int max) : value(initialValue), minValue(min), maxValue(max) {
        if (min >= max) {
            throw std::invalid_argument("minValue must be less than maxValue");
        }
        if (value < min || value >= max) {
            value = min; // clamp to min
        }
    }

    CircularInteger& operator++() { // Pre-increment
        value = (value + 1 - minValue) % (maxValue - minValue) + minValue;
        return *this;
    }

    CircularInteger operator++(int) { // Post-increment
        CircularInteger temp = *this;
        ++(*this);
        return temp;
    }


     CircularInteger& operator--() { // Pre-decrement
        value = (value - 1 - minValue) % (maxValue - minValue) + minValue;
        if (value < minValue)
            value += (maxValue - minValue);
        return *this;
    }

    CircularInteger operator--(int) { // Post-decrement
        CircularInteger temp = *this;
        --(*this);
        return temp;
    }

    int getValue() const { return value; }
};


struct Taxi
{
    long long timestamp;
    int taxi_id;
    int taxi_position;
};

struct Order
{
    long long timestamp;
    int order_id;
    int order_position;
    int order_time;
};

void print_free_taxi(vector<Taxi>& taxies, Order& order, int& S)
{
    for (size_t i = 0; i < taxies.size(); i++)
    {
        int timeEdit = abs(order.timestamp - taxies[i].timestamp);

        std::pair<int,int> coordinate_var(taxies[i].taxi_position-S*timeEdit,taxies[i].taxi_position+S*timeEdit);

        if (coordinate_var.first>= order.order_position &&  order.order_position <=(coordinate_var.first + order.order_time*S)
            && coordinate_var.second<= order.order_position &&  order.order_position >=(coordinate_var.second - order.order_time*S))
        {
            std::cout << taxies[i].taxi_id << " ";
        }
        
    }
    
}



int main()
{
    int N,L,S;

    cin >> N >> L >> S;

    //vector<variant<Taxi,Order>> events;

    vector<Taxi> taxi;
    vector<Order> orders;
    string word;
    for (int i = 0; i < N; i++)
    {
        cin >> word;
        if (word == "TAXI")
        {   
            int timestamp,taxi_id, taxi_position;
            cin >> timestamp >> taxi_id >> taxi_position;
            taxi.push_back(Taxi(timestamp,taxi_id,taxi_position));
        } else if(word == "ORDER")
        {
            int timestamp,order_id, order_position, order_time;
            cin >> timestamp >> order_id >> order_position >> order_time;
            orders.push_back(Order(timestamp,order_id,order_position,order_time));
        }
    }
    for (size_t i = 0; i < orders.size(); i++)
    {
        
    }
    
    cout << "Hello\n";
}