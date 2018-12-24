#include <iostream>
#include "IPostOffice.h"
#include "PostOffice.h"
#include "IClient.h"
#include "Client.h"
#include <string>
#include <cassert>
#include <vector>
using namespace std;

int main()
{
    auto post_office = IPostOffice::create(5);
    auto client0 = post_office->getClient("96052791812");
    client0->setFullName("Jan Kowalski");
    auto client1 = post_office->getClient("69100839677");
    client1->setFullName("Adam Nowak");
    client1->updatePriority(1);
    post_office->enqueueClient(client0);
    post_office->enqueueClient(client1);
    post_office->gateReady(3);
    auto status = post_office->getStatus();
    assert(status[3] == "Adam Nowak");
    client1->newPackage("123145");
    client1->newPackage("12323");
    client1->awaitingPackages();
    post_office->collectPackages(3);
    client1->awaitingPackages();
}
