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

};
#endif // IPOSTOFFICE_H

