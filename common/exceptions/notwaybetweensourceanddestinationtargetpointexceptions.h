//Author: Andrzej Chmielowski
//Representing exception when no way between start point and target point

#ifndef NOTWAYBETWEENSOURCEANDDESTINATIONTARGETPOINTEXCEPTIONS_H
#define NOTWAYBETWEENSOURCEANDDESTINATIONTARGETPOINTEXCEPTIONS_H

#include <exception>
#include <string>

class NotWayBetweenSourceAndDestinationTargetPointExceptions: public std::exception
{
public:
    /** Constructor
     *  @param message The error message.
     */
    explicit NotWayBetweenSourceAndDestinationTargetPointExceptions(const std::string& message):
      msg_(message)
      {}

    /** Destructor.
     * Virtual to allow for subclassing.
     */
    virtual ~NotWayBetweenSourceAndDestinationTargetPointExceptions() throw (){}

    /** Returns a pointer to the (constant) error description.
     *  @return
     */
    virtual const char* what() const throw (){
       return msg_.c_str();
    }

    virtual const std::string message() const throw(){
        return msg_;
    }

protected:
    /** Error message.
     */
    std::string msg_;
};

#endif // NOTWAYBETWEENSOURCEANDDESTINATIONTARGETPOINTEXCEPTIONS_H
