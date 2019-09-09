//
// Generated file, do not edit! Created by nedtool 5.4 from routerMsg.msg.
//

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#ifndef __ROUTERMSG_M_H
#define __ROUTERMSG_M_H

#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0504
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif



// cplusplus {{
#include <vector>
#define TRANSACTION_MSG 0
#define ACK_MSG 1
#define UPDATE_MSG 2
#define STAT_MSG 3
#define TIME_OUT_MSG 4
#define PROBE_MSG 5
#define CLEAR_STATE_MSG 6

//new msg types for price scheme
#define TRIGGER_PRICE_UPDATE_MSG 7
#define TRIGGER_PRICE_QUERY_MSG 8
#define PRICE_UPDATE_MSG 9
#define PRICE_QUERY_MSG 10
#define TRIGGER_TRANSACTION_SEND_MSG 11
#define COMPUTE_DEMAND_MSG 12
#define TRIGGER_RATE_DECREASE_MSG 13

#define MONITOR_PATHS_MSG 14
#define TRIGGER_REBALANCING_MSG 15
#define ADD_FUNDS_MSG 16
#define COMPUTE_BALANCE_MSG 17


typedef std::vector<int> IntVector;
// }}

/**
 * Class generated from <tt>routerMsg.msg:47</tt> by nedtool.
 * <pre>
 * packet routerMsg
 * {
 *     IntVector route;
 *     int hopCount = 0;
 *     int messageType;  //0 for transaction, 1 for ack, 2 for balance update
 * 
 * }
 * </pre>
 */
class routerMsg : public ::omnetpp::cPacket
{
  protected:
    IntVector route;
    int hopCount;
    int messageType;

  private:
    void copy(const routerMsg& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const routerMsg&);

  public:
    routerMsg(const char *name=nullptr, short kind=0);
    routerMsg(const routerMsg& other);
    virtual ~routerMsg();
    routerMsg& operator=(const routerMsg& other);
    virtual routerMsg *dup() const override {return new routerMsg(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual IntVector& getRoute();
    virtual const IntVector& getRoute() const {return const_cast<routerMsg*>(this)->getRoute();}
    virtual void setRoute(const IntVector& route);
    virtual int getHopCount() const;
    virtual void setHopCount(int hopCount);
    virtual int getMessageType() const;
    virtual void setMessageType(int messageType);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const routerMsg& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, routerMsg& obj) {obj.parsimUnpack(b);}


#endif // ifndef __ROUTERMSG_M_H

