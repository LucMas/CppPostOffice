#include "IPostOffice.h"
#include "PostOffice.h"
#include "Client.h"
#include <string>
#include <iterator>
#include <map>
#include <iostream>

PostOffice::PostOffice(){}
PostOffice::PostOffice(unsigned gate_co):gate_count(gate_co)
{
for (unsigned i=0;i<gate_co;i++)
{
    statusQ.push_back("");
    statusQObj.push_back(nullptr);
}
}

PostOffice::~PostOffice()
{
    //dtor
}

std::shared_ptr<IPostOffice> IPostOffice::create(unsigned gate_create)
{
    std::shared_ptr<IPostOffice> a(new PostOffice(gate_create));
    return a;
}


std::shared_ptr<IClient> PostOffice::getClient(const std::string& identificationNumber)
{
    std::shared_ptr<IClient> a(new Client(identificationNumber));
    return a;
}

void PostOffice::enqueueClient(const std::shared_ptr<IClient>& client)
{
        priorityQ.insert (std::pair<int,std::shared_ptr<IClient>>(client->getPriority(),client));
}

std::vector<std::string> PostOffice::getStatus()
{
    return statusQ;
}

void PostOffice::gateReady(unsigned gateIndex)
{
    std::multimap <int, std::shared_ptr<IClient>> :: iterator itr;
    itr=priorityQ.begin();
    statusQ[gateIndex]=itr->second->getFullName();
    statusQObj[gateIndex]=itr->second;
    priorityQ.erase(itr);
}

void PostOffice::collectPackages(unsigned gateIndex)
{

    statusQObj[gateIndex]->packagesCollected();

}
