#ifndef POSTOFFICE_H
#define POSTOFFICE_H

#include "IPostOffice.h"
#include "IClient.h"
#include "Client.h"
#include <map>
#include <string>


class PostOffice: public IPostOffice
{
    unsigned gate_count;
    std::multimap <int,std::string> priorityQ;
    std::vector<std::string> statusQ;
    public:
        PostOffice();
        PostOffice(unsigned gate_co);
        ~PostOffice();
        std::shared_ptr<IClient> getClient(const std::string& identificationNumber);
        void enqueueClient(const std::shared_ptr<IClient>& client);
        std::vector<std::string> getStatus();
        void gateReady(unsigned gateIndex);
};

#endif // POSTOFFICE_H
