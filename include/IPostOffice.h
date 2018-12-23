#ifndef IPOSTOFFICE_H
#define IPOSTOFFICE_H

#include <memory>
#include <vector>


#include "IClient.h"


class IPostOffice
{
public:

    static std::shared_ptr<IPostOffice> create(unsigned gate_create);
    virtual ~IPostOffice() = default;
    virtual std::shared_ptr<IClient> getClient(const std::string& identificationNumber) = 0;
    virtual void enqueueClient(const std::shared_ptr<IClient>& client) = 0;
    virtual std::vector<std::string> getStatus() = 0;
    virtual void gateReady(unsigned gateIndex) = 0;
};
#endif // IPOSTOFFICE_H

