#ifndef CLIENT_H
#define CLIENT_H

#include "IClient.h"

class Client: public IClient
{
    std::string id;
    std::string fullName;
    int priority;
    std::vector<std::string> packageQ;


    public:

        Client();
        Client(std::string Identy);
        std::string getIdNumber();
        std::string getFullName();
        void setFullName(const std::string& fullName);
        int getPriority();
        void updatePriority(int priority);
        void newPackage(const std::string& packageId);
        std::vector<std::string> awaitingPackages();
        void packagesCollected();






        ~Client();

};

#endif // CLIENT_H
