#ifndef WRONGIDOBJECT_H
#define WRONGIDOBJECT_H


#include <exception>
#include <string>

class WrongIdObjectException: public std::exception
{
public:
    /** Constructor
     *  @param message The error message.
     */
    explicit WrongIdObjectException(const std::string& message):
      msg_(message)
      {}

    /** Destructor.
     * Virtual to allow for subclassing.
     */
    virtual ~WrongIdObjectException() throw (){}

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

#endif // WRONGIDOBJECT_H
