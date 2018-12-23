#include <iostream>
#include "IPostOffice.h"
#include "PostOffice.h"
#include "IClient.h"
#include "Client.h"
#include <string>
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
}
