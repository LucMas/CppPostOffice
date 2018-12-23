#ifndef ICLIENT_H
#define ICLIENT_H

#include <string>
#include <vector>



class IClient
{
    public:
        virtual ~IClient() = default;
        virtual std::string getIdNumber() = 0;
        virtual std::string getFullName() = 0;
        virtual void setFullName(const std::string& fullName) = 0;
        virtual int getPriority() = 0;
        virtual void updatePriority(int priority) = 0;


    protected:

    private:
};

#endif // ICLIENT_H
