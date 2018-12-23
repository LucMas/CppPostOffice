#include "IPostOffice.h"
#include "PostOffice.h"
#include "Client.h"

PostOffice::PostOffice(){}
PostOffice::PostOffice(unsigned gate_co):gate_count(gate_co)
{

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


