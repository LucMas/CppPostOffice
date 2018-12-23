#ifndef POSTOFFICE_H
#define POSTOFFICE_H

#include "IPostOffice.h"
#include "IClient.h"
#include "Client.h"


class PostOffice: public IPostOffice
{
    public:
    unsigned gate_count;

    public:

        PostOffice();
        PostOffice(unsigned gate_co);
        ~PostOffice();
        std::shared_ptr<IClient> getClient(const std::string& identificationNumber);

};

#endif // POSTOFFICE_H
