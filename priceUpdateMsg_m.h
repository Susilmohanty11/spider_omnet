//
// Generated file, do not edit! Created by nedtool 5.4 from priceUpdateMsg.msg.
//

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#ifndef __PRICEUPDATEMSG_M_H
#define __PRICEUPDATEMSG_M_H

#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0504
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif



/**
 * Class generated from <tt>priceUpdateMsg.msg:17</tt> by nedtool.
 * <pre>
 * packet priceUpdateMsg
 * {
 *     double nLocal;
 *     double serviceRate;
 *     double arrivalRate;
 *     double queueSize;
 * }
 * </pre>
 */
class priceUpdateMsg : public ::omnetpp::cPacket
{
  protected:
    double nLocal;
    double serviceRate;
    double arrivalRate;
    double queueSize;

  private:
    void copy(const priceUpdateMsg& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const priceUpdateMsg&);

  public:
    priceUpdateMsg(const char *name=nullptr, short kind=0);
    priceUpdateMsg(const priceUpdateMsg& other);
    virtual ~priceUpdateMsg();
    priceUpdateMsg& operator=(const priceUpdateMsg& other);
    virtual priceUpdateMsg *dup() const override {return new priceUpdateMsg(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual double getNLocal() const;
    virtual void setNLocal(double nLocal);
    virtual double getServiceRate() const;
    virtual void setServiceRate(double serviceRate);
    virtual double getArrivalRate() const;
    virtual void setArrivalRate(double arrivalRate);
    virtual double getQueueSize() const;
    virtual void setQueueSize(double queueSize);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const priceUpdateMsg& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, priceUpdateMsg& obj) {obj.parsimUnpack(b);}


#endif // ifndef __PRICEUPDATEMSG_M_H

