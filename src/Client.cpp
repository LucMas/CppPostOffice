#include "Client.h"
#include "IClient.h"
Client::Client(){}
Client::Client(std::string Identy):id(Identy),priority(0)
{
    //ctor
}

Client::~Client()
{
    //dtor
}

std::string Client::getIdNumber()
{
    return id;
}
std::string Client::getFullName()
{
    return fullName;
}

void Client::setFullName(const std::string& fullName)
{
    this->fullName=fullName;
}

int Client::getPriority()
{
    return priority;
}

void Client::updatePriority(int priority)
{
    this->priority=priority;
}
