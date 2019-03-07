
using namespace std;
using namespace omnetpp;

typedef tuple<int,int> Id;

class PaymentChannel{
public:
    //channel information
    cGate* gate;
    double balance;
    double balanceEWMA;
    vector<tuple<int, double, routerMsg*,  Id, simtime_t >> queuedTransUnits; //make_heap in initialization
    map<Id, double> incomingTransUnits; //(key,value) := ((transactionId, htlcIndex), amount)
    map<Id, double> outgoingTransUnits;

    //channel information for price scheme
    double nValue;// Total amount across all transactions (i.e. the sum of the amount in each transaction)
        // that have arrived to be sent along the channel
    double lastNValue;
    double xLocal; //Transaction arrival rate ($x_local$)
    double totalCapacity; //Total channel capacity ($C$)
    double serviceRate; // ratio of rate transaction arrival over transaction service rate (queue->inflight)     
    double lambda; //Price due to load ($\lambda$)
    list<tuple<simtime_t, simtime_t>> serviceArrivalTimeStamps; //each entry is service and arrival time of last n transactions

    double lastLambdaGrad = 0; // for accelerated gradient descent
    double yLambda; // Nesterov's equation y

    double muLocal; //Price due to channel imbalance at my end  ($\mu_{local}$)
    double lastMuLocalGrad = 0; // for accelerated gradient descent
    double yMuLocal; // Nesterov's equation y

    double muRemote; //Price due to imbalance at the other end of the channel ($\mu_{remote}$)
    double yMuRemote; // Nesterov's equation y

    //statistics for price scheme per payment channel
    simsignal_t nValueSignal;
    simsignal_t xLocalSignal;
    simsignal_t serviceRateSignal;
    simsignal_t inFlightSignal;
    simsignal_t lambdaSignal;
    simsignal_t muLocalSignal;
    simsignal_t muRemoteSignal;

    //statistics - ones for per payment channel
    int statNumProcessed;
    int statNumSent;
    simsignal_t numInQueuePerChannelSignal;
    simsignal_t balancePerChannelSignal;
    simsignal_t numInflightPerChannelSignal;

};
