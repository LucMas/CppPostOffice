#include "Client.h"
#include "IClient.h"
#include <iostream>
#include <memory>
#include <string>
#include <iterator>
#include<vector>
Client::Client(){}
Client::Client(std::string Identy):id(Identy),priority(0)
{
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
void Client::newPackage(const std::string& packageId)
{
    packageQ.push_back(packageId);
}

std::vector<std::string> Client::awaitingPackages()
{
    for(int i=0;i<packageQ.capacity();i++)
    {
        std::cout << packageQ[i] << std::endl;
    }
    return packageQ;
}

void Client::packagesCollected()
{
    packageQ.clear();

    std::vector<std::string>::iterator it;

    packageQ.shrink_to_fit();
    std::cout << packageQ.capacity() << std::endl;
    for(it=packageQ.begin();it != packageQ.end();++it)
    {

        std::cout << *it << std::endl;
    }
   for(int i=0;i<packageQ.capacity();i++)
  {
        std::cout << packageQ.at(i) << std::endl;
  }
}

